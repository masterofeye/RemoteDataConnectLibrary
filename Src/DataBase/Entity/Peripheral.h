#pragma once
#include "Entity.h"
#include "PeripheralCondition.h"
#include "..\SQLGlobal.h"
#include <QQmlListProperty>

namespace RW{
	namespace SQL{

        class Project;
        class PeripheralPrivate;
        class PeripheralProperties;
        class REMOTE_DATA_CONNECT_API Peripheral :
			public Entity
		{
            Q_OBJECT
            Q_PROPERTY(quint64 Address READ Address WRITE SetAddress NOTIFY AddressChanged)
            Q_PROPERTY(QString LocationInformation READ LocationInformation WRITE SetLocationInformation NOTIFY LocationInformationChanged)
            Q_PROPERTY(QString LocationPath READ LocationPath WRITE SetLocationPath NOTIFY LocationPathChanged)
            Q_PROPERTY(QString Description READ Description WRITE SetDescription NOTIFY DescriptionChanged)
            Q_PROPERTY(QString DeviceName READ DeviceName WRITE SetDeviceName NOTIFY DeviceNameChanged)
            Q_PROPERTY(QStringList HardwareID READ HardwareID WRITE SetHardwareID NOTIFY HardwareIDChanged)
            Q_PROPERTY(QString FriendlyName READ FriendlyName WRITE SetFriendlyName NOTIFY FriendlyNameChanged)
            Q_PROPERTY(quint64 Busnummer READ Busnummer WRITE SetBusnummer NOTIFY BusnummerChanged)
            Q_PROPERTY(QString BusGUID READ BusGUID WRITE SetBusGUID NOTIFY BusGUIDChanged)
            Q_PROPERTY(QString Class READ Class WRITE SetClass NOTIFY ClassChanged)
            Q_PROPERTY(QString ClassGUID READ ClassGUID WRITE SetClassGUID NOTIFY ClassGUIDChanged)
            Q_PROPERTY(QStringList CompatibleID READ CompatibleID WRITE SetCompatibleID NOTIFY CompatibleIDChanged)
            Q_PROPERTY(quint64 WindowsDeviceType READ WindowsDeviceType WRITE SetWindowsDeviceType NOTIFY WindowsDeviceTypeChanged)
            Q_PROPERTY(QString EnumeratorName READ EnumeratorName WRITE SetEnumeratorName NOTIFY EnumeratorNameChanged)
            Q_PROPERTY(QString Manufacturer READ Manufacturer WRITE SetManufacturer NOTIFY ManufacturerChanged)
            Q_PROPERTY(QString ServiceName READ ServiceName WRITE SetServiceName NOTIFY ServiceNameChanged)
            Q_PROPERTY(quint64 InstallState READ InstallState WRITE SetInstallState NOTIFY InstallStateChanged)
            Q_PROPERTY(PeripheralType InteralType READ InteralType WRITE SetInteralType NOTIFY InteralTypeChanged)
            Q_PROPERTY(bool IsRegistered READ IsRegistered WRITE SetRegistered NOTIFY IsRegisteredChanged)
            Q_PROPERTY(bool IsActivate READ IsActivate WRITE SetActivate NOTIFY IsActivateChanged)
            Q_PROPERTY(bool IsProvided READ IsProvided WRITE SetProvided NOTIFY IsProvidedChanged)
            Q_PROPERTY(PeripheralConditionList* ConditionList READ ConditionList CONSTANT)
            Q_PROPERTY(PeripheralProperties* PeripheralPropertie READ PeripheralPropertie WRITE SetPeripheralPropertie NOTIFY PeripheralPropertieChanged)
            Q_CLASSINFO("Version", "0.0.1")
        private:
            PeripheralPrivate* d_ptr;
            Q_DECLARE_PRIVATE(Peripheral);
		public:
            Peripheral(Entity *Parent = nullptr);
            ~Peripheral();

            Peripheral(const Peripheral &F);
            Peripheral& operator=(const Peripheral &F);

            Peripheral(Peripheral &&F);
            Peripheral& operator=(Peripheral &&F);

            /*!
            @brief Busspezifische Adresse der Geräteinstanz.
            */
            quint64 Address()const;
            void SetAddress(quint64 Address);
            /*!
            @brief Busspezifische physikalischer Ort einer Geräteinstanz.
            */
            QString LocationInformation()const;
            void SetLocationInformation(QString Info);
            /*!
            @brief Ort der Geräteinstanz innerhalb des Gerätebaums.
            */
            QString LocationPath()const;
            void SetLocationPath(QString Path);
            /*!
            @brief Beschreibung des Gerätes.
            */
            QString Description()const;
            void SetDescription(QString Description);
            /*!
            @brief Sprechender Name des Gerätes.
            */
            QString DeviceName()const;
            void SetDeviceName(QString Name);
            /*!
            @brief HardwareID des Gerätes.
            */
            QStringList HardwareID()const;
            void SetHardwareID(QStringList ID);
            /*!
            @brief Friendly Name des Gerätes.
            */
            QString FriendlyName()const;
            void SetFriendlyName(QString FriendlyName);
            /*!
            @brief Busnummer des Gerätes.
            */
            quint64 Busnummer()const;
            void SetBusnummer(quint64 Busnummer);
            /*!
            @brief Bus-GUID des Gerätes.
            */
            QString BusGUID()const;
            void SetBusGUID(QString BusGUID);
            /*!
            @brief Device Setup Class des Gerätes.
            */
            QString Class()const;
            void SetClass(QString Class);
            /*!
            @brief GUID des Device Setup Class des Gerätes.
            */
            QString ClassGUID()const;
            void SetClassGUID(QString ClassGUID);
            /*!
            @brief Kompatible ID's für das Gerät.
            */
            QStringList CompatibleID()const;
            void SetCompatibleID(QStringList CompatibleID);
            /*!
            @brief Type des Gerätes welches der Windowszuordnung entspricht.
            Für eine Zuordnung siehe: https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/specifying-device-types
            */
            quint16 WindowsDeviceType()const;
            void SetWindowsDeviceType(quint16 WindowsDeviceType);
            /*!
            @brief Beinhaltet den Namen des Geräteenumerators, dieser entspricht dem übergeordneten Elterngruppe (z.b. für USB wäre es USB)
            */
            QString EnumeratorName()const;
            void SetEnumeratorName(QString EnumeratorName);
            /*!
            @brief Geräteinstallationsstatus. Für die Zuordnung siehe. https://msdn.microsoft.com/en-us/library/windows/hardware/ff543130(v=vs.85).aspx
            */
            quint16 InstallState()const;
            void SetInstallState(quint16 InstallState);
            /*!
            @brief Herstellername des Gerätes.
            */
            QString Manufacturer()const;
            void SetManufacturer(QString Manufacturer);
            /*!
            @brief Beinhaltet den Servicename für das Geräte.
            */
            QString ServiceName()const;
            void SetServiceName(QString ServiceName);
            /*!
            @brief Der interne Gerätetyp.
            */
            PeripheralType InteralType()const;
            void SetInteralType(PeripheralType InteralType);

            /*!
            @brief Gibt an, ob ein Gerät bereits registriert ist oder nicht.
            */
            bool IsRegistered()const;
            void SetRegistered(bool Registered);

            /*!
            @brief Gibt an, ob ein Gerät noch aktiv, als Betriebsbereit oder vom Strom getrennt ist.
            */
            bool IsActivate()const;
            void SetActivate(bool Activate);

            /*!
            @brief Gibt an, ob ein Geräte der Workstation zugeordnet wurde oder nicht.
            */
            bool IsProvided()const;
            void SetProvided(bool Provided);

            PeripheralConditionList* ConditionList() const;

            PeripheralProperties* PeripheralPropertie()const;
            void SetPeripheralPropertie(PeripheralProperties*);
        signals:
            void AddressChanged();
            void LocationInformationChanged();
            void LocationPathChanged();
            void DescriptionChanged();
            void DeviceNameChanged();
            void HardwareIDChanged();
            void FriendlyNameChanged();
            void BusnummerChanged();
            void BusGUIDChanged();
            void ClassChanged();
            void ClassGUIDChanged();
            void CompatibleIDChanged();
            void WindowsDeviceTypeChanged();
            void EnumeratorNameChanged();
            void ManufacturerChanged();
            void ServiceNameChanged();
            void InstallStateChanged();
            void InteralTypeChanged();
            void IsRegisteredChanged();
            void IsActivateChanged();
            void IsProvidedChanged();
            void ConditionListChanged();
            void PeripheralPropertieChanged();
		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::Peripheral)