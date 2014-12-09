#ifndef _ENTITY_MANAGER_H
#define _ENTITY_MANAGER_H

#include <vector>

#include "typedeff.h"
#include "entity.h"

namespace GameEngine
{
	class EntityManager
	{
	private:
		typedef std::vector<Entity *> EntityList;

		EntityList m_entityList;

	public:
		EntityManager();
		~EntityManager();

		void init();

		typename EntityList::iterator begin();
		typename EntityList::iterator end();
		typename EntityList::const_iterator cbegin() const;
		typename EntityList::const_iterator cend() const;

		template<class T>
		T * createEntity();

		void removeEntity(Entity * entity);

		Entity * getEntity(EntityID id);
	};

	EntityManager::EntityManager()
	{
		m_entityList = EntityList();
	}

	EntityManager::~EntityManager()
	{
		for(EntityList::iterator it = begin(); it != end(); it++)
		{
			(*it)->destroy;
			delete *it;
		}
	}

	void EntityManager::init()
	{
	}

	typename EntityManager::EntityList::iterator EntityManager::begin()
	{
		return m_entityList.begin();
	}

	typename EntityManager::EntityList::iterator EntityManager::end()
	{
		return m_entityList.end();
	}

	typename EntityManager::EntityList::const_iterator EntityManager::cbegin() const
	{
		return m_entityList.cbegin();
	}

	typename EntityManager::EntityList::const_iterator EntityManager::cend() const
	{
		return m_entityList.cend();
	}
	
	template<class T>
	T * EntityManager::createEntity()
	{
		T * entity = new T();
		m_entityList.add(entity);

		return entity;
	}
}

#endif