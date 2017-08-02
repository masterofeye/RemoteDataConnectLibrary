#pragma once
#include "Entity.h"
#include "qdebug.h"
#include <QQmlListProperty>

namespace RW{
	enum class WorkstationState;
    enum class WorkstationKind;
	namespace SQL{
		class WorkstationPrivate;
		class ElementConfiguration;
		class User;
		class Project;
        class WorkstationType;
        class Peripheral;
        class WorkstationSetting;
        

		class REMOTE_DATA_CONNECT_API Workstation :
			public Entity
		{
			Q_OBJECT
			//Q_PROPERTY(QQmlListProperty<RW::SQL::ElementConfiguration> ElementCfgQml READ ElementCfgQml NOTIFY ElementCfgChanged)
			Q_PROPERTY(User* CurrentUser READ CurrentUser WRITE SetCurrentUser NOTIFY CurrentUserChanged)
			Q_PROPERTY(Project* AssignedProject READ AssignedProject WRITE setAssignedProject NOTIFY ProjectChanged)
			Q_PROPERTY(QString hostname READ Hostname WRITE SetHostname NOTIFY HostnameChanged)
			Q_PROPERTY(QString Mac READ Mac WRITE SetMac NOTIFY MacChanged)
			Q_PROPERTY(QString Ip READ Ip WRITE SetIp NOTIFY IpChanged)
			Q_PROPERTY(WorkstationState State READ State WRITE SetState NOTIFY StateChanged)
            Q_PROPERTY(WorkstationType* TypeOfWorkstation READ TypeOfWorkstation WRITE SetTypeOfWorkstation NOTIFY TypeOfWorkstationChanged)
            Q_PROPERTY(WorkstationSetting* SettingOfWorkstation READ SettingOfWorkstation WRITE SetSettingOfWorkstation NOTIFY SettingOfWorkstationChanged)
            Q_PROPERTY(QQmlListProperty<RW::SQL::Peripheral> PeripheralListQml READ PeripheralListQml NOTIFY PeripheralListQmlChanged)

			Q_CLASSINFO("Version", "0.1.1")
		private:
			WorkstationPrivate* d_ptr;
			Q_DECLARE_PRIVATE(Workstation);
		public:
			Workstation(Entity *Parent = nullptr);
			~Workstation();
			 
			Workstation(const Workstation &R);
			Workstation& operator=(const Workstation &R);

			Workstation(Workstation &&R);
			Workstation& operator=( Workstation &&R);

			QList<ElementConfiguration*> ElementCfg() const;
            QQmlListProperty<ElementConfiguration> ElementCfgQml();

            void SetElementCfg(QList<ElementConfiguration*> ElementCfg);
			void AddElementCfg(ElementConfiguration ElementCfg);
			
			User* CurrentUser() const;
            /*
            @brief Setzt den User der Workstation. Dabei wird auch die Zunständigkeit für den Pointer übernommen!
            Das bedeutet Speicher wird freigegeben sobald die Instanz der Klasse zerstört wird.
            @param User* Der aktuelle User, der in der Workstation eingelogt ist. 
            */
			void SetCurrentUser(User *CurrentUser);

			QString Hostname() const;
			void SetHostname(QString Hostname);

			QString Mac() const;
			void SetMac(QString Mac);

			QString Ip() const;
			void SetIp(QString Ip);

			WorkstationState State() const;
			void SetState(WorkstationState State);

			Project* AssignedProject() const;
			void setAssignedProject(Project* Project);

            WorkstationSetting* SettingOfWorkstation() const;
            void SetSettingOfWorkstation(WorkstationSetting* Setting);

            WorkstationType* TypeOfWorkstation() const;
            /*
            @brief Setzt den Typ der Workstation. Dabei wird auch die Zunständigkeit für den Pointer übernommen!
            Das bedeutet Speicher wird freigegeben sobald die Instanz der Klasse zerstört wird. 
            @param WorkstationType Typ der Workstation
            */
            void SetTypeOfWorkstation(WorkstationType* Type);

            QList<Peripheral*> PeripheralList() const;
            QQmlListProperty<Peripheral> PeripheralListQml();

            void SetPeripheralList(QList<Peripheral*> PeripheralList);
            void AddPeripheral(Peripheral Peripheral);

		signals:
			void ElementCfgChanged();
			void CurrentUserChanged();
			void HostnameChanged();
			void MacChanged(); 
			void IpChanged();
			void PowerstripeIpChanged();
			void PowerstripeIdChanged();
			void RemoteboxComPortChanged();
			void RemoteboxHwIdChanged();
			void RemoteboxSwVersionChanged();
			void StateChanged();
			void ProjectChanged();
            void TypeOfWorkstationChanged();
            void PeripheralListQmlChanged();
            void SettingOfWorkstationChanged();

		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::Workstation)
Q_DECLARE_METATYPE(QQmlListProperty<RW::SQL::ElementConfiguration>)
Q_DECLARE_METATYPE(QQmlListProperty<RW::SQL::Peripheral>)

