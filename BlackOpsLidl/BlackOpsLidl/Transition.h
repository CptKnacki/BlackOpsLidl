#pragma once
#include "BlackBoard.h"

class State;

class Transition
{
protected:
	BlackBoard* blackBoard;
	State* nextState;

public:
	State* GetNextState() const 
	{
		return nextState;
	}

	void SetNextState(State* _state)
	{
		nextState = _state;
	}

public:
	Transition(BlackBoard* _blackBoard);

public:
	virtual void Init(State* _state) = 0;
	virtual bool CanNext() const = 0;
};