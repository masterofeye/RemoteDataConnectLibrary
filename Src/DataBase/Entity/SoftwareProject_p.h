#pragma once
#include "SQLGlobal.h"
#include <qobject.h>


namespace RW{
	namespace SQL{

        class Project;
        class SoftwareProject;
        class SoftwareProjectPrivate : public QObject
		{
			Q_OBJECT
            Q_DISABLE_COPY(SoftwareProjectPrivate)
            Q_DECLARE_PUBLIC(SoftwareProject)
		private:
            SoftwareProject * const q_ptr;
		public:
            SoftwareProjectPrivate(SoftwareProject *Parent);
            ~SoftwareProjectPrivate();
			
            Project* m_Project;
			QString m_Name;
			
		};
	}
}