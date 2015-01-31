#ifndef _MINING_GAME_H
#define _MINING_GAME_H

#include <ctime>

#include "gameEngine.h"

namespace GAME3011_Assignment1
{
	class Board;

	class MiningGame : public GameEngine::Engine
	{
	protected:
		MiningGame();
		~MiningGame();

	public:
		static MiningGame * instance();

		void startup();
		void shutdown();

		void update();

	private:
		Board * m_board;

		GameEngine::Engine * m_engne;
	};
}


#endif