#pragma once
#include "Entity.h"
#include "..\SQLGlobal.h"
namespace RW{
	namespace SQL{

        class Project;
        class PeripheralPrivate;

        class REMOTE_DATA_CONNECT_API Peripheral :
			public Entity
		{
            Q_OBJECT
            Q_PROPERTY(QString Address READ Address WRITE SetAddress NOTIFY AddressChanged)
            Q_PROPERTY(QString SubAddress1 READ SubAddress1 WRITE SetSubAddress1 NOTIFY SubAddress1Changed)
            Q_PROPERTY(QString SubAddress2 READ SubAddress2 WRITE SetSubAddress2 NOTIFY SubAddress2Changed)
            Q_PROPERTY(QString SubAddress3 READ SubAddress3 WRITE SetSubAddress3 NOTIFY SubAddress3Changed)
            Q_PROPERTY(QString Name READ Name WRITE SetName NOTIFY NameChanged)
            Q_PROPERTY(PeripheralType Type READ Type WRITE SetType NOTIFY TypeChanged)
            Q_PROPERTY(QString ConnectionType READ ConnectionType WRITE SetConnectionType NOTIFY ConnectionTypeChanged)
            Q_PROPERTY(QString SerialNumber READ SerialNumber WRITE SetSerialNumber NOTIFY SerialNumberChanged)
            Q_PROPERTY(QString DeviceName READ DeviceName WRITE SetDeviceName NOTIFY DeviceNameChanged)
            Q_PROPERTY(QString Description READ Description WRITE SetDescription NOTIFY DescriptionChanged)
            Q_PROPERTY(QString HardwareID1 READ HardwareID1 WRITE SetHardwareID1 NOTIFY HardwareID1Changed)
            Q_PROPERTY(QString HardwareID2 READ HardwareID2 WRITE SetHardwareID2 NOTIFY HardwareID2Changed)
            Q_PROPERTY(QString HardwareID3 READ HardwareID3 WRITE SetHardwareID3 NOTIFY HardwareID3Changed)
            Q_PROPERTY(PeripheralState State READ State WRITE SetState NOTIFY StateChanged)

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

            QString Address()const;
            void SetAddress(QString Address);

            QString SubAddress1()const;
            void SetSubAddress1(QString SubAddress1);

            QString SubAddress2()const;
            void SetSubAddress2(QString SubAddress2);

            QString SubAddress3()const;
            void SetSubAddress3(QString SubAddress3);

            QString Name()const;
            void SetName(QString Name);

            PeripheralType Type()const;
            void SetType(PeripheralType Type);

            QString ConnectionType()const;
            void SetConnectionType(QString ConnectionType);

            QString SerialNumber()const;
            void SetSerialNumber(QString SerialNumber);

            QString DeviceName()const;
            void SetDeviceName(QString DeviceName);

            QString Description()const;
            void SetDescription(QString Description);

            QString HardwareID1()const;
            void SetHardwareID1(QString ID1);

            QString HardwareID2()const;
            void SetHardwareID2(QString ID2);

            QString HardwareID3()const;
            void SetHardwareID3(QString ID3);

            PeripheralState State()const;
            void SetState(PeripheralState State);

        signals:
            void AddressChanged();
            void SubAddress1Changed();
            void SubAddress2Changed();
            void SubAddress3Changed();
            void NameChanged();
            void TypeChanged();
            void ConnectionTypeChanged();
            void SerialNumberChanged();
            void DeviceNameChanged();
            void DescriptionChanged();
            void HardwareID1Changed();
            void HardwareID2Changed();
            void HardwareID3Changed();
            void StateChanged();

		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::Peripheral)