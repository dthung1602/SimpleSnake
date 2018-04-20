//
// Created by hung on 17/04/18.
//

#ifndef SFMLSNAKE_GAME_H
#define SFMLSNAKE_GAME_H

#include "Window.h"
#include "Snake.h"
#include "World.h"
#include "HUD.h"

class Game {
public:
    Game();

    ~Game() = default;

    void handleInput();

    void update();

    void render();

    void checkClock();

    void reset();

    void setDone() { done = true; }

    auto isDone() { return done; };

    void incScore();

    void decLife();

    void decAllLives();

    auto isLost() { return life == 0; }

    auto getScore() { return score; }

    auto getLife() { return life; }

    auto isStateChanged() { return stateChanged; }

    void clearStateChanged() { stateChanged = false; }

    Window &getWindow() { return window; };

private:
    static const char GAME_NAME[];
    static const unsigned int INIT_LIVES = 3;
    static const unsigned int SCORE_PER_FOOD = 10;

    Window window;
    World world;
    Snake snake;
    HUD hud;

    bool done = false;
    bool stateChanged = true;
    unsigned int score;
    unsigned int life;

    sf::Clock clock;
    bool timePassed = false;
    static const unsigned int frameRate = 5;
    static constexpr float timeInterval = 1.0f / frameRate;
};


#endif //SFMLSNAKE_GAME_H
