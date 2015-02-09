#include "rectangle.h"

using namespace GameEngine;

Rectangle::Rectangle(int x, int y, int w, int h) :
	m_pos(x, y),
	m_size(w, h)
{
}
Rectangle::Rectangle() :
	m_pos(),
	m_size()
{
}

Rectangle::Rectangle(Rectangle const& rect2) :
	m_pos(rect2.m_pos),
	m_size(rect2.m_size)
{
}

Rectangle::~Rectangle()
{
}


bool Rectangle::equals(Rectangle const& rect2) const
{
	return m_pos == rect2.m_pos && m_size == rect2.m_size;
}

bool operator==(Rectangle const& rect1, Rectangle const& rect2)
{
	return rect1.equals(rect2);
}

bool operator!=(Rectangle const& rect1, Rectangle const& rect2)
{
	return !(rect1 == rect2);
}