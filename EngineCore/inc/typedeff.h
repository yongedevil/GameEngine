#ifndef _TYPEDEFF_H
#define _TYPEDEFF_H

namespace GameEngine
{
	typedef unsigned long EntityID;
	typedef long ComponentID;

	typedef short CompTypeData;
	enum class ComponentType : CompTypeData
	{
		COMPONENT_BASE,
		COMPONENT_CUSTOM
	};

	typedef short EntTypeData;
	enum class EntityType : EntTypeData
	{
		ENTITY_BASE,
		ENTITY_CUSTOM
	};
}

#endif