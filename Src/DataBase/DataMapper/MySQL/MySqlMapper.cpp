#include "MySqlMapper.h"
#include "DataFactory.h"

namespace RW{
    namespace SQL{


        template<class T, class T2 = Nothing> QList<T> MySqlMapper<T, T2>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<T> m; return std::move(m);
        }

        template<> QList<LogEntry> MySqlMapper<LogEntry>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<LogEntry> m; return std::move(m);
        }


        template<> QList<ElementConfiguration> MySqlMapper<ElementConfiguration>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<ElementConfiguration> m; return std::move(m);
        }


        template<> QList<ElementType> MySqlMapper<ElementType>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<ElementType> m; return std::move(m);
        }


        template<> QList<Instruction> MySqlMapper<Instruction>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<Instruction> m; return std::move(m);
        }

        template<> QList<Recept> MySqlMapper<Recept>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<Recept> m; return std::move(m);
        }

        template<> QList<Product> MySqlMapper<Product>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<Product> m; return std::move(m);
        }

        template<> QList<Device> MySqlMapper<Device>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<Device> m; return std::move(m);
        }

        template<> QList<GlobalSetting> MySqlMapper<GlobalSetting>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<GlobalSetting> m; return std::move(m);
        }

        template<> QList<UserSettings> MySqlMapper<UserSettings>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<UserSettings> list;
            QSqlQuery query;
            bool res = false;
            if (Value == Specifier::GetUserSettingByUserID)
            {
                quint64 userID = Parameter.first().toInt();
                query.prepare(SelectUserSettingsByUserID);
                query.bindValue(":userID", userID);
                res = query.exec();
            }

            while (query.next())
            {
                UserSettings d;
                d.SetLogoutTimeStart(query.value("logoutTimeStart").toTime());
                d.SetLogoutTimeEnd(query.value("logoutTimeEnd").toTime());
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl UserSettings FindBySpecifier failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }


        template<> QList<PeripheralCondition> MySqlMapper<PeripheralCondition>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<PeripheralCondition> list;
            QSqlQuery query;
            bool res = false;
            if (Value == Specifier::GetPeripheralConditionListByConditionID)
            {
                quint64 conditionID = Parameter.first().toInt();
                query.prepare(SelectAllConditionsInPeripheralCondition);
                query.bindValue(":followUpID", conditionID);
                res = query.exec();
            }

            while (query.next())
            {
                PeripheralCondition d;
                quint64 id = query.value("idPeripheralCondition").toInt();
                d.SetID(id);
                d.SetID(query.value("idPeripheralCondition").toInt());
                d.SetConditionPeripheral(new Peripheral(FindByID<Peripheral>(query.value("peripheralID").toInt())));
                d.SetPriority(query.value("priority").toInt());
                d.SetPort(query.value("port").toString());
                d.SetPin(query.value("pin").toString());
                d.SetTypeOfInformation(query.value("typeOfInformtation").toInt());
                d.SetState(query.value("state").toBool());
                d.SetDeviceType(query.value("internalType").value<PeripheralType>());
                d.SetTypeOfConnection(query.value("typeOfCondition").value<RW::TypeOfElement>());
                QVariant followUpID = query.value("followUpCondition");
                if (!followUpID.isNull())
                {
                    QVariantList var;
                    var.append(followUpID);
                    Specifier t = Specifier::GetPeripheralConditionListByConditionID;
                    d.SetFollowUpCondition(FindBySpecifier(t, var));;
                }
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl PeripheralCondition FindBySpecifier failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }



        template<> QList<Peripheral> MySqlMapper<Peripheral>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<Peripheral> list;
            QSqlQuery query;

            bool res = false;
            quint64 workstationId = Parameter.first().toInt();
            if (Value == Specifier::GetPeripheralByWorkstationID)
            {
                query.prepare(SelectByWorkstationID_PeripheralMapping);
                query.bindValue(":workstationID", workstationId);
                res = query.exec();
            }


            while (query.next())
            {
                Peripheral d;
                quint64 id = query.value("idPeripheral").toInt();
                d.SetID(id);
                d.SetAddress(query.value("address").toInt());
                d.SetBusGUID(query.value("busGUID").toString());
                d.SetBusnummer(query.value("busnummer").toUInt());
                d.SetClass(query.value("class").toString());
                d.SetClassGUID(query.value("classGUID").toString());
                d.SetCompatibleID(query.value("compatibleID").toStringList());
                d.SetDescription(query.value("description").toString());
                d.SetDeviceName(query.value("deviceName").toString());
                d.SetEnumeratorName(query.value("enumeratorName").toString());
                d.SetFriendlyName(query.value("friendlyName").toString());
                d.SetHardwareID(query.value("hardwareID").toStringList());
                d.SetInstallState(query.value("installState").toUInt());
                d.SetInteralType(query.value("internalType").value<PeripheralType>());
                d.SetLocationInformation(query.value("locationInformation").toString());
                d.SetLocationPath(query.value("locationPath").toString());
                d.SetManufacturer(query.value("manufacturer").toString());
                d.SetServiceName(query.value("serviceName").toString());
                d.SetWindowsDeviceType(query.value("windowsDeviceType").toUInt());
                d.SetProvided(query.value("provided").toBool());
                d.SetActivate(query.value("active").toBool());
                d.SetRegistered(query.value("registered").toBool());
                
                RW::SQL::DataFactory dProperties(m_logger);
                DataMapper<PeripheralProperties> *dmProperties = dProperties.GetMapper<PeripheralProperties>(SourceType::SQL);
                
                QVariantList varMappingID;
                varMappingID.append(query.value("idPeripheralMapping").toInt());
                QList<PeripheralProperties> listProperties = dmProperties->FindBySpecifier(DataMapper<PeripheralProperties>::Specifier::GetPeripheralPropertiesbyMappingID, varMappingID);
                if (listProperties.count() == 0)
                {
                    d.SetPeripheralPropertie(new PeripheralProperties());
                }
                else
                {
                    d.SetPeripheralPropertie(new PeripheralProperties(listProperties.first()));
                }
                
                delete dmProperties;
                dmProperties = nullptr;

                QSqlQuery subQuery;
                subQuery.prepare(SelectByPeripheralID_PeripheralConditionMapping);
                subQuery.bindValue(":peripheralID", id);
                subQuery.bindValue(":workstationID", workstationId);
                
                res = subQuery.exec();

                RW::SQL::DataFactory dd(m_logger);
                DataMapper<PeripheralCondition> *dm = dd.GetMapper<PeripheralCondition>(SourceType::SQL);

                while (subQuery.next())
                {
                    PeripheralCondition *p = new PeripheralCondition();
                    p->SetConditionPeripheral(new Peripheral(FindByID<Peripheral>(query.value("peripheralID").toInt())));
                    p->SetPriority(subQuery.value("priority").toInt());
                    p->SetPort(subQuery.value("port").toString());
                    p->SetPin(subQuery.value("pin").toString());
                    p->SetTypeOfInformation(subQuery.value("typeOfInformtation").toInt());
                    p->SetState(subQuery.value("state").toBool());
                    p->SetDeviceType(subQuery.value("internalType").value<PeripheralType>());
                    p->SetTypeOfConnection(subQuery.value("typeOfCondition").value<RW::TypeOfElement>());
                    QVariant followUpID = subQuery.value("followUpCondition");
                    if (!followUpID.isNull())
                    {
                        QVariantList var;
                        var.append(followUpID);

                        QList<PeripheralCondition> res = dm->FindBySpecifier(DataMapper<PeripheralCondition>::Specifier::GetPeripheralConditionListByConditionID, var);
                        p->SetFollowUpCondition(res);

                    }
                    d.ConditionList()->AddData(p);
                }
                list << d;

                delete dm;
                dm = nullptr;
            }



            if (!res)
            {
                m_logger->error("Tbl Peripheral FindBySpecifier failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }

        template<> QList<FlashHistory> MySqlMapper<FlashHistory>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<FlashHistory> list;
            QSqlQuery query;
            bool res = false;
            if (Value == Specifier::GetHistoryByWorkstationID)
            {
                quint64 workstationId = Parameter.first().toInt();
                query.prepare(SelectByWorkstationId_FlashHistory);
                query.bindValue(":workstationID", workstationId);
                res = query.exec();
            }
            else if (Value == Specifier::GetLastestFlasHistoryEntryByWorkstationIDAndSoftwareProjectID)
            {
                quint64 workstationId = Parameter.first().toInt();
                quint64 softwareProjectsId = Parameter.last().toInt();
                query.prepare(SelectByWorkstationIdAndSoftwareProject_FlastHistory);
                query.bindValue(":workstationID", workstationId);
                query.bindValue(":softwareProjectID", softwareProjectsId);
                res = query.exec();
            }


            while (query.next())
            {
                FlashHistory d;
                d.SetID(query.value("idFlashHistory").toInt());
                // \!todo unschöne Konvertierung
                d.SetUserHistory(new User(FindByID<User>(query.value("userID").toInt())));
                d.SetWorkstationHistory(new Workstation(FindByID<Workstation>(query.value("workstationID").toInt())));
                d.SetSoftwareProjectHistory(new SoftwareProject(FindByID<SoftwareProject>(query.value("softwareProjectID").toInt())));
                d.SetMajor(query.value("major"));
                d.SetMinor(query.value("minor"));
                d.SetPatchLevel(query.value("patchlevel"));
                d.SetBuildnumber(query.value("buildnumber"));
                d.SetDate(query.value("date").toDateTime());
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl flashHistory FindBySpecifier failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;

        }

        template<> QList<PeripheralProperties> MySqlMapper<PeripheralProperties>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<PeripheralProperties> list;
            QSqlQuery query;
            bool res = false;
            if (Value == Specifier::GetPeripheralPropertiesbyMappingID)
            {
                quint64 peripheralmappingID = Parameter.first().toInt();
                query.prepare(SelectByPeripheralMappingID_PeripheralProperties);
                query.bindValue(":peripheralmappingID", peripheralmappingID);
                res = query.exec();
            }
            while (query.next())
            {
                PeripheralProperties d;
                d.SetID(query.value("idPeripheralProperties").toInt());
                d.SetProperty1(query.value("property1"));
                d.SetProperty2(query.value("property2"));
                d.SetProperty3(query.value("property3"));
                d.SetProperty4(query.value("property4"));
                d.SetProperty5(query.value("property5"));
                list << d;
            }
            if (!res)
            {
                m_logger->error("Tbl PeripheralProperties FindBySpecifier failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;

        }

        template<> QList<SoftwareProject> MySqlMapper<SoftwareProject>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<SoftwareProject> list;
            QSqlQuery query;
            bool res = false;
            if (Value == Specifier::GetSoftwareProjectsByProjectID)
            {
                quint64 projectId = Parameter.first().toInt();
                query.prepare(SelectByProjectID_SoftwareProject);
                query.bindValue(":projectID", projectId);
                res = query.exec();
            }

            while (query.next())
            {
                SoftwareProject d;
                d.SetID(query.value("idSoftwareProject").toInt());
                d.SetProjectSw(new Project(FindByID<Project>(query.value("projectID").toInt())));
                // \!todo unschöne Konvertierung
                d.SetName(query.value("name").toString());
                d.SetNaturalName(query.value("naturalName").toString());
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl flashHistory FindBySpecifier failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }

        template<> QList<Workstation> MySqlMapper<Workstation>::FindBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QList<Workstation> list;
            QSqlQuery query;
            bool res = false;
            if (Value == Specifier::GetWorkstationByHostname)
            {
                QString hostname = Parameter.first().toString();
                query.prepare(SelectByHostname_Workstation);
                query.bindValue(":hostname", hostname);
                res = query.exec();
            }

            while (query.next())
            {
                Workstation d;
                d.SetID(query.value("idWorkstation").toInt());
                if (FindByID<User>(query.value("userID").toInt()).UserName() == "")
                    d.SetCurrentUser(nullptr);
                else
                    d.SetCurrentUser(new User(FindByID<User>(query.value("userID").toInt())));
                d.SetIp(query.value("ip").toString());
                d.SetMac(query.value("mac").toString());
                d.SetHostname(query.value("hostname").toString());
                d.SetSettingOfWorkstation(new WorkstationSetting(FindByID<WorkstationSetting>(query.value("workstationSettingID").toInt())));
                d.SetTypeOfWorkstation(new WorkstationType(FindByID<WorkstationType>(query.value("workstationTypeID").toInt())));
                d.SetState((RW::WorkstationState)query.value("state").toInt());
                d.setAssignedProject(new Project(FindByID<Project>(query.value("projectID").toInt())));
                d.SetPermanentLogin(query.value("permanentLogin").toBool());
                d.SetReason(new PermanentLoginReason(FindByID<PermanentLoginReason>(query.value("permanentLoginReasonID").toInt())));
                d.SetMaxPermanentLogin(query.value("maxPermanentLogin").toDateTime());
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl flashHistory FindBySpecifier failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }

        template<> User MySqlMapper<User>::FindByID(const quint64 ID, bool Flag)
        {
            User d;
            QSqlQuery query;
            query.prepare(SelectById_User);
            query.bindValue(":idUser", ID);
            bool res = query.exec();

            RW::SQL::DataFactory dd(m_logger);
            DataMapper<UserSettings> *dm = dd.GetMapper<UserSettings>(SourceType::SQL);

            while (query.next())
            {

                d.SetID(query.value("idUser").toInt());
                d.SetUserName(query.value("username").toString());
                d.SetPassword(query.value("password").toString());
                d.SetMKSUsername(query.value("mksUsername").toString());
                d.SetMKSPassword(query.value("mksPassword").toString());
                d.SetInitials(query.value("initials").toString());
                d.SetNotifiyRemoteDesktop(query.value("notifiyRemoteDesktop").toBool());
                d.SetNotifiyDesktop(query.value("notifiyDesktop").toBool());
                //@todo unschöner cast hier
                d.SetRole((RW::UserRole)query.value("role").toInt());
                d.SetUserWorkstation(query.value("userWorkstation").toInt());

                QVariantList var;
                var.append(query.value("idUser").toInt());

                QList<UserSettings> res = dm->FindBySpecifier(DataMapper<UserSettings>::Specifier::GetUserSettingByUserID, var);
                d.SetSettings(new UserSettings(res.first()));
            }

            delete dm;
            dm = nullptr;

            if (!res)
            {
                m_logger->error("Tbl user FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return d;
        }

        template<> Peripheral MySqlMapper<Peripheral>::FindByID(const quint64 ID, bool Flag)
        {
            Peripheral d;
            QSqlQuery query;
            query.prepare(SelectById_Peripheral);
            query.bindValue(":idPeripheral", ID);
            bool res = query.exec();

            while (query.next())
            {
                // \!todo unschöne Konvertierung
                d.SetID(query.value("idPeripheral").toInt());
                d.SetAddress(query.value("address").toInt());
                d.SetBusGUID(query.value("busGUID").toString());
                d.SetBusnummer(query.value("busnummer").toUInt());
                d.SetClass(query.value("class").toString());
                d.SetClassGUID(query.value("classGUID").toString());
                d.SetCompatibleID(query.value("compatibleID").toStringList());
                d.SetDescription(query.value("description").toString());
                d.SetDeviceName(query.value("deviceName").toString());
                d.SetEnumeratorName(query.value("enumeratorName").toString());
                d.SetFriendlyName(query.value("friendlyName").toString());
                d.SetHardwareID(query.value("hardwareID").toStringList());
                d.SetInstallState(query.value("installState").toUInt());
                d.SetInteralType(query.value("internalType").value<PeripheralType>());
                d.SetLocationInformation(query.value("locationInformation").toString());
                d.SetLocationPath(query.value("locationPath").toString());
                d.SetManufacturer(query.value("manufacturer").toString());
                d.SetServiceName(query.value("serviceName").toString());
                d.SetWindowsDeviceType(query.value("windowsDeviceType").toUInt());
                d.SetProvided(query.value("provided").toBool());

                RW::SQL::DataFactory dProperties(m_logger);
                DataMapper<PeripheralProperties> *dmProperties = dProperties.GetMapper<PeripheralProperties>(SourceType::SQL);
                QVariantList varMappingID;
                varMappingID.append(query.value("peripheralID").toInt());
                QList<PeripheralProperties> listProperties = dmProperties->FindBySpecifier(DataMapper<PeripheralProperties>::Specifier::GetPeripheralPropertiesbyMappingID, varMappingID);
                if (listProperties.count() == 0)
                {
                    d.SetPeripheralPropertie(new PeripheralProperties());
                }
                else
                {
                    d.SetPeripheralPropertie(new PeripheralProperties(listProperties.first()));
                }

                delete dmProperties;
                dmProperties = nullptr;


            }

            if (!res)
            {
                m_logger->error("Tbl Peripheral FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return d;
        }

        template<> bool MySqlMapper<Peripheral>::UpdateBySpecifier(const Specifier Value, const QVariantList Parameter)
        {
            QSqlQuery query;

            quint64 workstationID = Parameter[0].toInt();
            quint8 peripheralID = Parameter[1].toInt();
            bool isProvided = Parameter[2].toBool();
            bool isRegistered = Parameter[3].toBool();
            bool isActive = Parameter[4].toBool();

            query.prepare(Update_PeripheralState);
            query.bindValue(":workstationID", workstationID);
            query.bindValue(":peripheralID", peripheralID);
            query.bindValue(":provided", isProvided);
            query.bindValue(":registered", isRegistered);
            query.bindValue(":active", isActive);
            bool res = query.exec();

            if (!res)
            {
                m_logger->error("Tbl Peripheral UpdateBySpecifier failed. Error:{}", query.lastError().text().toUtf8().constData());
                return false;
            }
            return true;
        }

    }
}