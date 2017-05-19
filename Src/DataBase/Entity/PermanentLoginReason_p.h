#pragma once
#include <qobject.h>
#include "SQLGlobal.h"

namespace RW{
	namespace SQL{

        class PermanentLoginReason;
        class PermanentLoginReasonPrivate : public QObject
		{
			Q_OBJECT
                Q_DISABLE_COPY(PermanentLoginReasonPrivate)
                Q_DECLARE_PUBLIC(PermanentLoginReason)
			//Q_PROPERTY(TypeOFElement Type MEMBER m_Type READ Type WRITE SetType NOTIFY TypeChanged)
		private:
            PermanentLoginReason * const q_ptr;
		public:
            QString m_Description;
            QString m_Reason;
		public:
            PermanentLoginReasonPrivate(PermanentLoginReason *Parent);
            ~PermanentLoginReasonPrivate();
		signals:
            void PermanentLoginChanged();
		};
	}
}