//
// Created by hung on 17/04/18.
//

#include <iostream>

#include "Game.h"
#include "TextBox.h"

using namespace std;


Game::Game() : window(GAME_NAME),
               world(window),
               snake(world),
               hud() {
    reset();
}

void Game::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        snake.turn(Direction::UP);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        snake.turn(Direction::DOWN);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        snake.turn(Direction::LEFT);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        snake.turn(Direction::RIGHT);
}

void Game::update() {
    if (isLost()) {
        // todo
        exit(0);
    } else if (timePassed) {
        window.update(*this);
        world.update(snake);
        snake.update(world, *this);
        hud.update(*this);
    }
}

void Game::render() {
    window.beginDraw();

    world.render(window);
    snake.render(window);
    hud.render(window);

    window.endDraw();
}

void Game::checkClock() {
    float sec = clock.getElapsedTime().asSeconds();
    timePassed = (sec > timeInterval) ? (clock.restart(), true) : false;
}

void Game::reset() {
    score = 0;
    life = INIT_LIVES;
    world.reset(window);
    snake.reset(world);
}

void Game::incScore() {
    stateChanged = true;
    score += SCORE_PER_FOOD;
};

void Game::decLife() {
    stateChanged = true;
    life--;
}

void Game::decAllLives() {
    stateChanged = true;
    life = 0;
}

const char Game::GAME_NAME[] = "SFML Snake";
