#ifndef _SYS_INPUT_H
#define _SYS_INPUT_H

#include <cstdlib>
#include <GL\glut.h>

#include "system.h"

namespace GameEngine
{
	class Sys_Input : public System
	{
	public:
		Sys_Input();
		~Sys_Input();

		void startup();
		void shutdown();


		void keyboard(unsigned char key, int state, int x, int y);
		void mouse(int button, int state, int x, int y);

	protected:
		void update(float dt);
	};
}

#endif