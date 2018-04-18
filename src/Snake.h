#ifndef SNAKE_H
#define SNAKE_H

#include <sstream>
#include <deque>
#include <SFML/Graphics.hpp>

#include "Direction.h"
#include "World.h"

class Snake {
    friend std::stringstream &operator<<(std::stringstream &stream, const Snake &snake); // for debugging

public:

    explicit Snake(World &world, unsigned int length = INIT_LENGTH);

    void update(World &world);

    void turn(Direction d);

    void render(Window &window);

    bool is_dead();

    void reset(World &world);

    bool containPoint(sf::Vector2u vector);

private:
    static const unsigned int INIT_LENGTH = 8;
    static const sf::Color BODY_COLOR;
    static const sf::Color HEAD_COLOR;

    void move();

    void eat();

    void cut();

    void checkCollision(Window &window);

    sf::Vector2i direction = Direction::NONE;
    bool just_changed_direction = false;
    unsigned int blockSize;
    std::deque<sf::RectangleShape> body;
    sf::Vector2i tail;
};


#endif //TEST_SNAKE_H
