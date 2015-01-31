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
		int m_width;
		int m_height;

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

		void init(int width, int height);
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
		int getValue(int x, int y) const;
		void setvalue(int x, int y, int value);

		bool inBounds(int x, int y) const { return x >= 0 && x < m_width && y >= 0 && y < m_height; }
		bool inBounds(int index) const { return index >= 0 && index < m_width * m_height; }
		
		//Calcuating Adjacent indexes
		int * getAjacentIndexes(int index) const;
		int getAjacentIndex(eAdjacentDirection direction, int index) const;
		
	private:
		//Converstions between x, y and index
		int getIndex(int x, int y) const;
		int getXY(int index, int &x, int &y) const;

		float const* getColour(int value) const;


	};
}

#endif