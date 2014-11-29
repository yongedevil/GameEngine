#ifndef _COMPONENTMANAGER_H
#define _COMPONENTMANAGER_H

#include <vector>
#include <iterator>

#include "typedeff.h"
#include "component.h"
#include "componentReference.h"

namespace GameEngine
{
	class iComponentManager
	{
	public:
		virtual ComponentType getType() = 0;

		virtual ComponentReference * createComponent() = 0;
		virtual void removeComponent(Component * component) = 0;

		virtual Component * getComponent(int index) = 0;
	};

	template<class T>
	class ComponentManager : public iComponentManager
	{
	public:
		typedef std::vector<T> ComponentList;

		class iterator
		{
			friend iterator operator+(iterator const& it1, int difference);
			friend iterator operator+(int difference, iterator const& it2);
			friend iterator operator-(iterator const& it1, int difference);
			friend iterator operator-(int difference, iterator const& it2);
		private:
			ComponentManager<T> * m_manager;
			int m_index;

		public:
			iterator() : m_manager(NULL), m_index(-1) { }
			iterator(iterator const& other) : m_manager(other.m_manger), m_index(other.m_index) { }
			~iterator() { }

			iterator & operator=(iterator const& other);
			iterator & operator+=(int difference);
			iterator & operator-=(int difference);

			iterator & operator++();
			iterator & operator++(int);
			iterator & operator--();
			iterator & operator--(int);

			T & operator*();
			T & operator[](int index);

			bool equals(iterator const& other) const;
			bool greaterthan(iterator const& other) const;
			bool lessthan(iterator const& other) const;
		};

	private:
		ComponentList m_componentList;

	public:
		ComponentManager();
		~ComponentManager();

		void update(float dt);

		ComponentType getType() { return T::type(); }

		typename ComponentList::iterator begin();
		typename ComponentList::iterator end();
		typename ComponentList::const_iterator cbegin() const;
		typename ComponentList::const_iterator cend() const;


		ComponentReference * createComponent();
		void removeComponent(Component * component);

		Component * getComponent(int index);
	};

	/***********\
	* iterator *
	\***********/
	template<class T>
	ComponentManager<T>::iterator & ComponentManager<T>::iterator::operator=(ComponentManager<T>::iterator const& other)
	{
		m_manager = other.m_manager;
		m_index = other.m_index;
	}
	template<class T>
	ComponentManager<T>::iterator & ComponentManager<T>::iterator::operator+=(int difference)
	{
		m_index += difference;
	}
	template<class T>
	ComponentManager<T>::iterator & ComponentManager<T>::iterator::operator-=(int difference)
	{
		m_index -= difference;
	}

	template<class T>
	ComponentManager<T>::iterator & ComponentManager<T>::iterator::operator++()
	{
		m_index++;
		return *this;
	}
	template<class T>
	ComponentManager<T>::iterator & ComponentManager<T>::iterator::operator++(int)
	{
		ComponentManager<T>::iterator it = *this;
		m_index++;
		return *this;
	}
	template<class T>
	ComponentManager<T>::iterator & ComponentManager<T>::iterator::operator--()
	{
		m_index--;
		return *this;
	}
	template<class T>
	ComponentManager<T>::iterator & ComponentManager<T>::iterator::operator--(int)
	{
		ComponentManager<T>::iterator it = *this;
		m_index--;
		return it;
	}

	template<class T>
	T & ComponentManager<T>::iterator::operator*()
	{
		return &(m_manager->getComponent(m_index));
	}
	template<class T>
	T & ComponentManager<T>::iterator::operator[](int index)
	{
		return &(m_manager->getComponent(index));
	}

	template<class T>
	bool ComponentManager<T>::iterator::equals(ComponentManager<T>::iterator const& other) const
	{
		return m_manager == other.m_manager && m_index == other.m_index;
	}

	template<class T>
	bool operator==(ComponentManager<T>::iterator const& it1, ComponentManager<T>::iterator const& it2)
	{
		return it1.equals(it2);
	}

	template<class T>
	bool operator!=(ComponentManager<T>::iterator const& it1, ComponentManager<T>::iterator const& it2)
	{
		return !it1.equals(it2);
	}

	template<class T>
	ComponentManager<T>::iterator operator+(ComponentManager<T>::iterator const& it1, int difference)
	{
		ComponentManager<T>::iterator it = it1;
		it.m_index += difference;
		return it;
	}
	template<class T>
	ComponentManager<T>::iterator operator+(int difference, ComponentManager<T>::iterator const& it2)
	{
		ComponentManager<T>::iterator it = it2;
		it.m_index += difference;
		return it;
	}

	template<class T>
	ComponentManager<T>::iterator operator-(ComponentManager<T>::iterator const& it1, int difference)
	{
		ComponentManager<T>::iterator it = it1;
		it.m_index -= difference;
		return it;
	}
	template<class T>
	ComponentManager<T>::iterator operator-(int difference, ComponentManager<T>::iterator const& it2)
	{
		ComponentManager<T>::iterator it = it2;
		it.m_index -= difference;
		return it;
	}


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
	Component * ComponentManager<T>::getComponent(int index)
	{
		return &m_componentList[index];
	}

	template<class T>
	ComponentReference * ComponentManager<T>::createComponent()
	{
<<<<<<< HEAD
		T * comp = new T();
		ComponentReference * reference = comp->getReference();

		m_componentList.push_back(comp);
		reference->m_cManager = this;
		reference->m_index = m_componentList.size - 1;

		return reference;
=======
		m_componentList.push_back(T());
		
		return &m_componentList.back();
>>>>>>> origin/master
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