#ifndef SNAKE_H
#define SNAKE_H

#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Direction.h"
#include "World.h"

class Snake {
    friend std::stringstream &operator<<(std::stringstream &stream, const Snake &snake); // for debugging

public:
    using BodyContainer = std::vector<sf::RectangleShape>;
    using BodyIter = typename BodyContainer::iterator;

    explicit Snake(World &world, unsigned int length = INIT_LENGTH);

    void update(World &world);

    void turn(sf::Vector2i direc);

    void render(Window &window);

    bool isDead();

    void reset(World &world);

    BodyIter containPoint(sf::Vector2f point);

    BodyIter getEndOfBody() { return body.end(); }

private:
    static const unsigned int INIT_LENGTH = 8;
    static const sf::Color BODY_COLOR;
    static const sf::Color HEAD_COLOR;

    void move(World &world);

    void eat(World &world);

    void cut();

    void grow();

    void checkSelfIntersection();

    void checkWallCollision(World &world);

    sf::Vector2i getRealDirection();

    sf::Vector2i direction = Direction::NONE;

    unsigned int blockSize;
    BodyContainer body;
};


#endif //TEST_SNAKE_H
