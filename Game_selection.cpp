//
// Created by Konkuker on 15.05.2023.
//

#include "Game_selection.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

void Game_selection::show_games() {

    //renderowanie okna
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    //wczytanie czcionki
    sf::Font font;
    font.loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/czcionka/NEON____.ttf");

    //tworzenie napisów
    sf::Text text("Wybierz gre", font, 50);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(330, 100);

    sf::Text text1("Blackjack", font, 50);
    text1.setFillColor(sf::Color::Yellow);
    text1.setPosition(330, 100);

    sf::Text text2("Spin", font, 50);
    text2.setFillColor(sf::Color::Yellow);
    text2.setPosition(330, 100);

   //utworzenie przycisków
    sf::RectangleShape button(sf::Vector2f(400, 100));
    button.setFillColor(sf::Color::Black);
    button.setOutlineThickness(5);
    button.setOutlineColor(sf::Color::Yellow);
    button.setPosition(90, 312);

    sf::RectangleShape button1(sf::Vector2f(400, 100));
    button1.setFillColor(sf::Color::Black);
    button1.setOutlineThickness(5);
    button1.setOutlineColor(sf::Color::Yellow);
    button1.setPosition(510, 312);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(text);
        window.draw(button);
        window.draw(button1);
        window.draw(text1);
        window.draw(text2);
        window.display();
    }

}
