#include "Peripheral.h"
#include "Peripheral_p.h"

namespace RW{
	namespace SQL{

        PeripheralPrivate::PeripheralPrivate(Peripheral *Parent) :
            QObject(Parent),
            q_ptr(Parent)
        {
        }

        PeripheralPrivate::~PeripheralPrivate()
        {

        }

        Peripheral::Peripheral(Entity *Parent) : Entity(Parent),
            d_ptr(new PeripheralPrivate(this))
        {
        }


        Peripheral::~Peripheral()
		{
		}

        Peripheral::Peripheral(Peripheral &&R) : d_ptr(R.d_ptr)
        {
            d_ptr->setParent(this);
            SetID(R.ID());
            R.d_ptr = nullptr;
        }

        Peripheral& Peripheral::operator=(Peripheral &&R)
        {
            std::swap(d_ptr, R.d_ptr);
            d_ptr->setParent(this);
            SetID(R.ID());
            delete R.d_ptr;
            R.d_ptr = nullptr;
            return *this;
        }


        Peripheral::Peripheral(const Peripheral &F)
        {
            if (&F != nullptr)
            {
                d_ptr = new PeripheralPrivate(this);
                d_ptr->m_Name = F.d_ptr->m_Name;
                d_ptr->m_Address = F.d_ptr->m_Address;
                d_ptr->m_Name = F.d_ptr->m_Name;
                d_ptr->m_SubAddress1 = F.d_ptr->m_SubAddress1;
                d_ptr->m_SubAddress2 = F.d_ptr->m_SubAddress2;
                d_ptr->m_SubAddress3 = F.d_ptr->m_SubAddress3;
                d_ptr->m_HardwareID1 = F.d_ptr->m_HardwareID1;
                d_ptr->m_HardwareID2 = F.d_ptr->m_HardwareID2;
                d_ptr->m_HardwareID3 = F.d_ptr->m_HardwareID3;
                d_ptr->m_ConnectionType = F.d_ptr->m_ConnectionType;
                d_ptr->m_Description = F.d_ptr->m_Description;
                d_ptr->m_DeviceName = F.d_ptr->m_DeviceName;
                d_ptr->m_State = F.d_ptr->m_State;
                d_ptr->m_SerialNumber = F.d_ptr->m_SerialNumber;
                d_ptr->m_Type = F.d_ptr->m_Type;

                SetID(F.ID());
            }
        }

        Peripheral& Peripheral::operator=(const Peripheral &F)
        {
            if (&F != nullptr)
            {
                d_ptr = new PeripheralPrivate(this);

                d_ptr->m_Name = F.d_ptr->m_Name;
                d_ptr->m_Name = F.d_ptr->m_Name;
                d_ptr->m_Address = F.d_ptr->m_Address;
                d_ptr->m_Name = F.d_ptr->m_Name;
                d_ptr->m_SubAddress1 = F.d_ptr->m_SubAddress1;
                d_ptr->m_SubAddress2 = F.d_ptr->m_SubAddress2;
                d_ptr->m_SubAddress3 = F.d_ptr->m_SubAddress3;
                d_ptr->m_HardwareID1 = F.d_ptr->m_HardwareID1;
                d_ptr->m_HardwareID2 = F.d_ptr->m_HardwareID2;
                d_ptr->m_HardwareID3 = F.d_ptr->m_HardwareID3;
                d_ptr->m_ConnectionType = F.d_ptr->m_ConnectionType;
                d_ptr->m_Description = F.d_ptr->m_Description;
                d_ptr->m_DeviceName = F.d_ptr->m_DeviceName;
                d_ptr->m_State = F.d_ptr->m_State;
                d_ptr->m_SerialNumber = F.d_ptr->m_SerialNumber;
                d_ptr->m_Type = F.d_ptr->m_Type;
                SetID(F.ID());
            }
            return *this;
        }


        QString Peripheral::Name() const
        {
            Q_D(const Peripheral);
            return d->m_Name;
        }

        void Peripheral::SetName(QString Name)
        {
            Q_D(Peripheral);
            d->m_Name = Name;
            emit NameChanged();
        }


        /*!
        @brief Busspezifische Adresse der Geräteinstanz.
        */
        quint64 Peripheral::Address()
        {
            Q_D(const Peripheral);
            return d->m_Address;
        }
        void Peripheral::SetAddress(quint64 Address)
        {
            Q_D(Peripheral);
            d->m_Address = Address;
            emit AddressChanged();
        }
        /*!
        @brief Busspezifische physikalischer Ort einer Geräteinstanz.
        */
        QString Peripheral::LocationInformation()
        {
            Q_D(const Peripheral);
            return d->m_LocationInformation;
        }
        void Peripheral::SetLocationInformation(QString Info)
        {
            Q_D(Peripheral);
            d->m_LocationInformation = Info;
            emit LocationInformationChanged();
        }
        /*!
        @brief Ort der Geräteinstanz innerhalb des Gerätebaums.
        */
        QString Peripheral::Peripheral::LocationPath()
        {
            Q_D(const Peripheral);
            return d->m_LocationPath;
        }
        void Peripheral::Peripheral::SetLocationPath(QString Path)
        {
            Q_D(Peripheral);
            d->m_LocationPath = Path;
            emit LocationPathChanged();
        }
        /*!
        @brief Beschreibung des Gerätes.
        */
        QString Peripheral::Description()
        {
            Q_D(const Peripheral);
            return d->m_Description;
        }
        void Peripheral::SetDescription(QString Description)
        {
            Q_D(Peripheral);
            d->m_Description = Description;
            emit DescriptionChanged();
        }
        /*!
        @brief Sprechender Name des Gerätes.
        */
        QString Peripheral::DeviceName()
        {
            Q_D(const Peripheral);
            return d->m_DeviceName;
        }
        void Peripheral::SetDeviceName(QString Name)
        {
            Q_D(Peripheral);
            d->m_DeviceName = Name;
            emit DeviceNameChanged();
        }
        /*!
        @brief HardwareID des Gerätes.
        */
        QStringList Peripheral::HardwareID()
        {
            Q_D(const Peripheral);
            return d->m_HardwareID;
        }
        void Peripheral::SetHardwareID(QStringList ID)
        {
            Q_D(Peripheral);
            d->m_HardwareID = ID;
            emit HardwareIDChanged();
        }
        /*!
        @brief Friendly Name des Gerätes.
        */
        QString Peripheral::FriendlyName()
        {
            Q_D(const Peripheral);
            return d->m_FriendlyName;
        }
        void Peripheral::SetFriendyNane(QString FriendlyName)
        {
            Q_D(Peripheral);
            d->m_FriendlyName = FriendlyName;
            emit FriendlyNameChanged();
        }
        /*!
        @brief Busnummer des Gerätes.
        */
        quint64 Peripheral::Busnummer()
        {
            Q_D(const Peripheral);
            return d->m_Busnummer;
        }
        void Peripheral::SetBusnummer(quint64 Busnummer)
        {
            Q_D(Peripheral);
            d->m_Busnummer = Busnummer;
            emit FriendlyNameChanged();
        }
        /*!
        @brief Bus-GUID des Gerätes.
        */
        QString Peripheral::BusGUID();
        void Peripheral::BusGUID(QString BusGUID);
        /*!
        @brief Device Setup Class des Gerätes.
        */
        QString Peripheral::Class();
        void Peripheral::SetClass(QString Class);
        /*!
        @brief GUID des Device Setup Class des Gerätes.
        */
        QString Peripheral::ClassGUID();
        void Peripheral::SetClassGUID(QString ClassGUID);
        /*!
        @brief Kompatible ID's für das Gerät.
        */
        QStringList Peripheral::CompatibleID();
        void Peripheral::SetCompatibleID(QStringList CompatibleID);
        /*!
        @brief Type des Gerätes welches der Windowszuordnung entspricht.
        Für eine Zuordnung siehe: https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/specifying-device-types
        */
        quint16 Peripheral::WindowsDeviceType();
        void Peripheral::SetWindowsDeviceType(quint16 WindowsDeviceType);
        /*!
        @brief Beinhaltet den Namen des Geräteenumerators, dieser entspricht dem übergeordneten Elterngruppe (z.b. für USB wäre es USB)
        */
        QString Peripheral::EnumeratorName();
        void Peripheral::SetEnumeratorName(QString EnumeratorName);
        /*!
        @brief Geräteinstallationsstatus. Für die Zuordnung siehe. https://msdn.microsoft.com/en-us/library/windows/hardware/ff543130(v=vs.85).aspx
        */
        quint16 Peripheral::InstallState();
        void Peripheral::SetInstallState(quint16 InstallState);
        /*!
        @brief Herstellername des Gerätes.
        */
        QString Peripheral::Manufacturer();
        void Peripheral::SetManufacturer(QString Manufacturer);
        /*!
        @brief Beinhaltet den Servicename für das Geräte.
        */
        QString Peripheral::ServiceName();
        void Peripheral::SetServiceName(QString ServiceName);
        /*!
        @brief Der interne Gerätetyp.
        */
        PeripheralType Peripheral::InteralType();
        void Peripheral::SetInteralType(PeripheralType InteralType);

        /*!
        @brief Gibt an, ob ein Gerät bereits registriert ist oder nicht.
        */
        bool Peripheral::IsRegistered();
        void Peripheral::SetRegistered(bool Registered);

        /*!
        @brief Gibt an, ob ein Gerät noch aktiv, als Betriebsbereit oder vom Strom getrennt ist.
        */
        bool Peripheral::IsActivate();
        void Peripheral::SetActivate(bool Activate);

	}
}