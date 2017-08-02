#include <QObject>
#include "Repository.h"
#include "SQLGlobal.h"

namespace RW{
    namespace CORE{
        enum class ConfigurationName;
        class ConfigurationManager;
        typedef QMap<ConfigurationName, QVariant> ConfigCollection;
        typedef QMap<ConfigurationName, QList<QVariant>> ConfigCollectionLists;
        typedef QMap<ConfigurationName, QMap<QString, QVariant>> ConfigCollectionMaps;

        enum class ChangeReason
        {
            UserChanged,
            UserSave,
            WorkstationStatusUpdate
        };

        class ConfigurationManagerPrivate :
            public QObject
        {
            Q_OBJECT
                Q_DISABLE_COPY(ConfigurationManagerPrivate)
                Q_DECLARE_PUBLIC(ConfigurationManager)
        private:
            ConfigurationManagerPrivate(std::shared_ptr<spdlog::logger> Logger, QObject *Parent = nullptr);
            virtual ~ConfigurationManagerPrivate();

            ConfigurationManager * const q_ptr;
            ConfigCollection *m_ConfigCollection;
            ConfigCollectionLists *m_ConfigCollectionLists;
            ConfigCollectionMaps *m_ConfigCollectionMaps;
            RW::SQL::Repository *m_Repository;
            std::shared_ptr<spdlog::logger> m_Logger;

            /*
            *@brief Ladet den aktuellen User in die Konfiguration
            * @param Hostname Name der Workstation
            */
            bool LoadUser(QString HostName);
            /*
            *@brief Ladet den Verlauf der zuletzt geflashten Software auf dem Target in die Konfiguration
            *@param WorkstationID Id der Workstation für den die Konfiguration gilt.
            */
            bool LoadHistory(quint8 WorkstationID);
            /*
            *@brief Ladet die Workstation Daten
            */
            bool LoadWorkstation(QString HostName);
            /*
            *@brief Ladet die möglichen Softwareversionen aus der Datenbank in die Konfiguration
            *@param ProjectId ProjectId welcher den Softversionen zugeordnet ist.
            *@return Return true, if the configuration could load succesfully.
            */
            bool LoadProjectSoftware(quint8 ProjectId);

            bool LoadGlobalSetting();

            /*
            @brief Ladet die Komplette Table der möglichen Hardware die über den PC erkannt werden kann. 
            Diese wird später genutzt um gegen die tatsächlich angeschlosse HW zu vergleichen.
            */
            bool LoadPeripheralTable();

            void UpdateUser(const ConfigurationName &Key, const QVariant &Val);
            void UpdateWorkstation(const ConfigurationName &Key, const QVariant &Val);
            void UpdateWorkstationSettings(const ConfigurationName &Key, const QVariant &Val);
            void UpdateGlobalSettings(const ConfigurationName &Key, const QVariant &Val);
            void UpdateUserSettings(const ConfigurationName &Key, const QVariant &Val);


            void UpdateValue(ConfigurationName Name, QVariant Value);

            void UpdateUser();
            void ChangeUser(ChangeUserReason Reason);

        signals:
            void SaveConfiguration(ConfigurationName Key, ChangeReason Reason);
        public slots:
            void OnSaveConfiguration(ConfigurationName Key, ChangeReason Reason);
        };
    }
}