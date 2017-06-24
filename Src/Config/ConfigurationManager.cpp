#include "ConfigurationManager_p.h"
#include "ConfigurationManager.h"
#include "AllEntities.h"
#include "Repository.h"
#include "spdlog\spdlog.h"
#include <Winsock2.h>
#include <qdatetime.h>

#include <userenv.h>
#include <lm.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "userenv.lib")
#pragma comment(lib, "Netapi32.lib")

namespace RW{
    namespace CORE
    {
        //TODO API HELPER VERWENDEN
        bool ReturnCurrentUser(QString &Username)
        {
            LPWKSTA_USER_INFO_0 pBuf = NULL;
            LPWKSTA_USER_INFO_0 pTmpBuf;
            DWORD dwLevel = 0;
            DWORD dwPrefMaxLen = MAX_PREFERRED_LENGTH;
            DWORD dwEntriesRead = 0;
            DWORD dwTotalEntries = 0;
            DWORD dwResumeHandle = 0;
            DWORD i;
            DWORD dwTotalCount = 0;
            NET_API_STATUS nStatus;
            LPWSTR pszServerName = NULL;

            std::shared_ptr<spdlog::logger> logger = spdlog::get("file_logger");
            do // begin do
            {
                nStatus = NetWkstaUserEnum(pszServerName,
                    dwLevel,
                    (LPBYTE*)&pBuf,
                    dwPrefMaxLen,
                    &dwEntriesRead,
                    &dwTotalEntries,
                    &dwResumeHandle);
                if ((nStatus == NERR_Success) || (nStatus == ERROR_MORE_DATA))
                {
                    if ((pTmpBuf = pBuf) != NULL)
                    {
                        //
                        // Loop through the entries.
                        //
                        for (i = 0; (i < dwEntriesRead); i++)
                        {
                            assert(pTmpBuf != NULL);

                            if (pTmpBuf == NULL)
                            {
                                //
                                // Only members of the Administrators local group
                                //  can successfully execute NetWkstaUserEnum
                                //  locally and on a remote server.
                                //

                                logger->error("An access violation has occurred");
                                break;
                            }
                            //
                            // Print the user logged on to the workstation. 
                            //

                            logger->trace(QString::fromStdWString(pTmpBuf->wkui0_username).toStdString());
                            QString user = QString::fromStdWString(pTmpBuf->wkui0_username);
                            if (!user.contains("$"))
                                Username = user;

                            pTmpBuf++;
                            dwTotalCount++;
                        }
                    }
                }
                else
                    logger->error("A system error has occurred : {0:d}", nStatus);
                //
                // Free the allocated memory.
                //
                if (pBuf != NULL)
                {
                    NetApiBufferFree(pBuf);
                    pBuf = NULL;
                }
            } while (nStatus == ERROR_MORE_DATA); // end do
            //
            // Check again for allocated memory.
            //
            if (pBuf != NULL)
                NetApiBufferFree(pBuf);
            logger->trace("Total of {0:d} entries enumerated", dwTotalCount);
            return true;
        }

        ConfigurationManagerPrivate::ConfigurationManagerPrivate(std::shared_ptr<spdlog::logger> Logger, QObject *Parent) : QObject(Parent),
            m_Logger(Logger),
            q_ptr((ConfigurationManager*)Parent),
            m_ConfigCollection(new ConfigCollection()),
            m_ConfigCollectionLists(new ConfigCollectionLists()),
            m_Repository(new RW::SQL::Repository(RW::SourceType::SQL,Logger,this))
        {
            connect(this, &ConfigurationManagerPrivate::SaveConfiguration, this, &ConfigurationManagerPrivate::OnSaveConfiguration);
        }

        ConfigurationManagerPrivate::~ConfigurationManagerPrivate()
        {
            m_ConfigCollection->clear();
            delete m_ConfigCollection;
            m_ConfigCollection = nullptr;

            m_ConfigCollectionLists->clear();
            delete m_ConfigCollectionLists;
            m_ConfigCollectionLists = nullptr;
        }

        bool ConfigurationManagerPrivate::LoadWorkstation(QString HostName)
        {
            RW::SQL::Workstation rw;
            if ((m_Repository != nullptr))
            {
                if(!m_Repository->GetWorkstationByHostname(HostName, rw))
                    return false;

                m_ConfigCollection->insert(ConfigurationName::WorkstationId, rw.ID());
                m_ConfigCollection->insert(ConfigurationName::Ip, rw.Ip());
                m_ConfigCollection->insert(ConfigurationName::Mac, rw.Mac());
                m_ConfigCollection->insert(ConfigurationName::Hostname, rw.Hostname());
                m_ConfigCollection->insert(ConfigurationName::ProjectName, rw.AssignedProject()->Projectname());
                m_ConfigCollection->insert(ConfigurationName::ProjectId, rw.AssignedProject()->ID());
                m_ConfigCollection->insert(ConfigurationName::WorkstationType, QVariant::fromValue(rw.TypeOfWorkstation()->Type()));
                return true;
            }
            else
            {
                return false;
            }
        }

        bool ConfigurationManagerPrivate::LoadProjectSoftware(quint8 ProjectId)
        {
            RW::SQL::SoftwareProject s;
            QList<QVariant> list;
            if ((m_Repository != nullptr))
            {
                QList<RW::SQL::SoftwareProject> projList;
                if (!m_Repository->GetSoftwareProjectByProjectId(ProjectId, projList))
                    return false;

                m_ConfigCollection->insert(ConfigurationName::SoftwareProjectAmount, projList.count());
                for each (auto var in projList)
                {
                    list.append(var.Name());
                }

                m_ConfigCollectionLists->insert(ConfigurationName::SoftwareProject, list);

                return true;
            }
            else
            {
                return false;
            }
        }

        bool ConfigurationManagerPrivate::LoadUser(QString HostName)
        {
            RW::SQL::User user;
            if ((m_Repository != nullptr))
            {
                if (!m_Repository->GetUserByHostName(HostName, user))
                    return false;
            }
            else
            {
                return false;
            }
            
            m_ConfigCollection->insert(ConfigurationName::UserName, user.UserName());
            m_ConfigCollection->insert(ConfigurationName::UserPassword, user.Password());
            m_ConfigCollection->insert(ConfigurationName::UserRole, QVariant::fromValue(user.Role()));
            m_ConfigCollection->insert(ConfigurationName::MKSUsername, user.MKSUsername());
            m_ConfigCollection->insert(ConfigurationName::MKSPassword, user.MKSPassword());
            m_ConfigCollection->insert(ConfigurationName::Initials, user.Initials());

            if (user.ID() == 0)
                m_Logger->warn("LoadUser -> User id is 0");

            m_ConfigCollection->insert(ConfigurationName::UserId, user.ID());
        }

        bool ConfigurationManagerPrivate::LoadHistory(quint8 WorkstationID)
        {
            //TODO von Config lesen
            quint8 maxHistory = 10;
            
            QList<SQL::FlashHistory> listFlashHistory;
            QList<QVariant> list;
            if ((m_Repository != nullptr))
            {
                if (!m_Repository->GetAllFlashHistory(listFlashHistory))
                    return false;

                for each (auto var in listFlashHistory)
                {
                    list.append(QVariant::fromValue(var));
                }
            }
            else
            {
                return false;
            }


            m_ConfigCollectionLists->insert(ConfigurationName::FlashHistory, list);
            return true;
        }

        bool ConfigurationManagerPrivate::LoadGlobalSetting()
        {
            RW::SQL::GlobalSetting setting;
            if ((m_Repository != nullptr))
            {
                if (!m_Repository->GetGlobalSettingByID(1, setting))
                    return false;
            }
            else
            {
                return false;
            }

            m_ConfigCollection->insert(ConfigurationName::RwLogOutTimer, setting.RwLogOutTimer());
            m_ConfigCollection->insert(ConfigurationName::RwShutdownTimer, setting.RwShutdownTimer());
            m_ConfigCollection->insert(ConfigurationName::BeLogOutTimer, setting.BeLogOutTimer());
            m_ConfigCollection->insert(ConfigurationName::BeShutdownTimer, setting.BeShutdownTimer());
            return true;
        }

        void ConfigurationManagerPrivate::UpdateUser()
        {
            RW::SQL::User user;
            user.SetUserName(m_ConfigCollection->value(ConfigurationName::UserName).toString());
            user.SetPassword(m_ConfigCollection->value(ConfigurationName::UserPassword).toString());
            user.SetMKSUsername(m_ConfigCollection->value(ConfigurationName::MKSUsername).toString());
            user.SetMKSPassword(m_ConfigCollection->value(ConfigurationName::MKSPassword).toString());
            //TODO unschön
            user.SetRole((RW::UserRole)m_ConfigCollection->value(ConfigurationName::UserRole).toUInt());
            m_Repository->UpdateUser(user);
        }

        void ConfigurationManagerPrivate::UpdateValue(ConfigurationName Name, QVariant Value)
        {
            if (Name > ConfigurationName::UserStart && Name < ConfigurationName::UserEnd)
            {
                //Wenn User Free entspricht wird der StandartUser gesetzt
                if (Value == "Free" && Name == ConfigurationName::UserName)
                {

                }
                UpdateUser();
            }
        }


        void ConfigurationManagerPrivate::ChangeUser(ChangeUserReason Reason)
        {
            QString name = "";
            switch (Reason)
            {
            case ChangeUserReason::ServiceStarted:
            {
                name = "Free";
                m_Repository->UpdateWorkstationUser(m_ConfigCollection->value(ConfigurationName::WorkstationId).toInt(), name);
                break;
            }
            case ChangeUserReason::LogOff:
            {
                name = "Free";
                m_Repository->UpdateWorkstationUser(m_ConfigCollection->value(ConfigurationName::WorkstationId).toInt(), name);
                break;
            }
            case ChangeUserReason::Login:
            {

                if (ReturnCurrentUser(name))
                {
                    m_Repository->UpdateWorkstationUser(m_ConfigCollection->value(ConfigurationName::WorkstationId).toInt(), name);
                }
                else
                {
                    name = "Error";
                    m_Repository->UpdateWorkstationUser(m_ConfigCollection->value(ConfigurationName::WorkstationId).toInt(), name);
                }
                break;
            }
            case ChangeUserReason::ServiceStopped:
            {
                name = "Error";
                m_Repository->UpdateWorkstationUser(m_ConfigCollection->value(ConfigurationName::WorkstationId).toInt(), name);
                break;
            }

            default:
                break;
            }
        }        
        
        void ConfigurationManagerPrivate::UpdateUser(const ConfigurationName &Key, const QVariant &Val)
        {
            switch (Key)
            {
            case ConfigurationName::UserName:
                m_ConfigCollection->insert(Key, Val);
                emit SaveConfiguration(Key, ChangeReason::UserChanged);
                break;
            case ConfigurationName::UserPassword:
                m_ConfigCollection->insert(Key, Val);
                break;
            case ConfigurationName::Initials:
                m_ConfigCollection->insert(Key, Val);
                break;
            case ConfigurationName::UserRole:
                m_ConfigCollection->insert(Key, Val);
                break;
            case ConfigurationName::MKSPassword:
                m_ConfigCollection->insert(Key, Val);
                break;
            case ConfigurationName::MKSUsername:
                m_ConfigCollection->insert(Key, Val);
                break;
            default:
                break;
            }
        }



        void ConfigurationManagerPrivate::UpdateWorkstation(const ConfigurationName &Key, const QVariant &Val)
        {
            m_ConfigCollection->insert(Key, Val);
            if (Key == ConfigurationName::WorkstationState)
                emit SaveConfiguration(Key, ChangeReason::WorkstationStatusUpdate);
        }
        
        void ConfigurationManagerPrivate::UpdateWorkstationSettings(const ConfigurationName &Key, const QVariant &Val)
        {

        }

        void ConfigurationManagerPrivate::UpdateGlobalSettings(const ConfigurationName &Key, const QVariant &Val)
        {
        
        }

        void ConfigurationManagerPrivate::UpdateUserSettings(const ConfigurationName &Key, const QVariant &Val)
        {
        
        }



        void ConfigurationManagerPrivate::OnSaveConfiguration(ConfigurationName Key, ChangeReason Reason)
        {
            if (Key > ConfigurationName::UserStart && Key < ConfigurationName::UserEnd)
            {
                switch (Reason)
                {
                case ChangeReason::UserChanged:
                    //Aktualisiert den User für diese Workstation
                    m_Repository->UpdateWorkstationUser(m_ConfigCollection->value(ConfigurationName::WorkstationId).toInt(),
                        m_ConfigCollection->value(ConfigurationName::UserName).toString());
                    //Ladet den User und seinen Einstellungen nach der Aktualisierung
                    LoadUser(m_ConfigCollection->value(ConfigurationName::Hostname).toString());
                    break;
                case ChangeReason::UserSave:
                    UpdateUser();
                    break;
                case ChangeReason::WorkstationStatusUpdate:
                {
                    RW::WorkstationState state = m_ConfigCollection->value(ConfigurationName::WorkstationState).value<RW::WorkstationState>();
                    m_Repository->UpdateWorkstationState(m_ConfigCollection->value(ConfigurationName::WorkstationId).toInt(), state);
                    break;
                }
                default:
                    m_Logger->warn("OnSaveConfiguration: invalid change reason");  
                    break;
                }

            }
        }

        ConfigurationManager::ConfigurationManager(std::shared_ptr<spdlog::logger> Logger, QObject *Parent) : QObject(Parent),
            d_ptr(new ConfigurationManagerPrivate(Logger, Parent))
        {
        }

        ConfigurationManager::~ConfigurationManager()
        {
        }


        bool ConfigurationManager::GetConfigValue(const ConfigurationName &Key, QVariant &Val)
        {
            if (d_ptr->m_ConfigCollection->contains(Key))
            {
                Val = d_ptr->m_ConfigCollection->value(Key);
                return true;
            }
            else
            {
                return false;
            }
        }

        bool ConfigurationManager::GetConfigValue(const ConfigurationName &Key, QList<QVariant> &Val)
        {
            if (d_ptr->m_ConfigCollectionLists->contains(Key))
            {
                Val = d_ptr->m_ConfigCollectionLists->value(Key);
                return true;
            }
            else
            {
                return false;
            }
        }
        bool ConfigurationManager::GetConfigValue(const ConfigurationName &Key, QList<QVariant*> &Val)
        {
            return true;
        }

        bool ConfigurationManager::InsertConfigValue(const ConfigurationName &Key, const QVariant &Val)
        {
            if (Key > ConfigurationName::UserStart && Key < ConfigurationName::UserEnd)
            {
                d_ptr->UpdateUser(Key, Val);
            }
            else if (Key > ConfigurationName::HistoryStart && Key < ConfigurationName::HistoryEnd)
            {

            }
            else if (Key > ConfigurationName::WorkstationStart && Key < ConfigurationName::WorkstationEnd)
            {
                d_ptr->UpdateWorkstation(Key, Val);
            }

            return true;
        }


        bool ConfigurationManager::InsertConfigValue(const ConfigurationName &Key, const QList<QVariant> &Val)
        {
            return true;
        }

        bool ConfigurationManager::InsertConfigValue(const ConfigurationName &Key, const QList<QVariant*> &Val)
        {
            return true;
        }

        const QVariant ConfigurationManager::operator[](const ConfigurationName& Name)
        {
            return d_ptr->m_ConfigCollection->value(Name);
        }

        bool ConfigurationManager::Load()
        {
            char name[255] = {};
            DWORD size = 255;
            if (GetComputerNameA(name, &size) == 0)
            {
                return false;
            }

            QString hostName(name);
            if (!d_ptr->LoadWorkstation(hostName))
                return false;

            if (!d_ptr->LoadProjectSoftware(d_ptr->m_ConfigCollection->value(ConfigurationName::ProjectId).toInt()))
                return false;

            if (!d_ptr->LoadUser(hostName))
                return false;

            if (!d_ptr->LoadGlobalSetting())
                return false;
            return true;
        }
    }
}