//
// Created by hung on 17/04/18.
//

#include <iostream>

#include "Game.h"
#include "TextBox.h"

using namespace std;


Game::Game() : window(GAME_NAME),
               world(window),
               snake(world) {

    // load font
    std::shared_ptr<sf::Font> fontPtr(new sf::Font());
    if (!fontPtr->loadFromFile("../resources/arial.ttf"))    // todo fix path
        exit(EXIT_FAILURE);

    auto &textboxes = window.getTextboxes();

    auto textbox = std::make_shared<TextBox>("blah", fontPtr, 20);

    textbox->setPadding({5, 5});
    textbox->setPosition({30, 30});
    textbox->setTextColor(sf::Color::White);

    textbox->setBackgroundColor(sf::Color::Magenta);
    textbox->setBackgroundSize({100, 50});

    textboxes.push_back(std::move(textbox));
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
    if (timePassed) {
        cout << "------------------------------" << endl;
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
    timePassed = (sec > timeInterval) ? (clock.restart(), true) : false;
}

const char Game::GAME_NAME[] = "SFML Snake";



