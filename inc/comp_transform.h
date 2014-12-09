#ifndef _COMP_TRANSFORM_H
#define _COMP_TRANSFORM_H

#include "component.h"
#include "vector.h"
#include "quaternion.h"

namespace GameEngine
{
	class Transform : public Component
	{
	private:
		static System * s_system; //is initialized by the system
		Vector3f m_pos;
		Quaternionf m_rot;

	public:
		//Constructors / Destructors
		Transform();
		~Transform();

		//init, update, destroy
		void init(Entity * ent);
		void destroy();


		//getters and setters
		Vector3f & position() { return m_pos; }
		Vector3f const& position() const { return m_pos; }
		void setPosition(Vector3f position) { m_pos = position; }

		Quaternionf & quaternion() { return m_rot; }
		Quaternionf const& quaternion() const { return m_rot; }
		void setQuaternion(Quaternionf quaternion) { m_rot = quaternion; }

		void translate(Vector2f translation);
		void rotate(Quaternionf rotation);


		//type and system
		static ComponentType type() { return ComponentType::COMPONENT_TRANSFORM; }
		static System * setSystem(System * system) { s_system = system; }
		static System * system() { return s_system; }

		ComponentType getType() const { return type(); }
		System * getSystem() const { return system(); }

	protected:
		void update(float dt);
	};
}

#endif