#ifndef _COMP_TRANSFORM_H
#define _COMP_TRANSFORM_H

#include "component.h"
#include "vector.h"
#include "quaternion.h"
#include "typedeffex.h"

namespace GameEngine
{
	class Transform : public Component
	{
	private:
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
		Vector3f & position() { return Vector3f(m_pos);; }
		Vector3f const& position() const { return m_pos; }
		void setPosition(Vector3f position) { m_pos = position; }

		Quaternionf & quaternion() { return Quaternionf(m_rot); }
		Quaternionf const& quaternion() const { return m_rot; }
		void setQuaternion(Quaternionf quaternion) { m_rot = quaternion; }

		//modifiers
		void translate(Vector3f translation);
		void rotate(Quaternionf rotation);


		//type
		static ComponentType type() { return static_cast<ComponentType>(ComponentTypeEx::COMPONENT_TRANSFORM); }
		ComponentType getType() const { return type(); }

	protected:
		void update(float dt);
	};
}

#endif