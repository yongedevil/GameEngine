#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <vector>
#include "component.h"

namespace GameEngine
{
	class System
	{
		/**********\
		* Fields *
		\**********/
	protected:
		bool m_active;

		/************\
		* Functions *
		\************/
	public:
		//Constructors / Destructors
		System();
		virtual ~System();

		virtual void startup() = 0;
		virtual void updateSystem(float dt);
		virtual void shutdown() = 0;

	protected:
		virtual void update(float dt) = 0;
	};
}

#endif