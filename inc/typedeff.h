#ifndef _TYPEDEFF_H
#define _TYPEDEFF_H

namespace GameEngine
{
	typedef unsigned long EntityID;
	typedef long ComponentID;

	//typedef unsigned short EntityType;
	//typedef short ComponentType;

	enum class EntityType : unsigned short
	{
		ENTIT_BASE,
		NUM_TYPES
	};

	enum class ComponentType : short
	{
		COMPONENT_BASE,
		NUM_TYPES
	};
}

#endif