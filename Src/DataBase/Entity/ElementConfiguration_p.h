#pragma once
#include <qobject.h>
#include "ElementType.h"

namespace RW{
	namespace SQL{

		class Workstation;
		class ElementConfiguration;
		class ElementConfigurationPrivate : public QObject
		{
			Q_OBJECT
			Q_DISABLE_COPY(ElementConfigurationPrivate)
			Q_DECLARE_PUBLIC(ElementConfiguration)
		private:
			ElementConfiguration * const q_ptr;

		public:
			quint64 m_WorkstationID;
			ElementType* m_Type;
			QString m_DisplayName;
			QString m_Name;
			QString m_GroupName;
			QString m_Function;
			QString m_ToolTip;
			quint8 m_Pin;
			bool m_IsFeature;
			bool m_RemoteViewRelevant;
		public:
			ElementConfigurationPrivate(ElementConfiguration* QPointer);
			~ElementConfigurationPrivate();
		};


	}
}