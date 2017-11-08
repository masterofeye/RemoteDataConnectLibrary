#pragma once
#include "Entity.h"
#include <QTime>

namespace RW{
    namespace SQL{

        class PeripheralPropertiesPrivate;
        class REMOTE_DATA_CONNECT_API PeripheralProperties :
            public Entity
        {
            Q_OBJECT
            Q_PROPERTY(QVariant Property1 READ Property1 WRITE SetProperty1 NOTIFY Property1Changed)
            Q_PROPERTY(QVariant Property2 READ Property2 WRITE SetProperty2 NOTIFY Property1Changed)
            Q_PROPERTY(QVariant Property3 READ Property3 WRITE SetProperty3 NOTIFY Property1Changed)
            Q_PROPERTY(QVariant Property4 READ Property4 WRITE SetProperty4 NOTIFY Property1Changed)
            Q_PROPERTY(QVariant Property5 READ Property5 WRITE SetProperty5 NOTIFY Property1Changed)
            Q_CLASSINFO("Version", "0.0.1")

        private:
            PeripheralPropertiesPrivate *d_ptr;
            Q_DECLARE_PRIVATE(PeripheralProperties);
        public:
            PeripheralProperties(QObject *Parent = nullptr);
            ~PeripheralProperties();

            PeripheralProperties(const PeripheralProperties& other);
            PeripheralProperties& PeripheralProperties::operator=(PeripheralProperties& other);

            PeripheralProperties(PeripheralProperties&& other);
            PeripheralProperties& PeripheralProperties::operator=(PeripheralProperties&& other);

            QVariant Property1();
            void SetProperty1(QVariant);

            QVariant Property2();
            void SetProperty2(QVariant);

            QVariant Property3();
            void SetProperty3(QVariant);

            QVariant Property4();
            void SetProperty4(QVariant);

            QVariant Property5();
            void SetProperty5(QVariant);


        signals:
            void Property1Changed();
            void Property2Changed();
            void Property3Changed();
            void Property4Changed();
            void Property5Changed();

        };
    }
}
Q_DECLARE_METATYPE(RW::SQL::PeripheralProperties)