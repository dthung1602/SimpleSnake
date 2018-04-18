#include "Game.h"

int main() {
    Game game;

    while (!game.getWindow().isDone()) {
        game.handleInput();
        game.update();
        game.render();
        game.checkClock();
    }

    return 0;
}