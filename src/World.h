//
// Created by hung on 18/04/18.
//

#ifndef SFMLSNAKE_WORLD_H
#define SFMLSNAKE_WORLD_H

#include <SFML/Graphics.hpp>
#include <array>

#include "Window.h"

class Snake;

class World {
public:
    World(Window &window, unsigned int blockSize = BLOCK_SIZE);

    void update(Snake &snake);

    void render(Window &window);

    void reset(Window &window);

    auto getWorldSize() { return worldSize; }

    auto getBlockSize() { return blockSize; }

private:
    void spawnFood(Snake &snake);

    static const sf::Color WALL_COLOR;
    static const sf::Color FOOD_COLOR;
    static const unsigned int BLOCK_SIZE = 10;

    unsigned int blockSize;
    sf::Vector2u worldSize;

    sf::RectangleShape food;
    bool foodEaten;

    std::array<sf::RectangleShape, 4> walls;
};


#endif //SFMLSNAKE_WORLD_H
