#pragma once
#include <QObject>
#include "Global.h"

namespace spdlog
{
	class logger;
}


namespace RW{
    REMOTE_DATA_CONNECT_API Q_NAMESPACE
	enum class TypeOfElement
	{
		USB,
		IO,
		RELAY,
		SOUND,
		HUD,
		LVDS,
		INVALID
	};
    Q_ENUM_NS(TypeOfElement)

	enum class SourceType
	{
		SQL,
		XML,
		MOCK
	};
    Q_ENUM_NS(SourceType);


	enum class WorkstationState
	{
		ON,
		OFF,
		RESERVE,
		DEFECT,
                FREE,
                OCCUPY
	};
        Q_ENUM_NS(WorkstationState)

	enum class UserRole
	{
		User,
		Caretaker,
		Admin, 
        NON

	};
    Q_ENUM_NS(UserRole)



    enum class WorkstationKind
    {
        RemoteWorkstation,
        BackendPC,
        FrontEndPC,
        JenkinsBackendPC,
        NON

    };
    Q_ENUM_NS(WorkstationKind)

    enum class PeripheralType
    {
        MiniCube,
        IECube,
        RenesasE1,
        RPILvdsBox,
        LVDSContinentalBox,
        SPIGray,
        SPIRed,
        RemoteBox,
        PowerStripe_Anel_NETPwrCtrl,
        PowerSupply_Voltcraft_FPS1136,
        PowerSupply_Voltcraft_PPS11815,
        MaxAmount

    };
    Q_ENUM_NS(PeripheralType)

    enum class ChangeUserReason
    {
        ServiceStarted,
        LogOff,
        Login,
        ServiceStopped
    };
    Q_ENUM_NS(ChangeUserReason)

    enum class PeripheralState
    {
        Active,
        Offline,
        Error,
    };
    Q_ENUM_NS(PeripheralState)
}	
Q_DECLARE_METATYPE(RW::WorkstationState)
Q_DECLARE_METATYPE(RW::UserRole)
Q_DECLARE_METATYPE(RW::WorkstationKind)
Q_DECLARE_METATYPE(RW::ChangeUserReason)
Q_DECLARE_METATYPE(RW::PeripheralState)
Q_DECLARE_METATYPE(RW::PeripheralType)
