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
		Entity();
		virtual ~Entity();

		void init();
		void update(float dt);
		void destroy();


		EntityID getID() const { return m_id; }
		bool getActive() const { return m_active; }
		void setActive(bool active) { m_active = active; }

		template<class T>
		T * getComponent();
		Component * getComponent(ComponentID id);

		void addComponent(Component * comp);
		void removeComponent(Component * comp);


		static EntityType type() { return EntityType::ENTIT_BASE; }
		virtual EntityType getType() { return EntityType::ENTIT_BASE; }

	protected:

	};
}

#endif