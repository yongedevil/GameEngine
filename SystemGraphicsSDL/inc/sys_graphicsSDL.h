#ifndef _SYS_GRAPHICS_H
#define _SYS_GRAPHICS_H

#include "SDL.h"
#include "system.h"

namespace GameEngine
{
	class Sys_Graphics : public System
	{
	public:
		Sys_Graphics();
		~Sys_Graphics();

		void startup();
		void shutdown();

	protected:
		void update(float dt);

	private:
		static const int SCREEN_WIDTH = 640;
		static const int SCREEN_HEIGHT = 480;

		SDL_Window * m_window;
		SDL_Surface * m_screenSurface;
	};
}

#endif