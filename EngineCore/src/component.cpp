#include "component.h"
#include "entity.h"

using namespace GameEngine;

Component::Component() :
m_id((ComponentID)std::clock()),
m_ent(NULL),
m_active(false)
{
	m_reference = new ComponentReference();
}

Component::~Component()
{
	delete m_reference;
}

void Component::init(Entity * ent)
{
	m_ent = ent;
	m_active = true;
}

void Component::update(float dt)
{

}

void Component::destroy()
{
	if (m_ent)
	{
		m_ent->removeComponent(this);
	}
}

