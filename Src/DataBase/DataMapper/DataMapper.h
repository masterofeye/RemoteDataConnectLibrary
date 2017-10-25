#pragma once
#include "qobject.h"
#include "Entity.h"
#include "..\Entity\Nothing.h"
namespace RW{
	namespace SQL{
		class Entity;
		template <class T, class T2 = Nothing>
		class DataMapper
		{
		public:
			enum class Specifier
			{
                GetWorkstationByHostname,
                GetHistoryByWorkstationID,
                GetLastestFlasHistoryEntryByWorkstationIDAndSoftwareProjectID,
                GetSoftwareProjectsByProjectID,
                GetPeripheralByWorkstationID,
                GetPeripheralConditionListByConditionID,
                GetUserSettingByUserID,

			};
			Q_ENUMS(Specifier)

			virtual bool Insert(const T &Data) = 0;
			virtual bool Update(const T &Data) = 0;
			virtual T FindByID(const quint64 id,bool Flag) = 0;
			virtual QList<T> FindAll() = 0;

			virtual QList<T> FindBySpecifier(const Specifier Value, const QVariantList Parameter) = 0;
			//virtual QList<T> FindBySpecifier(const Specifier Value, const T2 Parameter) = 0;

			DataMapper(QObject* Parent = nullptr){}
			~DataMapper(){}
		};
	}
}