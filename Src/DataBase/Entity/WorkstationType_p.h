#pragma once
#include <qobject.h>

namespace RW{
    enum class WorkstationKind;
	namespace SQL{

        class WorkstationType;
        class WorkstationTypePrivate : public QObject
		{
			Q_OBJECT
                Q_DISABLE_COPY(WorkstationTypePrivate)
                Q_DECLARE_PUBLIC(WorkstationType)
		public:
            WorkstationKind m_Type;
		private:
            WorkstationType * const q_ptr;
		public:
            WorkstationTypePrivate(WorkstationType *Parent);
            ~WorkstationTypePrivate();
		};
	}
}