#include "sys_graphicsGlut.h"

using namespace GameEngine;

Sys_Graphics::Sys_Graphics()
{
}

Sys_Graphics::~Sys_Graphics()
{
}

void Sys_Graphics::startup()
{
	glutIdleFunc(idle);
	glutDisplayFunc(this->display);
}

void Sys_Graphics::shutdown()
{
}

void Sys_Graphics::idle()
{
}

void Sys_Graphics::display()
{
}

