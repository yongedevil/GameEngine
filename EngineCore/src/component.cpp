#include "component.h"
#include "entity.h"

using namespace GameEngine;

Component::Component() :
m_id((ComponentID)std::clock()),
m_ent(NULL),
m_active(false)
{
}

Component::~Component()
{
}

void Component::init(Entity * ent)
{
	m_ent = ent;
	m_active = true;
}

void Component::updateComponent(float dt)
{
	if (m_active)
		update(dt);
}

void Component::destory()
{
	if (m_ent)
	{
		m_ent->removeComponent(this);
	}
}

