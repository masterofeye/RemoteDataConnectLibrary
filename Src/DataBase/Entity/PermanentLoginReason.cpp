#include "PermanentLoginReason.h"
#include "PermanentLoginReason_p.h"
#include "SQLGlobal.h"
#include "qdebug.h"

namespace RW{
	namespace SQL{

		PermanentLoginReasonPrivate::PermanentLoginReasonPrivate(PermanentLoginReason *Parent) :
			QObject(Parent),
            m_Reason(""),
            m_Description(""),
			q_ptr(Parent)
		{
		}

		PermanentLoginReasonPrivate::~PermanentLoginReasonPrivate()
		{
		}

		PermanentLoginReason::PermanentLoginReason(QObject *Parent) : Entity(Parent),
			d_ptr(new PermanentLoginReasonPrivate(this))
		{
		}

		PermanentLoginReason::~PermanentLoginReason()
		{
		}

		PermanentLoginReason::PermanentLoginReason(const PermanentLoginReason& other)
		{
            if (&other != nullptr)
            {
                d_ptr = new PermanentLoginReasonPrivate(this);
                d_ptr->m_Reason = other.d_ptr->m_Reason;
                d_ptr->m_Description = other.d_ptr->m_Description;
                SetID(other.ID());
            }
		}

		PermanentLoginReason& PermanentLoginReason::operator=(PermanentLoginReason& other)
		{
            if (&other != nullptr)
            {
                d_ptr = new PermanentLoginReasonPrivate(this);
                d_ptr->m_Reason = other.d_ptr->m_Reason;
                d_ptr->m_Description = other.d_ptr->m_Description;
                SetID(other.ID());
            }
			return *this;
		}

		PermanentLoginReason::PermanentLoginReason(PermanentLoginReason&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
            SetID(other.ID());
			other.d_ptr = nullptr;

		}

		PermanentLoginReason& PermanentLoginReason::operator=(PermanentLoginReason&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
            SetID(other.ID());
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}


        QString PermanentLoginReason::Reason()
		{
			Q_D(PermanentLoginReason);
			return d_ptr->m_Reason;
		}

        void PermanentLoginReason::SetReason(QString PermanentLogin)
		{ 
			Q_D(PermanentLoginReason);
            d_ptr->m_Reason = PermanentLogin;
            emit ReasonChanged();
		}

        QString PermanentLoginReason::Description()
        {
            Q_D(PermanentLoginReason);
            return d_ptr->m_Description;
        }

        void PermanentLoginReason::SetDescription(QString Description)
        {
            Q_D(PermanentLoginReason);
            d_ptr->m_Description = Description;
            emit DescriptionChanged();
        }
	}
}