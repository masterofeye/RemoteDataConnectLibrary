#include "GlobalSetting.h"
#include "GlobalSetting_p.h"

namespace RW
{
	namespace SQL
	{
		GlobalSettingPrivate::GlobalSettingPrivate(GlobalSetting *Parent) :
            QObject(Parent),
			q_ptr(Parent)
		{
		}

		GlobalSettingPrivate::~GlobalSettingPrivate()
		{
		}



		GlobalSetting::GlobalSetting(QObject *Parent) : Entity(Parent),
			d_ptr(new GlobalSettingPrivate(this))
		{
		}


		GlobalSetting::~GlobalSetting()
		{
		}

		GlobalSetting::GlobalSetting(const GlobalSetting& other) : d_ptr(const_cast<GlobalSettingPrivate*>(other.d_ptr))
		{

		}

		GlobalSetting& GlobalSetting::operator=(GlobalSetting& other)
		{
			std::swap(d_ptr, const_cast<GlobalSettingPrivate*>(other.d_ptr));
			d_ptr->setParent(this);
			return *this;
		}


		GlobalSetting::GlobalSetting(GlobalSetting&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
			other.d_ptr = nullptr;
		}

		GlobalSetting& GlobalSetting::operator = (GlobalSetting&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}


        quint64 GlobalSetting::RwLogOutTimer()
        {
            Q_D(const GlobalSetting);
            return d->m_RwLogOutTimer;
        }

        void GlobalSetting::SetRwLogOutTimer(quint64 Timeout)
        {
            Q_D(GlobalSetting);

            d->m_RwLogOutTimer = Timeout;
            emit RwLogOutTimerChanged();
        }

        quint64 GlobalSetting::RwShutdownTimer()
        {
            Q_D(const GlobalSetting);
            return d->m_RwShutdownTimer;
        }


        void GlobalSetting::SetRwShutdownTimer(quint64 Timeout)
        {
            Q_D(GlobalSetting);

            d->m_RwShutdownTimer = Timeout;
            emit RwShutdownTimerChanged();
        }

        quint64 GlobalSetting::BeLogOutTimer()
        {
            Q_D(const GlobalSetting);
            return d->m_BeLogOutTimer;
        }

        void GlobalSetting::SetBeLogOutTimer(quint64 Timeout)
        {
            Q_D(GlobalSetting);

            d->m_BeLogOutTimer = Timeout;
            emit BeLogOutTimerChanged();
        }

        quint64 GlobalSetting::BeShutdownTimer()
        {
            Q_D(const GlobalSetting);
            return d->m_BeShutdownTimer;
        }
        void GlobalSetting::SetBeShutdownTimer(quint64 Timeout)
        {
            Q_D(GlobalSetting);

            d->m_BeShutdownTimer = Timeout;
            emit BeShutdownTimerChanged();
        }

        QDateTime GlobalSetting::LogoutTime()
        {
            Q_D(const GlobalSetting);
            return d->m_LogoutTime;
        }

        void GlobalSetting::SetLogoutTime(QDateTime Timeout)
        {
            Q_D(GlobalSetting);

            d->m_LogoutTime = Timeout;
            emit LogoutTimeChanged();
        }

	}
}