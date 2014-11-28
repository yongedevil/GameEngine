#ifndef _COMPONENTMANAGER_H
#define _COMPONENTMANAGER_H

#include <vector>

#include "typedeff.h"
#include "component.h"

namespace GameEngine
{
	class iComponentManager
	{
		virtual ComponentType getType() = 0;

		virtual Component * addComponent() = 0;
		virtual void removeComponent(Component * component) = 0;
	};

	template<class T>
	class ComponentManager : iComponentManager
	{
	public:
		typedef std::vector<T> ComponentList;

	private:
		ComponentList m_componentList;

	public:
		ComponentManager();
		~ComponentManager();

		ComponentType getType() { return T::type(); }

		typename ComponentList::iterator begin();
		typename ComponentList::iterator end();
		typename ComponentList::const_iterator cbegin() const;
		typename ComponentList::const_iterator cend() const;

		Component * addComponent();
		void removeComponent(Component * component);
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
	typename ComponentManager<T>::ComponentList::iterator ComponentManager<T>::begin()
	{
		return m_componentList->begin();
	}

	template<class T>
	typename ComponentManager<T>::ComponentList::iterator ComponentManager<T>::end()
	{
		return m_componentList->end();
	}

	template<class T>
	typename ComponentManager<T>::ComponentList::const_iterator ComponentManager<T>::cbegin() const
	{
		return m_componentList->cbegin();
	}

	template<class T>
	typename ComponentManager<T>::ComponentList::const_iterator ComponentManager<T>::cend() const
	{
		return m_componentList->cend();
	}

	template<class T>
	Component * ComponentManager<T>::addComponent()
	{
		T * comp = new T();
		m_componentList.push_back(comp);

		return comp;
	}

	template<class T>
	void ComponentManager<T>::removeComponent(Component * component)
	{
		bool compFound = false;
		for (ComponentList::iterator it = begin(); !compFound && it != end(); it++)
		{
			if (*it == *component)
			{
				it->destroy();
				m_componentList.erase(it);
			}
		}
	}


}

#endif