#include "gameStates.h"

#include "board.h"
#include <vector>

using namespace GAME3011_Assignment1;

GameEngine::State * GameStates::gamestate_scan = NULL;
GameEngine::State * GameStates::gamestate_mine = NULL;

GameState::GameState() : m_next(NULL)
{

}
GameState::~GameState()
{

}
void GameState::init(State * next)
{
	m_next = next;
}

GameEngine::State * GameState::getNext()
{
	return m_next;
}


GameState_Scan::GameState_Scan()
{
}

GameState_Scan::~GameState_Scan()
{

}

void GameState_Scan::init()
{
	m_actionsLeft = 6;

	std::vector<State *> validStates;

	validStates.push_back(GameStates::gamestate_mine);
	State::init(validStates);
	GameState::init(GameStates::gamestate_mine);
}

void GameState_Scan::enter()
{

}

void GameState_Scan::exit()
{

}

void GameState_Scan::clickAction(Board * board, int col, int row)
{
	if (board && m_actionsLeft > 0)
	{
		--m_actionsLeft;

		for (int i = -1; i < 2; ++i)
		{
			for (int j = -1; j < 2; ++j)
			{
				board->setVisible(col + i, row + j, true);
			}
		}
	}
}


GameState_Mine::GameState_Mine()
:
m_amountCollected(0)
{
}

GameState_Mine::~GameState_Mine()
{

}

void GameState_Mine::init()
{
	m_actionsLeft = 3;
	m_amountCollected = 0;

	std::vector<State *> validStates;

	validStates.push_back(GameStates::gamestate_scan);
	State::init(validStates);
	GameState::init(GameStates::gamestate_scan);
}

void GameState_Mine::enter()
{

}

void GameState_Mine::exit()
{

}

void GameState_Mine::clickAction(Board * board, int col, int row)
{
	if (board && m_actionsLeft > 0)
	{
		--m_actionsLeft;
		m_amountCollected += board->mineResources(col, row);
	}
}

