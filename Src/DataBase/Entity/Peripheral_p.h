#pragma once
#include "SQLGlobal.h"
#include <qobject.h>


namespace RW{
	namespace SQL{

        class Peripheral;
        class PeripheralPrivate : public QObject
		{
			Q_OBJECT
                Q_DISABLE_COPY(PeripheralPrivate)
                Q_DECLARE_PUBLIC(Peripheral)
		private:
            Peripheral * const q_ptr;
		public:
            PeripheralPrivate(Peripheral *Parent);
            ~PeripheralPrivate();
			
            QString m_Address;
            QString m_SubAddress1;
            QString m_SubAddress2;
            QString m_SubAddress3;
            QString m_Name;
            PeripheralType m_Type;
            QString m_ConnectionType;
            QString m_SerialNumber;
            QString m_DeviceName;
            QString m_Description;
            QString m_HardwareID1;
            QString m_HardwareID2;
            QString m_HardwareID3;
            PeripheralState m_State;
		};
	}
}