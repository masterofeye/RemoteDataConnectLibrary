#pragma once
#include <qobject.h>
namespace RW{
    enum class TypeOfElement;
    enum class PeripheralType;
	namespace SQL{

        class PeripheralCondition;
        class Peripheral;
        class PeripheralConditionPrivate : public QObject
		{
			Q_OBJECT
                Q_DISABLE_COPY(PeripheralConditionPrivate)
                Q_DECLARE_PUBLIC(PeripheralCondition)
		private:
            PeripheralCondition * const q_ptr;
		public:
            Peripheral* m_Peripheral = nullptr;
            quint8 m_Priority;
			QString m_Port;
            QString m_Pin;
            quint8 m_TypeOfInformation;
            bool m_State;
            PeripheralType m_DeviceType;
            TypeOfElement m_TypeOfConnection;
            QList<PeripheralCondition*> m_FollowUpCondition;
		public:
            PeripheralConditionPrivate(PeripheralCondition *Parent);
            ~PeripheralConditionPrivate();
		};
	}
}