#ifndef _SCREEN_H
#define _SCREEN_H

#include <vector>

#include "entity.h"
#include "button.h"

namespace GameEngine
{
	class Screen : Entity
	{
	public:
		Screen();
		~Screen();

	private:
		Button * addButton(int x, int y, int width, int height, void (Screen:: * onClick)(void));

	private:

	};
}

#endif