
#include <cstdlib>
#include <GL\glut.h>

#include "sys_graphicsGlut.h"

using namespace GameEngine;

const int Sys_Graphics::DEFAULT_SCREENWIDTH = 640;
const int Sys_Graphics::DEFAULT_SCREENHEIGHT = 480;

Sys_Graphics::Sys_Graphics() : m_screenWidth(DEFAULT_SCREENWIDTH), m_screenHeight(DEFAULT_SCREENHEIGHT)
{
}

Sys_Graphics::~Sys_Graphics()
{
}

void Sys_Graphics::startup()
{
}

void Sys_Graphics::shutdown()
{
}

void Sys_Graphics::update(float dt)
{
}

void Sys_Graphics::reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2,2, -2,2, 2,20);
	/*
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-11,11, -11,11, 0,20);
	*/
}

void Sys_Graphics::display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(0, 5, -10, 0, 0, 0, 0, 1, 0);
	
	glutSwapBuffers();
}

