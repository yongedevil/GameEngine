#ifndef _TILE_H
#define _TILE_H

namespace GAME3011_Assignment1
{
	class Tile
	{
	private:
		int m_value;
		bool m_visible;

	public:
		Tile();
		~Tile();

		int getValue() const { return m_value; }
		void setValue(int value) { m_value = value; }

		bool getVisible() const { return m_visible; }
		void setVisible(bool visible) { m_visible = visible; }

	protected:
	};
}

#endif