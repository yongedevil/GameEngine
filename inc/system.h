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
	private:
		typedef std::vector<iComponentManager*> ManagerList;
		//componentManagers for associated components go here
		ManagerList m_managerList;

		/************\
		* Functions *
		\************/
	public:
		//Constructors / Destructors
		System();
		virtual ~System();

		virtual void startup() = 0;
		virtual void update(float dt) = 0;
		virtual void shutdown() = 0;

		template<class T>
		T * createComponet();
	};
}

#endif