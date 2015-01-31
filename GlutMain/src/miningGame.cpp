#include "miningGame.h"

#include "board.h"
#include "entity.h"

#include "vector.h"

using namespace GAME3011_Assignment1;

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

	GameEngine::Entity * boardEnt = GameEngine::Engine::createEntity<GameEngine::Entity>();

	m_board = boardEnt->addComponent<Board>();
	m_board->init(16, 16);
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
		m_board->getValue(col, row);

	}
}