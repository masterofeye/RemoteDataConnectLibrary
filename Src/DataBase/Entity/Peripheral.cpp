#include "Peripheral.h"
#include "Peripheral_p.h"

namespace RW{
    namespace SQL{

        PeripheralPrivate::PeripheralPrivate(Peripheral *Parent) :
            QObject(Parent),
            q_ptr(Parent)
        {
        }

        PeripheralPrivate::~PeripheralPrivate()
        {

        }

        Peripheral::Peripheral(Entity *Parent) : Entity(Parent),
            d_ptr(new PeripheralPrivate(this))
        {
        }


        Peripheral::~Peripheral()
        {
        }

        Peripheral::Peripheral(Peripheral &&R) : d_ptr(R.d_ptr)
        {
            d_ptr->setParent(this);
            SetID(R.ID());
            R.d_ptr = nullptr;
        }

        Peripheral& Peripheral::operator=(Peripheral &&R)
        {
            std::swap(d_ptr, R.d_ptr);
            d_ptr->setParent(this);
            SetID(R.ID());
            delete R.d_ptr;
            R.d_ptr = nullptr;
            return *this;
        }


        Peripheral::Peripheral(const Peripheral &F)
        {
            if (&F != nullptr)
            {
                d_ptr = new PeripheralPrivate(this);
                d_ptr->m_Address = F.d_ptr->m_Address;
                d_ptr->m_BusGUID = F.d_ptr->m_BusGUID;
                d_ptr->m_Busnummer = F.d_ptr->m_Busnummer;
                d_ptr->m_Class = F.d_ptr->m_Class;
                d_ptr->m_ClassGUID = F.d_ptr->m_ClassGUID;
                d_ptr->m_CompatibleID = F.d_ptr->m_CompatibleID;
                d_ptr->m_Description = F.d_ptr->m_Description;
                d_ptr->m_DeviceName = F.d_ptr->m_DeviceName;
                d_ptr->m_EnumeratorName = F.d_ptr->m_EnumeratorName;
                d_ptr->m_FriendlyName = F.d_ptr->m_FriendlyName;
                d_ptr->m_HardwareID = F.d_ptr->m_HardwareID;
                d_ptr->m_InstallState = F.d_ptr->m_InstallState;
                d_ptr->m_IsActivate = F.d_ptr->m_IsActivate;
                d_ptr->m_IsRegistered = F.d_ptr->m_IsRegistered;
                d_ptr->m_LocationInformation = F.d_ptr->m_LocationInformation;
                d_ptr->m_LocationPath = F.d_ptr->m_LocationPath;
                d_ptr->m_Manufacturer = F.d_ptr->m_Manufacturer;
                d_ptr->m_ServiceName = F.d_ptr->m_ServiceName;
                d_ptr->m_Type = F.d_ptr->m_Type;
                d_ptr->m_WindowsDeviceType = F.d_ptr->m_WindowsDeviceType;
                d_ptr->m_IsProvided = F.d_ptr->m_IsProvided;
                SetID(F.ID());
            }
        }

        Peripheral& Peripheral::operator=(const Peripheral &F)
        {
            if (&F != nullptr)
            {
                d_ptr = new PeripheralPrivate(this);

                d_ptr->m_Address = F.d_ptr->m_Address;
                d_ptr->m_BusGUID = F.d_ptr->m_BusGUID;
                d_ptr->m_Busnummer = F.d_ptr->m_Busnummer;
                d_ptr->m_Class = F.d_ptr->m_Class;
                d_ptr->m_ClassGUID = F.d_ptr->m_ClassGUID;
                d_ptr->m_CompatibleID = F.d_ptr->m_CompatibleID;
                d_ptr->m_Description = F.d_ptr->m_Description;
                d_ptr->m_DeviceName = F.d_ptr->m_DeviceName;
                d_ptr->m_EnumeratorName = F.d_ptr->m_EnumeratorName;
                d_ptr->m_FriendlyName = F.d_ptr->m_FriendlyName;
                d_ptr->m_HardwareID = F.d_ptr->m_HardwareID;
                d_ptr->m_InstallState = F.d_ptr->m_InstallState;
                d_ptr->m_IsActivate = F.d_ptr->m_IsActivate;
                d_ptr->m_IsRegistered = F.d_ptr->m_IsRegistered;
                d_ptr->m_LocationInformation = F.d_ptr->m_LocationInformation;
                d_ptr->m_LocationPath = F.d_ptr->m_LocationPath;
                d_ptr->m_Manufacturer = F.d_ptr->m_Manufacturer;
                d_ptr->m_ServiceName = F.d_ptr->m_ServiceName;
                d_ptr->m_Type = F.d_ptr->m_Type;
                d_ptr->m_WindowsDeviceType = F.d_ptr->m_WindowsDeviceType;
                d_ptr->m_IsProvided = F.d_ptr->m_IsProvided;
                SetID(F.ID());
            }
            return *this;
        }


        quint64 Peripheral::Address()
        {
            Q_D(const Peripheral);
            return d->m_Address;
        }
        void Peripheral::SetAddress(quint64 Address)
        {
            Q_D(Peripheral);
            d->m_Address = Address;
            emit AddressChanged();
        }

        QString Peripheral::LocationInformation()
        {
            Q_D(const Peripheral);
            return d->m_LocationInformation;
        }
        void Peripheral::SetLocationInformation(QString Info)
        {
            Q_D(Peripheral);
            d->m_LocationInformation = Info;
            emit LocationInformationChanged();
        }

        QString Peripheral::LocationPath()
        {
            Q_D(const Peripheral);
            return d->m_LocationPath;
        }
        void Peripheral::SetLocationPath(QString Path)
        {
            Q_D(Peripheral);
            d->m_LocationPath = Path;
            emit LocationPathChanged();
        }

        QString Peripheral::Description()
        {
            Q_D(const Peripheral);
            return d->m_Description;
        }
        void Peripheral::SetDescription(QString Description)
        {
            Q_D(Peripheral);
            d->m_Description = Description;
            emit DescriptionChanged();
        }

        QString Peripheral::DeviceName()
        {
            Q_D(const Peripheral);
            return d->m_DeviceName;
        }
        void Peripheral::SetDeviceName(QString Name)
        {
            Q_D(Peripheral);
            d->m_DeviceName = Name;
            emit DeviceNameChanged();
        }

        QStringList Peripheral::HardwareID()
        {
            Q_D(const Peripheral);
            return d->m_HardwareID;
        }
        void Peripheral::SetHardwareID(QStringList ID)
        {
            Q_D(Peripheral);
            d->m_HardwareID = ID;
            emit HardwareIDChanged();
        }

        QString Peripheral::FriendlyName()
        {
            Q_D(const Peripheral);
            return d->m_FriendlyName;
        }
        void Peripheral::SetFriendlyName(QString FriendlyName)
        {
            Q_D(Peripheral);
            d->m_FriendlyName = FriendlyName;
            emit FriendlyNameChanged();
        }

        quint64 Peripheral::Busnummer()
        {
            Q_D(const Peripheral);
            return d->m_Busnummer;
        }
        void Peripheral::SetBusnummer(quint64 Busnummer)
        {
            Q_D(Peripheral);
            d->m_Busnummer = Busnummer;
            emit BusnummerChanged();
        }

        QString Peripheral::BusGUID(){
            Q_D(const Peripheral);
            return d->m_BusGUID;
        }

        void Peripheral::SetBusGUID(QString BusGUID){
            Q_D(Peripheral);
            d->m_BusGUID = BusGUID;
            emit BusGUIDChanged();
        }

        QString Peripheral::Class(){
            Q_D(const Peripheral);
            return d->m_Class;
        }

        void Peripheral::SetClass(QString Class){
            Q_D(Peripheral);
            d->m_Class = Class;
            emit ClassChanged();
        }

        
        QString Peripheral::ClassGUID(){
            Q_D(const Peripheral);
            return d->m_ClassGUID;
        }

        void Peripheral::SetClassGUID(QString ClassGUID){
            Q_D(Peripheral);
            d->m_ClassGUID = ClassGUID;
            emit ClassGUIDChanged();
        }

        QStringList Peripheral::CompatibleID(){
            Q_D(const Peripheral);
            return d->m_CompatibleID;
        }

        void Peripheral::SetCompatibleID(QStringList CompatibleID){
            Q_D(Peripheral);
            d->m_CompatibleID = CompatibleID;
            emit CompatibleIDChanged();
        }

        quint16 Peripheral::WindowsDeviceType(){
            Q_D(const Peripheral);
            return d->m_WindowsDeviceType;
        }
        void Peripheral::SetWindowsDeviceType(quint16 WindowsDeviceType){
            Q_D(Peripheral);
            d->m_WindowsDeviceType = WindowsDeviceType;
            emit WindowsDeviceTypeChanged();
        }

        QString Peripheral::EnumeratorName(){
            Q_D(const Peripheral);
            return d->m_EnumeratorName;
        }

        void Peripheral::SetEnumeratorName(QString EnumeratorName){
            Q_D(Peripheral);
            d->m_EnumeratorName = EnumeratorName;
            emit EnumeratorNameChanged();
        }

        quint16 Peripheral::InstallState(){
            Q_D(const Peripheral);
            return d->m_InstallState;
        }

        void Peripheral::SetInstallState(quint16 InstallState){
            Q_D(Peripheral);
            d->m_InstallState = InstallState;
            emit InstallStateChanged();
        }

        QString Peripheral::Manufacturer(){
            Q_D(const Peripheral);
            return d->m_Manufacturer;
        }
        void Peripheral::SetManufacturer(QString Manufacturer){
            Q_D(Peripheral);
            d->m_Manufacturer = Manufacturer;
            emit ManufacturerChanged();
        }

        QString Peripheral::ServiceName(){
            Q_D(const Peripheral);
            return d->m_ServiceName;
        }
        void Peripheral::SetServiceName(QString ServiceName){
            Q_D(Peripheral);
            d->m_ServiceName = ServiceName;
            emit ServiceNameChanged();
        }

        PeripheralType Peripheral::InteralType(){
            Q_D(const Peripheral);
            return d->m_Type;
        }
        void Peripheral::SetInteralType(PeripheralType InteralType){
            Q_D(Peripheral);
            d->m_Type = InteralType;
            emit InteralTypeChanged();
        }

        bool Peripheral::IsRegistered(){
            Q_D(const Peripheral);
            return d->m_IsRegistered;
        }
        void Peripheral::SetRegistered(bool Registered){
            Q_D(Peripheral);
            d->m_IsRegistered = Registered;
            emit IsRegisteredChanged();
        }

        bool Peripheral::IsActivate(){
            Q_D(const Peripheral);
            return d->m_IsActivate;
        }
        void Peripheral::SetActivate(bool Activate){
            Q_D(Peripheral);
            d->m_IsActivate = Activate;
            emit IsActivateChanged();
        }

        bool Peripheral::IsProvided()
        {
            Q_D(const Peripheral);
            return d->m_IsProvided;
        }
        void Peripheral::SetProvided(bool Provided){
            Q_D(Peripheral);
            d->m_IsProvided = Provided;
            emit IsProvidedChanged();
        }
	}
}