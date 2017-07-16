#pragma once

#include "qobject.h"
#include "..\Global.h"
#include <qvariant.h>

namespace RW{
	namespace SQL{
		class EntityPrivate;
		class REMOTE_DATA_CONNECT_API Entity :
			public QObject
		{
			Q_OBJECT
			Q_PROPERTY(QVariant ID READ ID WRITE SetID NOTIFY IDChanged)
		private:
			EntityPrivate* d_ptr;
			Q_DECLARE_PRIVATE(Entity);
		public:
			Entity(QObject *Parent = nullptr);
			~Entity();
			Entity(const Entity &obj);
			Entity& Entity::operator=(const Entity &obj);

			Entity(Entity &&rvalue);
			Entity& Entity::operator=(Entity&& other);

			QVariant ID() const;
			void SetID(quint64 ID);
            void SetID(QVariant ID);
		signals:
			void IDChanged(quint64);

		};
	}
}
