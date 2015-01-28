#include <stdlib.h>
#include <GL\glut.h>

#include "gameEngine.h"


void idle();
void display();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

void initlize();


int main (int argc, char ** argv)
{
	int WindowWidth = 500;
	int WindowHeight = 500;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GAME");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	initlize();
	glutMainLoop();

	return 0;
}

void initlize()
{
	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

	glDisable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	GameEngine::GEngine * engine = GameEngine::GEngine::instance();
	engine->startup();
}


void idle()
{
	GameEngine::GEngine * engine = GameEngine::GEngine::instance();
	engine->update();
	glutPostRedisplay();
}

void display()
{
	GameEngine::GEngine * engine = GameEngine::GEngine::instance();
	engine->draw();
}

void reshape(int width, int height)
{
	GameEngine::GEngine * engine = GameEngine::GEngine::instance();
	engine->reshape(width, height);
}

void keyboard(unsigned char key, int x, int y)
{
	GameEngine::GEngine * engine = GameEngine::GEngine::instance();
	engine->keyboard(key, GLUT_DOWN, x, y);
}

void keyboardUp(unsigned char key, int x, int y)
{
	GameEngine::GEngine * engine = GameEngine::GEngine::instance();
	engine->keyboard(key, GLUT_UP, x, y);
}

void mouse(int button, int state, int x, int y)
{
	GameEngine::GEngine * engine = GameEngine::GEngine::instance();
	engine->mouse(button, state, x, y);
}