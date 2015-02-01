#include "board.h"
#include "tile.h"

#include <GL\freeglut.h>

#include <cmath>

using namespace GAME3011_Assignment1;

float * Board::COLOUR_HIDDEN =	new float[4]{ 1.00f, 1.00f, 1.00f, 1.0f };
float * Board::COLOUR_MIN =		new float[4]{ 0.50f, 0.50f, 0.50f, 1.0f };
float * Board::COLOUR_QUARTER =	new float[4]{ 1.00f, 1.00f, 0.00f, 1.0f };
float * Board::COLOUR_HALF =	new float[4]{ 1.00f, 0.50f, 0.00f, 1.0f };
float * Board::COLOUR_MAX =		new float[4]{ 1.00f, 0.00f, 0.00f, 1.0f };

/********************************************************************************\
 * Board class, Constructor														*
\********************************************************************************/
Board::Board() :
GameEngine::Component(),
m_board(NULL),
m_numCol(0),
m_numRow(0),
m_halfTileWidth(0.2f),
m_halfTileHeight(0.2f),
m_tileSpacing(0.1f),
m_boardOffsetWidth(0.0f),
m_boardOffsetHeight(-0.25f),
m_gameOver(false)
{
}

Board::~Board()
{
	delete[] m_board;
}

/********************************************************************************\
* Board class, init function													*
* Creates a board with the specified size. If dimentions are invalid it			*
* defaults to 16.																*
*																				*
* Paramaters:																	*
*   width: width of the board.													*
*   height: height of the board.												*
\********************************************************************************/
void Board::init(int col, int row)
{
	Component::init();

	m_numCol = col;
	m_numRow = row;

	if (m_numCol < 0)
		m_numCol = 16;

	if (m_numRow < 0)
		m_numRow = 16;

	m_board = new Tile[m_numCol * m_numRow];
}


void Board::destroy()
{

}

void Board::update(float dt)
{

}

void Board::draw()
{
	float const* colour = COLOUR_HIDDEN;
	int col, row;

	float halfX = (m_numCol-1) / 2.0f;
	float halfY = (m_numRow-1) / 2.0f;

	float tileWidth = (m_numCol * m_halfTileWidth*2 + (m_numCol - 1) * m_tileSpacing) / m_numCol;
	float tileHeight = (m_numRow * m_halfTileHeight*2 + (m_numRow - 1) * m_tileSpacing) / m_numRow;

	glPushMatrix();
	glTranslatef(m_boardOffsetWidth, m_boardOffsetHeight, 0.0f);

	for (int i = 0; i < m_numCol * m_numRow; ++i)
	{
		getColRow(i, col, row);

		if (m_board[i].getVisible() || m_gameOver)
		{
			colour = getColour(m_board[i].getValue());
		}
		else
			colour = COLOUR_HIDDEN;

		glPushMatrix();
		{
			glColor4fv(colour);
			glTranslatef((col - halfX) * tileWidth, (row - halfY) * tileHeight, 0.0f);

			glBegin(GL_QUADS);
			{
				glVertex2f(-m_halfTileWidth, -m_halfTileHeight);
				glVertex2f(m_halfTileWidth, -m_halfTileHeight);
				glVertex2f(m_halfTileWidth, m_halfTileHeight);
				glVertex2f(-m_halfTileWidth, m_halfTileHeight);
			}
			glEnd();
		}
		glPopMatrix();
	}

	glPopMatrix();
}


void Board::setGameOver(bool gameOver)
{
	m_gameOver = gameOver;

	if (m_gameOver)
	{
		//reassgin colours
		delete COLOUR_HIDDEN;
		delete COLOUR_MIN;
		delete COLOUR_QUARTER;
		delete COLOUR_HALF;
		delete COLOUR_MAX;
		
		COLOUR_HIDDEN =		new float[4]{ 1.00f, 1.00f, 1.00f, 1.0f };
		COLOUR_MIN =		new float[4]{ 0.25f, 0.25f, 0.25f, 1.0f };
		COLOUR_QUARTER =	new float[4]{ 0.50f, 0.50f, 0.00f, 1.0f };
		COLOUR_HALF =		new float[4]{ 0.50f, 0.25f, 0.00f, 1.0f };
		COLOUR_MAX =		new float[4]{ 0.50f, 0.00f, 0.00f, 1.0f };
	}

	else
	{
		//reassgin colours
		delete COLOUR_HIDDEN;
		delete COLOUR_MIN;
		delete COLOUR_QUARTER;
		delete COLOUR_HALF;
		delete COLOUR_MAX;

		COLOUR_HIDDEN = new float[4]{ 1.00f, 1.00f, 1.00f, 1.0f };
		COLOUR_MIN = new float[4]{ 0.50f, 0.50f, 0.50f, 1.0f };
		COLOUR_QUARTER = new float[4]{ 1.00f, 1.00f, 0.00f, 1.0f };
		COLOUR_HALF = new float[4]{ 1.00f, 0.50f, 0.00f, 1.0f };
		COLOUR_MAX = new float[4]{ 1.00f, 0.00f, 0.00f, 1.0f };
	}

}

/********************************************************************************\
 * Board class, getValue function												*
 * Returns the value at (x, y).  If out of bounds it returns -1.				*
 *																				*
 * Paramaters:																	*
 *   row: the row corrdinate.													*
 *   col: the colunm corrdinate.												*
 * Returns:																		*
 *   the value of the cell at (x, y) if successful.								*
 *   -1 if (x, y) is out of bounds.												*
\********************************************************************************/
int Board::getValue(int index) const
{
	if (!inBounds(index))
		return -1;

	return m_board[index].getValue();
}
int Board::getValue(int col, int row) const
{
	return getValue(getIndex(col, row));
}

/********************************************************************************\
 * Board class, setValue function												*
 * Sets the value at (x, y).  If out of bounds nothing is changed.				*
 *																				*
 * Paramaters:																	*
 *   row: the row corrdinate.													*
 *   col: the colunm corrdinate.												*
 *   value: the value to set the cell at (x, y) to.								*
\********************************************************************************/
void Board::setValue(int index, int value)
{
	if (!inBounds(index))
		return;

	m_board[index].setValue(value);
}
void Board::setValue(int col, int row, int value)
{
	setValue(getIndex(col, row), value);
}

bool Board::getVisible(int col, int row) const
{
	int index = getIndex(col, row);

	if (!inBounds(index))
		return -1;

	return m_board[index].getVisible();
}
void Board::setVisible(int col, int row, bool visible)
{
	int index = getIndex(col, row);

	if (!inBounds(index))
		return;

	m_board[index].setVisible(visible);
}

void Board::setAllVisible(bool visible)
{
	for (int i = 0; i < m_numCol * m_numRow; ++i)
	{
		m_board[i].setVisible(visible);
	}
}

/********************************************************************************\
 * Board class, getIndex function												*
 * Converts (x, y) into an index position.										*
 *																				*
 * Paramaters:																	*
 *   col: the colunm corrdinate.												*
 *   row: the row corrdinate.													*
 * Returns:																		*
 *   index of the cell at (x, y) if successful.									*
 *   -1 if (x, y) is out of bounds.												*
\********************************************************************************/
int Board::getIndex(int col, int row) const
{
	if (!inBounds(col, row))
		return -1;

	return row*m_numCol + col;
}

/********************************************************************************\
 * Board class, getXY function													*
 * Converts and index into (x, y) corrdinates.									*
 *																				*
 * Paramaters:																	*
 *   index: the index to convert to corrdinates.								*
 *   col: reference value to store the output for the colunm corrdinate.		*
 *   row: reference value to store the output for the row corrdinate.			*
 * Returns:																		*
 *   1 if successful.															*
 *  -1 if index is out of bounds.												*
\********************************************************************************/
int Board::getColRow(int index, int &col, int &row) const
{
	if(!inBounds(index))
		return -1;

	col = index % m_numCol;
	row = index / m_numCol;

	return 1;
}

/********************************************************************************\
 * Board class, getAjacentIndexes function										*
 * Returns an array of 8 adjacent index positions.  Any positions out of bounds *
 * are set to -1.																*
 *																				*
 * Paramaters:																	*
 *   col: the colunm corrdinate.												*
 *   row: the row corrdinate.													*
 * Returns:																		*
 *   array of 8 indexes adjacent to index.  positions out of bounds are set to	*
 *		-1.																		*
\********************************************************************************/
int * Board::getAjacentIndexes(int col, int row) const
{
	int * adjacentIndexes = new int[8];

	for(int i = 0; i < 8; ++i)
	{
		adjacentIndexes[i] = getAjacentIndex(static_cast<eAdjacentDirection>(i), col, row);
	}
	
	return adjacentIndexes;
}

/********************************************************************************\
 * Board class, getAjacentIndex function										*
 * Returns the index adjacent to index in the specified direction.				*
 *																				*
 * Paramaters:																	*
 *   direction: the direction to get the adjacent index for.					*
 *   col: the colunm corrdinate.												*
 *   row: the row corrdinate.													*
 * Returns:																		*
 *   adjacent index if successful.												*
 *   -1 if the adjacent index is out of bounds.									*
\********************************************************************************/
int Board::getAjacentIndex(eAdjacentDirection direction, int col, int row) const
{
	int adjacentIndex = -1;

	switch(direction)
	{
	case eAdjacentDirection::UP_LEFT:
		adjacentIndex = getIndex(col-1, row-1);
		break;

	case eAdjacentDirection::UP:
		adjacentIndex = getIndex(col, row-1);
		break;

	case eAdjacentDirection::UP_RIGHT:
		adjacentIndex = getIndex(col+1, row-1);
		break;

	case eAdjacentDirection::LEFT:
		adjacentIndex = getIndex(col-1, row);
		break;

	case eAdjacentDirection::RIGHT:
		adjacentIndex = getIndex(col+1, row);
		break;

	case eAdjacentDirection::DOWN_LEFT:
		adjacentIndex = getIndex(col-1, row+1);
		break;

	case eAdjacentDirection::DOWN:
		adjacentIndex = getIndex(col, row+1);
		break;

	case eAdjacentDirection::DOWN_RIGHT:
		adjacentIndex = getIndex(col+1, row+1);
		break;
	}

	return adjacentIndex;
}

bool Board::getColRow(float x, float y, int & col, int & row) const
{
	bool found = false;

	float halfX = (m_numCol - 1) / 2.0f;
	float halfY = (m_numRow - 1) / 2.0f;

	float tileWidth = (m_numCol * m_halfTileWidth * 2 + (m_numCol - 1) * m_tileSpacing) / m_numCol;
	float tileHeight = (m_numRow * m_halfTileHeight * 2 + (m_numRow - 1) * m_tileSpacing) / m_numRow;

	for (int i = 0; !found && i < m_numCol; ++i)
	{
		if (isInCol(i, x))
		{
			for (int j = 0; !found && j < m_numRow; ++j)
			{
				if (isInRow(j, y))
				{
					found = true;
					col = i;
					row = j;
				}
			}
		}
	}

	return found;
}

float const* Board::getColour(int value) const
{
	if (value >= m_maxValue)
	{
		return COLOUR_MAX;
	}
	else if (value >= m_maxValue / 2)
	{
		return COLOUR_HALF;
	}
	else if (value >= m_maxValue / 4)
	{
		return COLOUR_QUARTER;
	}
	else
		return COLOUR_MIN;
}

bool Board::isInCol(int col, float x) const
{
	float colCentre;

	colCentre = ((col - (m_numCol - 1) / 2.0f) * (m_numCol * m_halfTileWidth * 2 + (m_numCol - 1) * m_tileSpacing) / m_numCol) + m_boardOffsetWidth;

	return (x > colCentre - m_halfTileWidth && x < colCentre + m_halfTileWidth);
}

bool Board::isInRow(int row, float y) const
{
	float rowCentre;

	rowCentre = ((row - (m_numRow - 1) / 2.0f) * (m_numRow * m_halfTileHeight * 2 + (m_numRow - 1) * m_tileSpacing) / m_numRow) + m_boardOffsetHeight;

	return (y > rowCentre - m_halfTileHeight && y < rowCentre + m_halfTileHeight);
}

void Board::addResources(int index, int amount)
{
	if (!inBounds(index))
		return;

	int col = 0;
	int row = 0;
	int pow;
	int amountToAdd;

	getColRow(index, col, row);

	for (int i = -2; i < 3; ++i)
	{
		for (int j = -2; j < 3; ++j)
		{
			index = getIndex(col + i, row + j);

			if (inBounds(index))
			{
				if (std::abs(i) > std::abs(j))
					pow = std::abs(i);
				else
					pow = std::abs(j);

				amountToAdd = amount / std::pow(2, pow);

				if (getValue(index) < amountToAdd)
					setValue(index, amountToAdd);
			}
		}
	}
}

int Board::mineResources(int col, int row)
{
	int amount;


	amount = getValue(col, row);
	setValue(col, row, 0);

	m_board[3];

	for (int i = -2; i < 3; ++i)
	{
		for (int j = -2; j < 3; ++j)
		{
			setValue(col + i, row + j, getValue(col + i, row + j) / 2);
		}
	}

	return amount;
}