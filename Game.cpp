#include "Game.h"

void Game::loop() {
    sf::Clock clock;

    while(this->currentState->getWindow().isOpen())
    {
        sf::Time dt = clock.restart();
        this->currentState->processEvents();
        this->currentState->update(dt);
        this->currentState->draw();

        this->checkStateEvent();
    }
}

void Game::checkStateEvent() {
    switch (this->currentState->getEvent()) {
    case State::Event::CLOSED:
        this->stop();
        break;
    case State::Event::STATE_CHANGED:
        this->currentState = this->currentState->getNewState();
        break;
    default: break;
    }
}

void Game::start() {
	sf::RenderWindow window(sf::VideoMode(1000, 810), "Doodle Jump");
	this->currentState = std::make_unique<GameState>(window);
    this->loop();
}

void Game::stop() {
    this->currentState->getWindow().close();
}
