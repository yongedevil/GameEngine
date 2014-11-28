#ifndef _COMP_TRANSFORM_H
#define _COMP_TRANSFORM_H

#include "vector.h"
#include "component.h"

namespace GameEngine
{
	class Transform : public Component
	{
	private:
		Vector3f m_pos;

	};
}

#endif