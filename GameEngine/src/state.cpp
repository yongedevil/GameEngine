#include "state.h"

using namespace GameEngine;

State::State()
{
}

State::~State()
{

}

bool State::isValidState(State const* state) const
{
	bool found = false;
	std::vector<State *>::const_iterator it;
	for (it = m_validStates.cbegin(); !found && it != m_validStates.cend(); ++it)
	{
		if (**it == *state)
			found = true;
	}

	return found;
}

void State::init(std::vector<State *> validStates)
{
	m_validStates = validStates;
}

bool GameEngine::operator==(State const& state1, State const& state2)
{
	return state1.getType() == state2.getType();
}
bool GameEngine::operator!=(State const& state1, State const& state2)
{
	return !(state1 == state2);
}
