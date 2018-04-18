//
// Created by hung on 08/03/18.
//

#ifndef SFMLSNAKE_DIRECTION_H
#define SFMLSNAKE_DIRECTION_H

#include <SFML/Graphics.hpp>

class Direction {

public:
    static const sf::Vector2i NONE;
    static const sf::Vector2i RIGHT;
    static const sf::Vector2i LEFT;
    static const sf::Vector2i UP;
    static const sf::Vector2i DOWN;
};

const sf::Vector2i operator!(const sf::Vector2i &vector);

#endif //SFMLSNAKE_DIRECTION_H
