#ifndef _GAME_ENGINE_H
#define _GAME_ENGINE_H

#include <vector>
#include <ctime>
#include <cassert>

#include "systemManager.h"
#include "entityManager.h"

namespace GameEngine
{
	class SystemManager;
	class EntityManager;
	class Sys_Graphics;
	class Sys_Input;

	class Engine
	{
	protected:
		Engine();
		~Engine();

	public:
		static Engine * instance();

		virtual void startup();
		virtual void shutdown();
		virtual void update();
		virtual void draw();

		void reshape(int width, int height);
		virtual void keyboard(unsigned char key, int state, int x, int y);
		virtual void mouse(int button, int state, int x, int y);

		template<class T>
		T * createEntity();

		int screenWidth() const;
		int screenHeight() const;

		void screenToWorld(int screenX, int screenY, float depthZ, float & worldX, float & worldY) const;

	private:
		static Engine * s_instance;
		std::time_t lastTime;

		SystemManager * m_sysManager;
		EntityManager * m_entManager;

		Sys_Graphics * m_graphics;
		Sys_Input * m_input;
	};

	template<class T>
	T * Engine::createEntity()
	{
		return m_entManager->create<T>();
	}
}

#endif