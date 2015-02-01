#include "miningGame.h"

#include <random>
#include <ctime>

#include "board.h"
#include "hud.h"
#include "entity.h"
#include "stateMachine.h"
#include "gameStates.h"

using namespace GAME3011_Assignment1;

const int MiningGame::BOARDWIDTH = 16;
const int MiningGame::BOARDHEIGHT = 16;

MiningGame * MiningGame::s_instance = NULL;

MiningGame::MiningGame() :
GameEngine::Engine(),
m_board(NULL),
m_hud(NULL),
m_stateMachine(NULL)
{
}

MiningGame::~MiningGame()
{
	delete m_board;
}


MiningGame * MiningGame::instance()
{
	if (NULL == s_instance)
	{
		s_instance = new MiningGame();
	}

	return s_instance;
}

void MiningGame::startup()
{
	GameEngine::Engine::startup();

	srand(std::time(NULL));

	GameEngine::Entity * boardEnt = GameEngine::Engine::createEntity<GameEngine::Entity>();

	m_board = boardEnt->addComponent<Board>();
	m_board->init(BOARDWIDTH, BOARDHEIGHT);
	m_board->setActive(true);

	//add resources to the board
	generateResources(6, 8, 1000);

	//setup state machine
	GameState_Scan * stateScan = new GameState_Scan();
	GameState_Mine * stateMine = new GameState_Mine();
	GameState_End * stateEnd = new GameState_End();

	GameStates::gamestate_scan = stateScan;
	GameStates::gamestate_mine = stateMine;
	GameStates::gamestate_end = stateEnd;

	stateScan->init();
	stateMine->init();
	stateEnd->init();

	m_stateMachine = new GameEngine::StateMachine();
	m_stateMachine->start(GameStates::gamestate_scan);

	//setup HUD
	GameEngine::Entity * hudEnt = GameEngine::Engine::createEntity<GameEngine::Entity>();

	m_hud = hudEnt->addComponent<HUD>();
	m_hud->init();
	m_hud->setScanCount(dynamic_cast<GameState*>(GameStates::gamestate_scan)->getActionsLeft());
	m_hud->setMineCount(dynamic_cast<GameState*>(GameStates::gamestate_mine)->getActionsLeft());
	m_hud->setMode(m_stateMachine->getState());
}

void MiningGame::shutdown()
{
	GameEngine::Engine::shutdown();
}

void MiningGame::update()
{
	GameEngine::Engine::update();
	
	m_hud->setScore(dynamic_cast<GameState_Mine*>(GameStates::gamestate_mine)->getAmountCollected());
	m_hud->setScanCount(dynamic_cast<GameState*>(GameStates::gamestate_scan)->getActionsLeft());
	m_hud->setMineCount(dynamic_cast<GameState*>(GameStates::gamestate_mine)->getActionsLeft());
	m_hud->setMode(m_stateMachine->getState());


	if (m_stateMachine->getState() == GameStates::gamestate_end)
	{
		m_board->setGameOver(true);
	}
	else if (dynamic_cast<GameState*>(GameStates::gamestate_mine)->getActionsLeft() <= 0)
	{
		m_stateMachine->changeState(GameStates::gamestate_end);
	}
}


void MiningGame::keyboard(unsigned char key, int state, int x, int y)
{
	GameEngine::Engine::keyboard(key, state, x, y);

	switch (key)
	{
	case ' ':
		if (0 == state)
		{
			GameState * gamestate = dynamic_cast<GameState*>(m_stateMachine->getState());
			m_stateMachine->changeState(gamestate->getNext());
		}
		break;
	}
}
void MiningGame::mouse(int button, int state, int x, int y)
{
	GameEngine::Engine::mouse(button, state, x, y);

	int col = 0;
	int row = 0;
	float worldX = 0;
	float worldY = 0;

	if (0 == state)
	{
		GameState * gamestate = dynamic_cast<GameState *>(m_stateMachine->getState());

		//convert from screen to world and then to board
		GameEngine::Engine::screenToWorld(x, y, 0, worldX, worldY);
		if (m_board->getColRow(worldX, worldY, col, row))
		{
			gamestate->clickAction(m_board, col, row);
		}
	}
}

void MiningGame::generateResources(int minNodes, int maxNodes, int amount)
{
	int numNodes;
	int nodeAmount;
	int attempts;
	int index;

	numNodes = rand() % (maxNodes - minNodes + 1) + minNodes;
	m_board->setMaxValue(amount); //sets the amount for the max nodes on the board so the colours are set properly

	for (int i = 0; i < numNodes; ++i)
	{
		//calcutate how much to add to this node, can but up to 20% more than amount
		nodeAmount = rand() % (int)(amount * 1.2 - amount + 1) + amount;

		//find a tile to add the resources to that isn't already set to at least value max
		attempts = 0;
		do
		{
			index = rand() % (BOARDWIDTH * BOARDHEIGHT);
			++attempts;
		} while (attempts < 100 && m_board->getValue(index) >= amount);

		//add resouces
		m_board->addResources(index, nodeAmount);
	}
}