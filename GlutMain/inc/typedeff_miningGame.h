#ifndef _TYPEDEFF_MININGGAME_H
#define _TYPEDEFF_MININGGAME_H

#include "typedeff.h"

namespace GAME3011_Assignment1
{
	enum class ComponentType : short
	{
		COMPONENT_TILE = GameEngine::ComponentType::COMPONENT_USERDEFINED
	};

	enum class EntityType : short
	{
		ENTITY_USERDEFINED
		//insert more types starting with ENTITY_USERDEFINED
	};
}

#endif