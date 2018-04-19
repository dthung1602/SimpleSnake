#include <sstream>
#include <iostream>

using namespace std;

#include "Snake.h"

Snake::Snake(World &world, unsigned int length)
        : blockSize(world.getBlockSize()),
          body(length) {

    auto worldSize = world.getWorldSize();
    float x = (static_cast<int>(worldSize.x) / blockSize - length) / 2 * blockSize + blockSize / 2.0f; // NOLINT
    float y = static_cast<int>(worldSize.y) / blockSize / 2 * blockSize + blockSize / 2.0f; // NOLINT

    for (int i = 0; i < length; i++) {
        body[i].setPosition(x + i * blockSize, y);
        body[i].setFillColor(BODY_COLOR);
        body[i].setOrigin(blockSize / 2.0f, blockSize / 2.0f);
        body[i].setSize({blockSize - 1, blockSize - 1});
    }

    body[0].setFillColor(HEAD_COLOR);
}

void Snake::update(World &world) {
    move(world);
    checkSelfIntersection();
    checkWallCollision(world);
    eat(world);
}

void Snake::move(World &world) {
    auto realDirection = direction;
    if (direction == Direction::NONE) {
        realDirection = getRealDirection();
    } else {
        direction = Direction::NONE;
    }

    for (auto i = body.size() - 1; i > 0; i--)
        body[i].setPosition(body[i - 1].getPosition());

    auto headPos = body[0].getPosition();
    body[0].setPosition(headPos.x + (int) blockSize * realDirection.x,
                        headPos.y + (int) blockSize * realDirection.y);
}

void Snake::eat(World &world) {
    auto food = world.getFoodPosition();
    cout << "food: " << food.x << " - " << food.y << endl;
    for (auto &i : body)
        cout << i.getPosition().x << " " << i.getPosition().y << endl;

    if (containPoint(food) != getEndOfBody()) {
        grow();
        world.eatFood();
    }
}


void Snake::render(Window &window) {
    for (auto &block : body)
        window.draw(block);
}

bool Snake::isDead() {
//    // check self-intersect
//    if (body.size() != coordinate_set.size())
//        return true;
//
//    // check border collision
//    Point head = body[0];
//    return head.x == 0 or head.x == global::window_width - 1
//           or head.y == 0 or head.y == global::window_height - 1;
}

std::stringstream &operator<<(std::stringstream &stream, const Snake &snake) {
//    stream << snake.body.size() << ':' << snake.coordinate_set.size() << "    ";
//    for (auto &point : snake.coordinate_set)
//        stream << point << ' ';
//    stream << std::endl;
    return stream;
}


void Snake::reset(World &world) {

}

void Snake::cut() {

}

void Snake::checkWallCollision(World &world) {

}

Snake::BodyIter Snake::containPoint(sf::Vector2f point) {
    auto halfBlock = static_cast<float>(blockSize) / 2;

    auto end = body.end();
    for (auto iter = body.begin(); iter != end; iter++) {
        auto blockPos = iter->getPosition();

        if (blockPos.x - halfBlock < point.x and
            blockPos.x + halfBlock > point.x and
            blockPos.y - halfBlock < point.y and
            blockPos.y + halfBlock > point.y)
            return iter;
    }

    return end;
}

const sf::Color Snake::BODY_COLOR = sf::Color::Green;
const sf::Color Snake::HEAD_COLOR = sf::Color::Yellow;

void Snake::turn(sf::Vector2i direc) {
    if (direc != !getRealDirection())
        direction = direc;
}

sf::Vector2i Snake::getRealDirection() {
    auto direction = body[0].getPosition() - body[1].getPosition();
    return sf::Vector2i(
            (int) direction.x / (int) blockSize,
            (int) direction.y / (int) blockSize
    );
}

void Snake::checkSelfIntersection() {

}

void Snake::grow() {
    cout << ">>>>>>>>>" << endl;
    auto size = body.size();
    auto tailPos = body[size - 1].getPosition() * 2.0f - body[size - 2].getPosition();
    body.push_back(body[size - 1]);
    body[size].setPosition(tailPos);
}
