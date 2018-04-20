#include <sstream>
#include <iostream>

using namespace std;

#include "Snake.h"

Snake::Snake(World &world, unsigned int length)
        : blockSize(world.getBlockSize()),
          body(length) {

    worldOffset = world.getWorldOffset();

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
    auto head = body[0].getPosition();

    if (isElapse(food, head)) {
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

void Snake::cut(BodyIter position) {
    // TODO -life
    body.erase(position, getEndOfBody());
}

void Snake::checkWallCollision(World &world) {
    auto head = body[0].getPosition();
    auto worldSize = world.getWorldSize();
    if (head.x < blockSize or head.x > worldSize.x - blockSize or
        head.y < blockSize or head.y > worldSize.y - blockSize) {
        // TODO
        cout << "YOU HAVE LOST!";
        exit(EXIT_SUCCESS);
    }
}

Snake::BodyIter Snake::containPoint(sf::Vector2f point) {
    auto halfBlock = static_cast<float>(blockSize) / 2;

    auto end = body.end();
    for (auto iter = body.begin(); iter != end; iter++) {
        auto blockPos = iter->getPosition();

        if (isElapse(blockPos, point))
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
    auto head = body[0].getPosition();
    auto end = getEndOfBody();
    for (auto iter = body.begin() + 1; iter != end; iter++)
        if (isElapse(head, iter->getPosition())) {
            cout << "*****   CUT at " << distance(body.begin(), iter) << endl;
            cut(iter);
        }
}

void Snake::grow() {
    cout << ">>>>>>>>>" << endl;
    auto size = body.size();
    auto tailPos = body[size - 1].getPosition() * 2.0f - body[size - 2].getPosition();
    body.push_back(body[size - 1]);
    body[size].setPosition(tailPos);
}

template<typename V, typename U>
bool Snake::isElapse(sf::Vector2<V> point1, sf::Vector2<U> point2) {
    auto halfBlock = blockSize / 2;
    return point1.x - halfBlock < point2.x and
           point1.x + halfBlock > point2.x and
           point1.y - halfBlock < point2.y and
           point1.y + halfBlock > point2.y;
}
