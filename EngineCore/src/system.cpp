#include "system.h"

using namespace GameEngine;

System::System()
{
	m_cManagers = std::vector<iComponentManager*>();
}

System::~System()
{
}