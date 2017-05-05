#pragma once
#include "SQLGlobal.h"
#include <qobject.h>
#include <qvariant.h>
#include <qdatetime.h>

namespace RW{
	namespace SQL{

		class FlashHistory;
		class User;
		class SoftwareProject;
        class Workstation;
		class FlashHistoryPrivate : public QObject
		{
			Q_OBJECT
			Q_DISABLE_COPY(FlashHistoryPrivate)
			Q_DECLARE_PUBLIC(FlashHistory)
		private:
			FlashHistory * const q_ptr;
		public:
			FlashHistoryPrivate(FlashHistory *Parent);
			~FlashHistoryPrivate();
			
			User* m_User;
			SoftwareProject* m_SoftwareProject;
			Workstation* m_Workstation;
			QVariant m_Major;
			QVariant m_Minor;
			QVariant m_PatchLevel;
			QVariant m_Buildnumber;
			QDateTime m_Date;
			
		};
	}
}