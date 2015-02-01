#ifndef _GAMESTATES_H
#define _GAMESTATES_H

#include "state.h"

namespace GAME3011_Assignment1
{
	class Board;

	enum class StateType
	{
		STATE_SCAN = static_cast<int>(GameEngine::State::StateType::STATE_USERDEFINED),
		STATE_MINE,
		STATE_END
	};

	struct GameStates
	{
		static GameEngine::State * gamestate_scan;
		static GameEngine::State * gamestate_mine;
		static GameEngine::State * gamestate_end;
	};

	class GameState : public GameEngine::State
	{
	public:
		GameState();
		virtual ~GameState();

		virtual void init(State * next);

		virtual void clickAction(Board * board, int col, int row) = 0;
		virtual State * getNext();
		virtual int getActionsLeft() const { return m_actionsLeft; }

	protected:
		State * m_next;
		int m_actionsLeft;
	};

	class GameState_Scan : public GameState
	{
	public:
		GameState_Scan();
		virtual ~GameState_Scan();

		virtual void init();
		virtual void enter();
		virtual void exit();

		virtual void clickAction(Board * board, int col, int row);

		virtual StateType getType() const { return static_cast<GameEngine::State::StateType>(GAME3011_Assignment1::StateType::STATE_SCAN); }
	};

	class GameState_Mine : public GameState
	{
	public:
		GameState_Mine();
		virtual ~GameState_Mine();

		virtual void init();
		virtual void enter();
		virtual void exit();

		virtual void clickAction(Board * board, int col, int row);

		virtual StateType getType() const { return static_cast<GameEngine::State::StateType>(GAME3011_Assignment1::StateType::STATE_MINE); }

		int getAmountCollected() const { return m_amountCollected; }

	private:
		int m_amountCollected;
	};

	class GameState_End : public GameState
	{
	public:
		GameState_End();
		virtual ~GameState_End();

		virtual void init();
		virtual void enter();
		virtual void exit();

		virtual void clickAction(Board * board, int col, int row);
		virtual StateType getType() const { return static_cast<GameEngine::State::StateType>(GAME3011_Assignment1::StateType::STATE_END); }
	};
}

#endif