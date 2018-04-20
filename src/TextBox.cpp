//
// Created by hung on 19/04/18.
//

#include "TextBox.h"
#include "Window.h"

TextBox::TextBox(const std::string &content, const sf::Font &font, unsigned int textSize)
        : text(content, font, textSize),
          padding({5, 5}) {}

void TextBox::setText(const std::string &content) {
    text.setString(content);
}

void TextBox::setFont(const sf::Font &font) {
    text.setFont(font);
}

void TextBox::setTextSize(unsigned int size) {
    text.setCharacterSize(size);
}

void TextBox::setTextColor(sf::Color color) {
    text.setFillColor(color);
}

void TextBox::setPadding(sf::Vector2f padding) {
    this->padding = padding;
}

void TextBox::setBackgroundSize(sf::Vector2f size) {
    background.setSize(size);
}

void TextBox::setBackgroundColor(sf::Color color) {
    background.setFillColor(color);
}

void TextBox::setPosition(sf::Vector2f position) {
    background.setPosition(position);
    text.setPosition(position + padding);
}

void TextBox::render(Window &window) {
    if (visible) {
        window.draw(background);
        window.draw(text);
    }
}


