#include "sys_core.h"

using namespace GameEngine;

Sys_Core::Sys_Core()
{
	m_cManagers.push_back(new ComponentManager<Transform>());
}