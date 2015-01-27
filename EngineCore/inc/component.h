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
 * Derived classes must define the following static fields and methods:
 *   static System * s_system;
 *   static ComponentType type();
 *   static System * system();
 *
 */
namespace GameEngine
{
	class Entity;

	/********************************************\
	 * Component class                          *
	 * Abstract class that attaches to an		*
	 * Entity to add functionallity.			*
	\********************************************/
	class Component
	{
		/**********\
		 * Fields *		
		\**********/
	private:
		//static System * s_system; //is initialized by the system

		ComponentID m_id;
		Entity * m_owner;
		bool m_active;


		/************\
		* Functions *
		\************/
	public:
		//Constructors / Destructors
		Component();
		virtual ~Component();

		//init, update, destroy
		virtual void init(Entity * owner);
		void updateComponent(float dt);
		virtual void destroy() = 0;


		//getters and setters
		ComponentID getID() const { return m_id; }
		Entity * getOwner() const { return m_owner; }

		bool getActive() const { return m_active; }
		void setActive(bool active) { m_active = active; }


		//type (this need to be implemented by derived classes)
		static ComponentType type() { return ComponentType::COMPONENT_BASE; }
		virtual ComponentType getType() const = 0;

	protected:		
		virtual void update(float dt) = 0;
	};

	/*
	bool operator==(Component const& comp1, Component const& comp2)
	{
		return comp1.getID() == comp2.getID();
	}

	bool operator!=(Component const& comp1, Component const & comp2)
	{
		return comp1.getID() != comp2.getID();
	}
	*/
}

#endif