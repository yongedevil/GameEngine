#include "comp_transform.h"

using namespace GameEngine;

System * Transform::s_system = NULL;

Transform::Transform()
{
	m_pos = Vector3f();
	m_rot = Quaternionf();
}

Transform::~Transform()
{
}

void Transform::init(Entity *ent)
{
	Component::init(ent);
}

void Transform::update(float dt)
{
	Component::update(dt);
}

void Transform::destroy()
{
	Component::destroy();
}