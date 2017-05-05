#pragma once
#include "Entity.h"
#include "..\SQLGlobal.h"

#include <qvariant.h>
#include "qdatetime.h"

namespace RW{
	namespace SQL{

        class User;
        class SoftwareProject;
        class Workstation;
        class FlashHistoryPrivate;

		class REMOTE_DATA_CONNECT_API FlashHistory :
			public Entity
		{
            Q_OBJECT
            Q_PROPERTY(User* UserHistory READ UserHistory WRITE SetUserHistory NOTIFY UserHistoryChanged)
            Q_PROPERTY(SoftwareProject* SoftwareProjectHistory READ SoftwareProjectHistory WRITE SetSoftwareProjectHistory NOTIFY SoftwareProjectHistoryChanged)
            Q_PROPERTY(Workstation* WorkstationHistory READ WorkstationHistory WRITE SetWorkstationHistory NOTIFY WorkstationHistoryChanged)
            Q_PROPERTY(QVariant Major READ Major WRITE SetMajor NOTIFY MajorChanged)
            Q_PROPERTY(QVariant Minor READ Minor WRITE SetMinor NOTIFY MajorChanged)
            Q_PROPERTY(QVariant PatchLevel READ PatchLevel WRITE SetPatchLevel NOTIFY PatchLevelChanged)
            Q_PROPERTY(QVariant Buildnumber READ Buildnumber WRITE SetBuildnumber NOTIFY BuildnumberChanged)
            Q_PROPERTY(QDateTime Date READ Date WRITE SetDate NOTIFY DateChanged)
            Q_CLASSINFO("Version", "0.0.1")
        private:
            FlashHistoryPrivate* d_ptr;
            Q_DECLARE_PRIVATE(FlashHistory);
		public:
            FlashHistory(Entity *Parent = nullptr);
			~FlashHistory(); 

            FlashHistory(const FlashHistory &F);
            FlashHistory& operator=(const FlashHistory &F);

            FlashHistory(FlashHistory &&F);
            FlashHistory& operator=(FlashHistory &&F);

            User* UserHistory()const;
            void SetUserHistory(User* User);

            SoftwareProject* SoftwareProjectHistory()const;
            void SetSoftwareProjectHistory(SoftwareProject* SoftwareProject);
 
            Workstation* WorkstationHistory()const;
            void SetWorkstationHistory(Workstation* Workstation);

            QVariant Major()const;
            void SetMajor(QVariant Major);

            QVariant Minor()const;
            void SetMinor(QVariant Minor);

            QVariant PatchLevel()const;
            void SetPatchLevel(QVariant PatchLevel);

            QVariant Buildnumber()const;
            void SetBuildnumber(QVariant Buildnumber);
            
            QDateTime Date()const;
            void SetDate(QDateTime Date);
        signals:
            void UserHistoryChanged();
            void SoftwareProjectHistoryChanged();
            void WorkstationHistoryChanged();
            void MajorChanged();
            void MinorChanged();
            void PatchLevelChanged();
            void BuildnumberChanged();
            void DateChanged();
		};
	}
}
Q_DECLARE_METATYPE(RW::SQL::FlashHistory);