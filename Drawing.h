//
// Created by Konkuker on 15.05.2023.
//

#ifndef CASINO_SFML__DRAWING_H
#define CASINO_SFML__DRAWING_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Drawing {
public:
    sf::RectangleShape draw_button(int x, int y , int number);
    sf::Text text(std::string text, int x, int y, int number);
    sf::RectangleShape buttons[5];
    sf::Text write[5];
};


#endif //CASINO_SFML__DRAWING_H
