#include "miningGame.h"

#include <random>
#include <ctime>

#include "board.h"
#include "entity.h"

using namespace GAME3011_Assignment1;

const int MiningGame::BOARDWIDTH = 16;
const int MiningGame::BOARDHEIGHT = 16;

MiningGame * MiningGame::s_instance = NULL;

MiningGame::MiningGame() : GameEngine::Engine(), m_board(NULL)
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

	//add resources to the board
	generateResources(6, 8, 1000);
}

void MiningGame::shutdown()
{
	GameEngine::Engine::shutdown();
}

void MiningGame::update()
{
	GameEngine::Engine::update();
}


void MiningGame::keyboard(unsigned char key, int state, int x, int y)
{
	GameEngine::Engine::keyboard(key, state, x, y);
}
void MiningGame::mouse(int button, int state, int x, int y)
{
	GameEngine::Engine::mouse(button, state, x, y);

	int col = 0;
	int row = 0;
	float worldX = 0;
	float worldY = 0;

	GameEngine::Engine::screenToWorld(x, y, 0, worldX, worldY);

	if (m_board->getColRow(worldX, worldY, col, row))
	{
		for (int i = -1; i < 2; ++i)
		{
			for (int j = -1; j < 2; ++j)
			{
				m_board->setVisible(col + i, row + j, true);
			}
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