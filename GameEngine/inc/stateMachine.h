#ifndef _STATEMACHINE_H
#define _STATEMACHINE_H

namespace GameEngine
{
	class State;

	class StateMachine
	{
	public:
		StateMachine();
		virtual ~StateMachine();

		void start(State * initialState);

		State * getState() const { return curState; }
		virtual bool changeState(State * state);

	private:
		State * curState;
	};
}

#endif