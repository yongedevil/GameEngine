#ifndef _COMPONENT_MANAGER_H
#define _COMPONENT_MANAGER_H

#include <vector>
#include <iterator>

#include "typedeff.h"
#include "component.h"
#include "componentReference.h"
#include "componentManagerInterface.h"

namespace GameEngine
{
	template<class T>
	class ComponentManager : public iComponentManager
	{
	public:
		typedef std::vector<T> ComponentList;
		
	private:
		ComponentList m_componentList;

	public:
		ComponentManager();
		~ComponentManager();

		void update(float dt);

		ComponentType getType() { return T::type(); }

		iterator begin();
		iterator end();
		int size() const { return m_componentList.size(); }
		//typename const_iterator cbegin() const;
		//typename const_iterator cend() const;


		ComponentReference * createComponent();
		void removeComponent(Component * component);

		Component * getComponent(int index);

	};
	

	/*******************\
	* ComponentManager *
	\*******************/
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
	void ComponentManager<T>::update(float dt)
	{
		for (ComponentList::iterator it = begin(); it != end(); it++)
		{
			if (it->getActive())
				it->update(dt);
		}
	}

	template<class T>
	typename ComponentManager<T>::iterator ComponentManager<T>::begin()
	{
		ComponentManager<T>::iterator it = ComponentManager<T>::iterator(this, 0);;
		return it;
	}
	template<class T>
	typename ComponentManager<T>::iterator ComponentManager<T>::end()
	{
		ComponentManager<T>::iterator it = ComponentManager<T>::iterator(this, m_componentList.size());
		return it;
	}
	/*
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
	*/

	template<class T>
	Component * ComponentManager<T>::getComponent(int index)
	{
		return &m_componentList[index];
	}

	template<class T>
	ComponentReference * ComponentManager<T>::createComponent()
	{
		m_componentList.push_back(T());

		ComponentReference * reference = m_componentList.back().getReference();
		iComponentManager::setReference(reference, m_componentList.size() - 1);
				
		return reference;
	}

	template<class T>
	void ComponentManager<T>::removeComponent(Component * component)
	{
		bool compFound = false;
		for (iterator it = begin(); !compFound && it != end(); it++)
		{
			if (*it == component)
			{
				(*it)->destroy();
				//TODO remove from list here
			}
		}
	}


}

#endif