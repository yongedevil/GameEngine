#include "sys_graphicsSDL.h"

using namespace GameEngine;

Sys_Graphics::Sys_Graphics() : System(), m_window(NULL), m_screenSurface(NULL)
{
}

Sys_Graphics::~Sys_Graphics()
{
}

void Sys_Graphics::startup()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
}

void Sys_Graphics::shutdown()
{
	SDL_Quit();
}

void Sys_Graphics::update(float dt)
{
}