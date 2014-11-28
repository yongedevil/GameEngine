#ifndef _ENTITY_H
#define _ENTITY_H

#include <vector>

#include "typedeff.h"

namespace GameEngine
{
	class Component;
	
	class Entity
	{
	private:
		typedef std::vector<Component*> ComponentList;

		/**********\
		* Fields *
		\**********/
	private:
		EntityID m_id;
		bool m_active;
		ComponentList * m_componentList;


		/************\
		* Functions *
		\************/
	public:
		//Constructors / Destructors
		Entity();
		virtual ~Entity();


		virtual void init();
		void updateEntity(float dt);
		virtual void destroy();

		//type
		static EntityType type() { return EntityType::ENTIT_BASE; }
		virtual EntityType getType() { return type(); }

		//getters and setters
		EntityID getID() const { return m_id; }
		bool getActive() const { return m_active; }
		void setActive(bool active) { m_active = active; }

		//component access
		template<class T>
		T * getComponent();
		Component * getComponent(ComponentID id);

		template<class T>
		T * addComponent();
		void removeComponent(Component * comp);


	protected:
		virtual void update(float dt);
	};

	/*
	bool operator==(Entity const& ent1, Entity const& ent2)
	{
		return ent1.getID() == ent2.getID();
	}

	bool operator!=(Entity const& ent1, Entity const & ent2)
	{
		return ent1.getID() != ent2.getID();
	}
	*/


	template<class T>
	T * Entity::getComponent()
	{
		T * comp = NULL;
		for (ComponentList::iterator it = m_componentList->begin(); NULL == comp && it != m_componentList->end(); ++it)
		{
			if ((*it)->getType() == T::type())
			{
				comp = *it;
			}
		}
		return comp;
	}

	template<class T>
	T * Entity::addComponent()
	{
		T * comp = T::system()->createComponent<T>();
		m_componentList->push_back(comp);

		return comp;
	}
}

#endif