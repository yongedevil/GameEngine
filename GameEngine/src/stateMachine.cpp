#include "stateMachine.h"
#include "state.h"

using namespace GameEngine;

StateMachine::StateMachine() :
curState(NULL)
{

}

StateMachine::~StateMachine()
{

}

void StateMachine::start(State * initialState)
{
	if (initialState)
	{
		curState = initialState;
		curState->enter();
	}
}

bool StateMachine::changeState(State * state)
{
	bool changed = false;

	if (curState && curState->isValidState(state) && *state != *curState)
	{
		curState->exit();
		curState = state;
		curState->enter();

		changed = true;
	}

	return changed;
}