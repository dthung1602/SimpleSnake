#include <sstream>
#include <iostream>

using namespace std;

#include "Snake.h"

Snake::Snake(World &world, unsigned int length)
        : blockSize(world.getBlockSize()),
          body(length) {

    auto worldSize = world.getWorldSize();
    auto xStart = (worldSize.x - length * blockSize + 1) / 2.0f;

    for (int i = 0; i < length; i++) {
        body[i].setPosition(xStart + i * blockSize, worldSize.y / 2.0f);
        cout << body[i].getPosition().x << " - " << body[i].getPosition().y << endl;
        body[i].setFillColor(BODY_COLOR);
        body[i].setSize({blockSize - 1, blockSize - 1});
    }

    body[0].setFillColor(HEAD_COLOR);
}

void Snake::update(World &world) {
    move();
//    eat();
}

void Snake::move() {
    for (auto &i : body)
        cout << i.getPosition().x << " ";
    cout << endl;

    auto realDirection = direction;
    if (direction == Direction::NONE) {
        realDirection = getRealDirection();
    } else {
        direction = Direction::NONE;
    }

    for (auto i = body.size() - 1; i > 0; i--)
        body[i].setPosition(body[i - 1].getPosition());

    auto headPos = body[0].getPosition();
    cout << realDirection.x << " * " << realDirection.y << endl;
    body[0].setPosition(headPos.x + (int) blockSize * realDirection.x,
                        headPos.y + (int) blockSize * realDirection.y);

//    for (auto &i : body)
//        cout << i.getPosition().x << " ";
//    cout << endl;

}

void Snake::eat() {
//    if (global::food and contain_point(*(global::food))) {
//
//        // eat food
//        global::food->eaten();
//
//        // grow up
//        Point new_tail(tail * 2 - body.back());
//        body.push_back(tail);
//        coordinate_set.insert(tail);
//        tail = new_tail;
//    }
}

//void Snake::turn(Direction d) {
//    if (d != direction and not d.is_opposite(direction)) {
//        direction = d;
//        just_changed_direction = true;
//    }
//}

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

void Snake::checkCollision(Window &window) {

}

bool Snake::containPoint(sf::Vector2u vector) {
    // TODO
    return false;
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
