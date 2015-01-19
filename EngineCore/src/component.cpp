#include "component.h"
#include "entity.h"

using namespace GameEngine;

Component::Component() :
m_id((ComponentID)std::clock()),
m_entid(0),
m_active(false)
{
	m_reference = new ComponentReference();
}

Component::~Component()
{
	delete m_reference;
}

void Component::init(EntityID entid)
{
	m_entid = entid;
	m_active = true;
}

void Component::update(float dt)
{

}

void Component::destroy()
{
}

