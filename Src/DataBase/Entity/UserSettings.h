#pragma once
#include "Entity.h"
#include <QTime>

namespace RW{
    namespace SQL{

        class UserSettingsPrivate;
        class REMOTE_DATA_CONNECT_API UserSettings :
            public Entity
        {
            Q_OBJECT
            Q_PROPERTY(QTime LogoutTimeStart READ LogoutTimeStart WRITE SetLogoutTimeStart NOTIFY LogoutTimeStartChanged)
            Q_PROPERTY(QTime LogoutTimeEnd READ LogoutTimeEnd WRITE SetLogoutTimeEnd NOTIFY LogoutTimeEndChanged)


            Q_CLASSINFO("Version", "0.0.1")

        private:
            UserSettingsPrivate *d_ptr;
            Q_DECLARE_PRIVATE(UserSettings);
        public:
            UserSettings(QObject *Parent = nullptr);
            ~UserSettings();

            UserSettings(const UserSettings& other);
            UserSettings& UserSettings::operator=(UserSettings& other);

            UserSettings(UserSettings&& other);
            UserSettings& UserSettings::operator=(UserSettings&& other);

            QTime LogoutTimeStart();
            void SetLogoutTimeStart(QTime);

            QTime LogoutTimeEnd();
            void SetLogoutTimeEnd(QTime);

        signals:
            void LogoutTimeStartChanged();
            void LogoutTimeEndChanged();
        };
    }
}
Q_DECLARE_METATYPE(RW::SQL::UserSettings)