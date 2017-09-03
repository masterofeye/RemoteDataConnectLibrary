#include "PeripheralCondition.h"
#include "PeripheralCondition_p.h"
#include "qdebug.h"
#include "../SQLGlobal.h"

namespace RW{
	namespace SQL{


		PeripheralConditionPrivate::PeripheralConditionPrivate(PeripheralCondition *Parent) :
			QObject(Parent),
            m_Port(""),
            m_Pin(""),
            m_TypeOfInformation(0),
            m_State(true),
			q_ptr(Parent),
            m_DeviceType(RW::PeripheralType::MaxAmount)
		{
		}

		PeripheralConditionPrivate::~PeripheralConditionPrivate()
		{
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
                d_ptr->m_Port = F.d_ptr->m_Port;
                d_ptr->m_Pin = F.d_ptr->m_Pin;
                d_ptr->m_State = F.d_ptr->m_State;
                d_ptr->m_TypeOfInformation = F.d_ptr->m_TypeOfInformation;
                d_ptr->m_DeviceType = F.d_ptr->m_DeviceType;
                d_ptr->m_TypeOfConnection = F.d_ptr->m_TypeOfConnection;
                SetID(F.ID());
            }
        }

        PeripheralCondition& PeripheralCondition::operator=(const PeripheralCondition &F)
        {
            if (&F != nullptr)
            {
                d_ptr = new PeripheralConditionPrivate(this);
                d_ptr->m_Port = F.d_ptr->m_Port;
                d_ptr->m_Pin = F.d_ptr->m_Pin;
                d_ptr->m_State = F.d_ptr->m_State;
                d_ptr->m_TypeOfInformation = F.d_ptr->m_TypeOfInformation;
                d_ptr->m_DeviceType = F.d_ptr->m_DeviceType;
                d_ptr->m_TypeOfConnection = F.d_ptr->m_TypeOfConnection;
                SetID(F.ID());
            }
            return *this;
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


        PeripheralConditionList::PeripheralConditionList(QObject *parent) : QAbstractListModel(parent)
        {
        
        }

        PeripheralConditionList::~PeripheralConditionList()
        {
            for (size_t i = 0; i < mThings.size(); i++)
            {
                if (mThings[i] != nullptr)
                    delete mThings[i];
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