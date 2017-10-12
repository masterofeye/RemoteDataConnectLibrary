#pragma once
#include "Entity.h"
#include <qdatetime.h>

namespace RW
{
	namespace SQL
	{
		class GlobalSettingPrivate;
		class REMOTE_DATA_CONNECT_API GlobalSetting :
			public Entity
		{
			Q_OBJECT
            Q_PROPERTY(quint64 RwLogOutTimer READ RwLogOutTimer WRITE SetRwLogOutTimer NOTIFY RwLogOutTimerChanged)
            Q_PROPERTY(quint64 RwShutdownTimer READ RwShutdownTimer WRITE SetRwShutdownTimer NOTIFY RwShutdownTimerChanged)
            Q_PROPERTY(quint64 BeLogOutTimer READ BeLogOutTimer WRITE SetBeLogOutTimer NOTIFY BeLogOutTimerChanged)
            Q_PROPERTY(quint64 BeShutdownTimer READ BeShutdownTimer WRITE SetBeShutdownTimer NOTIFY BeShutdownTimerChanged)
            Q_PROPERTY(QDateTime LogoutTime READ LogoutTime WRITE SetLogoutTime NOTIFY LogoutTimeChanged)
			Q_CLASSINFO("Version", "0.0.1")
		private:
			GlobalSettingPrivate* d_ptr;
			Q_DECLARE_PRIVATE(GlobalSetting);



		public:
			GlobalSetting(QObject *Parent = nullptr);
			~GlobalSetting();

            GlobalSetting(const GlobalSetting& other);
            GlobalSetting& GlobalSetting::operator=(GlobalSetting& other);

            GlobalSetting(GlobalSetting&& other);
            GlobalSetting& GlobalSetting::operator=(GlobalSetting&& other);

            quint64 RwLogOutTimer();
            void SetRwLogOutTimer(quint64);

            quint64 RwShutdownTimer();
            void SetRwShutdownTimer(quint64);

            quint64 BeLogOutTimer();
            void SetBeLogOutTimer(quint64);

            quint64 BeShutdownTimer();
            void SetBeShutdownTimer(quint64);

            QDateTime LogoutTime();
            void SetLogoutTime(QDateTime);

        signals:
            void RwLogOutTimerChanged();
            void RwShutdownTimerChanged();
            void BeLogOutTimerChanged();
            void BeShutdownTimerChanged();
            void LogoutTimeChanged();
		};
	}
}
