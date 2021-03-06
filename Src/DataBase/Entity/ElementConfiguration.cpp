#include "ElementConfiguration.h"
#include "ElementConfiguration_p.h"
#include "ElementType.h"
#include "qdebug.h"

namespace RW{
	namespace SQL{

		ElementConfigurationPrivate::ElementConfigurationPrivate(ElementConfiguration* Parent) :
			QObject(Parent),
			q_ptr(Parent),
			m_DisplayName(""),
			m_Function(""),
			m_GroupName(""),
			m_Type(nullptr),
			m_Name(""),
			m_ToolTip(""),
			m_WorkstationID(0), 
			m_RemoteViewRelevant(false),
			m_Pin(255),
			m_IsFeature(false)
		{
		}

		ElementConfigurationPrivate::~ElementConfigurationPrivate()
		{
		}


		ElementConfiguration::ElementConfiguration(QObject *Parent) : Entity(Parent),
			d_ptr(new ElementConfigurationPrivate(this))
		{
		}

		ElementConfiguration::~ElementConfiguration()
		{
		}

		ElementConfiguration::ElementConfiguration(const ElementConfiguration& other) : d_ptr(new ElementConfigurationPrivate(this))
		{
			d_ptr->m_Name = other.d_ptr->m_Name;
			d_ptr->m_DisplayName = other.d_ptr->m_DisplayName;
			d_ptr->m_Function = other.d_ptr->m_Function;
			d_ptr->m_GroupName = other.d_ptr->m_GroupName;
			d_ptr->m_WorkstationID = other.d_ptr->m_WorkstationID;
			d_ptr->m_ToolTip = other.d_ptr->m_ToolTip;
			d_ptr->m_Type = other.d_ptr->m_Type;
			d_ptr->m_RemoteViewRelevant = other.d_ptr->m_RemoteViewRelevant;
			d_ptr->m_IsFeature = other.d_ptr->m_IsFeature;
			d_ptr->m_Pin = other.d_ptr->m_Pin;
		}

		ElementConfiguration& ElementConfiguration::operator=(ElementConfiguration& other)
		{
			//todo Duplicate code here. see copy constructor
			d_ptr = new ElementConfigurationPrivate(this);
			d_ptr->m_Name = other.d_ptr->m_Name;
			d_ptr->m_DisplayName = other.d_ptr->m_DisplayName;
			d_ptr->m_Function = other.d_ptr->m_Function;
			d_ptr->m_GroupName = other.d_ptr->m_GroupName;
			d_ptr->m_WorkstationID = other.d_ptr->m_WorkstationID;
			d_ptr->m_ToolTip = other.d_ptr->m_ToolTip;
			d_ptr->m_Type = other.d_ptr->m_Type;
			d_ptr->m_RemoteViewRelevant = other.d_ptr->m_RemoteViewRelevant;
			d_ptr->m_IsFeature = other.d_ptr->m_IsFeature;
			d_ptr->m_Pin = other.d_ptr->m_Pin;
			return *this;
		}


		ElementConfiguration::ElementConfiguration(ElementConfiguration&& other) : d_ptr(other.d_ptr)
		{
			d_ptr->setParent(this);
			other.d_ptr = nullptr;
			
		}
		ElementConfiguration& ElementConfiguration::operator=(ElementConfiguration&& other)
		{
			std::swap(d_ptr, other.d_ptr);
			d_ptr->setParent(this);
			delete other.d_ptr;
			other.d_ptr = nullptr;
			return *this;
		}


		ElementType* ElementConfiguration::Type() const
		{
			Q_D(const ElementConfiguration);
			return d->m_Type;
		}
		void ElementConfiguration::SetType(ElementType *Type)
		{
			Q_D(ElementConfiguration);
			d->m_Type = Type;
			emit TypeChanged();
		}

		QString ElementConfiguration::DisplayName() const
		{ 
			Q_D(const ElementConfiguration);
			return d->m_DisplayName;
		}

		void ElementConfiguration::SetDisplayName(QString DisplayName)
		{ 
			Q_D(ElementConfiguration);
			d->m_DisplayName = DisplayName;
			emit DisplayNameChanged();
		}

		QString ElementConfiguration::Name() const
		{
			Q_D(const ElementConfiguration);
			return d->m_Name;
		}

		void ElementConfiguration::SetName(QString Name)
		{ 
			Q_D(ElementConfiguration);
			d->m_Name = Name;
			emit NameChanged();
		}

		QString ElementConfiguration::GroupName() const
		{
			Q_D(const ElementConfiguration);
			return d_ptr->m_GroupName;
		}
		void ElementConfiguration::SetGroupName(QString GroupName)
		{
			Q_D(ElementConfiguration);
			d->m_GroupName = GroupName;
			emit GroupNameChanged();
		}

		QString ElementConfiguration::Function() const
		{
			Q_D(const ElementConfiguration);
			return d->m_Function;
		}

		void ElementConfiguration::SetFunction(QString Function)
		{ 
			Q_D(ElementConfiguration);
			d->m_Function = Function;
			emit FunctionChanged();
		}

		QString ElementConfiguration::ToolTip() const
		{	
			Q_D(const ElementConfiguration);
			return d->m_ToolTip;
		}

		void ElementConfiguration::SetToolTip(QString ToolTip)
		{
			Q_D(ElementConfiguration);
			d->m_ToolTip = ToolTip;
			emit ToolTipChanged();
		}

		quint64 ElementConfiguration::WorkstationID() const
		{
			Q_D(const ElementConfiguration);
			return d->m_WorkstationID;
		}

		void ElementConfiguration::SetWorkstationID(quint64 WorkstationID)
		{
			Q_D(ElementConfiguration);
			d->m_WorkstationID = WorkstationID;
			emit ToolTipChanged();
		}

		bool ElementConfiguration::RemoteViewRelevant() const
		{
			Q_D(const ElementConfiguration);
			return d->m_RemoteViewRelevant;
		}

		void ElementConfiguration::SetRemoteViewRelevant(bool RemoteViewRelevant)
		{
			Q_D(ElementConfiguration);
			d->m_RemoteViewRelevant = RemoteViewRelevant;
			emit RemoteViewRelevantChanged();
		}

		bool ElementConfiguration::IsFeature() const
		{
			Q_D(const ElementConfiguration);
			return d->m_IsFeature;
		}

		void ElementConfiguration::SetIsFeature(bool Feature)
		{
			Q_D(ElementConfiguration);
			d->m_IsFeature = Feature;
			emit IsFeatureChanged();
		}

		quint8 ElementConfiguration::Pin() const
		{
			Q_D(const ElementConfiguration);
			return d->m_Pin;
		}

		void ElementConfiguration::SetPin(quint8 Pin)
		{
			Q_D(ElementConfiguration);
			d->m_Pin = Pin;
			emit PinChanged();
		}
		
	}
}
