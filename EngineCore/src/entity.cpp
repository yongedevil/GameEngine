#include "entity.h"
#include "component.h"
#include "componentReference.h"

using namespace GameEngine;

Entity::Entity() :
m_id((EntityID)std::clock()),
m_active(false)
{
	m_componentList = new ComponentList();
}

Entity::~Entity()
{
}

void Entity::init()
{
	m_active = true;
}

void Entity::update(float dt)
{
}

void Entity::destroy()
{
	for (ComponentList::iterator it = m_componentList->begin(); it != m_componentList->end(); it++)
	{
		//detach components here
		(*it)->getComponent()->destroy();
	}
	m_componentList->clear();
}

Component * Entity::getComponent(ComponentID id)
{
	Component * comp = NULL;
	for (ComponentList::iterator it = m_componentList->begin(); NULL == comp && it != m_componentList->end(); ++it)
	{
		if ((*it)->getComponent()->getID() == id)
		{
			comp = (*it)->getComponent();
		}
	}

	return comp;
}

void Entity::removeComponent(Component * component)
{
	bool compFound = false;
	for (ComponentList::iterator it = m_componentList->begin(); !compFound && it != m_componentList->end(); ++it)
	{
		if ((*it)->getComponent() == component)
		{
			compFound = true;
			//remove component
		}
	}
}