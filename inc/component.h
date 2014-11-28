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
	class System;


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
		Entity * m_ent;
		bool m_active;


		/************\
		* Functions *
		\************/
	public:
		//Constructors / Destructors
		Component();
		virtual ~Component();

		//init, update, destroy
		virtual void init(Entity * ent);
		void updateComponent(float dt);
		virtual void destory();


		//getters and setters
		ComponentID getID() const { return m_id; }

		Entity * getEntity() { return m_ent; }
		Entity const* getEntity() const { return m_ent; }

		bool getActive() const { return m_active; }
		void setActive(bool active) { m_active = active; }


		//type and system (these need to be implemented by derived classes)
		//static ComponentType type() { return ComponentType::COMPONENT_BASE; }
		//static System * setSystem(System * system) { s_system = system; }
		//static System * system() { return s_system; }

		virtual ComponentType getType() const = 0;
		virtual System * getSystem() const = 0;

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