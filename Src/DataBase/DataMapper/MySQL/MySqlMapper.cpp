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
                d.SetIp(QHostAddress(query.value("ip").toString()));
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

        template<class T, class T2 = Nothing> template<class X1> QList<X1> MySqlMapper<T, T2>::Temp(QVariant test)
        {
        }

        template<> template<> QList<PeripheralCondition> MySqlMapper<Peripheral>::Temp<PeripheralCondition>(QVariant test)
        {
            QVariantList var;
            var.append(test);
            RW::SQL::DataFactory dd(m_logger);
            DataMapper<PeripheralCondition> *dm = dd.GetMapper<PeripheralCondition>(SourceType::SQL);
            QList<PeripheralCondition> res = dm->FindBySpecifier(DataMapper<PeripheralCondition>::Specifier::GetPeripheralConditionListByConditionID, var);

            delete dm;
            dm = nullptr;

            return res;
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


                QSqlQuery subQuery;
                subQuery.prepare(SelectByPeripheralID_PeripheralConditionMapping);
                subQuery.bindValue(":peripheralID", id);
                subQuery.bindValue(":workstationID", workstationId);
                
                res = subQuery.exec();
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
                    p->SetIp(QHostAddress(subQuery.value("ip").toString()));
                    p->SetTypeOfConnection(subQuery.value("typeOfCondition").value<RW::TypeOfElement>());
                    QVariant followUpID = subQuery.value("followUpCondition");
                    if (!followUpID.isNull())
                    {
                        QList<PeripheralCondition> temp = Temp<PeripheralCondition>(followUpID);
                        p->SetFollowUpCondition(temp);

                    }
                    d.ConditionList()->AddData(p);
                }
                list << d;
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
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl flashHistory FindBySpecifier failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }



    }
}