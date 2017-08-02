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

        QString Peripheral::Address()const
        {
            Q_D(const Peripheral);
            return d->m_Address;
        }

        void Peripheral::SetAddress(QString Address)
        {
            Q_D(Peripheral);
            d->m_Address = Address;
            emit AddressChanged();
        }

        QString Peripheral::SubAddress1()const
        {
            Q_D(const Peripheral);
            return d->m_SubAddress1;
        }

        void Peripheral::SetSubAddress1(QString SubAddress1)
        {
            Q_D(Peripheral);
            d->m_SubAddress1 = SubAddress1;
            emit SubAddress1Changed();
        }

        QString Peripheral::SubAddress2()const
        {
            Q_D(const Peripheral);
            return d->m_SubAddress2;
        }

        void Peripheral::SetSubAddress2(QString SubAddress2)
        {
            Q_D(Peripheral);
            d->m_SubAddress2 = SubAddress2;
            emit SubAddress2Changed();
        }

        QString Peripheral::SubAddress3()const
        {
            Q_D(const Peripheral);
            return d->m_SubAddress3;
        }

        void Peripheral::SetSubAddress3(QString SubAddress3)
        {
            Q_D(Peripheral);
            d->m_SubAddress3 = SubAddress3;
            emit SubAddress3Changed();
        }

        PeripheralType Peripheral::Type()const
        {
            Q_D(const Peripheral);
            return d->m_Type;
        }

        void Peripheral::SetType(PeripheralType Type)
        {
            Q_D(Peripheral);
            d->m_Type = Type;
            emit TypeChanged();
        }

        QString Peripheral::ConnectionType()const
        {
            Q_D(const Peripheral);
            return d->m_ConnectionType;
        }

        void Peripheral::SetConnectionType(QString ConnectionType)
        {
            Q_D(Peripheral);
            d->m_ConnectionType = ConnectionType;
            emit ConnectionTypeChanged();
        }

        QString Peripheral::SerialNumber()const
        {
            Q_D(const Peripheral);
            return d->m_SerialNumber;
        }

        void Peripheral::SetSerialNumber(QString SerialNumber)
        {
            Q_D(Peripheral);
            d->m_SerialNumber = SerialNumber;
            emit SerialNumberChanged();
        }

        QString Peripheral::DeviceName()const
        {
            Q_D(const Peripheral);
            return d->m_DeviceName;
        }

        void Peripheral::SetDeviceName(QString DeviceName)
        {
            Q_D(Peripheral);
            d->m_DeviceName = DeviceName;
            emit DeviceNameChanged();
        }

        QString Peripheral::Description()const
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

        QString Peripheral::HardwareID1()const
        {
            Q_D(const Peripheral);
            return d->m_HardwareID1;
        }
        void Peripheral::SetHardwareID1(QString ID1)
        {
            Q_D(Peripheral);
            d->m_HardwareID1 = ID1;
            emit HardwareID1Changed();
        }

        QString Peripheral::HardwareID2()const
        {
            Q_D(const Peripheral);
            return d->m_HardwareID2;
        }

        void Peripheral::SetHardwareID2(QString ID2)
        {
            Q_D(Peripheral);
            d->m_HardwareID2 = ID2;
            emit HardwareID2Changed();
        }

        QString Peripheral::HardwareID3()const
        {
            Q_D(const Peripheral);
            return d->m_HardwareID3;
        }

        void Peripheral::SetHardwareID3(QString ID3)
        {
            Q_D(Peripheral);
            d->m_HardwareID3 = ID3;
            emit HardwareID3Changed();
        }

        PeripheralState Peripheral::State()const
        {
            Q_D(const Peripheral);
            return d->m_State;
        }

        void Peripheral::SetState(PeripheralState State)
        {
            Q_D(Peripheral);
            d->m_State = State;
            emit StateChanged();
        }
	}
}