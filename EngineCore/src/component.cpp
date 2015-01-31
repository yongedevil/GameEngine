#include "component.h"

using namespace GameEngine;

Component::Component() :
m_id((ComponentID)std::clock()),
m_owner(0),
m_active(true),
m_initilized(false)
{
}

Component::~Component()
{
}

void Component::init()
{
	m_initilized = true;
}

void Component::updateComponent(float dt)
{
	if (m_active && m_initilized)
	{
		update(dt);
	}
}

void Component::drawComponent()
{
	if (m_active && m_initilized)
	{
		draw();
	}
}

void Component::setOwner(Entity * owner)
{
	m_owner = owner;
}

