#ifndef _SYSTEM_MANAGER_H
#define _SYSTEM_MANAGER_H

#include <vector>

#include "manager.h"
#include "System.h"


namespace GameEngine
{
	class SystemManager : public Manager<System>
	{
	public:
		typedef ManagerList SystemList;

	public:
		SystemManager();
		~SystemManager();

	};
}

#endif