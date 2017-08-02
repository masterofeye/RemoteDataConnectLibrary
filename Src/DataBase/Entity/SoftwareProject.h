#pragma once
#include "Entity.h"
#include "..\SQLGlobal.h"
namespace RW{
	namespace SQL{

        class Project;
        class SoftwareProjectPrivate;

		class REMOTE_DATA_CONNECT_API SoftwareProject :
			public Entity
		{
            Q_OBJECT
            Q_PROPERTY(Project* ProjectSw READ ProjectSw WRITE SetProjectSw NOTIFY ProjectSwChanged)
            Q_PROPERTY(QString Name READ Name WRITE SetName NOTIFY NameChanged)
			Q_PROPERTY(QString NaturalName READ NaturalName WRITE SetNaturalName NOTIFY NaturalNameChanged)

            Q_CLASSINFO("Version", "0.0.1")
        private:
            SoftwareProjectPrivate* d_ptr;
            Q_DECLARE_PRIVATE(SoftwareProject);
		public:
            SoftwareProject(Entity *Parent = nullptr);
            ~SoftwareProject();

            SoftwareProject(const SoftwareProject &F);
            SoftwareProject& operator=(const SoftwareProject &F);

            SoftwareProject(SoftwareProject &&F);
            SoftwareProject& operator=(SoftwareProject &&F);

            Project* ProjectSw()const;
            void SetProjectSw(Project* User);

            QString Name()const;
            void SetName(QString SoftwareProject);
 
			QString NaturalName()const;
			void SetNaturalName(QString NaturalName);
        signals:
            void ProjectSwChanged();
            void NameChanged();
			void NaturalNameChanged();

		};
	}
}