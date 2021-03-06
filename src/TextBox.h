//
// Created by hung on 19/04/18.
//

#ifndef SFMLSNAKE_TEXTBOX_H
#define SFMLSNAKE_TEXTBOX_H

#include <memory>

#include <SFML/Graphics.hpp>

class Window;

class TextBox {
public:
    TextBox() = default;

    TextBox(const std::string &content, const sf::Font &font, unsigned int textSize);

    void setVisible(bool v) { visible = v; }

    void setText(const std::string &content);

    void setFont(const sf::Font &font);

    void setTextSize(unsigned int size);

    void setTextColor(sf::Color color);

    void setPadding(sf::Vector2f padding);

    void setBackgroundSize(sf::Vector2f size);

    void setBackgroundColor(sf::Color color);

    void setPosition(sf::Vector2f position);

    void render(Window &window);

private:
    bool visible = true;
    sf::Vector2f padding;
    sf::Text text;
    sf::RectangleShape background;
};


#endif //SFMLSNAKE_TEXTBOX_H
