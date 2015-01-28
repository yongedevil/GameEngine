#ifndef _GAME_ENGINE_H
#define _GAME_ENGINE_H

#include <vector>
#include <ctime>
#include <cassert>

#include "systemManager.h"
#include "entityManager.h"

#include "sys_graphicsGlut.h"
#include "sys_inputGlut.h"

namespace GameEngine
{
	class GEngine
	{
	public:
		static GEngine * instance();

		void startup();
		void shutdown();
		void update();
		void draw();

		void reshape(int width, int height);
		void keyboard(unsigned char key, int state, int x, int y);
		void mouse(int button, int state, int x, int y);

	private:
		GEngine();
		~GEngine();



	private:
		static GEngine * s_instance;
		std::time_t lastTime;

		SystemManager * m_sysManager;
		EntityManager * m_entManager;

		Sys_Graphics * m_graphics;
		Sys_Input * m_input;
	};
}

#endif