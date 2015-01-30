#ifndef _BOARD_H
#define _BOARD_H

#include "vector.h"
#include "quaternion.h"

namespace GAME3011_Assignment1
{
	/********************************************************\
	 * Board class											*
	 * Represents the game board as a 2D grid of int values	*
	\********************************************************/
	class Board
	{
		/****************\
		 * enum			*
		\****************/
	public:
		enum eAdjacentDirection : int //enum for relative positions of a cell.
		{
			UP_LEFT = 0,
			UP,
			UP_RIGHT,
			LEFT,
			RIGHT,
			DOWN_LEFT,
			DOWN,
			DOWN_RIGHT
		};

		/****************\
		 * Fields		*
		\****************/
	private:
		int * m_board;
		int m_width;
		int m_height;

		GameEngine::Vector3f m_pos;
		GameEngine::Quaternionf m_rot;
		

		/****************\
		 * Functions	*
		\****************/
	public:
		//Constructor
		Board(int width, int height);
		~Board();

		//Getters and Setters
		int getValue(int x, int y) const;
		void setvalue(int x, int y, int value);

		bool inBounds(int x, int y) const { return x >= 0 && x < m_width && y >= 0 && y < m_height; }
		bool inBounds(int index) const { return index >= 0 && index < m_width * m_height; }
		
		//Calcuating Adjacent indexes
		int * getAjacentIndexes(int index) const;
		int getAjacentIndex(eAdjacentDirection direction, int index) const;

		void display();

	private:
		//Converstions between x, y and index
		int getIndex(int x, int y) const;
		int getXY(int index, int &x, int &y) const;


	};
}

#endif