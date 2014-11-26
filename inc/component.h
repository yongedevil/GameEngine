#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <cstdio>
#include <ctime>
#include <vector>

#include "typedeff.h"

/* Component class
 * This class repesents a component that adds functionality to an Entity
 * Components are controlled and owned by Systems
 *
 * Child classes must define the following static functions:
 * static ComponentType type();
 * static System * system();
 *
 */
namespace GameEngine
{
	class Entity;
	class System;

	class Component
	{
	public:

		/**********\
		 * Fields *		
		\**********/
	private:
		ComponentID m_id;
		Entity * m_ent;
		bool m_active;


		/************\
		* Functions *
		\************/
	public:		
		Component();
		virtual ~Component();

		virtual void init(Entity * ent);
		void update(float dt);
		virtual void destory();

		ComponentID getID() const { return m_id; }
		virtual ComponentType getType() const = 0;

		bool getActive() const { return m_active; }
		void setActive(bool active) { m_active = active; }

		Entity * getEntity() { return m_ent; }
		Entity const* getEntity() const { return m_ent; }

	protected:
		virtual void updateComponent(float dt) = 0;
	};
}

#endif