#pragma once
#include "Workstation.h"
#include "ElementConfiguration.h"
#include "ElementType.h"
#include "User.h"
#include "Recept.h"
#include "Product.h"
#include "Instruction.h"
#include "LogEntry.h"
#include "GlobalSetting.h"
#include "Project.h"
#include "Device.h"
#include "SoftwareProject.h"
#include "FlashHistory.h"
#include "WorkstationType.h"
#include "Peripheral.h"
#include "WorkstationSetting.h"

#include <QQmlEngine>
namespace RW{
	namespace SQL{
		class Register
		{
		public:
			static void RegisterRWMetaTypes()
			{
				qRegisterMetaType<RW::WorkstationState>("WorkstationState");
				qRegisterMetaType<RW::WorkstationState>("RW::WorkstationState");

				qRegisterMetaType<RW::UserRole>("RW::UserRole");
				qRegisterMetaType<RW::UserRole>("UserRole");

				qRegisterMetaType<RW::SQL::User*>("RW::SQL::User*");
				qRegisterMetaType<RW::SQL::User*>("User*");

				qRegisterMetaType<RW::SQL::LogEntry*>("RW::SQL::LogEntry*");
				qRegisterMetaType<RW::SQL::LogEntry*>("LogEntry*");

				qRegisterMetaType<RW::SQL::Device*>("RW::SQL::Device*");
				qRegisterMetaType<RW::SQL::Device*>("Device*");

				qRegisterMetaType<RW::SQL::Project*>("RW::SQL::Project*");
				qRegisterMetaType<RW::SQL::Project*>("Project*");
				qRegisterMetaType<RW::SQL::ElementType*>("RW::SQL::ElementType*");
				qRegisterMetaType<RW::SQL::ElementType*>("ElementType*");

                                //qRegisterMetaType<RW::SQL::ElementConfiguration*>("RW::SQL::ElementConfiguration*");
                                //qRegisterMetaType<RW::SQL::ElementConfiguration*>("ElementConfiguration*");
                                //qRegisterMetaType<RW::SQL::ElementConfiguration>("RW::SQL::ElementConfiguration");
                                //qRegisterMetaType<RW::SQL::ElementConfiguration>("ElementConfiguration");
				
				qmlRegisterType<RW::SQL::Workstation>();
				qmlRegisterType<RW::SQL::Project>();
				qmlRegisterType<RW::SQL::ElementConfiguration>();

			}
		};
	}
}

