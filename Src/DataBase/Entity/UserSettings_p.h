#pragma once
#include <qobject.h>
#include "SQLGlobal.h"
#include <QTime>

namespace RW{
    namespace SQL{

        class UserSettings;
        class UserSettingsPrivate : public QObject
        {
            Q_OBJECT
                Q_DISABLE_COPY(UserSettingsPrivate)
                Q_DECLARE_PUBLIC(UserSettings)
        public:
            QTime m_LogoutTimeStart;
            QTime m_LogoutTimeEnd;
        private:
            UserSettings * const q_ptr;
        public:
            UserSettingsPrivate(UserSettings *Parent);
            ~UserSettingsPrivate();

        };
    }
}