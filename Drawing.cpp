//
// Created by Konkuker on 15.05.2023.
//

#include "Drawing.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>



//tworzenie napisów
sf::Text Drawing::text(std::string text, int x, int y,sf::Font& font)
{
    sf::Text lettering(text, font, 50);
    lettering.setFillColor(sf::Color::Yellow);
    lettering.setPosition(x, y);
    return lettering;
}

//tworzenie przycisków
sf::RectangleShape Drawing::draw_button(int x, int y, int z, int i)
{
    sf::RectangleShape button(sf::Vector2f(z, i));
    button.setFillColor(sf::Color::Black);
    button.setOutlineThickness(5);
    button.setOutlineColor(sf::Color::Yellow);
    button.setPosition(x, y);
    return button;
}
