#include "system.h"

using namespace GameEngine;

System::System() : m_managerList(), m_active(false)
{
}

System::~System()
{
}

void System::update(float dt)
{
	if (m_active)
	{
		for (ManagerList::iterator itManager = m_managerList.begin(); itManager != m_managerList.end(); ++itManager)
		{
			for (iComponentManager::iterator itComponent = (*itManager)->begin(); itComponent != (*itManager)->end(); ++itComponent)
			{
				(*itComponent)->update(dt);
			}
		}
	}
}