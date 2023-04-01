#pragma once

#include "State.h"
#include "GameState.h"

#include <memory>

class Game
{
private:
	std::unique_ptr<State> currentState;

	void loop();
	void checkStateEvent();

public:
	void start();
	void stop();
};

