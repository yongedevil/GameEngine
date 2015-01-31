
#include <cstdlib>
#include <GL\glut.h>

#include "sys_graphicsGlut.h"
#include "entityManager.h"
#include "entity.h"
#include "vector.h"

using namespace GameEngine;

const int Sys_Graphics::DEFAULT_SCREENWIDTH = 600;
const int Sys_Graphics::DEFAULT_SCREENHEIGHT = 600;

const float Sys_Graphics::DEFAULT_CAMERAWIDTH = 5;
const float Sys_Graphics::DEFAULT_CAMERAHEIGHT = 5;

Sys_Graphics::Sys_Graphics():
m_screenWidth(DEFAULT_SCREENWIDTH),
m_screenHeight(DEFAULT_SCREENHEIGHT),
m_cameraWidth(DEFAULT_CAMERAWIDTH),
m_cameraHeight(DEFAULT_CAMERAHEIGHT)

{
	m_cameraPos = new float[3]{ 0.0f, 0.0f, 5.0f };
	m_cameraTarget = new float[3]{ 0.0f, 0.0f, 0.0f };
}

Sys_Graphics::~Sys_Graphics()
{
}

void Sys_Graphics::startup()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glDisable(GL_LIGHTING);
	//glEnable(GL_DEPTH_TEST);
	//glDisable(GL_BLEND);
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

	m_screenWidth = width;
	m_screenHeight = height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-2,2, -2,2, 2,20);
	//gluPerspective(90.0, (float)m_screenWidth / m_screenHeight, 2, 20);
	glOrtho(-m_cameraWidth, m_cameraWidth, -m_cameraHeight, m_cameraHeight, 2, 20);
}

void Sys_Graphics::displayStart()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		m_cameraPos[0], m_cameraPos[1], m_cameraPos[2],
		m_cameraTarget[0], m_cameraTarget[1], m_cameraTarget[2],
		0.0f, 1.0f, 0.0f);
}

void Sys_Graphics::display(EntityManager * m_entManager)
{
	for (EntityManager::EntityList::iterator itEnt = m_entManager->begin(); itEnt != m_entManager->end(); ++itEnt)
	{
		(*itEnt)->draw();
	}
}	
void Sys_Graphics::displayEnd()
{
	glutSwapBuffers();
}


void Sys_Graphics::screenToWorld(int screenX, int screenY, float depthZ, float & worldX, float & worldY) const
{
	worldX = ((2.0f * screenX) / m_screenWidth - 1.0f) * m_cameraWidth;
	worldY = (1.0f - (2.0f * screenY) / m_screenHeight) * m_cameraHeight;
}


void Sys_Graphics::displayText(std::string)
{

}