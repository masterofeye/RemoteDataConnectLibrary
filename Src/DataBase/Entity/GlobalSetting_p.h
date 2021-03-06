#pragma once
#include <qobject.h>
#include "SQLGlobal.h"
#include <QTime>

namespace RW
{
	namespace SQL{

		class GlobalSetting;
        class GlobalSettingPrivate : public QObject
		{
			Q_OBJECT
				Q_DISABLE_COPY(GlobalSettingPrivate)
				Q_DECLARE_PUBLIC(GlobalSetting)
		private:
			GlobalSetting * const q_ptr;
		public:
			GlobalSettingPrivate(GlobalSetting *Parent);
			~GlobalSettingPrivate();

            quint64 m_RwLogOutTimer;
            quint64 m_RwShutdownTimer;
            quint64 m_BeLogOutTimer;
            quint64 m_BeShutdownTimer;
            QTime m_UpdateStartTime;
            QTime m_UpdateEndTime;
		};
	}
}