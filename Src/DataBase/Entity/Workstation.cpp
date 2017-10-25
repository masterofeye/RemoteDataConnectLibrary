#include "Workstation.h"
#include "Workstation_p.h"
#include "User.h"
#include "ElementConfiguration.h"
#include "Project.h"
#include "WorkstationType.h"
#include "Peripheral.h"
#include "WorkstationSetting.h"
#include "WorkstationType.h"
#include "PermanentLoginReason.h"

namespace RW{
	namespace SQL{

		WorkstationPrivate::WorkstationPrivate(Workstation *Parent) :
			QObject(Parent),
			q_ptr(Parent),
			m_Hostname(""),
			m_Mac(""),
			m_Ip(""),
			m_User(nullptr),
            m_WorkstationSetting(nullptr),
            m_Type(nullptr),
			m_State(RW::WorkstationState::OFF),
			m_ElementConfiguration(),
			m_Project(nullptr),
            m_Reason(nullptr),
            m_PermanentLogin(false),
            m_MaxPermamentLogin(QDateTime(QDate::currentDate(), QTime(23,59,0,0)))
		{
		}

		WorkstationPrivate::~WorkstationPrivate()
		{
			//Es sollte sichergestellt werden, dass alle Elementconfigurationen gelöscht werden in der Liste, die die Workstations pflegt. 
			//Weiterhin kann es aber vorkommen, dass zwei verschiedene Workstationobjekte die gleichen Kinder referenzieren. Deswegen 
			//wird hier überprüft ob die Elementkonfigurationen schon gelöscht wurden und nur noch die Objekte aus der Liste entfernt werden müssen
			for each (auto var in m_ElementConfiguration)
			{
				if (var != nullptr)
				{
					delete var;
					var = nullptr;
				}
			}
		
			m_ElementConfiguration.clear();
		}

		Workstation::Workstation(Entity *Parent) : Entity(Parent),
			d_ptr(new WorkstationPrivate(this))
		{
		}

		Workstation::Workstation(Workstation &&R) : d_ptr(R.d_ptr)
		{
			d_ptr->setParent(this);
            SetID(R.ID());
			R.d_ptr = nullptr;
		}

		Workstation& Workstation::operator=(Workstation &&R)
		{
			std::swap(d_ptr, R.d_ptr);
			d_ptr->setParent(this);
            SetID(R.ID());
			delete R.d_ptr;
			R.d_ptr = nullptr;
			return *this;
		}


		Workstation::Workstation(const Workstation &R)
		{
			if (&R != nullptr)
			{

				d_ptr = new WorkstationPrivate(this);
                d_ptr->m_PermanentLogin = R.d_ptr->m_PermanentLogin;
                if (R.d_ptr->m_Reason != nullptr)
                {
                    if (d_ptr->m_Reason == nullptr)
                    {
                        d_ptr->m_Reason = new PermanentLoginReason(*R.d_ptr->m_Reason);
                    }
                    else
                    {
                        *d_ptr->m_Reason = *R.d_ptr->m_Reason;
                    }
                }
                d_ptr->m_MaxPermamentLogin = R.d_ptr->m_MaxPermamentLogin;
				d_ptr->m_Hostname = R.d_ptr->m_Hostname;
				d_ptr->m_Mac = R.d_ptr->m_Mac;
				d_ptr->m_Ip = R.d_ptr->m_Ip;
				if (R.d_ptr->m_User != nullptr)
				{
					if (d_ptr->m_User == nullptr)
					{
						d_ptr->m_User = new User(*R.d_ptr->m_User);
					}
					else
					{
						*d_ptr->m_User = *R.d_ptr->m_User;
					}
				}
				d_ptr->m_State = R.d_ptr->m_State;
				if (R.d_ptr->m_Project != nullptr)
				{
					if (d_ptr->m_Project == nullptr)
					{
						d_ptr->m_Project = new Project(*R.d_ptr->m_Project);
					}
					else
					{
						*d_ptr->m_Project = *R.d_ptr->m_Project;
					}
				}

                if (R.d_ptr->m_WorkstationSetting != nullptr)
                {
                    if (d_ptr->m_WorkstationSetting == nullptr)
                    {
                        d_ptr->m_WorkstationSetting = new WorkstationSetting(*R.d_ptr->m_WorkstationSetting);
                    }
                    else
                    {
                        *d_ptr->m_WorkstationSetting = *R.d_ptr->m_WorkstationSetting;
                    }
                }

                if (R.d_ptr->m_Type != nullptr)
                {
                    if (d_ptr->m_Type == nullptr)
                    {
                        d_ptr->m_Type = new WorkstationType(*R.d_ptr->m_Type);
                    }
                    else
                    {
                        *d_ptr->m_Type = *R.d_ptr->m_Type;
                    }
                }

				//Deep Copy of all Elements!
				for each (auto var in R.d_ptr->m_ElementConfiguration)
				{
					ElementConfiguration *el = new ElementConfiguration();
					*el = *var;
					d_ptr->m_ElementConfiguration.append(el);
				}
                SetID(R.ID());
			}
		}

		Workstation& Workstation::operator=(const Workstation &R)
		{
			if (&R != nullptr)
			{
				d_ptr = new WorkstationPrivate(this);
                d_ptr->m_PermanentLogin = R.d_ptr->m_PermanentLogin;
                if (R.d_ptr->m_Reason != nullptr)
                {
                    if (d_ptr->m_Reason == nullptr)
                    {
                        d_ptr->m_Reason = new PermanentLoginReason(*R.d_ptr->m_Reason);
                    }
                    else
                    {
                        *d_ptr->m_Reason = *R.d_ptr->m_Reason;
                    }
                }
                
                d_ptr->m_MaxPermamentLogin = R.d_ptr->m_MaxPermamentLogin;
                d_ptr->m_Hostname = R.d_ptr->m_Hostname;
                d_ptr->m_Mac = R.d_ptr->m_Mac;
                d_ptr->m_Ip = R.d_ptr->m_Ip;
                if (R.d_ptr->m_User != nullptr)
                {
                    if (d_ptr->m_User == nullptr)
                    {
                        d_ptr->m_User = new User(*R.d_ptr->m_User);
                    }
                    else
                    {
                        *d_ptr->m_User = *R.d_ptr->m_User;
                    }
                }
                d_ptr->m_State = R.d_ptr->m_State;
                if (R.d_ptr->m_Project != nullptr)
                {
                    if (d_ptr->m_Project == nullptr)
                    {
                        d_ptr->m_Project = new Project(*R.d_ptr->m_Project);
                    }
                    else
                    {
                        *d_ptr->m_Project = *R.d_ptr->m_Project;
                    }
                }

                if (R.d_ptr->m_WorkstationSetting != nullptr)
                {
                    if (d_ptr->m_WorkstationSetting == nullptr)
                    {
                        d_ptr->m_WorkstationSetting = new WorkstationSetting(*R.d_ptr->m_WorkstationSetting);
                    }
                    else
                    {
                        *d_ptr->m_WorkstationSetting = *R.d_ptr->m_WorkstationSetting;
                    }
                }

                if (R.d_ptr->m_Type != nullptr)
                {
                    if (d_ptr->m_Type == nullptr)
                    {
                        d_ptr->m_Type = new WorkstationType(*R.d_ptr->m_Type);
                    }
                    else
                    {
                        *d_ptr->m_Type = *R.d_ptr->m_Type;
                    }
                }
				//Deep Copy of all Elements!
				for each (auto var in R.d_ptr->m_ElementConfiguration)
				{
					ElementConfiguration *el = new ElementConfiguration();
					*el = *var;
					d_ptr->m_ElementConfiguration.append(el);
				}
                SetID(R.ID());
			}
			return *this;
		}

		Workstation::~Workstation()
		{
        }

		QQmlListProperty<ElementConfiguration>  Workstation::ElementCfgQml()
		{
			Q_D( Workstation);
				
			return QQmlListProperty<ElementConfiguration>(this, d->m_ElementConfiguration);
		}

		QList<ElementConfiguration*> Workstation::ElementCfg() const
		{ 
			Q_D(const Workstation);
			return d->m_ElementConfiguration;
		}

		void Workstation::SetElementCfg(QList<ElementConfiguration*> ElementCfg)
		{
			Q_D(Workstation);
			d->m_ElementConfiguration = ElementCfg;
			emit ElementCfgChanged();
		}

		void Workstation::AddElementCfg(ElementConfiguration ElementCfg)
		{
			Q_D(Workstation);
			ElementConfiguration *tempEl = new ElementConfiguration();
			*tempEl = ElementCfg;
			d->m_ElementConfiguration.append(tempEl);
			emit ElementCfgChanged();
		}


		User* Workstation::CurrentUser() const
		{ 
			Q_D(const Workstation);
			return const_cast<User*>(d->m_User);
		}

		void Workstation::SetCurrentUser(User *CurrentUser)
		{
			Q_D(Workstation);
			if (CurrentUser != nullptr)
			{
				CurrentUser->setParent(d);
                if (d->m_User != nullptr)
                    delete d->m_User;

				d->m_User = CurrentUser;
				emit CurrentUserChanged();
			}
		}

		Project* Workstation::AssignedProject() const
		{
			Q_D(const Workstation);
			return d->m_Project ;
		}

		void Workstation::setAssignedProject(Project* Project)
		{
			Q_D(Workstation);
            if (Project != nullptr)
            {
                Project->setParent(d);
                if (d->m_Project != nullptr)
                    delete d->m_Project;

                d->m_Project = Project;
                emit ProjectChanged();
            }

		}

		QString Workstation::Hostname() const
		{ 
			Q_D(const Workstation);
			return d->m_Hostname;
		}
		
		void Workstation::SetHostname(QString Hostname)
		{ 
			Q_D(Workstation);
			d->m_Hostname = Hostname;
			emit HostnameChanged();
		}

		QString Workstation::Mac() const
		{
			Q_D(const Workstation);
			return d->m_Mac;
		}

		void Workstation::SetMac(QString Mac)
		{ 
			Q_D(Workstation);
			d->m_Mac = Mac;
			emit MacChanged();
		}

		QString Workstation::Ip() const
		{ 
			Q_D(const Workstation);
			return d->m_Ip;
		}

		void Workstation::SetIp(QString Ip)
		{ 
			Q_D(Workstation);
			d->m_Ip = Ip;
			emit IpChanged();
		}

		WorkstationState Workstation::State() const
		{
			Q_D(const Workstation);
			return d->m_State;
		}

		void Workstation::SetState(WorkstationState State)
		{
			Q_D(Workstation);
			d->m_State = State;
			emit StateChanged();
		}

        WorkstationType* Workstation::TypeOfWorkstation() const
        {
            Q_D(const Workstation);
            return d->m_Type;
        }
        
        void Workstation::SetTypeOfWorkstation(WorkstationType* Type)
        {
            Q_D(Workstation);
            if (Type != nullptr)
            {
                if (d->m_Type != nullptr)
                    delete d->m_Type;
                Type->setParent(d);
                d->m_Type = Type;
                emit TypeOfWorkstationChanged();
            }
        }

        QQmlListProperty<Peripheral> Workstation::PeripheralListQml()
        {
            Q_D(Workstation);
            
            return QQmlListProperty<Peripheral>(this, d->m_PeripheralList);
        }

        QList<Peripheral*> Workstation::PeripheralList() const
        {
            Q_D(const Workstation);
            return d->m_PeripheralList;
        }

        void Workstation::SetPeripheralList(QList<Peripheral*> ElementCfg)
        {
            Q_D(Workstation);
            d->m_PeripheralList = ElementCfg;
            emit PeripheralListQml();
        }

        void Workstation::AddPeripheral(Peripheral P)
        {
            Q_D(Workstation);
            Peripheral *tempEl = new Peripheral();
            *tempEl = P;
            d->m_PeripheralList.append(tempEl);
            emit PeripheralListQml();
        }

        WorkstationSetting* Workstation::SettingOfWorkstation() const
        {
            Q_D(const Workstation);
            return d->m_WorkstationSetting;
        }

        void Workstation::SetSettingOfWorkstation(WorkstationSetting* Setting)
        {
            Q_D(Workstation);
            if (Setting != nullptr)
            {
                if (d->m_WorkstationSetting != nullptr)
                    delete d->m_Type;
                Setting->setParent(d);
                d->m_WorkstationSetting = Setting;
                emit SettingOfWorkstationChanged();
            }
        }

        bool Workstation::PermanentLogin()
        {
            Q_D(Workstation);
            return d_ptr->m_PermanentLogin;
        }

        void Workstation::SetPermanentLogin(bool PermanentLogin)
        {
            Q_D(Workstation);
            d_ptr->m_PermanentLogin = PermanentLogin;
            emit PermanentLoginChanged();
        }

        PermanentLoginReason* Workstation::Reason()
        {
            Q_D(Workstation);
            return d_ptr->m_Reason;
        }

        void Workstation::SetReason(PermanentLoginReason* Reason)
        {
            Q_D(Workstation);
            d_ptr->m_Reason = Reason;
            emit ReasonChanged();
        }

        QDateTime Workstation::MaxPermanentLogin()
        {
            Q_D(Workstation);
            return d_ptr->m_MaxPermamentLogin;
        }

        void Workstation::SetMaxPermanentLogin(QDateTime PermanentLogin)
        {
            Q_D(Workstation);
            d_ptr->m_MaxPermamentLogin = PermanentLogin;
            emit MaxPermanentLoginChanged();
        }


	}
}
