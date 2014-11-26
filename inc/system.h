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
		//componentManagers for associated components go here

		/************\
		* Functions *
		\************/
	public:
		System();
		virtual ~System();

		virtual void init() = 0;
		virtual void update(float dt) = 0;
		virtual void shutdown() = 0;

	};
}

#endif