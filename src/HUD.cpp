//
// Created by hung on 20/04/18.
//

#include "HUD.h"
#include "Window.h"
#include "Game.h"

#include <iostream>

HUD::HUD() {
    // load font
    if (!font.loadFromFile("../resources/arial.ttf"))    // todo fix path
        exit(EXIT_FAILURE);

    // score
    score = {"Score: 03", font, DEFAULT_TEXT_SIZE};
    score.setPosition({0, 0});
    score.setPadding({8, 8});
    score.setTextColor(sf::Color::White);
    score.setBackgroundColor(sf::Color::Transparent);

    // life
    life = {"Life: x x x x", font, DEFAULT_TEXT_SIZE};
    life.setPosition({0, 35});
    life.setPadding({8, 8});
    life.setTextColor(sf::Color::White);
    life.setBackgroundColor(sf::Color::Transparent);

    // info
    info = {"", font, DEFAULT_TEXT_SIZE};
    info.setVisible(false);
    info.setPosition({200, 0});
    info.setPadding({8, 8});
    info.setTextColor(sf::Color::Red);
    info.setBackgroundColor(sf::Color::Transparent);
}

void HUD::update(Game &game) {
    std::cout << game.isStateChanged() << std::endl;

    if (game.isStateChanged()) {
        score.setText("Score: " + std::to_string(game.getScore()));
        life.setText("Lives: " + std::to_string(game.getLife()));
        game.clearStateChanged();
    }
}

void HUD::render(Window &window) {
    score.render(window);
    life.render(window);
    info.render(window);
}
