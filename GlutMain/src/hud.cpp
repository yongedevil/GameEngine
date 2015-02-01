#include "hud.h"
#include "gamestates.h"

#include <cstdlib>
#include <string>
#include <GL\freeglut.h>

using namespace GAME3011_Assignment1;

HUD::HUD() :
GameEngine::Component(),
m_scanCount(0),
m_mineCount(0),
m_score(0),
m_mode(Mode::MODE_SCAN)
{

}

HUD::~HUD()
{

}

void HUD::init()
{
	Component::init();
}

void HUD::destroy()
{
}

void HUD::update(float dt)
{

}

void HUD::draw()
{
	std::string scanCountStr = std::to_string(m_scanCount);
	std::string mineCountStr = std::to_string(m_mineCount);
	std::string scoreStr = std::to_string(m_score);

	char const* scanCountcStr = scanCountStr.c_str();
	char const* mineCountcStr = mineCountStr.c_str();
	char const* scorecStr = scoreStr.c_str();

	glPushMatrix();

	if (Mode::MODE_SCAN == m_mode)
		glColor4f(0.5f, 0.5f, 1.0f, 1.0f);
	else
		glColor4f(1.0f, 0.5f, 0.5f, 1.0f);

	glRasterPos2f(-4.0f, 4.2f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char const*>("Current Mode: "));
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char const*>(Mode::MODE_SCAN == m_mode ? "Scanning" : "Extraction"));

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glRasterPos2f(1.0f, 4.2f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char const*>("Amount Collected: "));
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char const*>(scorecStr));


	glColor4f(0.5f, 0.5f, 1.0f, 1.0f);
	glRasterPos2f(-4.0f, 3.8f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char const*>("Scans left: "));
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char const*>(scanCountcStr));

	glColor4f(1.0f, 0.5f, 0.5f, 1.0f);
	glRasterPos2f(1.0f, 3.8f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char const*>("Extractions left: "));
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char const*>(mineCountcStr));

	if (Mode::MODE_END == m_mode)
	{

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glRasterPos2f(-0.9f, -0.35f);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char const*>("GAME OVER"));
	}

	glPopMatrix();
}

void HUD::setMode(GameEngine::State * curState)
{
	switch (static_cast<int>(curState->getType()))
	{
	case static_cast<int>(StateType::STATE_SCAN) :
		m_mode = Mode::MODE_SCAN;
		break;

	case static_cast<int>(StateType::STATE_MINE) :
		m_mode = Mode::MODE_MINE;
		break;

	case static_cast<int>(StateType::STATE_END) :
		m_mode = Mode::MODE_END;
		break;
	}
}