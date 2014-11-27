#ifndef _COMPONENTMANAGER_H
#define _COMPONENTMANAGER_H

#include <vector>

#include "typedeff.h"
#include "component.h"

namespace GameEngine
{
	template<class T>
	class ComponentManager
	{
	private:
		typedef std::vector<T> ComponentList;

		ComponentList m_componentList;

	public:
		ComponentManager();
		~ComponentManager();

		void inti();

		ComponentType getComponentType() { return T::type(); }

		typename ComponentList::iterator begin();
		typename ComponentList::iterator end();
		typename ComponentList::const_iterator cbegin() const;
		typename ComponentList::const_iterator cend() const;

	};


	template<class T>
	ComponentManager<T>::ComponentManager()
	{
		m_componentList = ComponentList();
	}

	template<class T>
	ComponentManager<T>::~ComponentManager()
	{
		for (typename ComponentList::iterator it = begin(); it != end(); it++)
		{
			it->destory();
		}
	}


	template<class T>
	void ComponentManager<T>::inti()
	{
	}

	template<class T>
	typename ComponentList::iterator ComponentManager<T>::begin()
	{
		return m_componentList->begin();
	}

	template<class T>
	typename ComponentList::iterator ComponentManager<T>::end()
	{
		return m_componentList->end();
	}

	template<class T>
	typename ComponentList::const_iterator ComponentManager<T>::cbegin() const
	{
		return m_componentList->cbegin();
	}

	template<class T>
	typename ComponentList::const_iterator ComponentManager<T>::cend() const
	{
		return m_componentList->cend();
	}


}

#endif