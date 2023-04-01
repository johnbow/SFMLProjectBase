#pragma once

#include "SFML/Graphics.hpp"

#include "State.h"

class GameState : public State
{
private:

	void initTextures();
	void initEntities();

public:
	GameState(sf::RenderWindow& window);
	virtual void processEvents() override;
	virtual void update(sf::Time dt) override;
	virtual void draw() override;
};

