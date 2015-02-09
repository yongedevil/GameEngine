#include "entity.h"
#include "component.h"

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
	for(ComponentList::iterator it = m_componentList->begin(); it != m_componentList->end(); ++it)
	{
		(*it)->updateComponent(dt);
	}
}

void Entity::draw()
{
	for(ComponentList::iterator it = m_componentList->begin(); it != m_componentList->end(); ++it)
	{
		(*it)->drawComponent();
	}
}

void Entity::destroy()
{
	for (ComponentList::iterator it = m_componentList->begin(); it != m_componentList->end(); it++)
	{
		//detach components here
		(*it)->destroy();
		delete *it;
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
			comp = (*it);
		}
	}

	return comp;
}

void Entity::removeComponent(Component * component)
{
	bool compFound = false;
	for (ComponentList::iterator it = m_componentList->begin(); !compFound && it != m_componentList->end(); ++it)
	{
		if ((*it) == component)
		{
			compFound = true;
			m_componentList->erase(it);
		}
	}
}


bool operator==(Entity const& ent1, Entity const& ent2)
{
	return ent1.getID() == ent2.getID();
}

bool operator!=(Entity const& ent1, Entity const & ent2)
{
	return ent1.getID() != ent2.getID();
}