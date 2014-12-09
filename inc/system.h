#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <vector>
#include "component.h"
#include "componentManager.h"

namespace GameEngine
{
	class System
	{
		/**********\
		* Fields *
		\**********/
	protected:
		typedef std::vector<iComponentManager*> ManagerList;
		//componentManagers for associated components go here
		ManagerList m_managerList;
		bool m_active;

		/************\
		* Functions *
		\************/
	public:
		//Constructors / Destructors
		System();
		virtual ~System();

		virtual void startup() = 0;
		virtual void update(float dt);
		virtual void shutdown() = 0;

		template<class T>
		T * createComponet();
	};


	template<class T>
	T * System::createComponet()
	{
		Component * comp = NULL;
		for (ManagerList::iterator itManager = m_managerList.begin(); NULL == comp && itManager != m_managerList.end(); ++itManager)
		{
			if (T::type() == (*itManager)->getType())
			{
				comp = (*itManager)->createComponent();
			}
		}

		return comp;
	}
}

#endif