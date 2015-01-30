#include "board.h"

using namespace GAME3011_Assignment1;

/********************************************************************************\
 * Board class, Constructor														*
 * Creates a board with the specified size. If dimentions are invalid it		*
 * defaults to 16.																*
 *																				*
 * Paramaters:																	*
 *   width: width of the board.													*
 *   height: height of the board.												*
\********************************************************************************/
Board::Board(int width, int height) : m_width(width), m_height(height), m_pos(), m_rot()
{
	if(m_width <= 0)
		m_width = 16;

	if(m_height <= 0)
		m_height = 16;

	m_board = new int[m_width * m_height];
}

Board::~Board()
{
	delete[] m_board;
}

/********************************************************************************\
 * Board class, getValue function												*
 * Returns the value at (x, y).  If out of bounds it returns -1.				*
 *																				*
 * Paramaters:																	*
 *   x: the x corrdinate.														*
 *   y: the y corrdinate.														*
 * Returns:																		*
 *   the value of the cell at (x, y) if successful.								*
 *   -1 if (x, y) is out of bounds.												*
\********************************************************************************/
int Board::getValue(int x, int y) const
{
	int index = getIndex(x, y);
	
	if(!inBounds(index))
		return -1;

	return m_board[index];
}

/********************************************************************************\
 * Board class, setValue function												*
 * Sets the value at (x, y).  If out of bounds nothing is changed.				*
 *																				*
 * Paramaters:																	*
 *   x: the x corrdinate.														*
 *   y: the y corrdinate.														*
 *   value: the value to set the cell at (x, y) to.								*
\********************************************************************************/
void Board::setvalue(int x, int y, int value)
{
	int index = getIndex(x, y);

	if(!inBounds(index))
		return;
	
	m_board[index] = value;
}


/********************************************************************************\
 * Board class, dispaly function												*
 * openGL calls to display the board											*
\********************************************************************************/
void Board::display()
{
}

/********************************************************************************\
 * Board class, getIndex function												*
 * Converts (x, y) into an index position.										*
 *																				*
 * Paramaters:																	*
 *   x: the x corrdinate.														*
 *   y: the y corrdinate.														*
 * Returns:																		*
 *   index of the cell at (x, y) if successful.									*
 *   -1 if (x, y) is out of bounds.												*
\********************************************************************************/
int Board::getIndex(int x, int y) const
{
	if(!inBounds(x, y))
		return -1;

	return y*m_width + x;
}

/********************************************************************************\
 * Board class, getXY function													*
 * Converts and index into (x, y) corrdinates.									*
 *																				*
 * Paramaters:																	*
 *   index: the index to convert to corrdinates.								*
 *   x: reference value to store the output for the x corrdinate.				*
 *   y: reference value to store the output for the y corrdinate.				*
 * Returns:																		*
 *   1 if successful.															*
 *  -1 if index is out of bounds.												*
\********************************************************************************/
int Board::getXY(int index, int &x, int &y) const
{
	if(!inBounds(x, y))
		return -1;

	x = index % m_width;
	y = index / m_width;

	return 1;
}

/********************************************************************************\
 * Board class, getAjacentIndexes function										*
 * Returns an array of 8 adjacent index positions.  Any positions out of bounds *
 * are set to -1.																*
 *																				*
 * Paramaters:																	*
 *   index: the index to get adjacent indexes for.								*
 * Returns:																		*
 *   Array of 8 adjacent indexes.  Any adjacent cells out of bounds are set to	*
 *	   -1.																		*
\********************************************************************************/
int * Board::getAjacentIndexes(int index) const
{
	int * adjacent = new int[8];

	for(int i = 0; i < 8; i++)
	{
		adjacent[i] = getAjacentIndex(static_cast<eAdjacentDirection>(i), index);
	}

	return adjacent;
}

/********************************************************************************\
 * Board class, getAjacentIndex function										*
 * Returns the index adjacent to index in the specified direction.				*
 *																				*
 * Paramaters:																	*
 *   direction: the direction to get the adjacent index for.					*
 *   index: the index to get the adjacent index for								*
 * Returns:																		*
 *   adjacent index if successful.												*
 *   -1 if the adjacent index is out of bounds.									*
\********************************************************************************/
int Board::getAjacentIndex(eAdjacentDirection direction, int index) const
{
	int adjacentIndex = -1;
	int x, y;

	getXY(index, x, y);

	switch(direction)
	{
	case eAdjacentDirection::UP_LEFT:
		adjacentIndex = getIndex(x-1, y-1);
		break;

	case eAdjacentDirection::UP:
		adjacentIndex = getIndex(x, y-1);
		break;

	case eAdjacentDirection::UP_RIGHT:
		adjacentIndex = getIndex(x+1, y-1);
		break;

	case eAdjacentDirection::LEFT:
		adjacentIndex = getIndex(x-1, y);
		break;

	case eAdjacentDirection::RIGHT:
		adjacentIndex = getIndex(x+1, y);
		break;

	case eAdjacentDirection::DOWN_LEFT:
		adjacentIndex = getIndex(x-1, y+1);
		break;

	case eAdjacentDirection::DOWN:
		adjacentIndex = getIndex(x, y+1);
		break;

	case eAdjacentDirection::DOWN_RIGHT:
		adjacentIndex = getIndex(x+1, y+1);
		break;
	}

	return adjacentIndex;
}