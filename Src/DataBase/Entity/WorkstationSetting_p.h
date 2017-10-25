#pragma once
#include <qobject.h>
#include "SQLGlobal.h"

namespace RW{
	namespace SQL{

        class WorkstationSetting;
        class PermanentLoginReason;
        class WorkstationSettingPrivate : public QObject
		{
			Q_OBJECT
                Q_DISABLE_COPY(WorkstationSettingPrivate)
                Q_DECLARE_PUBLIC(WorkstationSetting)
			//Q_PROPERTY(TypeOFElement Type MEMBER m_Type READ Type WRITE SetType NOTIFY TypeChanged)
		private:
            WorkstationSetting * const q_ptr;
		public:
            WorkstationSettingPrivate(WorkstationSetting *Parent);
            ~WorkstationSettingPrivate();
		signals:
            void PermanentLoginChanged();
		};
	}
}