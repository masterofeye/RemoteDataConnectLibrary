#pragma once
#include <qobject.h>
#include <QDateTime>
#include "SQLGlobal.h"
#include "Product.h"


namespace RW{
	namespace SQL{

		class Project;
		class Workstation;
		class ElementConfiguration;
		class User;
        class WorkstationType;
        class WorkstationSetting;
        class Peripheral;
        class PermanentLoginReason;
		class WorkstationPrivate : public QObject
		{
			Q_OBJECT
			Q_DISABLE_COPY(WorkstationPrivate)
			Q_DECLARE_PUBLIC(Workstation)
		private:
			Workstation * const q_ptr;
		public:
			WorkstationPrivate(Workstation *Parent);
			~WorkstationPrivate();

			QList<ElementConfiguration*> m_ElementConfiguration;
			User* m_User;
			Project* m_Project;
			QString m_Hostname;
			/*
			@brief
			*/
			QString m_Mac;
			/*
			@todo QHostAdress verwenden
			*/
			QString m_Ip;

            WorkstationSetting* m_WorkstationSetting;
			WorkstationState m_State;
            WorkstationType* m_Type;
            QList<Peripheral*> m_PeripheralList;
            bool m_PermanentLogin;
            PermanentLoginReason* m_Reason;
            QDateTime m_MaxPermamentLogin;

		};
	}
}
