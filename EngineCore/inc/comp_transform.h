#ifndef _COMP_TRANSFORM_H
#define _COMP_TRANSFORM_H

#include "component.h"
#include "vector.h"
#include "quaternion.h"

namespace GameEngine
{
	class Transform : public Component
	{
		friend class SysCore;

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
		Vector3f & position() { return m_pos; }
		Vector3f const& position() const { return m_pos; }
		void setPosition(Vector3f position) { m_pos = position; }

		Quaternionf & quaternion() { return m_rot; }
		Quaternionf const& quaternion() const { return m_rot; }
		void setQuaternion(Quaternionf quaternion) { m_rot = quaternion; }

		//modifiers
		void translate(Vector3f translation);
		void rotate(Quaternionf rotation);


		//type
		static ComponentType type() { return ComponentType::COMPONENT_TRANSFORM; }
		ComponentType getType() const { return type(); }

	protected:
		void update(float dt);
		void draw();
	};
}

#endif