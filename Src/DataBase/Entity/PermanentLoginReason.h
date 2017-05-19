#pragma once
#include "Entity.h"
#include "..\SQLGlobal.h"

namespace RW{
	namespace SQL{

		class PermanentLoginReasonPrivate;
        class REMOTE_DATA_CONNECT_API PermanentLoginReason :
			public Entity
		{
			Q_OBJECT
            Q_PROPERTY(QString Reason READ Reason WRITE SetReason NOTIFY ReasonChanged)
            Q_PROPERTY(QString Description READ Description WRITE SetDescription NOTIFY DescriptionChanged)
			Q_CLASSINFO("Version", "0.0.1")
		private:
            PermanentLoginReasonPrivate* d_ptr;
            Q_DECLARE_PRIVATE(PermanentLoginReason);
		public:
            explicit PermanentLoginReason(QObject *Parent = nullptr);
            ~PermanentLoginReason();

			QString Reason();
            void SetReason(QString Reason);

            QString Description();
            void SetDescription(QString Description);

            PermanentLoginReason(const PermanentLoginReason& other);
            PermanentLoginReason& PermanentLoginReason::operator=(PermanentLoginReason& other);

            PermanentLoginReason(PermanentLoginReason&& other);
            PermanentLoginReason& PermanentLoginReason::operator=(PermanentLoginReason&& other);

        signals:
            void ReasonChanged();
            void DescriptionChanged();
		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::PermanentLoginReason)