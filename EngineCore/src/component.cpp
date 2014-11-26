#include "component.h"

using namespace GameEngine;

Component::Component() :
mptr_parent(NULL)
{
	m_id = (ComponentID)std::clock();
	mptr_parent = NULL;
}

Component::~Component()
{
}

void Component::attach(Entity * parent)
{
	if (NULL != parent)
	{
		mptr_parent = parent;
		checkDependencies();
	}
}

void Component::checkDependencies()
{
	std::vector<eComponentTypes> dependencies = getDependencies();
	for (std::vector<eComponentTypes>::iterator it = dependencies.begin(); it != dependencies.end(); it++)
	{
		checkDependency(*it);
	}
}

Component * Component::checkDependency(eComponentTypes type)
{
	Component * ptr_dependency = mptr_parent->getComponentType(type);
	if (NULL == ptr_dependency)
	{
		//add dependency to Entity here
	}

	return ptr_dependency;
}
