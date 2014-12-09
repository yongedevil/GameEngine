#include "sys_core.h"

using namespace GameEngine;

SysCore::SysCore()
{
	m_managerList.push_back(new ComponentManager<Transform>());
}

SysCore::~SysCore()
{
	for (ManagerList::iterator it = m_managerList.begin(); it != m_managerList.end(); ++it)
	{
		delete (*it);
	}
}

void SysCore::startup()
{
	m_active = true;
}

void SysCore::update(float dt)
{
}

void SysCore::shutdown()
{
	for (ManagerList::iterator itManager = m_managerList.begin(); itManager != m_managerList.end(); ++itManager)
	{
		for (iComponentManager::iterator itComponent = (*itManager)->begin(); itComponent != (*itManager)->end(); ++itComponent)
		{
			(*itComponent)->destroy();
		}
	}
}