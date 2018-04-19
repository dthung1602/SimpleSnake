//
// Created by hung on 17/04/18.
//

#include <iostream>
#include "Game.h"

using namespace std;


Game::Game() : window(GAME_NAME),
               world(window),
               snake(world) {}

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
    if (timePassed) {
        cout << "Updated" << endl;
        window.update();
        world.update(snake);
        snake.update(world);
    }
}

void Game::render() {
    window.beginDraw();

    world.render(window);
    snake.render(window);

    window.endDraw();
}

void Game::checkClock() {
    float sec = clock.getElapsedTime().asSeconds();
//    cout << sec << endl;
    timePassed = (sec > timeInterval) ? (clock.restart(), true) : false;
}

const char Game::GAME_NAME[] = "SFML Snake";



