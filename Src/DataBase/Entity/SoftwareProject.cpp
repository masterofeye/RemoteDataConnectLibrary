#include "SoftwareProject.h"
#include "SoftwareProject_p.h"

#include "Project.h"

namespace RW{
	namespace SQL{

        SoftwareProjectPrivate::SoftwareProjectPrivate(SoftwareProject *Parent) :
            QObject(Parent),
            q_ptr(Parent),
            m_Project(nullptr),
            m_Name("")
        {
        }

        SoftwareProjectPrivate::~SoftwareProjectPrivate()
        {

        }

        SoftwareProject::SoftwareProject(Entity *Parent) : Entity(Parent),
            d_ptr(new SoftwareProjectPrivate(this))
        {
        }


        SoftwareProject::~SoftwareProject()
		{
		}

        SoftwareProject::SoftwareProject(SoftwareProject &&R) : d_ptr(R.d_ptr)
        {
            d_ptr->setParent(this);
            SetID(R.ID());
            R.d_ptr = nullptr;
        }

        SoftwareProject& SoftwareProject::operator=(SoftwareProject &&R)
        {
            std::swap(d_ptr, R.d_ptr);
            d_ptr->setParent(this);
            SetID(R.ID());
            delete R.d_ptr;
            R.d_ptr = nullptr;
            return *this;
        }


        SoftwareProject::SoftwareProject(const SoftwareProject &F)
        {
            if (&F != nullptr)
            {
                d_ptr = new SoftwareProjectPrivate(this);
                if (F.d_ptr->m_Project != nullptr)
                {
                    if (d_ptr->m_Project == nullptr)
                    {
                        d_ptr->m_Project = new Project(*F.d_ptr->m_Project);
                    }
                    else
                    {
                        *d_ptr->m_Project = *F.d_ptr->m_Project;
                    }
                }

                d_ptr->m_Name = F.d_ptr->m_Name;
                SetID(F.ID());
            }
        }

        SoftwareProject& SoftwareProject::operator=(const SoftwareProject &F)
        {
            if (&F != nullptr)
            {
                d_ptr = new SoftwareProjectPrivate(this);
                if (F.d_ptr->m_Project != nullptr)
                {
                    if (d_ptr->m_Project == nullptr)
                    {
                        d_ptr->m_Project = new Project(*F.d_ptr->m_Project);
                    }
                    else
                    {
                        *d_ptr->m_Project = *F.d_ptr->m_Project;
                    }
                }

                d_ptr->m_Name = F.d_ptr->m_Name;
                SetID(F.ID());
            }
            return *this;
        }



        Project* SoftwareProject::ProjectSw() const
        {
            Q_D(const SoftwareProject);
            return const_cast<Project*>(d->m_Project);
        }


        void SoftwareProject::SetProjectSw(Project* Project)
        {
            Q_D(SoftwareProject);
            if (Project != nullptr)
            {
                if (d->m_Project != nullptr)
                    delete d->m_Project;

                Project->setParent(d);
                d->m_Project = Project;
                emit ProjectSwChanged();
            }
        }

        QString SoftwareProject::Name() const
        {
            Q_D(const SoftwareProject);
            return d->m_Name;
        }

        void SoftwareProject::SetName(QString Name)
        {
            Q_D(SoftwareProject);
            d->m_Name = Name;
            emit NameChanged();
        }
	}
}