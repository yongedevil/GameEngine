#ifndef _SYSTEM_MANAGER_H
#define _SYSTEM_MANAGER_H

#include <vector>

#include "System.h"


namespace GameEngine
{
	class SystemManager
	{
	public:
		typedef std::vector<System*> SystemList;
		
	private:
		SystemList mlist_systems;


	};
}

#endif