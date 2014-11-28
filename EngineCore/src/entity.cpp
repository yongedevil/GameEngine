#include "entity.h"
#include "component.h"

using namespace GameEngine;

Entity::Entity() :
m_id((EntityID)std::clock()),
m_active(false)
{
	m_componentList = new std::vector<Component *>();
}

Entity::~Entity()
{
}

void Entity::init()
{
	m_active = true;
}

void Entity::updateEntity(float dt)
{
	if (m_active)
	{
		for (ComponentList::iterator it = m_componentList->begin(); it != m_componentList->end(); ++it)
		{
			(*it)->updateComponent(dt);
		}
		update(dt);
	}
}

void Entity::update(float dt)
{
}

void Entity::destroy()
{
	for (ComponentList::iterator it = m_componentList->begin(); it != m_componentList->end(); it++)
	{
		//detach components here
		(*it)->destory();
	}
	m_componentList->clear();
}

Component * Entity::getComponent(ComponentID id)
{
	Component * comp = NULL;
	for (ComponentList::iterator it = m_componentList->begin(); NULL == comp && it != m_componentList->end(); ++it)
	{
		if ((*it)->getID() == id)
		{
			comp = *it;
		}
	}

	return comp;
}

void Entity::removeComponent(Component * comp)
{
	bool compFound = false;
	for (ComponentList::iterator it = m_componentList->begin(); !compFound && it != m_componentList->end(); ++it)
	{
		if ((*it) == comp)
		{
			compFound = true;
			m_componentList->erase(it);
		}
	}
}