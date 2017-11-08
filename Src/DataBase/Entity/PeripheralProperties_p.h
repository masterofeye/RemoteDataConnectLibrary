#pragma once
#include <qobject.h>
#include "SQLGlobal.h"
#include <QTime>
#include <qvariant.h>

namespace RW{
    namespace SQL{

        class PeripheralProperties;
        class PeripheralPropertiesPrivate : public QObject
        {
            Q_OBJECT
                Q_DISABLE_COPY(PeripheralPropertiesPrivate)
                Q_DECLARE_PUBLIC(PeripheralProperties)
        public:
            QVariant m_Property1;
            QVariant m_Property2;
            QVariant m_Property3;
            QVariant m_Property4;
            QVariant m_Property5;
        private:
            PeripheralProperties * const q_ptr;
        public:
            PeripheralPropertiesPrivate(PeripheralProperties *Parent);
            ~PeripheralPropertiesPrivate();

        };
    }
}