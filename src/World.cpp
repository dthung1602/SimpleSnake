//
// Created by hung on 18/04/18.
//

#include <random>
#include <iostream>

#include "World.h"
#include "Snake.h"

using namespace std;

World::World(Window &window, unsigned int blockSize) : blockSize(blockSize) {
    srand(time(NULL));

    food.setFillColor(FOOD_COLOR);
    food.setSize({blockSize, blockSize});
    food.setOrigin(blockSize / 2.0f, blockSize / 2.0f);
    reset(window);

    // set colors
    for (auto &wall : walls)
        wall.setFillColor(WALL_COLOR);
}


void World::update(Snake &snake) {
    if (foodEaten) {
        cout << "eaten" << endl;
        spawnFood(snake);
        // TODO inc score
    }
}

void World::render(Window &window) {
    for (auto &wall : walls)
        window.draw(wall);
    window.draw(food);
}

void World::reset(Window &window) {
    worldSize = window.getWindowSize();
    foodEaten = true;

    // wall 0, 1, 2, 3 = top, bottom, left, right
    // set sizes for walls
    walls[0].setSize({worldSize.x, blockSize});
    walls[1].setSize({worldSize.x, blockSize});
    walls[2].setSize({blockSize, worldSize.y});
    walls[3].setSize({blockSize, worldSize.y});

    // set positions for walls
    walls[0].setPosition(0, 0);
    walls[1].setPosition(0, worldSize.y - blockSize);
    walls[2].setPosition(0, 0);
    walls[3].setPosition(worldSize.x - blockSize, 0);
}

void World::spawnFood(Snake &snake) {
    auto maxX = (worldSize.x / blockSize) - 2;
    auto maxY = (worldSize.y / blockSize) - 2;

    sf::Vector2f pos;
    auto end = snake.getEndOfBody();
    do {
        pos = {rand() % maxX + 1, rand() % maxY + 1};
    } while (snake.containPoint(pos) != end);


    food.setPosition((pos.x + 0.5f) * blockSize, (pos.y + 0.5f) * blockSize);
    foodEaten = false;
}

const sf::Color World::WALL_COLOR = sf::Color::Blue;
const sf::Color World::FOOD_COLOR = sf::Color::Red;