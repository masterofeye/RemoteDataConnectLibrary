#pragma once
#include <QObject>
#include <QMap>
#include <QVariant>
#include "..\DataBase\SQLGlobal.h"
#include <memory>

namespace RW{
    namespace SQL
    {
        class Repository;
    }

    namespace CORE
    {
        enum class ConfigurationName
        {
            UserStart,
            UserId,
            UserName,
            UserRole,
            UserPassword,
            MKSPassword,
            MKSUsername,
            Initials,
            UserWorkstation,
            UserEnd,
            /*UserSettings*/
            UserSettingsStart,
            NotifyRemoteDesktop,
            NotifyDesktop,
            StartCanEasy,
            StartRemoteApp,
            UserSettingsEnd,
            /*Globalsettings*/
            GlobalSettingsStart,
            RwLogOutTimer,
            RwShutdownTimer,
            BeLogOutTimer, 
            BeShutdownTimer,
            LogoutTimeStart,
            LogoutTimeEnd,
            GlobalSettingsEnd,
            /*Project*/
            ProjectStart,
            ProjectName,
            ProjectId,
            ProjectEnd,
            /*Workstation*/
            WorkstationStart,
            WorkstationId,
            Hostname,
            Ip,
            Mac,
            WorkstationType,
            WorkstationState,
            WorkstationEnd,
            /*WorkstationSettings*/
            WorkstationSettingsStart,
            PermanentLogin,
            PermanentLoginReason,
            WorkstationSettingsEnd,

            /*History*/
            HistoryStart,
            FlashedByUser,
            Software,
            Major,
            Minor,
            PatchLevel,
            BuildNumber,
            Date,
            FlashHistory,
            AmoundOfFlashHistory,
            HistoryEnd,
            /*SoftwareProject*/
            SoftwareProjectStart,
            SoftwareProject,
            SoftwareProjectAmount,  //Anzahl der Softwarestände bzw. Firmwareversionen
            SoftwareProjectEnd,

            /*Peripheral*/
            PeripheralTable,        //Liste alle möglichen HW Geräte, die aus der Datenbank ermittelt wird
            PeripheralCurrentActive, //Liste an HW Komponenten die Wirklich angeschlossen sind und erkannt wurden

        };

        class ConfigurationManagerPrivate;
        class REMOTE_DATA_CONNECT_API ConfigurationManager :
            public QObject
        {
            Q_OBJECT
        private:
            ConfigurationManagerPrivate *d_ptr;
            Q_DECLARE_PRIVATE(ConfigurationManager);
        public:
            ConfigurationManager(std::shared_ptr<spdlog::logger> Logger, QObject *Parent = nullptr);
            ~ConfigurationManager();

            ConfigurationManager(const ConfigurationManager &R);
            ConfigurationManager& operator=(const ConfigurationManager &R);

            ConfigurationManager(ConfigurationManager &&R);
            ConfigurationManager& operator=(ConfigurationManager &&R);


            const QVariant operator[](const ConfigurationName& Name);

            bool Load();
            bool Save(); 

            bool GetConfigValue(const ConfigurationName &Key, QVariant &Val);
            bool GetConfigValue(const ConfigurationName &Key, QList<QVariant> &Val);
            bool GetConfigValue(const ConfigurationName &Key, QList<QVariant*> &Val);
            bool GetConfigValue(const ConfigurationName &Key, QMap<QString, QVariant> &Val);

            bool InsertConfigValue(const ConfigurationName &Key, const QVariant &Val);
            bool InsertConfigValue(const ConfigurationName &Key, const QList<QVariant> &Val);
            bool InsertConfigValue(const ConfigurationName &Key, const QList<QVariant*> &Val);
            bool InsertConfigValue(const ConfigurationName &Key, const QMap<QString, QVariant> &Val);


        };
    }
}
