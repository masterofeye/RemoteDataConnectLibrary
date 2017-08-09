#pragma once
#include "SQLGlobal.h"
#include <qobject.h>


namespace RW{
	namespace SQL{

        class Peripheral;
        class PeripheralPrivate : public QObject
		{
			Q_OBJECT
                Q_DISABLE_COPY(PeripheralPrivate)
                Q_DECLARE_PUBLIC(Peripheral)
		private:
            Peripheral * const q_ptr;
		public:
            PeripheralPrivate(Peripheral *Parent);
            ~PeripheralPrivate();
			
            /*!
            @brief Busspezifische Adresse der Geräteinstanz.
            */
            quint64 m_Address = 0;
            /*!
            @brief Busspezifische physikalischer Ort einer Geräteinstanz.
            */
            QString m_LocationInformation = "";
            /*!
            @brief Ort der Geräteinstanz innerhalb des Gerätebaums.
            */
            QString m_LocationPath = "";
            /*!
            @brief Beschreibung des Gerätes.
            */
            QString m_Description = "";
            /*!
            @brief Sprechender Name des Gerätes.
            */
            QString m_DeviceName = "";
            /*!
            @brief HardwareID des Gerätes.
            */
            QStringList m_HardwareID;
            /*!
            @brief Friendly Name des Gerätes.
            */
            QString m_FriendlyName = "";
            /*!
            @brief Busnummer des Gerätes.
            */
            quint64 m_Busnummer = 0;
            /*!
            @brief Bus-GUID des Gerätes.
            */
            QString m_BusGUID = "";
            /*!
            @brief Device Setup Class des Gerätes.
            */
            QString m_Class = "";
            /*!
            @brief GUID des Device Setup Class des Gerätes.
            */
            QString m_ClassGUID = "";
            /*!
            @brief Kompatible ID's für das Gerät.
            */
            QStringList m_CompatibleID;
            /*!
            @brief Type des Gerätes welches der Windowszuordnung entspricht.
            Für eine Zuordnung siehe: https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/specifying-device-types
            */
            quint16 m_WindowsDeviceType = 0;
            /*!
            @brief Beinhaltet den Namen des Geräteenumerators, dieser entspricht dem übergeordneten Elterngruppe (z.b. für USB wäre es USB)
            */
            QString m_EnumeratorName = "";
            /*!
            @brief Geräteinstallationsstatus. Für die Zuordnung siehe. https://msdn.microsoft.com/en-us/library/windows/hardware/ff543130(v=vs.85).aspx
            */
            quint16 m_InstallState = 0;
            /*!
            @brief Herstellername des Gerätes.
            */
            QString m_Manufacturer = "";
            /*!
            @brief Beinhaltet den Servicename für das Geräte.
            */
            QString m_ServiceName = "";
            /*!
            @brief Der interne Gerätetyp.
            */
            PeripheralType m_Type;
            /*!
            @brief Gibt an, ob ein Gerät bereits registriert ist oder nicht.
            */
            bool m_IsRegistered;
            /*!
            @brief Gibt an, ob ein Gerät noch aktiv, als Betriebsbereit oder vom Strom getrennt ist. 
            */
            bool m_IsActivate;

		};
	}
}