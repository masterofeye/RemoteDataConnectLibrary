#include "FlashHistory.h"
#include "FlashHistory_p.h"

#include "User.h"
#include "SoftwareProject.h"
#include "Workstation.h"


namespace RW{
	namespace SQL{

        FlashHistoryPrivate::FlashHistoryPrivate(FlashHistory *Parent) :
            QObject(Parent),
            q_ptr(Parent),
            m_User(nullptr),
            m_Workstation(nullptr),
            m_SoftwareProject(nullptr),
            m_Major(0),
            m_Minor(0),
            m_PatchLevel(0),
            m_Buildnumber(0),
            m_Date(QDate::currentDate())
        {
        }

        FlashHistoryPrivate::~FlashHistoryPrivate()
        {

        }

        FlashHistory::FlashHistory(Entity *Parent) : Entity(Parent),
            d_ptr(new FlashHistoryPrivate(this))
        {
        }


		FlashHistory::~FlashHistory()
		{
		}

        FlashHistory::FlashHistory(FlashHistory &&R) : d_ptr(R.d_ptr)
        {
            d_ptr->setParent(this);
            R.d_ptr = nullptr;
        }

        FlashHistory& FlashHistory::operator=(FlashHistory &&R)
        {
            std::swap(d_ptr, R.d_ptr);
            d_ptr->setParent(this);
            delete R.d_ptr;
            R.d_ptr = nullptr;
            return *this;
        }


        FlashHistory::FlashHistory(const FlashHistory &F)
        {
            if (&F != nullptr)
            {
                d_ptr = new FlashHistoryPrivate(this);
                if (F.d_ptr->m_User != nullptr)
                {
                    if (d_ptr->m_User == nullptr)
                    {
                        d_ptr->m_User = new User(*F.d_ptr->m_User);
                    }
                    else
                    {
                        *d_ptr->m_User = *F.d_ptr->m_User;
                    }
                }

                if (F.d_ptr->m_SoftwareProject != nullptr)
                {
                    if (d_ptr->m_SoftwareProject == nullptr)
                    {
                        d_ptr->m_SoftwareProject = new SoftwareProject(*F.d_ptr->m_SoftwareProject);
                    }
                    else
                    {
                        *d_ptr->m_SoftwareProject = *F.d_ptr->m_SoftwareProject;
                    }
                }

                if (F.d_ptr->m_Workstation != nullptr)
                {
                    if (d_ptr->m_Workstation == nullptr)
                    {
                        d_ptr->m_Workstation = new Workstation(*F.d_ptr->m_Workstation);
                    }
                    else
                    {
                        *d_ptr->m_Workstation = *F.d_ptr->m_Workstation;
                    }
                }


                d_ptr->m_Major = F.d_ptr->m_Major;
                d_ptr->m_Minor = F.d_ptr->m_Minor;
                d_ptr->m_PatchLevel = F.d_ptr->m_PatchLevel;
                d_ptr->m_Buildnumber = F.d_ptr->m_Buildnumber;
                d_ptr->m_Date = F.d_ptr->m_Date;

            }
        }

        FlashHistory& FlashHistory::operator=(const FlashHistory &F)
        {
            if (&F != nullptr)
            {
                d_ptr = new FlashHistoryPrivate(this);
                if (F.d_ptr->m_User != nullptr)
                {
                    if (d_ptr->m_User == nullptr)
                    {
                        d_ptr->m_User = new User(*F.d_ptr->m_User);
                    }
                    else
                    {
                        *d_ptr->m_User = *F.d_ptr->m_User;
                    }
                }

                if (F.d_ptr->m_SoftwareProject != nullptr)
                {
                    if (d_ptr->m_SoftwareProject == nullptr)
                    {
                        d_ptr->m_SoftwareProject = new SoftwareProject(*F.d_ptr->m_SoftwareProject);
                    }
                    else
                    {
                        *d_ptr->m_SoftwareProject = *F.d_ptr->m_SoftwareProject;
                    }
                }

                if (F.d_ptr->m_Workstation != nullptr)
                {
                    if (d_ptr->m_Workstation == nullptr)
                    {
                        d_ptr->m_Workstation = new Workstation(*F.d_ptr->m_Workstation);
                    }
                    else
                    {
                        *d_ptr->m_Workstation = *F.d_ptr->m_Workstation;
                    }
                }


                d_ptr->m_Major = F.d_ptr->m_Major;
                d_ptr->m_Minor = F.d_ptr->m_Minor;
                d_ptr->m_PatchLevel = F.d_ptr->m_PatchLevel;
                d_ptr->m_Buildnumber = F.d_ptr->m_Buildnumber;
                d_ptr->m_Date = F.d_ptr->m_Date;

            }
            return *this;
        }



        User* FlashHistory::UserHistory() const
        {
            Q_D(const FlashHistory);
            return const_cast<User*>(d->m_User);
        }


        void FlashHistory::SetUserHistory(User* User)
        {
            Q_D(FlashHistory);
            if (User != nullptr)
            {
                if (d->m_User != nullptr)
                    delete  d->m_User;

                User->setParent(d);
                d->m_User = User;
                emit UserHistoryChanged();
            }
        }

        SoftwareProject* FlashHistory::SoftwareProjectHistory() const
        {
            Q_D(const FlashHistory);
            return d->m_SoftwareProject;
        }

        void FlashHistory::SetSoftwareProjectHistory(SoftwareProject* SoftwareProject)
        {
            Q_D(FlashHistory);
            if (SoftwareProject != nullptr)
            {
                if (d->m_SoftwareProject != nullptr)
                    delete  d->m_SoftwareProject;

                SoftwareProject->setParent(d);
                d->m_SoftwareProject = SoftwareProject;
                emit SoftwareProjectHistoryChanged();
            }
        }

        Workstation* FlashHistory::WorkstationHistory() const
        {
            Q_D(const FlashHistory);
            return d->m_Workstation;
        }

        void FlashHistory::SetWorkstationHistory(Workstation* Workstation)
        {
            Q_D(FlashHistory);
            if (Workstation != nullptr)
            {
                if (d->m_Workstation != nullptr)
                    delete  d->m_Workstation;

                Workstation->setParent(d);
                d->m_Workstation = Workstation;
                emit WorkstationHistoryChanged();
            }
        }

        QVariant FlashHistory::Major() const
        {
            Q_D(const FlashHistory);
            return d->m_Major;
        }

        void FlashHistory::SetMajor(QVariant Major)
        {
            Q_D(FlashHistory);

            d->m_Major = Major;
            emit MajorChanged();
        }

        QVariant FlashHistory::Minor() const
        {
            Q_D(const FlashHistory);
            return d->m_Minor;
        }

        void FlashHistory::SetMinor(QVariant Minor)
        {
            Q_D(FlashHistory);

            d->m_Minor = Minor;
            emit MinorChanged();
        }

        QVariant FlashHistory::PatchLevel() const
        {
            Q_D(const FlashHistory);
            return d->m_PatchLevel;
        }
        void FlashHistory::SetPatchLevel(QVariant PatchLevel)
        {
            Q_D(FlashHistory);

            d->m_PatchLevel = PatchLevel;
            emit PatchLevelChanged();
        }

        QVariant FlashHistory::Buildnumber() const 
        {
            Q_D(const FlashHistory);
            return d->m_Buildnumber;
        }
        void FlashHistory::SetBuildnumber(QVariant Buildnumber)
        {
            Q_D(FlashHistory);

            d->m_Buildnumber = Buildnumber;
            emit BuildnumberChanged();
        }

        QDateTime FlashHistory::Date() const
        {
            Q_D(const FlashHistory);
            return d->m_Date;
        }

        void FlashHistory::SetDate(QDateTime Date)
        {
            Q_D(FlashHistory);

            d->m_Date = Date;
            emit DateChanged();
        }


	}
}