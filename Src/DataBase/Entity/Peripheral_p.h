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
            @brief Busspezifische Adresse der Ger�teinstanz.
            */
            quint64 m_Address = 0;
            /*!
            @brief Busspezifische physikalischer Ort einer Ger�teinstanz.
            */
            QString m_LocationInformation = "";
            /*!
            @brief Ort der Ger�teinstanz innerhalb des Ger�tebaums.
            */
            QString m_LocationPath = "";
            /*!
            @brief Beschreibung des Ger�tes.
            */
            QString m_Description = "";
            /*!
            @brief Sprechender Name des Ger�tes.
            */
            QString m_DeviceName = "";
            /*!
            @brief HardwareID des Ger�tes.
            */
            QStringList m_HardwareID;
            /*!
            @brief Friendly Name des Ger�tes.
            */
            QString m_FriendlyName = "";
            /*!
            @brief Busnummer des Ger�tes.
            */
            quint64 m_Busnummer = 0;
            /*!
            @brief Bus-GUID des Ger�tes.
            */
            QString m_BusGUID = "";
            /*!
            @brief Device Setup Class des Ger�tes.
            */
            QString m_Class = "";
            /*!
            @brief GUID des Device Setup Class des Ger�tes.
            */
            QString m_ClassGUID = "";
            /*!
            @brief Kompatible ID's f�r das Ger�t.
            */
            QStringList m_CompatibleID;
            /*!
            @brief Type des Ger�tes welches der Windowszuordnung entspricht.
            F�r eine Zuordnung siehe: https://docs.microsoft.com/en-us/windows-hardware/drivers/kernel/specifying-device-types
            */
            quint16 m_WindowsDeviceType = 0;
            /*!
            @brief Beinhaltet den Namen des Ger�teenumerators, dieser entspricht dem �bergeordneten Elterngruppe (z.b. f�r USB w�re es USB)
            */
            QString m_EnumeratorName = "";
            /*!
            @brief Ger�teinstallationsstatus. F�r die Zuordnung siehe. https://msdn.microsoft.com/en-us/library/windows/hardware/ff543130(v=vs.85).aspx
            */
            quint16 m_InstallState = 0;
            /*!
            @brief Herstellername des Ger�tes.
            */
            QString m_Manufacturer = "";
            /*!
            @brief Beinhaltet den Servicename f�r das Ger�te.
            */
            QString m_ServiceName = "";
            /*!
            @brief Der interne Ger�tetyp.
            */
            PeripheralType m_Type;
            /*!
            @brief Gibt an, ob ein Ger�t bereits registriert ist oder nicht.
            */
            bool m_IsRegistered;
            /*!
            @brief Gibt an, ob ein Ger�t noch aktiv, als Betriebsbereit oder vom Strom getrennt ist. 
            */
            bool m_IsActivate;

		};
	}
}