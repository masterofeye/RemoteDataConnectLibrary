#include "WorkstationType.h"
#include "WorkstationType_p.h"
#include "SQLGlobal.h"

namespace RW{
	namespace SQL{

        WorkstationTypePrivate::WorkstationTypePrivate(WorkstationType* Parent) :
			QObject(Parent),
			q_ptr(Parent),
            m_Type(RW::WorkstationKind::NON)
		{
		}

        WorkstationTypePrivate::~WorkstationTypePrivate()
		{
		}

        WorkstationType::WorkstationType(const  WorkstationType& other)
		{
			if (&other != nullptr)
			{
                d_ptr = new WorkstationTypePrivate(this);
                d_ptr->m_Type = other.d_ptr->m_Type;
                SetID(other.ID());
			}
		}
        WorkstationType&  WorkstationType::operator=(WorkstationType& other)
		{
			if (&other != nullptr)
			{
                d_ptr = new WorkstationTypePrivate(this);
                d_ptr->m_Type = other.d_ptr->m_Type;
                SetID(other.ID());
			}
			return *this;
		}


        WorkstationType::WorkstationType(WorkstationType&& other) : d_ptr(other.d_ptr)
		{

			d_ptr->setParent(this);
            SetID(other.ID());
			other.d_ptr = nullptr;
		}

        WorkstationType& WorkstationType::operator=(WorkstationType&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
            SetID(other.ID());
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}

        WorkstationType::WorkstationType(QObject *Parent) : Entity(Parent),
            d_ptr(new WorkstationTypePrivate(this))
		{
		}


        WorkstationType::~WorkstationType()
		{
		}


        RW::WorkstationKind WorkstationType::Type() const
		{
            Q_D(const WorkstationType);
			return d->m_Type;
		}

        void  WorkstationType::SetType(RW::WorkstationKind Type)
		{
            Q_D(WorkstationType);
            d->m_Type = Type;
            emit TypeChanged();
		}
	}
}