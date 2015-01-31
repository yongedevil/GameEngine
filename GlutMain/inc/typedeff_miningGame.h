#ifndef _TYPEDEFF_MININGGAME_H
#define _TYPEDEFF_MININGGAME_H

#include "typedeff.h"

namespace GAME3011_Assignment1
{
	enum class ComponentType : short
	{
		COMPONENT_BOARD = static_cast<short>(GameEngine::ComponentType::COMPONENT_USERDEFINED)
	};
}

#endif