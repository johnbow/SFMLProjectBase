#include "State.h"

State::State(sf::RenderWindow& window) : window(window) {}

sf::RenderWindow& State::getWindow() {
	return this->window;
}

State::Event State::getEvent() const {
	return this->event;
}

std::unique_ptr<State> State::getNewState() {
	return NULL;	// TODO: implemented
}

void State::setEvent(State::Event newState) {
	this->event = newState;
}
