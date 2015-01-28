#ifndef _SYS_GRAPHICS_H
#define _SYS_GRAPHICS_H

#include <cstdlib>
#include <GL\glut.h>

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
		
		void reshape(int width, int height);
		void display();

		int screenWidth() const { return m_screenWidth; }
		int screenHeight() const { return m_screenHeight; }

	protected:
		void update(float dt);
		

	private:
		int m_screenWidth;
		int m_screenHeight;

		static const int DEFAULT_SCREENWIDTH;
		static const int DEFAULT_SCREENHEIGHT;
	};
}

#endif