#include "gameEngine.h"

using namespace GameEngine;

GEngine * GEngine::s_instance = NULL;

GEngine * GEngine::instance()
{
	if(NULL == s_instance)
	{
		s_instance = new GEngine();
	}

	return s_instance;
}

GEngine::GEngine() : lastTime(0), m_sysManager(NULL), m_entManager(NULL)
{
}

GEngine::~GEngine()
{
	delete m_sysManager;
	delete m_entManager;
}

void GEngine::startup()
{
	lastTime = std::time(NULL);
	m_sysManager = new SystemManager();
	m_entManager = new EntityManager();

	//add systems to sysManger
	m_graphics = m_sysManager->create<Sys_Graphics>();
	m_input = m_sysManager->create<Sys_Input>(); 
}

void GEngine::shutdown()
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


void GEngine::update()
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

void GEngine::draw()
{
	if(m_graphics)
	{
		m_graphics->display();
		
		EntityManager::EntityList::iterator itEnt;
		for(itEnt = m_entManager->begin(); itEnt != m_entManager->end(); ++itEnt)
		{
			(*itEnt)->draw();
		}
	}
}

void GEngine::reshape(int width, int height)
{
	if(m_graphics)
	{
		m_graphics->reshape(width, height);
	}
}

void GEngine::keyboard(unsigned char key, int state, int x, int y)
{
	if(m_input)
	{
		m_input->keyboard(key, state, x, y);
	}
}

void GEngine::mouse(int button, int state, int x, int y)
{
	if(m_input)
	{
		m_input->mouse(button, state, x, y);
	}
}