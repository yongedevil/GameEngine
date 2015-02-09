#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "vector.h"

namespace GameEngine
{
	class Rectangle
	{
	public:
		Rectangle(int x, int y, int w, int h);
		Rectangle();
		Rectangle(Rectangle const& rect2);
		~Rectangle();

		int x() const { return m_pos.x(); }
		int y() const { return m_pos.y(); }
		int w() const { return m_size.x(); }
		int h() const { return m_size.y(); }

		int x(int x) { return m_pos.x(x); }
		int y(int y) { return m_pos.y(y); }
		int w(int w) { return m_size.x(w); }
		int h(int h) { return m_size.y(h); }


		Rectangle & operator=(Rectangle const& rect2);

		bool equals(Rectangle const& rect2) const;

	private:
		Point m_pos;
		Point m_size;
	};

	bool operator==(Rectangle const& rect1, Rectangle const& rect2);
	bool operator!=(Rectangle const& rect1, Rectangle const& rect2);
}

#endif