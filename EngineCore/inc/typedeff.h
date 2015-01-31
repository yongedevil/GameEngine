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
		COMPONENT_USERDEFINED
		//insert more types starting from USERDEFINED
	};

	enum class EntityType : short
	{
		ENTITY_BASE,
		ENTITY_USERDEFINED
		//insert more types starting from USERDEFINED
	};
}

#endif