#ifndef _GAME_ENGINE_H
#define _GAME_ENGINE_H

#include <vector>
#include <ctime>
#include <cassert>

#include "systemManager.h"
#include "entityManager.h"

#include "Component.h"
#include "Entity.h"
#include "System.h"


namespace GameEngine
{
	class GEngine
	{
	public:
		GEngine * instance();

		void update();

	private:
		GEngine();
		~GEngine();

		void startup();



	private:
		static GEngine * s_instance;
		std::time_t lastTime;

		SystemManager * sysManager;
		EntityManager * entManager;
	};
}

#endif