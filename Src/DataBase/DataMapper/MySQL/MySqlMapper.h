#pragma once
#include "DataMapper.h"
#include "AllEntities.h"
#include "qsqlquery.h"
#include "qvariant.h"
#include "qdatetime.h"
#include "qdebug.h"
#include "qsqlerror.h"
#include "spdlog/spdlog.h"
namespace RW{
	namespace SQL{

        const QString Insert_Workstation = "INSERT INTO Workstation (userID,hostname,mac,ip,state,projectID,workstationSetting,workstationType) VALUES (:user,:hostname,:mac,:ip,:state,( SELECT idProject FROM project WHERE name=:name),:workstationSetting,:workstationType)";
		const QString Insert_User = "INSERT INTO user (username,password,mksUsername,mksPassword,initials,notifiyRemoteDesktop,notifiyDesktop,role ) VALUES (:username,:password,:mksUsername,:mksPassword,:initials,:notifiyRemoteDesktop,:notifiyDesktop, :role)";
		const QString Insert_ElementConfiguration = "INSERT INTO elementConfiguration (WorkstationID, elementTypeID, displayName, name, groupName, function, tooltip, remoteViewRelevant, isFeature, pin) VALUES (:WorkstationID, (SELECT idElementType FROM elementType WHERE type=:type),:displayName,:name,:groupName,:function,:tooltip,:remoteViewRelevant, :isFeature, :pin)";
		const QString Insert_ElementType = "INSERT INTO elementType (type) VALUES (:type)";
		const QString Insert_Instruction = "INSERT INTO instruction (step) VALUES (:step)";
		const QString Insert_Recept = "INSERT INTO recept (receptName,orderNumber,instructionID) VALUES (:receptName,:orderNumber,:instructionID)";
		const QString Insert_Product = "INSERT INTO product (productName,part,receptID) VALUES (:productName,:part,:receptID)";
		const QString Insert_LogEntry = "INSERT INTO log (date,message,loglevel,threadId,errorId,type,computerName, filter) VALUES (:datetime,:message,:loglevel,:threadId,:errorId,:type,:computerName,:filter)";
		const QString Insert_Project = "INSERT INTO project (name) VALUES (:name)";
		const QString Insert_Device = "INSERT INTO device( description, vendorId, productId, serial, deviceName) VALUES (:description, :vendorId, :productId, :serial, :deviceName)";
        const QString Insert_SoftwareProject = "INSERT INTO softwareProject (name) VALUES (:name)";
        const QString Insert_FlashHistory = "INSERT INTO flashHistory (userID, softwareProjectID, remoteWorkstationID, major, minor, patchlevel, buildnumber, data) VALUES (:userID, :softwareProjectID, :remoteWorkstationID,:major, :minor, :patchlevel, :buildnumber, :data)";
        const QString Insert_WorkstationType = "INSERT INTO workstationType (type) VALUES (type)";
        const QString Insert_PeripheralMapping = "INSERT INTO peripheralMapping (workstationID, peripheralID) VALUES (:workstationID, :peripheralID)";
        const QString Insert_Peripheral = "INSERT INTO peripheral (address, subAddress1, subAddress2, subAddress3, name, type, connectionType, serialNumber, deviceName, description, hardwareID1, hardwareID2, hardwareID3, state)";
        const QString Insert_GlobalSetting = "INSERT INTO globalsetting ( rwShutdownTime, rwLogoutTime, beShutdownTime, beLogoutTime) VALUES ( :rwShutdownTime, :rwLogoutTime, :beShutdownTime, :beLogoutTime)";
        const QString Insert_WorkstationSetting = "INSERT INTO workstationsetting(permanentLogin, permamentLoginReasonID) VALUES (:permanentLogin,:permamentLoginReasonID)";
        const QString Insert_PermanentLoginReason = "INSERT INTO permanentloginreason(reason, description) VALUES (:reason,:description)";


		const QString Update_Workstation = "UPDATE workstation SET userID=:userID,hostname=:hostname,mac=:mac,ip=:ip,state=:state, projectID=:projectID, workstationSettingID=:workstationSettingID, workstationTypeID=:workstationTypeID WHERE idWorkstation=:idWorkstation";
		const QString Update_User = "UPDATE user SET username=:username,password=:password,mksUsername=:mksUsername,mksPassword=:mksPassword,initials=:intitials,notifiyRemoteDesktop=:notifiyRemoteDesktop,notifiyDesktop=:notifiyDesktop, role=:role";
		const QString Update_ElementConfiguration = "UPDATE elementConfiguration SET WorkstationID=:WorkstationID,type=:type,displayName=:displayName,name=:name,groupName=:groupName,function=:function, tooltip=:tooltip, remoteViewRelevant=:remoteViewRelevant, isFeature=:isFeature, pin=:pin";
		const QString Update_ElementType = "UPDATE elementType SET type=:type";
		const QString Update_Instruction = "UPDATE instruction SET step=:step";
		const QString Update_Recept = "UPDATE recept SET receptName=:receptName,orderNumber=:orderNumber,instructionID=:instructionID";
		const QString Update_Product = "UPDATE product SET productName=:productName,part=:part,receptID=:receptID";
		const QString Update_LogEntry = "UPDATE log SET datetime=:datetime,message=:message,loglevel=:loglevel,threadId=:threadId,errorId=:errorId,type=:type,computerName=:computerName, filter=:filter";
		const QString Update_Project = "UPDATE project SET name=:name";
		const QString Update_Device = "UPDATE device SET description=:description, vendorId=vendorId, productId=productId, serial=serial, deviceName=deviceName";
        const QString Update_SoftwareProject = "UPDATE softwareProject SET name=:name";
        const QString Update_FlashHistory = "UPDATE flashHistory SET userID=:userID, softwareProjectID=:softwareProjectID, remoteWorkstationID=:remoteWorkstationID, major=:major, minor=:minor, patchlevel=:patchlevel, buildnumber=:buildnumber, data=:data";
        const QString Update_WorkstationType = "UPDATE workstationType SET workstationTypeID=:workstationTypeID, type=:type";
        const QString Update_PeripheralMapping = "UPDATE peripheralMapping SET workstationID=:workstationID, peripheralID=:peripheralID";
        const QString Update_Peripheral = "Update peripheral SET address=:adress, subAddress1=:subAddress1, subAddress2=:subAddress2, subAddress3=:subAddress3, name=:name, type=:type, connectionType=:connectionType, serialNumber=:serialNumber, deviceName=:deviceName, description=:description, hardwareID1=:hardwareID1, hardwareID2=:hardwareID2, hardwareID3=:hardwareID3, state=:state)";
        const QString Update_GlobalSetting = "UPDATE globalsetting rwShutdownTime=:rwShutdownTime, rwLogoutTime=:rwLogoutTime, beShutdownTime=:beShutdownTime, beLogoutTime=:beLogoutTime";
        const QString Update_WorkstationSetting = "UPDATE workstationsetting permanentLogin=:permanentLogin,permamentLoginReasonID=:permamentLoginReasonID";
        const QString Update_PermanentLoginReason = "UPDATE permanentloginreason reason=:reason,description=:description";

		const QString Delete_RemoteWorkstattion = "DELETE FROM Workstation WHERE idWorkstation=:idWorkstation";
		const QString Delete_User = "DELETE FROM user WHERE idUser=:idUser";
		const QString Delete_ElementConfiguration = "DELETE FROM elementConfiguration WHERE idElementConfiguration=:idElementConfiguration";
		const QString Delete_ElementType = "DELETE FROM elementType WHERE idElementType=:idElementType";
		const QString Delete_Instruction = "DELETE FROM instruction WHERE idIntruction=:idIntruction";
		const QString Delete_Recept = "DELETE FROM recept WHERE idRecept=:idRecept";
		const QString Delete_Product = "DELETE FROM product WHERE idProduct=:idProduct";
		const QString Delele_LogEntry = "DELETE FROM log WHERE idLogEntry=:idLogEntry";
		const QString Delele_Project = "DELETE FROM project WHERE idProject=:idProject";
		const QString Delele_Device = "DELETE FROM device WHERE idDevice=:idDevice";
        const QString Delete_SoftwareProject = "DELETE FROM softwareProject WHERE idSoftwareProject=:idSoftwareProject";
        const QString Delete_FlashHistory = "DELETE FROM flashHistory WHERE idFlashHistory=:idFlashHistory";
        const QString Delete_WorkstationType = "DELETE FROM workstationType WHERE idWorkstationType=:idWorkstationType";
        const QString Delete_PeripheralMapping = "DELETE FROM peripheralMapping WHERE idPeripheralMapping=:idPeripheralMapping";
        const QString Delete_Peripheral = "DELETE FROM peripheral WHERE idPeripheral=:idPeripheral";
        const QString Delete_GlobalSetting= "DELETE FROM globalsetting WHERE idGlobalSetting=:idGlobalSetting";
        const QString Delete_WorkstationSetting = "DELETE FROM workstationsetting WHERE idWorkstationSetting=:idWorkstationSetting";
        const QString Delete_PermanentLoginReason = "DELETE FROM permanentloginreason WHERE idPermanentLoginReason=:idPermanentLoginReason";

		const QString SelectById_Workstation = "SELECT * FROM Workstation WHERE idWorkstation = :idWorkstation";
		const QString SelectById_User = "SELECT * FROM user WHERE idUser = :idUser";
		const QString SelectById_ElementConfiguration = "SELECT * FROM elementConfiguration WHERE idElementConfiguration = :idElementConfiguration";
		const QString SelectById_ElementType = "SELECT * FROM elementType WHERE idElementType = :idElementType";
		const QString SelectById_Instruction = "SELECT * FROM Instruction WHERE idInstruction = :idInstruction";
		const QString SelectById_Recept = "SELECT * FROM recept WHERE idRecept = :idRecept";
		const QString SelectById_Product = "SELECT * FROM product WHERE idProduct = :idProduct";
		const QString SelectById_LogEntry = "SELECT * FROM log WHERE idLogEntry=:idLogEntry";
		const QString SelectById_Project = "SELECT * FROM project WHERE idProject=:idProject";
		const QString SelectById_Device = "SELECT * FROM device WHERE idDevice=:idDevice";
        const QString SelectById_SoftwareProject = "SELECT * FROM softwareProject WHERE idSoftwareProject=:idSoftwareProject";
        const QString SelectById_FlashHistory = "SELECT * FROM flashHistory WHERE idFlashHistory=:idFlashHistory";
        const QString SelectById_WorkstationType = "SELECT * FROM workstationType WHERE idWorkstationType=:idWorkstationType";
        const QString SelectById_PeripheralMapping = "SELECT * FROM peripheralMapping WHERE idPeripheralMapping=:idPeripheralMapping";
        const QString SelectById_Peripheral = "SELECT * FROM peripheral WHERE idPeripheral=:idPeripheral";
        const QString SelectById_GlobalSetting = "SELECT * FROM globalsetting WHERE idGlobalSetting=:idGlobalSetting";
        const QString SelectById_WorkstationSetting = "SELECT * FROM workstationsetting WHERE idWorkstationSetting=:idWorkstationSetting";
        const QString SelectById_PermanentLoginReason= "SELECT * FROM permanentloginreason WHERE idPermanentLoginReason=:idPermanentLoginReason";

		const QString SelectAll_Workstation = "SELECT * FROM Workstation";
		const QString SelectAll_User = "SELECT * FROM user";
		const QString SelectAll_ElementConfiguration = "SELECT * FROM elementConfiguration";
		const QString SelectAll_ElementType = "SELECT * FROM elementType";
		const QString SelectAll_Instruction = "SELECT * FROM Instructio";
		const QString SelectAll_Recept = "SELECT * FROM recept";
		const QString SelectAll_Product = "SELECT * FROM product";
		const QString SelectAll_LogEntry = "SELECT * FROM log";
		const QString SelectAll_Project = "SELECT * FROM project";
		const QString SelectAll_Device = "SELECT * FROM device";
        const QString SelectAll_SoftwareProject = "SELECT * FROM softwareProject";
        const QString SelectAll_FlashHistory = "SELECT * FROM flashHistory";
        const QString SelectAll_WorkstationType = "SELECT * FROM workstationType";
        const QString SelectAll_PeripheralMapping = "SELECT * FROM peripheralMapping";
        const QString SelectAll_Peripheral = "SELECT * FROM peripheral";
        const QString SelectAll_GlobalSetting = "SELECT * FROM globalsetting";
        const QString SelectALL_WorkstationSetting = "SELECT * FROM workstationsetting";
        const QString SelectALL_PermanentLoginReason = "SELECT * FROM permanentloginreason";

		const QString Select_ElementConfigurationByWorkstationID = "SELECT el.remoteWorkstationID, t.type = type ,el.displayName,el.name,el.groupName, el.function, el.tooltip, el.pin, el.isFeature FROM elementConfiguration el join elementType t on el.elementTypeID = t.idElementType WHERE el.remoteWorkstationID = :WorkstationID";
		const QString SelectLastID = "SELECT idWorkstation from Workstation ORDER BY idWorkstation DESC LIMIT 1;";
		class Entity;
		template<class T>
		class MySqlMapper :
			public DataMapper<T>
		{
		private:
			std::shared_ptr<spdlog::logger> m_logger;

		public:
			MySqlMapper(std::shared_ptr<spdlog::logger> Logger, QObject* Parent = nullptr) : DataMapper<T>(Parent),
				m_logger(Logger)
			{

				QSqlDatabase db = QSqlDatabase::database();
				if (!db.isOpen())
				{
					db = QSqlDatabase::addDatabase("QMYSQL");
					db.setHostName("elektrik");
					db.setPort(3306);
					db.setDatabaseName("remoteworkstation");
					db.setUserName("rwsUser");
					db.setPassword("rwsUser!5%2017$");

					//Please see the link for QT5: http://seppemagiels.com/blog/create-mysql-driver-qt5-windows => qsqlmysql.dll and libmysql.dll
					//(and libmysql.lib, if your installation of MySQL has it) are needed
					db.open();
				}

			}
			~MySqlMapper(){}

			bool Insert(const T &Data){ return false; }
			bool Update(const T &Data){ return false; }

			T FindByID(const quint64 id, bool Flag){ return new T(); }
			template<class Y> Y FindByID(const quint64 ID){
				MySqlMapper<Y> temp(this->m_logger);
				return temp.FindByID(ID, true);
			}
			QList<T> FindAll(){ QList<T> m; return std::move(m); }

		};

		template<> bool MySqlMapper<LogEntry>::Insert(const LogEntry &Data)
		{
			LogEntry d(Data);

			QSqlQuery query;
			query.prepare(Insert_LogEntry);
			query.bindValue(":datetime", d.Date());
			query.bindValue(":message", d.Message());
			query.bindValue(":loglevel", d.LogLevel());
			query.bindValue(":threadId", d.ThreadID());
			query.bindValue(":errorId", d.ErrorID());
			query.bindValue(":type", d.Type());
			query.bindValue(":computerName", d.ComputerNameRW());
            query.bindValue(":filter",(int) d.Filter());

			bool res = query.exec();
			if (!res)
			{
                QString error = query.lastError().text();
                qDebug() << error;
			}
			return res;
		}


		template<> bool MySqlMapper<Workstation>::Insert(const Workstation &Data)
		{
			Workstation d(Data);

			QSqlQuery query;
			quint64 id;
			query.prepare(Insert_Workstation);
			if (d.CurrentUser() == nullptr)
				query.bindValue(":user", QVariant(QVariant::UserType));
			else
			query.bindValue(":user", d.CurrentUser()->ID());
			query.bindValue(":hostname", d.Hostname());
			query.bindValue(":mac", d.Mac());
			query.bindValue(":ip", d.Ip());
            query.bindValue(":workstationType", d.TypeOfWorkstation()->ID());
            query.bindValue(":workstationSetting", d.SettingOfWorkstation()->ID());
			query.bindValue(":state",(int) d.State());
			if (d.AssignedProject() == nullptr)
			{
				m_logger->error("Project entry can't be NULL!");
				return false;
			}
			else
				query.bindValue(":name", d.AssignedProject()->Projectname());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl Workstation insert failed. Error: {}", query.lastError().text().toStdString());
			}
			else
			{
				bool res = query.exec(SelectLastID);
				while (query.next()) {
					id = query.value(0).toInt();
				}

				for each (auto var in d.ElementCfg())
				{
					QSqlQuery query;
					query.prepare(Insert_ElementConfiguration);
					query.bindValue(":WorkstationID", id);
					query.bindValue(":type", (int)var->Type()->Type());
					query.bindValue(":displayName", var->DisplayName());
					query.bindValue(":name", var->Name());
					query.bindValue(":groupName", var->GroupName());
					query.bindValue(":function", var->Function());
					query.bindValue(":tooltip", var->ToolTip());
					query.bindValue(":remoteViewRelevant", var->RemoteViewRelevant());
					query.bindValue(":isFeature", var->IsFeature());
					query.bindValue(":pin", var->Pin());

					res = query.exec();
					if (!res)
					{
						m_logger->error("Tbl elementConfiguration insert failed. Error: {}", query.lastError().text().toStdString());
					}
				}
			}
			return res;
		}

		template<> bool MySqlMapper<User>::Insert(const User &Data)
		{
			User d(Data);

			QSqlQuery query;
			query.prepare(Insert_User);
			query.bindValue(":username", d.UserName());
			query.bindValue(":password", d.Password());
			query.bindValue(":mksUsername", d.MKSUsername());
			query.bindValue(":mksPassword", d.MKSPassword());
			query.bindValue(":initials", d.Initials());
			query.bindValue(":notifiyRemoteDesktop", d.NotifiyRemoteDesktop());
			query.bindValue(":notifiyDesktop", d.NotifiyDesktop());
			query.bindValue(":role", (int)d.Role());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl user insert failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}


		template<> bool MySqlMapper<ElementConfiguration>::Insert(const ElementConfiguration &Data)
		{
			ElementConfiguration d(Data);

			QSqlQuery query;
			query.prepare(Insert_ElementConfiguration);
			query.bindValue(":type", (int)d.Type()->Type());
			query.bindValue(":displayName", d.DisplayName());
			query.bindValue(":name", d.Name());
			query.bindValue(":groupName", d.GroupName());
			query.bindValue(":function", d.Function());
			query.bindValue(":remoteViewRelevant", d.RemoteViewRelevant());
			query.bindValue(":isFeature", d.IsFeature());
			query.bindValue(":pin", d.Pin());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl elementConfiguration insert failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<ElementType>::Insert(const ElementType &Data)
		{
			ElementType d = Data;

			QSqlQuery query;
			query.prepare(Insert_ElementType);
			query.bindValue(":type", (int)d.Type());

			bool res = query.exec();
			if (!res)
			{
				QString test = query.lastError().text();
				if (m_logger != nullptr)
					m_logger->debug("Tbl elementType insert failed. Error: {0}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}


		template<> bool MySqlMapper<Instruction>::Insert(const Instruction &Data)
		{
			Instruction d = Data;

			QSqlQuery query;
			query.prepare(Insert_Instruction);
			query.bindValue(":step", d.Step());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl instruction insert failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Recept>::Insert(const Recept &Data)
		{
			Recept d = Data;

			QSqlQuery query;
			query.prepare(Insert_Recept);
			query.bindValue(":receptName", d.ReceptName());
			query.bindValue(":orderNumber", d.OrderNumber());
			query.bindValue(":instructionID", d.Instruction()->ID());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl recept insert failed. Error: " + query.lastError().text().toStdString());
			}
			return res;
		}

		template<> bool MySqlMapper<Product>::Insert(const Product &Data)
		{
			Product d = Data;

			QSqlQuery query;
			query.prepare(Insert_Product);
			query.bindValue(":productName", d.ProductName());
			query.bindValue(":part", d.Part());
			query.bindValue(":receptID", d.Recept()->ID());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl product insert failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Project>::Insert(const Project &Data)
		{
			Project d = Data;

			QSqlQuery query;
			query.prepare(Insert_Project);
			query.bindValue(":name", d.Projectname());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl Project insert failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Device>::Insert(const Device &Data)
		{
			Device d = Data;

			QSqlQuery query;
			query.prepare(Insert_Device);
			query.bindValue(":description", d.Description());
			query.bindValue(":vendorId", d.VendorID());
			query.bindValue(":productId", d.ProductID());
			query.bindValue(":serial", d.Serial());
			query.bindValue(":deviceName", d.DeviceName());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl Device insert failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}


        template<> bool MySqlMapper<SoftwareProject>::Insert(const SoftwareProject &Data)
        {
            SoftwareProject d = Data;

            QSqlQuery query;
            query.prepare(Insert_SoftwareProject);
            query.bindValue(":name", d.Name());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl SoftwareProject insert failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }

        template<> bool MySqlMapper<FlashHistory>::Insert(const FlashHistory &Data)
        {
            FlashHistory d = Data;

            QSqlQuery query;
            query.prepare(Insert_Device);
            query.bindValue(":userID", d.UserHistory()->ID());
            query.bindValue(":workstationID", d.WorkstationHistory()->ID());
            query.bindValue(":softwareProjectID", d.SoftwareProjectHistory()->ID());
            query.bindValue(":major", d.Major());
            query.bindValue(":minor", d.Minor());
            query.bindValue(":patchlevel", d.PatchLevel());
            query.bindValue(":buildnumber", d.Buildnumber());
            query.bindValue(":date", d.Date());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl FlashHistory insert failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }

        template<> bool MySqlMapper<WorkstationType>::Insert(const WorkstationType &Data)
        {
            WorkstationType d = Data;

            QSqlQuery query;
            query.prepare(Insert_WorkstationType);
            query.bindValue(":type",(int)d.Type());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl WorkstationType insert failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }


        template<> bool MySqlMapper<Peripheral>::Insert(const Peripheral &Data)
        {
            Peripheral d = Data;

            QSqlQuery query;
            query.prepare(Insert_Peripheral);
            query.bindValue(":address", d.Address());
            query.bindValue(":subAddress1", d.SubAddress1());
            query.bindValue(":subAddress2", d.SubAddress2());
            query.bindValue(":subAddress3", d.SubAddress3());
            query.bindValue(":name", d.Name());
            query.bindValue(":type", (int)d.Type());
            query.bindValue(":connectionType", d.ConnectionType());
            query.bindValue(":serialNumber", d.SerialNumber());
            query.bindValue(":deviceName", d.DeviceName());
            query.bindValue(":description", d.Description());
            query.bindValue(":hardwareID1", d.HardwareID1());
            query.bindValue(":hardwareID2", d.HardwareID2());
            query.bindValue(":hardwareID3", d.HardwareID3());
            query.bindValue(":state", (int)d.State());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl Peripheral insert failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }

        template<> bool MySqlMapper<GlobalSetting>::Insert(const GlobalSetting &Data)
        {
            GlobalSetting d = Data;

            QSqlQuery query;
            query.prepare(Insert_GlobalSetting);
            query.bindValue(":beLogOutTimer", d.BeLogOutTimer());
            query.bindValue(":beShutdownTimer", d.BeShutdownTimer());
            query.bindValue(":rwLogOutTimerChanged", d.RwLogOutTimer());
            query.bindValue(":rwShutdownTimerChanged", d.RwShutdownTimer());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl GlobalSetting insert failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }

        template<> bool MySqlMapper<WorkstationSetting>::Insert(const WorkstationSetting &Data)
        {
            WorkstationSetting d = Data;

            QSqlQuery query;
            query.prepare(Insert_WorkstationSetting);
            query.bindValue(":permanentLogin", d.PermanentLogin());
            query.bindValue(":permanentLoginReason", d.Reason()->ID());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl WorkstationSetting insert failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }

        template<> bool MySqlMapper<PermanentLoginReason>::Insert(const PermanentLoginReason &Data)
        {
            PermanentLoginReason d = Data;

            QSqlQuery query;
            query.prepare(Insert_PermanentLoginReason);
            query.bindValue(":reason", d.Reason());
            query.bindValue(":description", d.Description());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl PermanentLoginReason insert failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }

		template<> bool MySqlMapper<Workstation>::Update(const Workstation &Data)
		{
			Workstation d = Data;
			QSqlQuery query;
			query.prepare(Update_Workstation);
            query.bindValue(":idWorkstation", d.ID());
			//query.bindValue(":elementConfiguration", d.ElementCfg()->ID());
			query.bindValue(":userID", d.CurrentUser()->ID());
            query.bindValue(":projectID", d.AssignedProject()->ID());
			query.bindValue(":hostname", d.Hostname());
			query.bindValue(":mac", d.Mac());
			query.bindValue(":ip", d.Ip());
            query.bindValue(":workstationTypeID", d.TypeOfWorkstation()->ID());
            query.bindValue(":workstationSettingID", d.SettingOfWorkstation()->ID());
			query.bindValue(":state", (int)d.State());
            bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl Workstation update failed. Error: {}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<ElementConfiguration>::Update(const ElementConfiguration &Data)
		{
			ElementConfiguration d = Data;
			QSqlQuery query;
			query.prepare(Update_ElementConfiguration);
			query.bindValue(":WorkstationID", d.WorkstationID());
			query.bindValue(":type", d.Type()->ID());
			query.bindValue(":displayName", d.DisplayName());
			query.bindValue(":name", d.Name());
			query.bindValue(":groupName", d.GroupName());
			query.bindValue(":function", d.Function());
			query.bindValue(":tooltip", d.ToolTip());
			query.bindValue(":remoteViewRelevant", d.RemoteViewRelevant());
			query.bindValue(":isFeature", d.IsFeature());
			query.bindValue(":pin", d.Pin());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl elementConfiguration update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<ElementType>::Update(const ElementType &Data)
		{
			ElementType d = Data;
			QSqlQuery query;
			query.prepare(Update_ElementType);
			query.bindValue(":type", (int)d.Type());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl elementType update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Instruction>::Update(const Instruction &Data)
		{
			Instruction d = Data;
			QSqlQuery query;
			query.prepare(Update_Instruction);
			query.bindValue(":step", d.Step());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl instruction update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Project>::Update(const Project &Data)
		{
			Project d = Data;
			QSqlQuery query;
			query.prepare(Update_Project);
			query.bindValue(":name", d.Projectname());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl project update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Recept>::Update(const Recept &Data)
		{
			Recept d = Data;
			QSqlQuery query;
			query.prepare(Update_Recept);
			query.bindValue(":orderNumber", d.OrderNumber());
			query.bindValue(":receptName", d.ReceptName());
			query.bindValue(":instructionID", d.Instruction()->ID());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl recept update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<User>::Update(const User &Data)
		{
			User d = Data;
			QSqlQuery query;
			query.prepare(Update_User);
			query.bindValue(":username", d.UserName());
			query.bindValue(":password", d.Password());
			query.bindValue(":mksUsername", d.MKSUsername());
			query.bindValue(":mksPassword", d.MKSPassword());
			query.bindValue(":initials", d.Initials());
			query.bindValue(":notifiyRemoteDesktop", d.NotifiyRemoteDesktop());
			query.bindValue(":notifiyDesktop", d.NotifiyDesktop());
			//@todo unschöner cast
			query.bindValue(":role", (int)d.Role());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl user update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}

		template<> bool MySqlMapper<Device>::Update(const Device &Data)
		{
			Device d = Data;
			QSqlQuery query;
			query.prepare(Update_Device);
			query.bindValue(":description", d.Description());
			query.bindValue(":vendorId", d.VendorID());
			query.bindValue(":productId", d.ProductID());
			query.bindValue(":serial", d.Serial());
			query.bindValue(":deviceName", d.DeviceName());

			bool res = query.exec();
			if (!res)
			{
				m_logger->error("Tbl device update failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return res;
		}


        template<> bool MySqlMapper<SoftwareProject>::Update(const SoftwareProject &Data)
        {
            SoftwareProject d = Data;

            QSqlQuery query;
            query.prepare(Update_SoftwareProject);
            query.bindValue(":name", d.Name());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl SoftwareProject update failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }

        template<> bool MySqlMapper<FlashHistory>::Update(const FlashHistory &Data)
        {
            FlashHistory d = Data;

            QSqlQuery query;
            query.prepare(Update_Device);
            query.bindValue(":userID", d.UserHistory()->ID());
            query.bindValue(":workstationID", d.WorkstationHistory()->ID());
            query.bindValue(":softwareProjectID", d.SoftwareProjectHistory()->ID());
            query.bindValue(":major", d.Major());
            query.bindValue(":minor", d.Minor());
            query.bindValue(":patchlevel", d.PatchLevel());
            query.bindValue(":buildnumber", d.Buildnumber());
            query.bindValue(":date", d.Date());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl FlashHistory update failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }

        template<> bool MySqlMapper<WorkstationType>::Update(const WorkstationType &Data)
        {
            WorkstationType d = Data;

            QSqlQuery query;
            query.prepare(Update_WorkstationType);
            query.bindValue(":type", (int)d.Type());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl WorkstationType update failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }


        template<> bool MySqlMapper<Peripheral>::Update(const Peripheral &Data)
        {
            Peripheral d = Data;

            QSqlQuery query;
            query.prepare(Update_Peripheral);
            query.bindValue(":address", d.Address());
            query.bindValue(":subAddress1", d.SubAddress1());
            query.bindValue(":subAddress2", d.SubAddress2());
            query.bindValue(":subAddress3", d.SubAddress3());
            query.bindValue(":name", d.Name());
            query.bindValue(":type", (int)d.Type());
            query.bindValue(":connectionType", d.ConnectionType());
            query.bindValue(":serialNumber", d.SerialNumber());
            query.bindValue(":deviceName", d.DeviceName());
            query.bindValue(":description", d.Description());
            query.bindValue(":hardwareID1", d.HardwareID1());
            query.bindValue(":hardwareID2", d.HardwareID2());
            query.bindValue(":hardwareID3", d.HardwareID3());
            query.bindValue(":state", (int)d.State());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl Peripheral update failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }

        template<> bool MySqlMapper<GlobalSetting>::Update(const GlobalSetting &Data)
        {
            GlobalSetting d = Data;

            QSqlQuery query;
            query.prepare(Update_GlobalSetting);
            query.bindValue(":beLogOutTimer", d.BeLogOutTimer());
            query.bindValue(":beShutdownTimer", d.BeShutdownTimer());
            query.bindValue(":rwLogOutTimerChanged", d.RwLogOutTimer());
            query.bindValue(":rwShutdownTimerChanged", d.RwShutdownTimer());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl GlobalSetting update failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }

        template<> bool MySqlMapper<WorkstationSetting>::Update(const WorkstationSetting &Data)
        {
            WorkstationSetting d = Data;

            QSqlQuery query;
            query.prepare(Update_WorkstationSetting);
            query.bindValue(":permanentLogin", d.PermanentLogin());
            query.bindValue(":permanentLoginReason", d.Reason()->ID());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl WorkstationSetting update failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }

        template<> bool MySqlMapper<PermanentLoginReason>::Update(const PermanentLoginReason &Data)
        {
            PermanentLoginReason d = Data;

            QSqlQuery query;
            query.prepare(Update_PermanentLoginReason);
            query.bindValue(":reason", d.Reason());
            query.bindValue(":description", d.Description());

            bool res = query.exec();
            if (!res)
            {
                m_logger->error("Tbl PermanentLoginReason Update failed. Error: {}", query.lastError().text().toUtf8().constData());
            }
            return res;
        }


		template<> Workstation MySqlMapper<Workstation>::FindByID(const quint64 ID, bool Flag)
		{
			Workstation d;
			QSqlQuery query;
			query.prepare(SelectById_Workstation);
			query.bindValue(":idWorkstation", ID);
			bool res = query.exec();
			while (query.next())
			{
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

				QSqlQuery query;
				query.prepare(Select_ElementConfigurationByWorkstationID);
				query.bindValue(":WorkstationID", d.ID());
				bool res = query.exec();
				while (query.next())
				{
					ElementConfiguration el;
                    el.SetID(query.value("idElementConfiguration").toInt());
					el.SetType(new ElementType(FindByID<ElementType>(query.value("elementTypeID").toInt())));
					el.SetDisplayName(query.value("displayName").toString());
					el.SetName(query.value("name").toString());
					el.SetGroupName(query.value("groupName").toString());
					el.SetFunction(query.value("function").toString());
					el.SetToolTip(query.value("tooltip").toString());
					el.SetRemoteViewRelevant(query.value("remoteViewRelevant").toBool());
					el.SetIsFeature(query.value("isFeature").toBool());
					el.SetPin(query.value("pin").toInt());
					d.AddElementCfg(el);
				}
				if (!res)
				{
					m_logger->error("Tbl Workstation FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
				}
			}

			if (!res)
			{
				m_logger->error("Tbl Workstation FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> User MySqlMapper<User>::FindByID(const quint64 ID, bool Flag)
		{
			User d;
			QSqlQuery query;
			query.prepare(SelectById_User);
			query.bindValue(":idUser", ID);
			bool res = query.exec();
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
			}

			if (!res)
			{
				m_logger->error("Tbl user FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}


		template<> ElementConfiguration MySqlMapper<ElementConfiguration>::FindByID(const quint64 ID, bool Flag)
		{
			ElementConfiguration d;
			QSqlQuery query;
			query.prepare(SelectById_ElementConfiguration);
			query.bindValue(":idElementConfiguration", ID);
			bool res = query.exec();
			while (query.next())
			{
                d.SetID(query.value("idElementConfiguration").toInt());
				d.SetType(new ElementType(FindByID<ElementType>(query.value("elementTypeID").toInt())));
				d.SetDisplayName(query.value("displayName").toString());
				d.SetName(query.value("name").toString());
				d.SetGroupName(query.value("groupName").toString());
				d.SetFunction(query.value("function").toString());
				d.SetToolTip(query.value("tooltip").toString());
				d.SetRemoteViewRelevant(query.value("remoteViewRelevant").toBool());
				d.SetIsFeature(query.value("isFeature").toBool());
				d.SetPin(query.value("pin").toInt());
			}

			if (!res)
			{
				m_logger->error("Tbl elementConfiguration FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> ElementType MySqlMapper<ElementType>::FindByID(const quint64 ID, bool Flag)
		{
			ElementType d;
			QSqlQuery query;
			query.prepare(SelectById_ElementType);
			query.bindValue(":idElementType", ID);
			bool res = query.exec();
			while (query.next())
			{
                d.SetID(query.value("idElementType").toInt());
				// \!todo unschöne Konvertierung
				d.SetType((TypeOfElement)query.value("type").toInt());
			}

			if (!res)
			{
				m_logger->error("Tbl elementType FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}


		template<> Instruction MySqlMapper<Instruction>::FindByID(const quint64 ID, bool Flag)
		{
			Instruction d;
			QSqlQuery query;
			query.prepare(SelectById_Instruction);
			query.bindValue(":idInstruction", ID);
			bool res = query.exec();

			while (query.next())
			{
                d.SetID(query.value("idInstruction").toInt());
				// \!todo unschöne Konvertierung
				d.SetStep(query.value("step").toString());
			}

			if (!res)
			{
				m_logger->error("Tbl instruction FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> Recept MySqlMapper<Recept>::FindByID(const quint64 ID, bool Flag)
		{
			Recept d;
			QSqlQuery query;
			query.prepare(SelectById_Recept);
			query.bindValue(":idRecept", ID);
			bool res = query.exec();

			while (query.next())
			{
                d.SetID(query.value("idRecept").toInt());
				// \!todo unschöne Konvertierung
				d.SetOrderNumber(query.value("orderNumber").toInt());
				d.SetInstruction(new Instruction(FindByID<Instruction>(query.value("instructionID").toInt())));
				d.SetReceptName(query.value("receptName").toString());
			}

			if (!res)
			{
				m_logger->error("Tbl recept FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> Product MySqlMapper<Product>::FindByID(const quint64 ID, bool Flag)
		{
			Product d;
			QSqlQuery query;
			query.prepare(SelectById_Product);
			query.bindValue(":idProduct", ID);
			bool res = query.exec();

			while (query.next())
			{
                d.SetID(query.value("idProduct").toInt());
				// \!todo unschöne Konvertierung
				d.SetProductName(query.value("productName").toString());
				d.SetRecept(new Recept(FindByID<Recept>(query.value("receptID").toInt())));
				d.SetPart(query.value("part").toString());
			}

			if (!res)
			{
				m_logger->error("Tbl product FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> Project MySqlMapper<Project>::FindByID(const quint64 ID, bool Flag)
		{
			Project d;
			QSqlQuery query;
			query.prepare(SelectById_Project);
			query.bindValue(":idProject", ID);
			bool res = query.exec();

			while (query.next())
			{
                d.SetID(query.value("idProject").toInt());
				// \!todo unschöne Konvertierung
				d.SetProjectname(query.value("name").toString());
			}

			if (!res)
			{
				m_logger->error("Tbl project FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> LogEntry MySqlMapper<LogEntry>::FindByID(const quint64 ID, bool Flag)
		{
			LogEntry d;
			QSqlQuery query;
			query.prepare(SelectById_LogEntry);
			query.bindValue(":idLogEntry", ID);
			bool res = query.exec();

			while (query.next())
			{
                d.SetID(query.value("idLogEntry").toInt());
				// \!todo unschöne Konvertierung
				d.SetComputerNameRW(query.value("computerName").toString());
				d.SetType(query.value("type").toString());
				d.SetDate(query.value("date").toDateTime());
				d.SetThreadID(query.value("threadId").toInt());
				d.SetMessage(query.value("message").toString());
				d.SetLogLevel(query.value("logLevel").toString());
				d.SetErrorID(query.value("threadId").toInt());
                d.SetFilter((spdlog::sinks::FilterType)query.value("filter").toInt());
			}

			if (!res)
			{
				m_logger->error("Tbl log FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

		template<> Device MySqlMapper<Device>::FindByID(const quint64 ID, bool Flag)
		{
			Device d;
			QSqlQuery query;
			query.prepare(SelectById_Device);
			query.bindValue(":idDevice", ID);
			bool res = query.exec();

			while (query.next())
			{
                d.SetID(query.value("idDevice").toInt());
				// \!todo unschöne Konvertierung
				d.SetDescription(query.value("description").toString());
				d.SetVendorID(query.value("vendorId").toByteArray());
				d.SetProductID(query.value("productId").toByteArray());
				d.SetSerial(query.value("serial").toByteArray());
				d.SetDeviceName(query.value("deviceName").toString());
			}

			if (!res)
			{
				m_logger->error("Tbl device FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return d;
		}

        template<> SoftwareProject MySqlMapper<SoftwareProject>::FindByID(const quint64 ID, bool Flag)
        {
            SoftwareProject d;
            QSqlQuery query;
            query.prepare(SelectById_SoftwareProject);
            query.bindValue(":idSoftwareProject", ID);
            bool res = query.exec();

            while (query.next())
            {
                d.SetID(query.value("idSoftwareProject").toInt());
                // \!todo unschöne Konvertierung
                d.SetName(query.value("name").toString());
            }

            if (!res)
            {
                m_logger->error("Tbl softwareProject FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return d;
        }

        template<> FlashHistory MySqlMapper<FlashHistory>::FindByID(const quint64 ID, bool Flag)
        {
            FlashHistory d;
            QSqlQuery query;
            query.prepare(SelectById_FlashHistory);
            query.bindValue(":idFlashHistory", ID);
            bool res = query.exec();

            while (query.next())
            {
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
            }

            if (!res)
            {
                m_logger->error("Tbl flashHistory FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return d;
        }

        template<> WorkstationType MySqlMapper<WorkstationType>::FindByID(const quint64 ID, bool Flag)
        {
            WorkstationType d;
            QSqlQuery query;
            query.prepare(SelectById_WorkstationType);
            query.bindValue(":idWorkstationType", ID);
            bool res = query.exec();

            while (query.next())
            {
                d.SetID(query.value("idWorkstationType").toInt());
                // \!todo unschöne Konvertierung
                d.SetType((RW::WorkstationKind)query.value("type").toInt());
            }

            if (!res)
            {
                m_logger->error("Tbl WorkstationType FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
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
                d.SetAddress(query.value("address").toString());
                d.SetSubAddress1(query.value("subAddress1").toString());
                d.SetSubAddress2(query.value("subAddress2").toString());
                d.SetSubAddress3(query.value("subAddress3").toString());
                d.SetName(query.value("name").toString());
                d.SetType((PeripheralType)query.value("type").toInt());
                d.SetConnectionType(query.value("connectionType").toString());
                d.SetSerialNumber(query.value("serialNumber").toString());
                d.SetDeviceName(query.value("deviceName").toString());
                d.SetDescription(query.value("description").toString());
                d.SetHardwareID1(query.value("hardwareID1").toString());
                d.SetHardwareID2(query.value("hardwareID2").toString());
                d.SetHardwareID3(query.value("hardwareID3").toString());
                d.SetState((PeripheralState)query.value("state").toInt());

            }

            if (!res)
            {
                m_logger->error("Tbl Peripheral FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return d;
        }

        template<> GlobalSetting MySqlMapper<GlobalSetting>::FindByID(const quint64 ID, bool Flag)
        {
            GlobalSetting d;
            QSqlQuery query;
            query.prepare(SelectById_GlobalSetting);
            query.bindValue(":idGlobalSetting", ID);
            bool res = query.exec();

            while (query.next())
            {
                d.SetID(query.value("idGlobalSetting").toInt());
                d.SetRwLogOutTimer(query.value("rwLogOutTime").toInt());
                d.SetRwShutdownTimer(query.value("rwShutdownTime").toInt());
                d.SetBeLogOutTimer(query.value("beLogOutTime").toInt());
                d.SetBeShutdownTimer(query.value("beShutdownTime").toInt());

            }

            if (!res)
            {
                m_logger->error("Tbl GlobalSetting FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return d;
        }

        template<> WorkstationSetting MySqlMapper<WorkstationSetting>::FindByID(const quint64 ID, bool Flag)
        {
            WorkstationSetting d;
            QSqlQuery query;
            query.prepare(SelectById_WorkstationSetting);
            query.bindValue(":idWorkstationSetting", ID);
            bool res = query.exec();

            while (query.next())
            {
                d.SetID(query.value("idWorkstationSetting").toInt());
                d.SetPermanentLogin(query.value("permanentLogin").toBool());
                d.SetReason(new PermanentLoginReason(FindByID<PermanentLoginReason>(query.value("permanentLoginReason").toInt())));
            }

            if (!res)
            {
                m_logger->error("Tbl WorkstationSetting FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return d;
        }

        template<> PermanentLoginReason MySqlMapper<PermanentLoginReason>::FindByID(const quint64 ID, bool Flag)
        {
            PermanentLoginReason d;
            QSqlQuery query;
            query.prepare(SelectById_PermanentLoginReason);
            query.bindValue(":idPermanentLoginReason", ID);
            bool res = query.exec();

            while (query.next())
            {
                d.SetID(query.value("idPermanentLoginReason").toInt());
                d.SetDescription(query.value("description").toString());
                d.SetReason(query.value("reason").toString());
            }

            if (!res)
            {
                m_logger->error("Tbl PermanentLoginReason FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return d;
        }

		template<> QList<Workstation> MySqlMapper<Workstation>::FindAll()
		{
			QList<Workstation> list;
			QSqlQuery query;
			query.prepare(SelectAll_Workstation);
			bool res = query.exec();
			while (query.next())
			{
				Workstation d;
				d.SetID(query.value("idWorkstation").toInt());
				d.SetCurrentUser(new User(FindByID<User>(query.value("userID").toInt())));
				d.SetIp(query.value("ip").toString());
				d.SetMac(query.value("mac").toString());
				d.SetHostname(query.value("hostname").toString());
                d.SetSettingOfWorkstation(new WorkstationSetting(FindByID<WorkstationSetting>(query.value("workstationSettingID").toInt())));
                d.SetTypeOfWorkstation(new WorkstationType(FindByID<WorkstationType>(query.value("workstationTypeID").toInt())));
				d.SetState((RW::WorkstationState)query.value("state").toInt());
				d.setAssignedProject(new Project(FindByID<Project>(query.value("projectID").toInt())));

				QSqlQuery query;
				query.prepare(Select_ElementConfigurationByWorkstationID);
				query.bindValue(":WorkstationID", d.ID());
				bool res = query.exec();
				while (query.next())
				{
					ElementConfiguration el;
					//Todo warum wird hier ein Pointer verwendet?!
					ElementType* elType = new ElementType();
                    elType->SetID(query.value("idElementConfiguration").toInt());
					elType->SetType((RW::TypeOfElement)query.value("type").toInt());
					el.SetType(elType);
					el.SetDisplayName(query.value("displayName").toString());
					el.SetName(query.value("name").toString());
					el.SetGroupName(query.value("groupName").toString());
					el.SetFunction(query.value("function").toString());
					el.SetToolTip(query.value("tooltip").toString());
					el.SetRemoteViewRelevant(query.value("remoteViewRelevant").toBool());
					el.SetIsFeature(query.value("isFeature").toBool());
					el.SetPin(query.value("pin").toInt());
					d.AddElementCfg(el);
				}
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl Workstation FindByID failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}

		template<> QList<User> MySqlMapper<User>::FindAll()
		{
			QList<User> list;
			QSqlQuery query;
			query.prepare(SelectAll_User);
			bool res = query.exec();
			while (query.next())
			{
				User d;
                d.SetID(query.value("idUser").toInt());
				d.SetUserName(query.value("username").toString());
				d.SetPassword(query.value("password").toString());
				d.SetMKSUsername(query.value("mksUsername").toString());
				d.SetMKSPassword(query.value("mksPassword").toString());
				d.SetInitials(query.value("initials").toString());
				d.SetNotifiyRemoteDesktop(query.value("notifiyRemoteDesktop").toBool());
				d.SetNotifiyDesktop(query.value("notifiyDesktop").toBool());
				d.SetRole((RW::UserRole)query.value("role").toInt());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl elementConfiguration FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}


		template<> QList<ElementConfiguration> MySqlMapper<ElementConfiguration>::FindAll()
		{
			QList<ElementConfiguration> list;
			QSqlQuery query;
			query.prepare(SelectAll_ElementConfiguration);
			bool res = query.exec();
			while (query.next())
			{
				ElementConfiguration d;
                d.SetID(query.value("idElementConfiguration").toInt());
				d.SetType(new ElementType(FindByID<ElementType>(query.value("elementTypeID").toInt())));
				d.SetDisplayName(query.value("displayName").toString());
				d.SetName(query.value("name").toString());
				d.SetGroupName(query.value("groupName").toString());
				d.SetFunction(query.value("function").toString());
				d.SetToolTip(query.value("tooltip").toString());
				d.SetRemoteViewRelevant(query.value("remoteViewRelevant").toBool());
				d.SetIsFeature(query.value("isFeature").toBool());
				d.SetPin(query.value("pin").toInt());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl elementConfiguration FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}

		template<> QList<ElementType> MySqlMapper<ElementType>::FindAll()
		{
			QList<ElementType> list;
			QSqlQuery query;
			query.prepare(SelectAll_ElementType);
			bool res = query.exec();
			while (query.next())
			{
				ElementType d;
                d.SetID(query.value("idElementType").toInt());
				// \!todo unschöne Konvertierung
				d.SetType((TypeOfElement)query.value("type").toInt());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl elementType FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}


		template<> QList<Instruction> MySqlMapper<Instruction>::FindAll()
		{
			QList<Instruction> list;
			QSqlQuery query;
			query.prepare(SelectAll_Instruction);
			bool res = query.exec();
			while (query.next())
			{
				Instruction d;
				// \!todo unschöne Konvertierung
                d.SetID(query.value("idInstruction").toInt());
				d.SetStep(query.value("step").toString());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl instruction FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}
	
		template<> QList<Recept> MySqlMapper<Recept>::FindAll()
		{
			QList<Recept> list;
			QSqlQuery query;
			query.prepare(SelectAll_Recept);
			bool res = query.exec();
			while (query.next())
			{
				Recept d;
				// \!todo unschöne Konvertierung
                d.SetID(query.value("idRecept").toInt());
				d.SetOrderNumber(query.value("orderNumber").toInt());
				d.SetInstruction(new Instruction(FindByID<Instruction>(query.value("instructionID").toInt())));
				d.SetReceptName(query.value("receptName").toString());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl recept FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}

		template<> QList<Product> MySqlMapper<Product>::FindAll()
		{
			QList<Product> list;
			QSqlQuery query;
			query.prepare(SelectAll_Product);
			bool res = query.exec();
			while (query.next())
			{
				Product d;
				// \!todo unschöne Konvertierung
                d.SetID(query.value("idProduct").toInt());
				d.SetProductName(query.value("productName").toString());
				d.SetRecept(new Recept(FindByID<Recept>(query.value("receptID").toInt())));
				d.SetPart(query.value("part").toString());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl product FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}

		template<> QList<Project> MySqlMapper<Project>::FindAll()
		{
			QList<Project> list;
			QSqlQuery query;
			query.prepare(SelectAll_Project);
			bool res = query.exec();
			while (query.next())
			{
				Project d;

				// \!todo unschöne Konvertierung
                d.SetID(query.value("idProject").toInt());
				d.SetProjectname(query.value("name").toString());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl project FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}


		template<> QList<LogEntry> MySqlMapper<LogEntry>::FindAll()
		{
			QList<LogEntry> list;
			QSqlQuery query;
			query.prepare(SelectAll_LogEntry);
			bool res = query.exec();
			while (query.next())
			{
				LogEntry d;
				// \!todo unschöne Konvertierung
                d.SetID(query.value("idLogEntry").toInt());
				d.SetComputerNameRW(query.value("computerName").toString());
				d.SetType(query.value("type").toString());
				d.SetDate(query.value("date").toDateTime());
				d.SetThreadID(query.value("threadId").toInt());
				d.SetMessage(query.value("message").toString());
				d.SetLogLevel(query.value("logLevel").toString());
				d.SetErrorID(query.value("threadId").toInt());
                d.SetFilter((spdlog::sinks::FilterType)query.value("filter").toInt());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl logEntry FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}

		template<> QList<Device> MySqlMapper<Device>::FindAll()
		{
			QList<Device> list;
			QSqlQuery query;
			query.prepare(SelectAll_Device);
			bool res = query.exec();
			while (query.next())
			{
				Device d;

				// \!todo unschöne Konvertierung
				d.SetDescription(query.value("description").toString());
				d.SetVendorID(query.value("vendorId").toByteArray());
				d.SetProductID(query.value("productId").toByteArray());
				d.SetSerial(query.value("serial").toByteArray());
				d.SetDeviceName(query.value("deviceName").toString());
				list << d;
			}

			if (!res)
			{
				m_logger->error("Tbl device FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
			}
			return list;
		}

        template<> QList<SoftwareProject> MySqlMapper<SoftwareProject>::FindAll()
        {
            QList<SoftwareProject> list;
            QSqlQuery query;
            query.prepare(SelectAll_SoftwareProject);
            bool res = query.exec();

            while (query.next())
            {
                SoftwareProject d;
                d.SetID(query.value("idSoftwareProject").toInt());
                // \!todo unschöne Konvertierung
                d.SetName(query.value("name").toString());
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl softwareProject FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }

        template<> QList<FlashHistory> MySqlMapper<FlashHistory>::FindAll()
        {
            QList<FlashHistory> list;

            QSqlQuery query;
            query.prepare(SelectAll_FlashHistory);
            bool res = query.exec();

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
                m_logger->error("Tbl flashHistory FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }

        template<> QList<WorkstationType> MySqlMapper<WorkstationType>::FindAll()
        {
            QList<WorkstationType> list;
            QSqlQuery query;
            query.prepare(SelectAll_WorkstationType);
            bool res = query.exec();

            while (query.next())
            {
                RW::SQL::WorkstationType d;
                d.SetID(query.value("idWorkstationType").toInt());
                // \!todo unschöne Konvertierung
                d.SetType((RW::WorkstationKind)query.value("type").toInt());
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl WorkstationType FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }

        template<> QList<Peripheral> MySqlMapper<Peripheral>::FindAll()
        {
            QList<Peripheral> list;
            
            QSqlQuery query;
            query.prepare(SelectAll_Peripheral);
            bool res = query.exec();

            while (query.next())
            {
                Peripheral d;
                // \!todo unschöne Konvertierung
                d.SetID(query.value("idPeripheral").toInt());
                d.SetAddress(query.value("address").toString());
                d.SetSubAddress1(query.value("subAddress1").toString());
                d.SetSubAddress2(query.value("subAddress2").toString());
                d.SetSubAddress3(query.value("subAddress3").toString());
                d.SetName(query.value("name").toString());
                d.SetType((PeripheralType)query.value("type").toInt());
                d.SetConnectionType(query.value("connectionType").toString());
                d.SetSerialNumber(query.value("serialNumber").toString());
                d.SetDeviceName(query.value("deviceName").toString());
                d.SetDescription(query.value("description").toString());
                d.SetHardwareID1(query.value("hardwareID1").toString());
                d.SetHardwareID2(query.value("hardwareID2").toString());
                d.SetHardwareID3(query.value("hardwareID3").toString());
                d.SetState((PeripheralState)query.value("state").toInt());
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl Peripheral FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
        }

        template<> QList<GlobalSetting> MySqlMapper<GlobalSetting>::FindAll()
        {
            QList<GlobalSetting> list;
            
            QSqlQuery query;
            query.prepare(SelectAll_GlobalSetting);
            bool res = query.exec();

            while (query.next())
            {
                GlobalSetting d;
                d.SetID(query.value("idGlobalSetting").toInt());
                d.SetRwLogOutTimer(query.value("rwLogOutTimer").toInt());
                d.SetRwShutdownTimer(query.value("rwShutdownTimer").toInt());
                d.SetBeLogOutTimer(query.value("beLogOutTimer").toInt());
                d.SetBeShutdownTimer(query.value("beShutdownTimer").toInt());
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl GlobalSetting FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }

        template<>  QList<WorkstationSetting> MySqlMapper<WorkstationSetting>::FindAll()
        {
            QList<WorkstationSetting> list;
            
            QSqlQuery query;
            query.prepare(SelectALL_WorkstationSetting);
            bool res = query.exec();

            while (query.next())
            {
                WorkstationSetting d;
                d.SetID(query.value("idWorkstationSetting").toInt());
                d.SetPermanentLogin(query.value("permanentLogin").toInt());
                d.SetReason(new PermanentLoginReason(FindByID<PermanentLoginReason>(query.value("permanentLoginReason").toInt())));
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl WorkstationSetting FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }

        template<> QList<PermanentLoginReason>  MySqlMapper<PermanentLoginReason>::FindAll()
        {
            QList<PermanentLoginReason> list;
           
            QSqlQuery query;
            query.prepare(SelectALL_PermanentLoginReason);
            bool res = query.exec();

            while (query.next())
            {
                PermanentLoginReason d;
                d.SetID(query.value("idPermanentLoginReason").toInt());
                d.SetDescription(query.value("description").toString());
                d.SetReason(query.value("reason").toString());
                list << d;
            }

            if (!res)
            {
                m_logger->error("Tbl PermanentLoginReason FindAll failed. Error:{}", query.lastError().text().toUtf8().constData());
            }
            return list;
        }

	}
}
