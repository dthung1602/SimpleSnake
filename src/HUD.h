//
// Created by hung on 20/04/18.
//

#ifndef SFMLSNAKE_HUD_H
#define SFMLSNAKE_HUD_H

#include "TextBox.h"

class Game;

class Window;

class HUD {
public:
    HUD();

    void update(Game &game);

    void render(Window &window);

private:
    static const unsigned int DEFAULT_TEXT_SIZE = 20;

    sf::Font font;
    TextBox score;
    TextBox life;
    TextBox info;
};


#endif //SFMLSNAKE_HUD_H
