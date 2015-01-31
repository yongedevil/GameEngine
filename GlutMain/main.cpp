#include <cstdlib>
#include <GL\glut.h>

#include "miningGame.h"

using namespace GAME3011_Assignment1;

void idle();
void display();
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

void initlize();


int main (int argc, char ** argv)
{
	int WindowWidth = 600;
	int WindowHeight = 600;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GAME3011_Assignment1");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);

	initlize();
	glutMainLoop();

	return 0;
}

void initlize()
{
	MiningGame * game = MiningGame::instance();
	game->startup();
}


void idle()
{
	MiningGame * game = MiningGame::instance();
	game->update();

	glutPostRedisplay();
}

void display()
{
	MiningGame * game = MiningGame::instance();
	game->draw();
}

void reshape(int width, int height)
{
	MiningGame * game = MiningGame::instance();
	game->reshape(width, height);
}

void keyboard(unsigned char key, int x, int y)
{
	MiningGame * game = MiningGame::instance();
	game->keyboard(key, GLUT_DOWN, x, y);
}

void keyboardUp(unsigned char key, int x, int y)
{
	MiningGame * game = MiningGame::instance();
	game->keyboard(key, GLUT_UP, x, y);
}

void mouse(int button, int state, int x, int y)
{
	MiningGame * game = MiningGame::instance();
	game->mouse(button, state, x, y);
}