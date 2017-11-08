#include "PeripheralProperties.h"
#include "PeripheralProperties_p.h"

namespace RW{
    namespace SQL{

        PeripheralPropertiesPrivate::PeripheralPropertiesPrivate(PeripheralProperties* Parent) :
            QObject(Parent),
            q_ptr(Parent)
        {
        }

        PeripheralPropertiesPrivate::~PeripheralPropertiesPrivate()
        {
        }


        PeripheralProperties::PeripheralProperties(const PeripheralProperties& other)
        {
            if (&other != nullptr)
            {
                d_ptr = new PeripheralPropertiesPrivate(this);
                d_ptr->m_Property1 = other.d_ptr->m_Property1;
                d_ptr->m_Property2 = other.d_ptr->m_Property2;
                d_ptr->m_Property3 = other.d_ptr->m_Property3;
                d_ptr->m_Property4 = other.d_ptr->m_Property4;
                d_ptr->m_Property5 = other.d_ptr->m_Property5;
                SetID(other.ID());
            }
        }
        PeripheralProperties& PeripheralProperties::operator=(PeripheralProperties& other)
        {
            if (&other != nullptr)
            {
                d_ptr = new PeripheralPropertiesPrivate(this);
                d_ptr->m_Property1 = other.d_ptr->m_Property1;
                d_ptr->m_Property2 = other.d_ptr->m_Property2;
                d_ptr->m_Property3 = other.d_ptr->m_Property3;
                d_ptr->m_Property4 = other.d_ptr->m_Property4;
                d_ptr->m_Property5 = other.d_ptr->m_Property5;

                SetID(other.ID());
            }
            return *this;
        }


        PeripheralProperties::PeripheralProperties(PeripheralProperties&& other) : d_ptr(other.d_ptr)
        {
            if (&other != nullptr)
            {
                d_ptr->setParent(this);
                SetID(other.ID());
                other.d_ptr = nullptr;

            }
        }

        PeripheralProperties& PeripheralProperties::operator=(PeripheralProperties&& other)
        {
            if (&other != nullptr)
            {
                std::swap(d_ptr, other.d_ptr);
                d_ptr->setParent(this);

                SetID(other.ID());
                delete other.d_ptr;
                other.d_ptr = nullptr;

            }
            return *this;
        }

        PeripheralProperties::PeripheralProperties(QObject *Parent) : Entity(Parent),
            d_ptr(new PeripheralPropertiesPrivate(this))
        {
        }


        PeripheralProperties::~PeripheralProperties()
        {
        }


        QVariant PeripheralProperties::Property1()
        {
            Q_D(const PeripheralProperties);
            return d->m_Property1;
        }
        void PeripheralProperties::SetProperty1(QVariant Property1)
        {
            Q_D(PeripheralProperties);
            d->m_Property1 = Property1;
            emit Property1Changed();
        }

        QVariant PeripheralProperties::Property2()
        {
            Q_D(const PeripheralProperties);
            return d->m_Property2;
        }

        void PeripheralProperties::SetProperty2(QVariant Property2)
        {
            Q_D(PeripheralProperties);
            d->m_Property2 = Property2;
            emit Property2Changed();
        }

        QVariant PeripheralProperties::Property3()
        {
            Q_D(const PeripheralProperties);
            return d->m_Property3;
        }

        void PeripheralProperties::SetProperty3(QVariant Property3)
        {
            Q_D(PeripheralProperties);
            d->m_Property3 = Property3;
            emit Property3Changed();
        }

        QVariant PeripheralProperties::Property4()
        {
            Q_D(const PeripheralProperties);
            return d->m_Property4;
        }

        void PeripheralProperties::SetProperty4(QVariant Property4)
        {
            Q_D(PeripheralProperties);
            d->m_Property4 = Property4;
            emit Property4Changed();
        }

        QVariant PeripheralProperties::Property5()
        {
            Q_D(const PeripheralProperties);
            return d->m_Property5;
        }

        void PeripheralProperties::SetProperty5(QVariant Property5)
        {
            Q_D(PeripheralProperties);
            d->m_Property5 = Property5;
            emit Property5Changed();
        }



    }
}