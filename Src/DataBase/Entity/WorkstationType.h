#pragma once
#include "Entity.h"

namespace RW{
    enum class WorkstationKind;
	namespace SQL{

        class WorkstationTypePrivate;
        
        class REMOTE_DATA_CONNECT_API WorkstationType :
			public Entity
		{
			Q_OBJECT
            Q_PROPERTY(WorkstationKind Type READ Type WRITE SetType NOTIFY TypeChanged)
			Q_CLASSINFO("Version", "0.0.1")

		private:
            WorkstationTypePrivate *d_ptr;
            Q_DECLARE_PRIVATE(WorkstationType);
		public:
            WorkstationType(QObject *Parent = nullptr);
            ~WorkstationType();

            WorkstationType(const WorkstationType& other);
            WorkstationType& WorkstationType::operator=(WorkstationType& other);

            WorkstationType(WorkstationType&& other);
            WorkstationType& WorkstationType::operator=(WorkstationType&& other);

            RW::WorkstationKind Type() const;
            void SetType(RW::WorkstationKind Type);


		signals:
            void TypeChanged();

		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::WorkstationType)