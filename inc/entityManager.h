#ifndef _ENTITYMANAGER_H
#define _ENTITYMANAGER_H

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

		EntityType getEntityType() { return T::type(); }

		typename EntityList::iterator begin();
		typename EntityList::iterator end();
		typename EntityList::const_iterator cbegin() const;
		typename EntityList::const_iterator cend() const;

		template<class T>
		T * addEntity();
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

	typename EntityList::iterator EntityManager::begin()
	{
		return m_entityList.begin();
	}

	typename EntityList::iterator EntityManager::end()
	{
		return m_entityList.end();
	}

	typename EntityList::const_iterator EntityManager::cbegin() const
	{
		return m_entityList.cbegin();
	}

	typename EntityList::const_iterator EntityManager::cend() const
	{
		return m_entityList.cend();
	}
	
	template<class T>
	T * EntityManager::addEntity()
	{
		T * entity = new T();
		m_entityList.add(entity);

		return entity;
	}
}

#endif