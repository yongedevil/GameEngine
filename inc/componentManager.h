#ifndef _COMPONENTMANAGER_H
#define _COMPONENTMANAGER_H

#include <vector>

#include "component.h"

namespace GameEngine
{
	template<class T>
	class ComponentManager
	{
	private:
		eComponentTypes m_componentType;
		std::vector<T> * mptr_componentList;

	public:
		ComponentManager();
		~ComponentManager();

		void inti();

		eComponentTypes getComponentType() { return m_componentType; }

		typename std::vector<T>::iterator begin();
		typename std::vector<T>::iterator end();
		typename std::vector<T>::const_iterator cbegin() const;
		typename std::vector<T>::const_iterator cend() const;

	};


	template<class T>
	ComponentManager<T>::ComponentManager()
	{
		mptr_componentList = new std::vector<T>();
		m_componentType = T::getTypeS();
	}

	template<class T>
	ComponentManager<T>::~ComponentManager()
	{
		for (typename std::vector<T>::iterator it = begin(); it != end(); it++)
		{
			it->shutdown();
		}

		delete mptr_componentList;
	}


	template<class T>
	void ComponentManager<T>::inti()
	{
	}

	template<class T>
	typename std::vector<T>::iterator ComponentManager<T>::begin()
	{
		return mptr_comonentList->begin();
	}

	template<class T>
	typename std::vector<T>::iterator ComponentManager<T>::end()
	{
		return mptr_componentList->end();
	}

	template<class T>
	typename std::vector<T>::const_iterator ComponentManager<T>::cbegin() const
	{
		return mptr_comonentList->cbegin();
	}

	template<class T>
	typename std::vector<T>::const_iterator ComponentManager<T>::cend() const
	{
		return mptr_componentList->cend();
	}


}

#endif