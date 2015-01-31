#include "miningGame.h"
#include "board.h"

using namespace GAME3011_Assignment1;

MiningGame::MiningGame() : GameEngine::Engine(), m_board(NULL)
{
}

MiningGame::~MiningGame()
{
	delete m_board;
}


MiningGame * MiningGame::instance()
{
	return static_cast<MiningGame*>(GameEngine::Engine::instance());
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