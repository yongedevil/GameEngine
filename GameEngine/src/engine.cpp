#include "engine.h"

#include "sys_graphicsGlut.h"
#include "sys_inputGlut.h"

#include "vector.h"

using namespace GameEngine;

Engine * Engine::s_instance = NULL;

Engine * Engine::instance()
{
	if(NULL == s_instance)
	{
		s_instance = new Engine();
	}

	return s_instance;
}

Engine::Engine() : lastTime(0), m_sysManager(NULL), m_entManager(NULL)
{
}

Engine::~Engine()
{
	delete m_sysManager;
	delete m_entManager;
}

void Engine::startup()
{
	lastTime = std::time(NULL);
	m_sysManager = new SystemManager();
	m_entManager = new EntityManager();

	//add systems to sysManger
	m_graphics = m_sysManager->create<Sys_Graphics>();
	m_input = m_sysManager->create<Sys_Input>(); 
}

void Engine::shutdown()
{
	SystemManager::SystemList::iterator itSys;
	EntityManager::EntityList::iterator itEnt;

	//shutdown systems
	if(m_sysManager)
	{
		for(itSys = m_sysManager->begin(); itSys != m_sysManager->end(); ++itSys)
		{
			(*itSys)->shutdown();
		}
	}

	//destroy entities
	if(m_entManager)
	{
		for(itEnt = m_entManager->begin(); itEnt != m_entManager->end(); ++itEnt)
		{
			(*itEnt)->destroy();
		}
	}
}


void Engine::update()
{
	std::time_t curTime = std::time(NULL);
	float dt = static_cast<float>(lastTime - curTime) / CLOCKS_PER_SEC;
	
	//Update systems
	SystemManager::SystemList::iterator itSys;
	for(itSys = m_sysManager->begin(); itSys != m_sysManager->end(); ++itSys)
	{
		(*itSys)->shutdown();
	}

	//Update entities
	EntityManager::EntityList::iterator itEnt;
	for(itEnt = m_entManager->begin(); itEnt != m_entManager->end(); ++itEnt)
	{
		(*itEnt)->update(dt);
	}
}

void Engine::draw()
{
	if(m_graphics)
	{
		m_graphics->displayStart();
		m_graphics->display(m_entManager);
		m_graphics->displayEnd();
		
	}
}

void Engine::reshape(int width, int height)
{
	if(m_graphics)
	{
		m_graphics->reshape(width, height);
	}
}

void Engine::keyboard(unsigned char key, int state, int x, int y)
{
	if(m_input)
	{
		m_input->keyboard(key, state, x, y);
	}
}

void Engine::mouse(int button, int state, int x, int y)
{
	if(m_input)
	{
		m_input->mouse(button, state, x, y);
	}
}


int Engine::screenWidth() const
{
	return m_graphics->screenWidth();
}
int Engine::screenHeight() const
{
	return m_graphics->screenHeight();
}

void Engine::screenToWorld(int screenX, int screenY, float depthZ, float & worldX, float & worldY) const
{
	m_graphics->screenToWorld(screenX, screenY, depthZ, worldX, worldY);
}