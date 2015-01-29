#include "component.h"

using namespace GameEngine;

Component::Component() :
m_id((ComponentID)std::clock()),
m_owner(0),
m_active(false)
{
}

Component::~Component()
{
}

void Component::init(Entity * owner)
{
	m_owner = owner;
	m_active = true;
}

void Component::updateComponent(float dt)
{
	if(m_active)
	{
		update(dt);
	}
}

void Component::drawComponent()
{
	if(m_active)
	{
		draw();
	}
}

void Component::draw()
{
}

