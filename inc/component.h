#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <cstdio>
#include <ctime>
#include <vector>

#include "entity.h"

namespace GameEngine
{

	class Entity;

	class Component
	{
	public:

		/**********\
		 * Fields *		
		\**********/
	private:
		ComponentID m_id;
		Entity * mptr_parent;


		/************\
		* Functions *
		\************/
	public:		
		Component();
		virtual ~Component();

		virtual void init() = 0;
		virtual void update(float dt) = 0;
		virtual void shutdown() = 0;

		static eComponentTypes getTypeS() { return eCT_BASE; }

		virtual eComponentTypes getType() const = 0;
		ComponentID getID() const { return m_id; }

		Entity const* parent() const { return mptr_parent; }
		Entity * parent() { return mptr_parent; }

	protected:
		void attach(Entity * parent);

		virtual std::vector<eComponentTypes> getDependencies() const { return std::vector<eComponentTypes>(); }

		virtual void checkDependencies() = 0;
		Component * checkDependency(eComponentTypes type);
	};
}

#endif