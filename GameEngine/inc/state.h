#ifndef _STATE_H
#define _STATE_H

#include <vector>

namespace GameEngine
{
	class StateMachine;

	class State
	{
	public:
		enum class StateType
		{
			STATE_BASE,
			STATE_USERDEFINED
		};

		State();
		virtual ~State();

		virtual void init(std::vector<State *> validStates);
		bool isValidState(State const* state) const;

		virtual void enter() = 0;
		virtual void exit() = 0;

		virtual StateType getType() const { return StateType::STATE_BASE; }

	protected:
		std::vector<State *> m_validStates;

	};

	bool operator==(State const& state1, State const& state2);
	bool operator!=(State const& state1, State const& state2);
}

#endif