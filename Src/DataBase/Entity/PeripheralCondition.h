#pragma once

#include "qobject.h"
#include "..\Global.h"
#include "Entity.h"
#include "QAbstractListModel"

namespace RW{
    enum class PeripheralType;
    enum class TypeOfElement;
    namespace SQL{
        class PeripheralConditionPrivate;


        /*!
        @brief Diese Klasse kapselt eine Einschaltbedingung für ein Gerät. Dabei können zwei Parameter (Port & Pin) angegeben werden,
        um bestimmte Ein- & Ausgänge zu schalten. Um auch invertierte Logigen abzubilden, gibt es den State. Diese Flag ermöglicht es
        dem zu schaltenden Gerät mitzuteilen, welchen Status der Ein- oder Ausgang annehmen soll.
        Weiterhin kann über TypeOfInformation angegeben werden, ob es sich, um eine Power- oder Datenleitung handelt, die geschalten werden soll.
        */
        class REMOTE_DATA_CONNECT_API PeripheralCondition :
            public Entity
        {
            Q_OBJECT
                Q_PROPERTY(QString Port READ Port WRITE SetPort NOTIFY PortChanged)
                Q_PROPERTY(QString Pin READ Pin WRITE SetPin NOTIFY PinChanged)
                Q_PROPERTY(quint8 TypeOfInformation READ TypeOfInformation WRITE SetTypeOfInformation NOTIFY TypeOfInformationChanged)
                Q_PROPERTY(bool State READ State WRITE SetState NOTIFY StateChanged)
                Q_PROPERTY(PeripheralType DeviceType READ DeviceType WRITE SetDeviceType NOTIFY DeviceTypeChanged)
                Q_PROPERTY(TypeOfElement TypeOfConnection READ TypeOfConnection WRITE SetTypeOfConnection NOTIFY TypeOfConnectionChanged)
        private:
            PeripheralConditionPrivate* d_ptr;
            Q_DECLARE_PRIVATE(PeripheralCondition);
        public:
            PeripheralCondition(QObject *Parent = nullptr);
            ~PeripheralCondition();
            PeripheralCondition(const PeripheralCondition &obj);
            PeripheralCondition& PeripheralCondition::operator=(const PeripheralCondition &obj);

            PeripheralCondition(PeripheralCondition &&rvalue);
            PeripheralCondition& PeripheralCondition::operator=(PeripheralCondition&& other);

            /*!
            @brief Erster Parameter für die Einschaltbedingung.
            @return Paremter für die Einschaltbedingung.
            */
            QString Port();
            void SetPort(QString Port);

            /*!
            @brief Zweiter Parameter für die Einschaltbedingung.
            @return Paremter für die Einschaltbedingung.
            */
            QString Pin();
            void SetPin(QString Pin);

            quint8 TypeOfInformation();
            void SetTypeOfInformation(quint8 TypeOfInformation);

            bool State();
            void SetState(bool State);

            PeripheralType DeviceType();
            void SetDeviceType(PeripheralType Type);
            
            TypeOfElement TypeOfConnection();
            void SetTypeOfConnection(TypeOfElement);


        signals:
            void PortChanged();
            void PinChanged();
            void StateChanged();
            void TypeOfInformationChanged();
            void DeviceTypeChanged();
            void TypeOfConnectionChanged();

        };

        class REMOTE_DATA_CONNECT_API PeripheralConditionList : public QAbstractListModel
        {
            Q_OBJECT
        public:
            explicit PeripheralConditionList(QObject *parent = 0);
            ~PeripheralConditionList();

            int rowCount(const QModelIndex& parent = QModelIndex()) const override;
            QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

            void AddData(PeripheralCondition* const Data);

        public slots:
            // Extra function to get the thing easily from outside Repeaters.
            PeripheralCondition* peripheralCondition(int idx);

        private:
            QList<PeripheralCondition*> mThings;
        };



    };
}
