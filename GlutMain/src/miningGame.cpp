#include "miningGame.h"

using namespace GAME3011_Assignment1;

MiningGame::MiningGame() : GameEngine::Engine()
{
	m_board = new Board(16, 16);
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
}

void MiningGame::shutdown()
{
	GameEngine::Engine::shutdown();
}

void MiningGame::update()
{
	GameEngine::Engine::update();
	GameEngine::Engine::draw();
}