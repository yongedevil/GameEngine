#include "entity.h"

using namespace GameEngine;

Entity::Entity()
{
	m_id = (EntityID)std::clock();
	mptr_componentList = new std::vector<Component *>();
}

Entity::~Entity()
{
	for (ComponentList_it it = mptr_componentList->begin(); it != mptr_componentList->end(); it++)
	{
		//detach components here
		(*it)->shutdown();

	}
}

Component * Entity::getComponentType(eComponentTypes type)
{
	return NULL;
}

Component * Entity::getComponentID(ComponentID id)
{
	return NULL;
}

bool Entity::addComponent(Component * component)
{
	return true;
}