#include "WorkstationSetting.h"
#include "WorkstationSetting_p.h"
#include "SQLGlobal.h"
#include "qdebug.h"
#include "PermanentLoginReason.h"

namespace RW{
	namespace SQL{

		WorkstationSettingPrivate::WorkstationSettingPrivate(WorkstationSetting *Parent) :
			QObject(Parent),
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

		WorkstationSetting::WorkstationSetting(const WorkstationSetting& other)
        {
            if (&other != nullptr)
            {
                d_ptr = new WorkstationSettingPrivate(this);
                SetID(other.ID());
            }


		}

		WorkstationSetting& WorkstationSetting::operator=(WorkstationSetting& other)
		{
            if (&other != nullptr)
            {
                d_ptr = new WorkstationSettingPrivate(this);

                SetID(other.ID());
            }
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


	}
}