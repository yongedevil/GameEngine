#include "gameEngine.h"

using namespace GameEngine;

GEngine * GEngine::s_instance = NULL;

GEngine * GEngine::instance()
{
	if(NULL == s_instance)
	{
		s_instance = new GEngine();
		s_instance->startup();
	}

	return s_instance;
}

GEngine::GEngine() : lastTime(0), sysManager(NULL), entManager(NULL)
{
}

GEngine::~GEngine()
{
}

void GEngine::startup()
{
	lastTime = std::time(NULL);
	sysManager = new SystemManager();
	entManager = new EntityManager();
}

void GEngine::update()
{
	std::time_t curTime = std::time(NULL);
	float dt = static_cast<float>(lastTime - curTime) / CLOCKS_PER_SEC;
	
}