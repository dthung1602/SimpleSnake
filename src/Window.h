//
// Created by hung on 17/04/18.
//

#ifndef SFMLSNAKE_WINDOW_H
#define SFMLSNAKE_WINDOW_H

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "TextBox.h"

class Game;

class Window {

public:
    //----------------------- ctors and dtors----------------------------

    explicit Window(const std::string &title,
                    sf::Vector2u defaultSize = {DEFAULT_WIDTH, DEFAULT_HEIGHT},
                    unsigned int hudHeight = DEFAULT_HUD_HEIGHT) {
        setup(title, defaultSize, hudHeight);
    };

    ~Window() { destroy(); };

    //----------------------- draw ----------------------------

    void beginDraw();

    void draw(const sf::Drawable &drawable) { window.draw(drawable); };

    void endDraw();

    void update(Game &game);

    void toggleFullScreen();

    //----------------------- getter ----------------------------

    bool isFullScreen() { return fullscreen; };

    auto getWindowSize() { return window.getSize(); };

    auto getHUDHeight() { return hudHeight; }

private:
    void setup(const std::string &title, sf::Vector2u defaultSize, unsigned int height);

    void create();

    void destroy();

    static const unsigned int DEFAULT_WIDTH = 800;
    static const unsigned int DEFAULT_HEIGHT = 550;
    static const unsigned int DEFAULT_HUD_HEIGHT = 80;

    sf::RenderWindow window;
    sf::Vector2u defaultSize;
    std::string windowTitle;
    unsigned int hudHeight;

    bool fullscreen = false;
};


#endif //SFMLSNAKE_WINDOW_H
