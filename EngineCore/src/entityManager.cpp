#include "entityManager.h"

using namespace GameEngine;


EntityManager::EntityManager() : Manager<Entity>()
{
}

EntityManager::~EntityManager()
{
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