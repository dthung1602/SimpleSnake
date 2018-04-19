//
// Created by hung on 17/04/18.
//

#ifndef SFMLSNAKE_GAME_H
#define SFMLSNAKE_GAME_H

#include "Window.h"
#include "Snake.h"
#include "World.h"

class Game {
public:
    Game();

    ~Game() = default;

    void handleInput();

    void update();

    void render();

    void checkClock();

    bool timeIntervalPassed() { return timePassed; };

    Window &getWindow() { return window; };

private:
    static const char GAME_NAME[];

    Window window;
    World world;
    Snake snake;

    sf::Clock clock;
    bool timePassed = false;
    static const unsigned int frameRate = 2;
    static constexpr float timeInterval = 1.0f / frameRate;
};


#endif //SFMLSNAKE_GAME_H
