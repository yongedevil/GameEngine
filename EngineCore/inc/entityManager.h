#ifndef _ENTITY_MANAGER_H
#define _ENTITY_MANAGER_H

#include <vector>

#include "manager.h"

#include "typedeff.h"
#include "entity.h"

namespace GameEngine
{
	class EntityManager : Manager<Entity>
	{
	public:
		typedef ManagerList EntityList;
		
	public:
		EntityManager();
		~EntityManager();

		Entity * getEntity(EntityID id);
	};

	EntityManager::EntityManager() : Manager<Entity>()
	{
	}

	EntityManager::~EntityManager()
	{
		for(EntityList::iterator it = begin(); it != end(); ++it)
		{
			(*it)->destroy;
		}
	}

	Entity * EntityManager::getEntity(EntityID id)
	{
		Entity * ent = NULL;
		for(EntityList::iterator it = begin(); NULL == ent && it != end(); ++it)
		{
			if((*it)->getID() == id)
			{
				ent = *it;
			}
		}

		return ent;
	}
}

#endif