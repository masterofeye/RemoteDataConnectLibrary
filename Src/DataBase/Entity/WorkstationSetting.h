#pragma once
#include "Entity.h"
#include "..\SQLGlobal.h"

namespace RW{
	namespace SQL{

        class PermanentLoginReason;
		class WorkstationSettingPrivate;
        class REMOTE_DATA_CONNECT_API WorkstationSetting :
			public Entity
		{
			Q_OBJECT
            Q_PROPERTY(bool PermanentLogin READ PermanentLogin WRITE SetPermanentLogin NOTIFY PermanentLoginChanged)
            Q_PROPERTY(PermanentLoginReason* Reason READ Reason WRITE SetReason NOTIFY ReasonChanged)
			Q_CLASSINFO("Version", "0.0.1")
		private:
            WorkstationSettingPrivate* d_ptr;
            Q_DECLARE_PRIVATE(WorkstationSetting);
		public:
            explicit WorkstationSetting(QObject *Parent = nullptr);
            ~WorkstationSetting();

			bool PermanentLogin();
            void SetPermanentLogin(bool PermanentLogin);

            PermanentLoginReason* Reason();
            void SetReason(PermanentLoginReason*);

            WorkstationSetting(const WorkstationSetting& other);
            WorkstationSetting& WorkstationSetting::operator=(WorkstationSetting& other);

            WorkstationSetting(WorkstationSetting&& other);
            WorkstationSetting& WorkstationSetting::operator=(WorkstationSetting&& other);
        signals:
            void PermanentLoginChanged();
            void ReasonChanged();
		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::WorkstationSetting)