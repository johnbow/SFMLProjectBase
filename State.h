#pragma once

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

#include <memory>

class State	// ABC
{
public:
	enum class Event { NONE, STATE_CHANGED, CLOSED };
	State(sf::RenderWindow& window);

	virtual void processEvents() = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void draw() = 0;

	State::Event getEvent() const;
	std::unique_ptr<State> getNewState();
	sf::RenderWindow& getWindow();

private:
	sf::RenderWindow& window;
	State::Event event = State::Event::NONE;

protected:
	void setEvent(State::Event newState);
};

