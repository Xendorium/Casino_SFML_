/**
 * Created by Dominik Micor on 15/5/2023.
 *
 * @file main.cpp
 *
 * Drawing a menu
 */


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game_selection.h"
#include "Drawing.h"

int main() {
    srand(time(NULL));

    //utworzenie okna
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    //załadowanie grfiki menu
    sf::Texture menu;
    menu.loadFromFile("grafiki jpg/menu/menu.png");
    sf::Sprite sprite;
    sprite.setTexture(menu);

    //ustawianie czcionmi
    sf::Font font;
    font.loadFromFile("czcionka/NEON____.TTF");

    //przypisywanie rysowania
    sf::RectangleShape button = Drawing().draw_button(298, 350, 400, 100);
    sf::Text write = Drawing().text("Start Game", 318, 370, font);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (button.getGlobalBounds().contains(mousePos)) {
                    window.close();
                    Game_selection *Game_selection1 = new Game_selection;
                    Game_selection1->show_games();
                }
            }
            window.clear();
            window.draw(sprite);
            window.draw(button);
            window.draw(write);
            window.display();
        }
    }
    return 0;
}