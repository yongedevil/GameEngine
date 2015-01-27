#ifndef _SYS_GRAPHICS_H
#define _SYS_GRAPHICS_H

#include "GL\glut.h"

#include "system.h"

namespace GameEngine
{
	class Sys_Graphics : System
	{
	public:
		Sys_Graphics();
		~Sys_Graphics();

		void startup();
		void shutdown();

		int screenWidth() const { return m_screenWidth; }
		int screenHeight() const { return m_screenHeight; }

	protected:
		void update(float dt);


	private:
		void idle();
		void display();


	private:
		int m_screenWidth;
		int m_screenHeight;
	};
}

#endif