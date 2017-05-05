#pragma once
#include "..\Global.h"
#include <QMetaType>
namespace spdlog
{
	class logger;
}


namespace RW{
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

	enum class SourceType
	{
		SQL,
		XML,
		MOCK
	};
	//Q_ENUM(SourceType);


	enum class WorkstationState
	{
		ON,
		OFF,
		RESERVE,
		DEFECT
	};

	enum class UserRole
	{
		User,
		Caretaker,
		Admin, 
        NON

	};

    enum class WorkstationKind
    {
        RemoteWorkstation,
        BackendPC,
        FrontEndPC,
        JenkinsBackendPC,
        NON

    };

    enum class PeripheralType
    {
        MiniCube,
        IceCube,
        RenesasE1,
        RPILvdsBox,
        SPIGray,
        SPIRed,

    };

    enum class ChangeUserReason
    {
        ServiceStarted,
        LogOff,
        Login,
        ServiceStopped
    };

    enum class PeripheralState
    {
        Active,
        Offline,
        Error,
    };
}	
Q_DECLARE_METATYPE(RW::WorkstationState)
Q_DECLARE_METATYPE(RW::UserRole)
Q_DECLARE_METATYPE(RW::WorkstationKind)
Q_DECLARE_METATYPE(RW::ChangeUserReason)
Q_DECLARE_METATYPE(RW::PeripheralState)
Q_DECLARE_METATYPE(RW::PeripheralType)