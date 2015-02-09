#ifndef _TYPEDEFFEX_H
#define _TYPEDEFFEX_H

#include <typedeff.h>

namespace GameEngine
{
	typedef unsigned long EntityID;
	typedef long ComponentID;

	enum class ComponentTypeEx : CompTypeData
	{
		COMPONENT_TRANSFORM = ComponentType::COMPONENT_CUSTOM,
		COMPONENT_SPRITE,
		COMPONENT_BUTTON
	};


	enum class EntityTypeEx : EntTypeData
	{

	};
}

#endif