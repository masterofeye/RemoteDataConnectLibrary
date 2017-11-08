#include "Repository.h"
#include "SqlGlobal.h"

#include "AllEntities.h"

#include "DataFactory.h"
#include "DataMapper.h"
#include "spdlog\spdlog.h"

namespace RW{
	namespace SQL{


		Repository::Repository(SourceType Source, QObject* Parent) : QObject(Parent),
			m_Source(Source)
		{

		}

		Repository::Repository(SourceType Source, std::shared_ptr<spdlog::logger> Logger, QObject* Parent) : QObject(Parent),
			m_Source(Source),
			m_logger(Logger)
		{
		}

		Repository::~Repository()
		{
		}

		bool Repository::InsertWorkstation(Workstation &R)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<Workstation> *dm = d.GetMapper<Workstation>(m_Source);
			if (dm == nullptr)
				return false;
			res = dm->Insert(R);
			delete dm;
			return res;
		}

		bool Repository::InsertLogEntry(LogEntry &E)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<LogEntry> *dm = d.GetMapper<LogEntry>(m_Source);
			if (dm == nullptr)
				return false;
			res = dm->Insert(E);
			delete dm;
			return res;
		}

		bool Repository::InsertUser(User &U)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<User> *dm = d.GetMapper<User>(m_Source);
			if (dm == nullptr)
				return false;
			res = dm->Insert(U);
			delete dm;
			return res;
		}

		bool Repository::InsertElementType(ElementType &E)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<ElementType> *dm = d.GetMapper<ElementType>(m_Source);
			if (dm == nullptr)
				return false;
			res = dm->Insert(E);
			delete dm;
			return res;
		}

		bool Repository::InsertElementConfiguration(ElementConfiguration &E)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<ElementConfiguration> *dm = d.GetMapper<ElementConfiguration>(m_Source);
			if (dm == nullptr)
				return false;
			res = dm->Insert(E);
			delete dm;
			return res;
		}

		bool Repository::InsertProduct(Product &P)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<Product> *dm = d.GetMapper<Product>(m_Source);
			if (dm == nullptr)
				return false;
			res = dm->Insert(P);
			delete dm;
			return res;
		}

		bool Repository::InsertInstruction(Instruction &I)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<Instruction> *dm = d.GetMapper<Instruction>(m_Source);
			if (dm == nullptr)
				return false;
			res = dm->Insert(I);
			delete dm;
			return res;
		}

		bool Repository::InsertRecept(Recept &R)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<Recept> *dm = d.GetMapper<Recept>(m_Source);
			if (dm == nullptr)
				return false;
			res = dm->Insert(R);
			delete dm;
			return res;
		}

		bool Repository::InsertProject(Project &P)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<Project> *dm = d.GetMapper<Project>(m_Source);
			if (dm == nullptr)
				return false;
			res = dm->Insert(P);
			delete dm;
			return res;
		}

		bool Repository::InsertDevice(Device &P)
		{
			bool res = false;
			DataFactory d(m_logger);
			DataMapper<Device> *dm = d.GetMapper<Device>(m_Source);
			if (dm == nullptr)
				return false;
			res = dm->Insert(P);
			delete dm;
			return res;
		}

        bool Repository::InsertFlashHistory(FlashHistory &H)
        {
            bool res = false;
            DataFactory d(m_logger);
            DataMapper<FlashHistory> *dm = d.GetMapper<FlashHistory>(m_Source);
            if (dm == nullptr)
                return false;
            res = dm->Insert(H);
            delete dm;
            return res;
        }

        bool Repository::InsertSoftwareProject(SoftwareProject &S)
        {
            bool res = false;
            DataFactory d(m_logger);
            DataMapper<SoftwareProject> *dm = d.GetMapper<SoftwareProject>(m_Source);
            if (dm == nullptr)
                return false;
            res = dm->Insert(S);
            delete dm;
            return res;

        }

        bool Repository::InsertWorkstationType(Workstation &W)
        {
            bool res = false;
            DataFactory d(m_logger);
            DataMapper<Workstation> *dm = d.GetMapper<Workstation>(m_Source);
            if (dm == nullptr)
                return false;
            res = dm->Insert(W);
            delete dm;
            return res;
        }

		bool Repository::GetWorkstationByID(quint64 ID, Workstation& R)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Workstation> *dm = d.GetMapper<Workstation>(m_Source);
				R = dm->FindByID(ID, false);
                delete dm;

                if (R.Hostname() == "")
                {
                    return false;
                }
			}
			catch (...)
			{
				m_logger->error("GetWorkstationByID throwed a exception");
				return false;
			}
			return true;
		}

        bool Repository::GetWorkstationByHostname(QString Hostname, Workstation& R)
        {
            bool found = false;

            try{
                DataFactory d(m_logger);
                DataMapper<Workstation> *dm = d.GetMapper<Workstation>(m_Source);
                QVariantList list;
                list << Hostname;
                QList<Workstation> rwList = dm->FindBySpecifier(DataMapper<Workstation>::Specifier::GetWorkstationByHostname, list);

                if (rwList.count() == 0)
                {
                    m_logger->error("GetWorkstationByHostname: List of workstations is empty.");
                    delete dm;
                    return false;
                }
                else if (rwList.count() > 1)
                {
                    m_logger->error("GetWorkstationByHostname: Multiple clients found");
                    delete dm;
                    return false;
                }

                R = rwList.first();

                delete dm;
            }
            catch (...)
            {
                m_logger->error("GetWorkstationByID throwed a exception.");
                return false;
            }
            return true;
        }

		bool Repository::GetUserByID(quint64 ID, User& U)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<User> *dm = d.GetMapper<User>(m_Source);
				U = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetUserByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetElementConfigurationByID(quint64 ID, ElementConfiguration& E)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<ElementConfiguration> *dm = d.GetMapper<ElementConfiguration>(m_Source);
				E = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetElementConfigurationByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetElementTypeByID(quint64 ID, ElementType& E)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<ElementType> *dm = d.GetMapper<ElementType>(m_Source);
				if (dm == nullptr)
					return false;
				E = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetElementConfigurationByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetProductByID(quint64 ID, Product& P)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Product> *dm = d.GetMapper<Product>(m_Source);
				if (dm == nullptr)
					return false;
				P = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetProductByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetInstructionByID(quint64 ID, Instruction& I)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Instruction> *dm = d.GetMapper<Instruction>(m_Source);
				if (dm == nullptr)
					return false;
				I = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetInstructionByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetReceptByID(quint64 ID, Recept& R)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Recept> *dm = d.GetMapper<Recept>(m_Source);
				if (dm == nullptr)
					return false;
				R = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetReceptByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetLogEntryByID(quint64 ID, LogEntry& L)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<LogEntry> *dm = d.GetMapper<LogEntry>(m_Source);
				if (dm == nullptr)
					return false;
				L = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetLogEntryByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetProjectByID(quint64 ID, Project& P)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Project> *dm = d.GetMapper<Project>(m_Source);
				if (dm == nullptr)
					return false;
				P = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetProjectByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetDeviceByID(quint64 ID, Device& P)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Device> *dm = d.GetMapper<Device>(m_Source);
				if (dm == nullptr)
					return false;
				P = dm->FindByID(ID, false);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetDeviceByID throwed a exception");
				return false;
			}
			return true;
        }

        bool Repository::GetFlashHistoryByID(quint64 ID, FlashHistory& P)
        {
            try{
                DataFactory d(m_logger);
                DataMapper<FlashHistory> *dm = d.GetMapper<FlashHistory>(m_Source);
                if (dm == nullptr)
                    return false;
                P = dm->FindByID(ID, false);
                delete dm;
            }
            catch (...)
            {
                m_logger->error("GetFlashHistoryByID throwed a exception");
                return false;
            }
            return true;
        }

        bool Repository::GetSoftwareProjectByID(quint64 ID, SoftwareProject& P)
        {
            try{
                DataFactory d(m_logger);
                DataMapper<SoftwareProject> *dm = d.GetMapper<SoftwareProject>(m_Source);
                if (dm == nullptr)
                    return false;
                P = dm->FindByID(ID, false);
                delete dm;
            }
            catch (...)
            {
                m_logger->error("GetSoftwareProjectByID throwed a exception");
                return false;
            }
            return true;
        }

        bool Repository::GetSoftwareProjectByProjectId(quint64 ID, QList<SoftwareProject>& P)
        {
            QList<SoftwareProject> projList;
            try{
                DataFactory d(m_logger);
                DataMapper<SoftwareProject> *dm = d.GetMapper<SoftwareProject>(m_Source);
                if (dm == nullptr)
                    return false;
                projList = dm->FindAll();

                if (projList.count() == 0)
                {
                    m_logger->error("GetSoftwareProjectByProjectId can't find any projects with id: {}", ID);
                    delete dm;
                    return false;
                }

                for each (SoftwareProject var in projList)
                {
					if (var.ProjectSw()->ID() == ID)
                    {
                        P.append(var);
                    }
                }
                delete dm;
            }
            catch (...)
            {
                m_logger->error("GetSoftwareProjectByID throwed a exception");
                return false;
            }
            return true;
        }

        bool Repository::GetWorkstationTypeByID(quint64 ID, QList<WorkstationType>& P)
        {
            QList<WorkstationType> projList;
            try{
                DataFactory d(m_logger);
                DataMapper<WorkstationType> *dm = d.GetMapper<WorkstationType>(m_Source);
                if (dm == nullptr)
                    return false;
                projList = dm->FindAll();

                for each (WorkstationType var in projList)
                {
                    if (var.ID() == ID)
                    {
                        P.append(var);
                    }
                }
                delete dm;
            }
            catch (...)
            {
                m_logger->error("GetWorkstationTypeByID throwed a exception");
                return false;
            }
            return true;
        }

        bool Repository::GetGlobalSettingByID(quint64 ID, GlobalSetting& P)
        {
            try{
                DataFactory d(m_logger);
                DataMapper<GlobalSetting> *dm = d.GetMapper<GlobalSetting>(m_Source);
                if (dm == nullptr)
                    return false;
                P = dm->FindByID(ID, false);

                delete dm;
            }
            catch (...)
            {
                m_logger->error("GetGlobalSettingByID throwed a exception");
                return false;
            }
            return true;
        }

		bool Repository::GetAllWorkstation(QList<Workstation> &AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Workstation> *dm = d.GetMapper<Workstation>(m_Source);
				if (dm == nullptr)
					return false;
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetLogEntryByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllUser(QList<User> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<User> *dm = d.GetMapper<User>(m_Source);
				if (dm == nullptr)
					return false;
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetLogEntryByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllElementConfiguration(QList<ElementConfiguration> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<ElementConfiguration> *dm = d.GetMapper<ElementConfiguration>(m_Source);
				if (dm == nullptr)
					return false;
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllElementConfiguration throwed a exception");
				return false;
			}
			return true;
		}


		bool Repository::GetAllElementType(QList<ElementType> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<ElementType> *dm = d.GetMapper<ElementType>(m_Source);
				if (dm == nullptr)
					return false;
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllElementType throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllInstruction(QList<Instruction> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Instruction> *dm = d.GetMapper<Instruction>(m_Source);
				if (dm == nullptr)
					return false;
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllInstruction throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllRecept(QList<Recept> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Recept> *dm = d.GetMapper<Recept>(m_Source);
				if (dm == nullptr)
					return false;
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllRecept throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllProduct(QList<Product> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Product> *dm = d.GetMapper<Product>(m_Source);
				if (dm == nullptr)
					return false;
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllProduct throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllLogEntry(QList<LogEntry> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<LogEntry> *dm = d.GetMapper<LogEntry>(m_Source);
				if (dm == nullptr)
					return false;
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllLogEntry throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllProject(QList<Project> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Project> *dm = d.GetMapper<Project>(m_Source);
				if (dm == nullptr)
					return false;
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllProject throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetAllDevice(QList<Device> & AllR)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<Device> *dm = d.GetMapper<Device>(m_Source);
				if (dm == nullptr)
					return false;
				AllR = dm->FindAll();
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetAllDevice throwed a exception");
				return false;
			}
			return true;
		}

        bool Repository::GetAllSoftwareProject(QList<SoftwareProject> & AllR)
        {
            try{
                DataFactory d(m_logger);
                DataMapper<SoftwareProject> *dm = d.GetMapper<SoftwareProject>(m_Source);
                if (dm == nullptr)
                    return false;
                AllR = dm->FindAll();
                delete dm;
            }
            catch (...)
            {
                m_logger->error("GetAllSoftwareProject throwed a exception");
                return false;
            }
            return true;
        }

        bool Repository::GetAllFlashHistory(QList<FlashHistory> & AllR)
        {
            try{
                DataFactory d(m_logger);
                DataMapper<FlashHistory> *dm = d.GetMapper<FlashHistory>(m_Source);
                if (dm == nullptr)
                    return false;
                AllR = dm->FindAll();
                delete dm;
            }
            catch (...)
            {
                m_logger->error("GetAllFlashHistory throwed a exception");
                return false;
            }
            return true;
        }

        bool Repository::GetAllWorkstationType(QList<WorkstationType> & AllR)
        {
            try{
                DataFactory d(m_logger);
                DataMapper<WorkstationType> *dm = d.GetMapper<WorkstationType>(m_Source);
                if (dm == nullptr)
                    return false;
                AllR = dm->FindAll();
                delete dm;
            }
            catch (...)
            {
                m_logger->error("GetAllWorkstationType throwed a exception");
                return false;
            }
            return true;
        }

        bool Repository::GetAllPeripheral(QList<Peripheral> & AllR)
        {
            try{
                DataFactory d(m_logger);
                DataMapper<Peripheral> *dm = d.GetMapper<Peripheral>(m_Source);
                if (dm == nullptr)
                    return false;
                AllR = dm->FindAll();
                delete dm;
            }
            catch (...)
            {
                m_logger->error("GetAllPeripheral throwed a exception");
                return false;
            }
            return true;
        }


		bool Repository::GetUserByName(QString Name, User& U)
		{
			QList<User> list;
			try{
				DataFactory d(m_logger);
				DataMapper<User> *dm = d.GetMapper<User>(m_Source);
				if (dm == nullptr)
					return false;
				list = dm->FindAll();
				for each (auto var in list)
				{
					if (var.UserName().compare(Name, Qt::CaseInsensitive) == 0)
						U = var;
				}

				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetUserByName throwed a exception");
				return false;
			}
	        return true;
		}

        bool Repository::GetUserByHostName(QString Hostname, User& U)
        {
            QList<Workstation> list;
            try{
                Workstation rw;
                DataFactory d(m_logger);
                DataMapper<Workstation> *dm = d.GetMapper<Workstation>(m_Source);
                if (dm == nullptr)
                    return false;
                list = dm->FindAll();
                for each (auto var in list)
                {
                    if (var.Hostname().compare(Hostname, Qt::CaseInsensitive) == 0)
                    {
                        rw = var;
                        break;
                    }
                }

                U = *rw.CurrentUser();
                delete dm;
            }
            catch (...)
            {
                m_logger->error("GetUserByHostName throwed a exception.");
                return false;
            }
            return true;
        }


        bool Repository::UpdateUser(User& U)
        {
            try{
                Workstation rw;
                DataFactory d(m_logger);
                DataMapper<User> *dm = d.GetMapper<User>(m_Source);
                if (dm == nullptr)
                    return false;

                if(!dm->Update(U))
                    m_logger->error("UpdateUser failed durring update.");
                delete dm;
            }
            catch (...)
            {
                m_logger->error("UpdateUser throwed a exception.");
                return false;
            }
            return true;
        }

        bool Repository::UpdatePeripheralState(quint64 WorkstationID, quint8 PeripheralID, bool IsProvided, bool IsRegistered, bool IsActive)
        {
            try{
                Workstation rw;
                DataFactory d(m_logger);
                DataMapper<Peripheral> *dm = d.GetMapper<Peripheral>(m_Source);
                if (dm == nullptr)
                    return false;

                QVariantList list;
                list.append(WorkstationID);
                list.append(PeripheralID);
                list.append(IsProvided);
                list.append(IsRegistered);
                list.append(IsActive);

                if (!dm->UpdateBySpecifier(DataMapper<Peripheral>::Specifier::UpdatePeripheralState, list))
                    m_logger->error("UpdatePeripheralState failed durring update.");
                delete dm;
            }
            catch (...)
            {
                m_logger->error("UpdatePeripheralState throwed a exception.");
                return false;
            }
            return true;
        }

        bool Repository::UpdateWorkstationSetting(WorkstationSetting Setting)
        {
            try{
                Workstation rw;
                DataFactory d(m_logger);
                DataMapper<WorkstationSetting> *dm = d.GetMapper<WorkstationSetting>(m_Source);
                if (dm == nullptr)
                    return false;

                if (!dm->Update(Setting))
                    m_logger->error("UpdateWorkstationSetting failed durring update.");
                delete dm;
            }
            catch (...)
            {
                m_logger->error("UpdateWorkstationSetting throwed a exception.");
                return false;
            }
            return true;
        }


        bool Repository::UpdateWorkstation(Workstation& R)
        {
            try{
                Workstation rw;
                DataFactory d(m_logger);
                DataMapper<Workstation> *dm = d.GetMapper<Workstation>(m_Source);
                if (dm == nullptr)
                    return false;

                if (!dm->Update(R))
                    m_logger->error("UpdateWorkstation failed durring update.");
                delete dm;
            }
            catch (...)
            {
                m_logger->error("UpdateWorkstation throwed a exception.");
                return false;
            }
            return true;
        }

        bool Repository::UpdateWorkstationUser(quint16 WorkstationId, QString& Name)
        {
            try{
                Workstation rw;
                User user;
                DataFactory d(m_logger);
                DataMapper<Workstation> *dmRw = d.GetMapper<Workstation>(m_Source);
                if (dmRw == nullptr)
                    return false;

                rw = dmRw->FindByID(WorkstationId, false);

                if (rw.Hostname().isEmpty())
                {
                    m_logger->error("UpdateWorkstationUser failed durring update, couldn't find Workstation with id {}.", WorkstationId);
                    delete dmRw;
                    return false;
                }


                if (!GetUserByName(Name, user))
                {
                    m_logger->error("UpdateWorkstationUser failed durring update.");
                    delete dmRw;
                    return false;
                }
                rw.SetCurrentUser(&user);

                if (!dmRw->Update(rw))
                {
                    m_logger->error("UpdateWorkstationUser failed durring update.");
                    delete dmRw;
                    return false;
                }
                delete dmRw;
            }
            catch (...)
            {
                m_logger->error("UpdateWorkstationUser throwed a exception.");
                return false;
            }
            return true;
        }

		bool Repository::GetFlashHistoryByWorkstationID(quint64 ID, QList<FlashHistory>& P)
		{
			try{
				DataFactory d(m_logger);
				QVariantList list; 
				list << ID;
				DataMapper<FlashHistory> *dm = d.GetMapper<FlashHistory>(m_Source);
				if (dm == nullptr)
					return false;
				P = dm->FindBySpecifier(DataMapper<FlashHistory>::Specifier::GetHistoryByWorkstationID, list);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetFlashHistoryByID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetLastestFlasHistoryEntryByWorkstationIDAndSoftwareProjectID(quint64 WorkstationID,
			quint64 SoftwareProjectID,
			QList<FlashHistory>& P)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<FlashHistory> *dm = d.GetMapper<FlashHistory>(m_Source);
				if (dm == nullptr)
					return false;
				QVariantList list;
				list << WorkstationID << SoftwareProjectID;
				P = dm->FindBySpecifier(DataMapper<FlashHistory>::Specifier::GetLastestFlasHistoryEntryByWorkstationIDAndSoftwareProjectID, list);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetLastestFlasHistoryEntryByWorkstationIDAndSoftwareProjectID throwed a exception");
				return false;
			}
			return true;
		}

		bool Repository::GetSoftwareProjectsByProjectID(quint64 ID, QList<SoftwareProject>& P)
		{
			try{
				DataFactory d(m_logger);
				DataMapper<SoftwareProject> *dm = d.GetMapper<SoftwareProject>(m_Source);
				if (dm == nullptr)
					return false;
				QVariantList list;
				list  << ID;
				P = dm->FindBySpecifier(DataMapper<SoftwareProject>::Specifier::GetSoftwareProjectsByProjectID, list);
				delete dm;
			}
			catch (...)
			{
				m_logger->error("GetSoftwareProjectsByProjectID throwed a exception");
				return false;
			}
			return true;
		}


        bool Repository::GetLogEntryByHostName(QString HostName, QList<LogEntry> & AllR)
        {
            QList<LogEntry> allLogEntry;
            try{
                DataFactory d(m_logger);
                DataMapper<LogEntry> *dm = d.GetMapper<LogEntry>(m_Source);
                if (dm == nullptr)
                    return false;
                allLogEntry = dm->FindAll();
                delete dm;

                for each (auto var in allLogEntry)
                {
                    if (var.ComputerNameRW() == HostName)
                    {
                        AllR.append(var);
                    }
                }              
            }
            catch (...)
            {
                m_logger->error("GetLogEntryByHostName throwed a exception");
                return false;
            }
            return true;
        }

        bool Repository::GetPeripheralByHardwareID(QString HardwareID, Peripheral& R)
        {
            QList<Peripheral> allLogEntry;
            try{
                DataFactory d(m_logger);
                DataMapper<Peripheral> *dm = d.GetMapper<Peripheral>(m_Source);
                if (dm == nullptr)
                    return false;
                allLogEntry = dm->FindAll();
                delete dm;

                //for each (auto var in allLogEntry)
                //{
                //    if (var.HardwareID() == HardwareID)
                //    {
                //        R = var;
                //    }
                //}
            }
            catch (...)
            {
                m_logger->error("GetPeripheralByHardwareID throwed a exception");
                return false;
            }
            return true;
        }

        bool Repository::GetPeripheralByWorkstationID(quint64 ID, QList<Peripheral>& R)
        {
            try{
                DataFactory d(m_logger);
                DataMapper<Peripheral> *dm = d.GetMapper<Peripheral>(m_Source);
                if (dm == nullptr)
                    return false;
                QVariantList list;
                list << ID;
                R = dm->FindBySpecifier(DataMapper<Peripheral>::Specifier::GetPeripheralByWorkstationID, list);
                delete dm;

            }
            catch (...)
            {
                m_logger->error("GetPeripheralByWorkstationID throwed a exception");
                return false;
            }
            return true;
        }



	}
}