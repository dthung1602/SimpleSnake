//
// Created by hung on 17/04/18.
//

#include "Window.h"
#include "Game.h"

void Window::beginDraw() {
    window.clear(sf::Color::Black);
}

void Window::endDraw() {
    window.display();
}

void Window::update(Game &game) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                game.setDone();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::F5)
                    toggleFullScreen();
                break;
            default:
                break;
        }
    }
}

void Window::toggleFullScreen() {
    fullscreen = !fullscreen;
    destroy();
    create();
}

void Window::setup(const std::string &title, sf::Vector2u size, unsigned int height) {
    windowTitle = title;
    defaultSize = size;
    hudHeight = height;
    create();
}

void Window::create() {
    auto style = (fullscreen ? sf::Style::Fullscreen : sf::Style::Titlebar | sf::Style::Close);
    window.create({defaultSize.x, defaultSize.y}, windowTitle, style);
}

void Window::destroy() {
    window.close();
}