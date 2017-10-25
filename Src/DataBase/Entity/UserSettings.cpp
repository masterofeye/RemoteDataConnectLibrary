#include "UserSettings.h"
#include "UserSettings_p.h"

namespace RW{
    namespace SQL{

        UserSettingsPrivate::UserSettingsPrivate(UserSettings* Parent) :
            QObject(Parent),
            q_ptr(Parent),
            m_LogoutTimeEnd(QTime::currentTime()),
            m_LogoutTimeStart(QTime::currentTime())
        {
        }

        UserSettingsPrivate::~UserSettingsPrivate()
        {
        }


        UserSettings::UserSettings(const UserSettings& other)
        {
            if (&other != nullptr)
            {
                d_ptr = new UserSettingsPrivate(this);
                d_ptr->m_LogoutTimeEnd = other.d_ptr->m_LogoutTimeEnd;
                d_ptr->m_LogoutTimeStart = other.d_ptr->m_LogoutTimeStart;
                SetID(other.ID());
            }
        }
        UserSettings& UserSettings::operator=(UserSettings& other)
        {
            if (&other != nullptr)
            {
                d_ptr = new UserSettingsPrivate(this);
                d_ptr->m_LogoutTimeEnd = other.d_ptr->m_LogoutTimeEnd;
                d_ptr->m_LogoutTimeStart = other.d_ptr->m_LogoutTimeStart;
                SetID(other.ID());
            }
            return *this;
        }


        UserSettings::UserSettings(UserSettings&& other) : d_ptr(other.d_ptr)
        {
            if (&other != nullptr)
            {
                d_ptr->setParent(this);
                SetID(other.ID());
                other.d_ptr = nullptr;

            }
        }

        UserSettings& UserSettings::operator=(UserSettings&& other)
        {
            if (&other != nullptr)
            {
                std::swap(d_ptr, other.d_ptr);
                d_ptr->setParent(this);

                SetID(other.ID());
                delete other.d_ptr;
                other.d_ptr = nullptr;

            }
            return *this;
        }

        UserSettings::UserSettings(QObject *Parent) : Entity(Parent),
            d_ptr(new UserSettingsPrivate(this))
        {
        }


        UserSettings::~UserSettings()
        {
        }


        QTime UserSettings::LogoutTimeStart()
        {
            Q_D(const UserSettings);
            return d->m_LogoutTimeStart;
        }

        void UserSettings::SetLogoutTimeStart(QTime Timeout)
        {
            Q_D(UserSettings);

            d->m_LogoutTimeStart = Timeout;
            emit LogoutTimeStartChanged();
        }

        QTime UserSettings::LogoutTimeEnd()
        {
            Q_D(const UserSettings);
            return d->m_LogoutTimeEnd;
        }

        void UserSettings::SetLogoutTimeEnd(QTime Timeout)
        {
            Q_D(UserSettings);

            d->m_LogoutTimeEnd = Timeout;
            emit UserSettings();
        }


    }
}