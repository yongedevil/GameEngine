#ifndef _HUD_H
#define _HUD_H

#include "component.h"
#include "typedeff_miningGame.h"

namespace GameEngine
{
	class State;
}
namespace GAME3011_Assignment1
{
	class GameState;

	class HUD : public GameEngine::Component
	{
	public:
		enum class Mode
		{
			MODE_SCAN,
			MODE_MINE,
			MODE_END
		};

		HUD();
		virtual ~HUD();

		void init();
		void destroy();

		static GameEngine::ComponentType type() { return static_cast<GameEngine::ComponentType>(ComponentType::COMPONENT_HUD); }
		GameEngine::ComponentType getType() const { return static_cast<GameEngine::ComponentType>(ComponentType::COMPONENT_HUD); }

	protected:
		void update(float dt);
		void draw();


	public:
		void setScanCount(int scanCount) { m_scanCount = scanCount; }
		void setMineCount(int mineCount) { m_mineCount = mineCount; }
		void setScore(int score) { m_score = score; }
		void setMode(GameEngine::State * curState);

	private:
		int m_scanCount;
		int m_mineCount;
		int m_score;
		Mode m_mode;
	};
}

#endif