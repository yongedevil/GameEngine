#ifndef _MINING_GAME_H
#define _MINING_GAME_H

#include <ctime>

#include "gameEngine.h"

namespace GameEngine
{
	class StateMachine;
}

namespace GAME3011_Assignment1
{
	class Board;
	class HUD;

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

		void keyboard(unsigned char key, int state, int x, int y);
		void mouse(int button, int state, int x, int y);

	private:
		void generateResources(int minNodes, int maxNodes, int amount);

	private:
		static const int BOARDWIDTH;
		static const int BOARDHEIGHT;

		static MiningGame * s_instance;

		Board * m_board;
		HUD * m_hud;
		GameEngine::StateMachine * m_stateMachine;
	};
}


#endif