#ifndef _TYPEDEFF_H
#define _TYPEDEFF_H

namespace GameEngine
{
	typedef unsigned long EntityID;
	typedef long ComponentID;

	enum class ComponentType : short
	{
		COMPONENT_BASE,
		COMPONENT_TRANSFORM,
		//insert more types here
		NUM_TYPES
	};

	enum class EntityType : short
	{
		ENTITY_BASE,
		//insert more types here
		NUM_TYPES
	};
}

#endif