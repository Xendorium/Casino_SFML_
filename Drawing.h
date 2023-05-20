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
    /// sf::RectangleShape draw_button(int x, int y, int z, int i) method
    /// </summary>
    ///<example>
    /// <code>
    /// int main()
    ///{
    ///   sf::RectangleShape button = Drawing().draw_button(298, 350, 400 , 100);
    ///}
    /// </code>
    /// </example>
    */
    sf::RectangleShape draw_button(int x, int y, int z, int i);

    /**<summary>
    /// sf::Text text(std::string text, int x, int y, sf::Font& font) method
    /// </summary>
    ///<example>
    /// <code>
    ///int main()
    ///{
    ///    sf::Text write = Drawing().text("Start Game",318,370,font);
    ///}
    /// </code>
    /// </example>
    */
    sf::Text text(std::string text, int x, int y, sf::Font& font);
};


#endif //CASINO_SFML__DRAWING_H
