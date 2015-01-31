#ifndef _BOARD_H
#define _BOARD_H

#include "component.h"
#include "typedeff_miningGame.h"

namespace GAME3011_Assignment1
{
	class Tile;

	/********************************************************\
	 * Board class											*
	 * Represents the game board as a 2D grid of int values	*
	\********************************************************/
	class Board : public GameEngine::Component
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
		Tile * m_board;
		int m_numCol;
		int m_numRow;

		float m_halfTileWidth;
		float m_halfTileHeight;
		float m_tileSpacing;

		static const int VALUE_MAX;

		static const float * COLOUR_HIDDEN;
		static const float * COLOUR_MIN;
		static const float * COLOUR_QUARTER;
		static const float * COLOUR_HALF;
		static const float * COLOUR_MAX;
		

		/****************************\
		 * Inherited from Component	*
		\****************************/
	public:
		Board();
		~Board();

		void init(int col, int row);
		void destroy();

		static GameEngine::ComponentType type() { return static_cast<GameEngine::ComponentType>(ComponentType::COMPONENT_BOARD); }
		GameEngine::ComponentType getType() const { return static_cast<GameEngine::ComponentType>(ComponentType::COMPONENT_BOARD); }

	protected:
		void update(float dt);
		void draw();



		/*******************\
		* Board functtions *
		\*******************/
	public:
		//Getters and Setters
		int getValue(int col, int row) const;
		void setvalue(int col, int row, int value);

		bool inBounds(int col, int row) const { return col >= 0 && col < m_numCol && row >= 0 && row < m_numRow; }
		bool inBounds(int index) const { return index >= 0 && index < m_numCol * m_numRow; }
		
		//Calcuating Adjacent indexes
		int * getAjacentIndexes(int index) const;
		int getAjacentIndex(eAdjacentDirection direction, int index) const;

		bool getColRow(float x, float y, int & col, int & row) const;
		
	private:
		//Converstions between col, row and index
		int getIndex(int col, int row) const;
		int getColRow(int index, int & col, int & row) const;

		float const* getColour(int value) const;

		bool isInCol(int col, float x) const;
		bool isInRow(int row, float y) const;
	};
}

#endif