#include "transform.h"

using namespace GameEngine;

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
}

void Transform::destroy()
{
	Component::destroy();
}

void Transform::translate(Vector3f translation)
{
	m_pos += translation;
}

void Transform::rotate(Quaternionf rotation)
{
	m_rot *= rotation;
}