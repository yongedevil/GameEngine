#ifndef _ENTITY_MANAGER_H
#define _ENTITY_MANAGER_H

#include <vector>

#include "manager.h"
#include "typedeff.h"
#include "entity.h"

namespace GameEngine
{
	class EntityManager : public Manager<Entity>
	{
	public:
		typedef ManagerList EntityList;
		
	public:
		EntityManager();
		~EntityManager();

		Entity * getEntity(EntityID id);
	};

}

#endif