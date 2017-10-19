#include "PeripheralCondition.h"
#include "PeripheralCondition_p.h"
#include "qdebug.h"
#include "../SQLGlobal.h"
#include "Peripheral.h"

namespace RW{
	namespace SQL{


		PeripheralConditionPrivate::PeripheralConditionPrivate(PeripheralCondition *Parent) :
			QObject(Parent),
            m_Port(""),
            m_Pin(""),
            m_TypeOfInformation(0),
            m_State(true),
			q_ptr(Parent),
            m_DeviceType(RW::PeripheralType::MaxAmount),
            m_Peripheral(nullptr)
		{
		}

		PeripheralConditionPrivate::~PeripheralConditionPrivate()
		{
            for each (auto var in m_FollowUpCondition)
            {
                if (var != nullptr)
                {
                    delete var;
                    var = nullptr;
                }
            }
            m_FollowUpCondition.clear();
		}

		PeripheralCondition::PeripheralCondition(QObject *Parent) : Entity(Parent),
			d_ptr(new PeripheralConditionPrivate(this))
		{
		}


		PeripheralCondition::~PeripheralCondition()
		{
		}

        PeripheralCondition::PeripheralCondition(PeripheralCondition &&R) : d_ptr(R.d_ptr)
        {
            d_ptr->setParent(this);
            SetID(R.ID());
            R.d_ptr = nullptr;
        }

        PeripheralCondition& PeripheralCondition::operator=(PeripheralCondition &&R)
        {
            std::swap(d_ptr, R.d_ptr);
            d_ptr->setParent(this);
            SetID(R.ID());
            delete R.d_ptr;
            R.d_ptr = nullptr;
            return *this;
        }


        PeripheralCondition::PeripheralCondition(const PeripheralCondition &F)
        {
            if (&F != nullptr)
            {
                d_ptr = new PeripheralConditionPrivate(this);
                if (F.d_ptr->m_Peripheral != nullptr)
                {
                    if (d_ptr->m_Peripheral == nullptr)
                    {
                        d_ptr->m_Peripheral = new Peripheral(*F.d_ptr->m_Peripheral);
                    }
                    else
                    {
                        *d_ptr->m_Peripheral = *F.d_ptr->m_Peripheral;
                    }
                }
                d_ptr->m_Priority = F.d_ptr->m_Priority;
                d_ptr->m_Port = F.d_ptr->m_Port;
                d_ptr->m_Pin = F.d_ptr->m_Pin;
                d_ptr->m_State = F.d_ptr->m_State;
                d_ptr->m_TypeOfInformation = F.d_ptr->m_TypeOfInformation;
                d_ptr->m_DeviceType = F.d_ptr->m_DeviceType;
                d_ptr->m_TypeOfConnection = F.d_ptr->m_TypeOfConnection;
                for each (auto var in F.d_ptr->m_FollowUpCondition)
                {
                    d_ptr->m_FollowUpCondition.append(new RW::SQL::PeripheralCondition(*var));
                }
                SetID(F.ID());
            }
        }

        PeripheralCondition& PeripheralCondition::operator=(const PeripheralCondition &F)
        {
            if (&F != nullptr)
            {
                d_ptr = new PeripheralConditionPrivate(this);
                if (F.d_ptr->m_Peripheral != nullptr)
                {
                    if (d_ptr->m_Peripheral == nullptr)
                    {
                        d_ptr->m_Peripheral = new Peripheral(*F.d_ptr->m_Peripheral);
                    }
                    else
                    {
                        *d_ptr->m_Peripheral = *F.d_ptr->m_Peripheral;
                    }
                }
                d_ptr->m_Priority = F.d_ptr->m_Priority;
                d_ptr->m_Port = F.d_ptr->m_Port;
                d_ptr->m_Pin = F.d_ptr->m_Pin;
                d_ptr->m_State = F.d_ptr->m_State;
                d_ptr->m_TypeOfInformation = F.d_ptr->m_TypeOfInformation;
                d_ptr->m_DeviceType = F.d_ptr->m_DeviceType;
                d_ptr->m_TypeOfConnection = F.d_ptr->m_TypeOfConnection;

                for each (auto var in F.d_ptr->m_FollowUpCondition)
                {
                    d_ptr->m_FollowUpCondition.append(new RW::SQL::PeripheralCondition(*var));
                }

                SetID(F.ID());
            }
            return *this;
        }

        RW::SQL::Peripheral* PeripheralCondition::ConditionPeripheral()
        {
            Q_D(const PeripheralCondition);
            return d->m_Peripheral;
        }

        void PeripheralCondition::SetConditionPeripheral(RW::SQL::Peripheral* P)
        {
            Q_D(PeripheralCondition);
            if (P != nullptr)
            {
                P->setParent(d);
                if (d->m_Peripheral != nullptr)
                    delete d->m_Peripheral;

                d->m_Peripheral = P;
                emit ConditionPeripheralChanged();
            }
        }

        quint8 PeripheralCondition::Priority()
        {
            Q_D(const PeripheralCondition);
            return d->m_Priority;
        }

        void PeripheralCondition::SetPriority(quint8 Priority)
        {
            Q_D(PeripheralCondition);
            d->m_Priority = Priority;
            emit PriorityChanged();
        }

        QString PeripheralCondition::Port()       
        {
            Q_D(const PeripheralCondition);
            return d->m_Port;
        }
        void PeripheralCondition::SetPort(QString Port)
        {
            Q_D(PeripheralCondition);
            d->m_Port = Port;
            emit PortChanged();
        }

        QString PeripheralCondition::Pin()
        {
            Q_D(const PeripheralCondition);
            return d->m_Pin;
        }
        void PeripheralCondition::SetPin(QString Pin)
        {
            Q_D(PeripheralCondition);
            d->m_Pin = Pin;
            emit PinChanged();
        }

        quint8 PeripheralCondition::TypeOfInformation()
        {
            Q_D(const PeripheralCondition);
            return d->m_TypeOfInformation;
        }
        void PeripheralCondition::SetTypeOfInformation(quint8 TypeOfInformation)
        {
            Q_D(PeripheralCondition);
            d->m_TypeOfInformation = TypeOfInformation;
            emit TypeOfInformationChanged();
        }

        bool PeripheralCondition::State()
        {
            Q_D(const PeripheralCondition);
            return d->m_State;
        }
        void PeripheralCondition::SetState(bool State)
        {
            Q_D(PeripheralCondition);
            d->m_State = State;
            emit StateChanged();
        }

        PeripheralType PeripheralCondition::DeviceType()
        {
            Q_D(const PeripheralCondition);
            return d->m_DeviceType;
        }

        void PeripheralCondition::SetDeviceType(PeripheralType Type)
        {
            Q_D(PeripheralCondition);
            d->m_DeviceType = Type;
            emit DeviceTypeChanged();
        }

        TypeOfElement PeripheralCondition::TypeOfConnection()
        {
            Q_D(const PeripheralCondition);
            return d->m_TypeOfConnection;
        }
        void PeripheralCondition::SetTypeOfConnection(TypeOfElement El)
        {
            Q_D(PeripheralCondition);
            d->m_TypeOfConnection = El;
            emit TypeOfConnectionChanged();
        }

        QList<PeripheralCondition*> PeripheralCondition::FollowUpCondition()
        {
            Q_D(const PeripheralCondition);
            return d->m_FollowUpCondition;
        }
        void PeripheralCondition::SetFollowUpCondition(QList<PeripheralCondition*> El)
        {
            Q_D(PeripheralCondition);

            d->m_FollowUpCondition = El;
            emit FollowUpConditionChanged();
        }

        QHostAddress PeripheralCondition::Ip()
        {
            Q_D(const PeripheralCondition);
            return d->m_Ip;
        }
        void PeripheralCondition::SetIp(QHostAddress El)
        {
            Q_D(PeripheralCondition);

            d->m_Ip = El;
            emit IpChanged();
        }


        void PeripheralCondition::SetFollowUpCondition(QList<PeripheralCondition> El)
        {
            Q_D(PeripheralCondition);

            for each (auto var in El)
            {
                d->m_FollowUpCondition.append(new PeripheralCondition(var));
            }

            emit FollowUpConditionChanged();
        }


        PeripheralConditionList::PeripheralConditionList(QObject *parent) : QAbstractListModel(parent)
        {
        
        }

        PeripheralConditionList::~PeripheralConditionList()
        {
            for (size_t i = 0; i < mThings.size(); i++)
            {
                if (mThings[i] != nullptr)
                {
                    delete mThings[i];
                    mThings[i] = nullptr;
                }
            }
            mThings.clear();
        }

        int PeripheralConditionList::rowCount(const QModelIndex& parent) const
        {
            return mThings.size();
        }

        QVariant PeripheralConditionList::data(const QModelIndex& index, int role) const
        {
            int i = index.row();
            if (i < 0 || i >= mThings.size())
                return QVariant(QVariant::Invalid);

            return QVariant::fromValue(mThings[i]);
        }

        PeripheralCondition* PeripheralConditionList::peripheralCondition(int idx)
        {
            if (idx < 0 || idx >= mThings.size())
                return nullptr;

            return mThings[idx];
        }

        void PeripheralConditionList::AddData(PeripheralCondition* const Data)
        {
            beginInsertRows(QModelIndex(), rowCount(), rowCount());

            mThings.append(Data);

            endInsertRows();
        }
	}
}