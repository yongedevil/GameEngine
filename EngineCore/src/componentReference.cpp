#include "componentReference.h"
#include "componentManager.h"

using namespace GameEngine;

ComponentReference::ComponentReference() :
m_cManager(NULL),
m_index(-1)
{

}

ComponentReference::~ComponentReference()
{
}

Component * ComponentReference::getComponent()
{
	return m_cManager->getComponent(m_index);
}