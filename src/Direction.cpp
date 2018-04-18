#include "Direction.h"

const sf::Vector2i Direction::NONE = sf::Vector2(0, 0);
const sf::Vector2i Direction::RIGHT = sf::Vector2(1, 0);
const sf::Vector2i Direction::LEFT = sf::Vector2(-1, 0);
const sf::Vector2i Direction::UP = sf::Vector2(0, -1);
const sf::Vector2i Direction::DOWN = sf::Vector2(0, 1);

const sf::Vector2i operator!(const sf::Vector2i &vector) {
    return {-vector.x, -vector.y};
}
