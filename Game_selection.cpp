//
// Created by Konkuker on 15.05.2023.
//

#include "Game_selection.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Drawing.h"
#include "Blackjack.h"

void Game_selection::show_games() {


    //stworzenie tablicy napisów i przycisków
    sf::Text text[3];
    sf::RectangleShape button[2];

    //renderowanie okna
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    //wczytanie czcionki
    sf::Font font;
    font.loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/czcionka/NEON____.ttf");

    //tworzenie napisów
    text[0] = Drawing().text("Wybeirz gre",330,150,font);
    text[1] = Drawing().text("Blackjack",130,332,font);
    text[2] = Drawing().text("Spin",660,332,font);

   //utworzenie przycisków
    button[0] = Drawing().draw_button(85, 312,400 , 100);
    button[1] = Drawing().draw_button(515, 312,400 , 100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (button[0].getGlobalBounds().contains(mousePos)) {
                window.close();
                Blackjack *Blackjack1 = new Blackjack;
                Blackjack1->start_game();
            }
            if (button[1].getGlobalBounds().contains(mousePos)) {
                window.close();
                std::cout<< "wybrales spin" << std::endl;
            }
        }
        window.clear();
        window.draw(text[0]);
        window.draw(button[0]);
        window.draw(button[1]);
        window.draw(text[1]);
        window.draw(text[2]);
        window.display();
    }

}
