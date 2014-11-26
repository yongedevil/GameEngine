#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "typedeff.h"
#include "component.h"

namespace GameEngine
{
	class Component;
	
	class Entity
	{
	protected:
		typedef std::vector<Component*> ComponentList;
		typedef ComponentList::iterator ComponentList_it;


		/**********\
		* Fields *
		\**********/
	private:
		EntityID m_id;
		ComponentList * mptr_componentList;


		/************\
		* Functions *
		\************/
	public:
		Entity();
		virtual ~Entity();

		EntityID getID() const { return m_id; }

		Component * getComponentType(eComponentTypes type);
		Component * getComponentID(ComponentID id);

	protected:
		bool addComponent(Component * component);


	};
}

#endif