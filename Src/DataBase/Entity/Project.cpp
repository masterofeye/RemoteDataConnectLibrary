#include "Project.h"
#include "Project_p.h"

#include "qdebug.h"
namespace RW{
	namespace SQL{

		ProjectPrivate::ProjectPrivate(Project* Parent) :
			QObject(Parent),
			q_ptr(Parent),
			m_ProjectName("")
		{
		}

		ProjectPrivate::~ProjectPrivate()
		{
		}

		Project::Project(const Project& other)
		{
			if (&other != nullptr)
			{
				d_ptr = new ProjectPrivate(this);
				d_ptr->m_ProjectName = other.d_ptr->m_ProjectName;
                SetID(other.ID());
			}
 
		}
		Project& Project::operator=(Project& other) 
		{
			if (&other != nullptr)
			{
				d_ptr = new ProjectPrivate(this);
				d_ptr->m_ProjectName = other.d_ptr->m_ProjectName;
                SetID(other.ID());
			}
			return *this;
		}


		Project::Project(Project&& other) : d_ptr(other.d_ptr)
		{

			d_ptr->setParent(this);
            SetID(other.ID());
			other.d_ptr = nullptr;
		}

		Project& Project::operator=(Project&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
            SetID(other.ID());
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}

		Project::Project(QObject *Parent) : Entity(Parent),
		d_ptr(new ProjectPrivate(this))
		{
		}


		Project::~Project()
		{
		}


		QString Project::Projectname() const
		{
			Q_D(const Project);
			return d->m_ProjectName;
		}

		void Project::SetProjectname(QString Projectname)
		{
			Q_D(Project);
			d->m_ProjectName = Projectname;
			emit ProjectnameChanged();
		}
	}
}