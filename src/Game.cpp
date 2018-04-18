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

}

void Game::update() {
//    if (timePassed) {
        window.update();
        world.update(snake);
        snake.update(world);
//    }
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



