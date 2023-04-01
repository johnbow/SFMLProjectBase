#include "GameState.h"

#include <random>

GameState::GameState(sf::RenderWindow& window) : State(window)
{
    initTextures();
    initEntities();
}

void GameState::initTextures()
{
    
}

void GameState::initEntities()
{

}

void GameState::processEvents() 
{
    sf::Event event;
    while (getWindow().pollEvent(event))
    {
        switch (event.type) {
        case sf::Event::Closed:
            setEvent(State::Event::CLOSED);
            break;
        case sf::Event::Resized: {
            break;
        }
        default: break;
        }
    }
}

void GameState::draw()
{
    getWindow().clear(sf::Color::Black);

    // draw here

    getWindow().display();
}

void GameState::update(sf::Time dt) 
{
}
