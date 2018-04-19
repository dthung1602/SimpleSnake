#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

#include <SFML/Graphics.hpp>

int main() {
    sf::Font font;
    if (!font.loadFromFile("../resources/arial.ttf"))
        exit(1);

    sf::Text text("Testing", font, 60);
    text.setPosition(5, 5);
    text.setFillColor(sf::Color::White);

    sf::RenderWindow window({500, 300}, "Font");

    int i = 0;

    while (true) {
        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
        cout << i++ << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    window.close();
    return 0;
}