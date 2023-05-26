//
// Created by Konkuker on 15.05.2023.
//

/**
 * Created by Dominik Micor on 15/5/2023.
 *
 * @file Drawing.h
 *
 * Declaration of methods implemented in "Drawing.cpp".
 *
 * This class is use to draw a button and text on SFML window
 */


#ifndef CASINO_SFML__DRAWING_H
#define CASINO_SFML__DRAWING_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

///Class Drawing
class Drawing {
public:
    /**<summary>
    /// drawing buttons
    /// </summary>
    */
    sf::RectangleShape draw_button(int x, int y, int z, int i);

    /**<summary>
    /// drawing texts
    /// </summary>
    */
    sf::Text text(std::string text, int x, int y, sf::Font& font);
};


#endif //CASINO_SFML__DRAWING_H
