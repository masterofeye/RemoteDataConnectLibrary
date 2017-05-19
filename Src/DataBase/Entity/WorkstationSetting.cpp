#include "WorkstationSetting.h"
#include "WorkstationSetting_p.h"
#include "SQLGlobal.h"
#include "qdebug.h"
#include "PermanentLoginReason.h"

namespace RW{
	namespace SQL{

		WorkstationSettingPrivate::WorkstationSettingPrivate(WorkstationSetting *Parent) :
			QObject(Parent),
            m_PermanentLogin(false),
			q_ptr(Parent)
		{
		}

		WorkstationSettingPrivate::~WorkstationSettingPrivate()
		{
		}

		WorkstationSetting::WorkstationSetting(QObject *Parent) : Entity(Parent),
			d_ptr(new WorkstationSettingPrivate(this))
		{
		}

		WorkstationSetting::~WorkstationSetting()
		{
		}

		WorkstationSetting::WorkstationSetting(const WorkstationSetting& other) : d_ptr(new WorkstationSettingPrivate(this))
		{
            d_ptr->m_PermanentLogin = other.d_ptr->m_PermanentLogin;

		}

		WorkstationSetting& WorkstationSetting::operator=(WorkstationSetting& other)
		{
			std::swap(d_ptr, const_cast<WorkstationSettingPrivate*>(other.d_ptr));
			return *this;
		}

		WorkstationSetting::WorkstationSetting(WorkstationSetting&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
            SetID(other.ID());
			other.d_ptr = nullptr;

		}

		WorkstationSetting& WorkstationSetting::operator=(WorkstationSetting&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
            SetID(other.ID());
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}


        bool WorkstationSetting::PermanentLogin()
		{
			Q_D(WorkstationSetting);
			return d_ptr->m_PermanentLogin;
		}

        void WorkstationSetting::SetPermanentLogin(bool PermanentLogin)
		{ 
			Q_D(WorkstationSetting);
            d_ptr->m_PermanentLogin = PermanentLogin;
			emit d_ptr->PermanentLoginChanged();
		}

        PermanentLoginReason* WorkstationSetting::Reason()
        {
            Q_D(WorkstationSetting);
            return d_ptr->m_Reason;
        }

        void WorkstationSetting::SetReason(PermanentLoginReason* Reason)
        {
            Q_D(WorkstationSetting);
            d_ptr->m_Reason = Reason;
            emit ReasonChanged();
        }
	}
}