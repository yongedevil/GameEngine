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
		NUM_TYPES
	};
}

#endif