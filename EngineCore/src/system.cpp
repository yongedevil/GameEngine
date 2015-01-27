#include "system.h"

using namespace GameEngine;

System::System() : m_active(false)
{
}

System::~System()
{
}

void System::updateSystem(float dt)
{
	if (m_active)
	{
		update(dt);
	}
}