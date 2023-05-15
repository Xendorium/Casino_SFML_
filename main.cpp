#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game_selection.h"
#include "Drawing.h"

#include "Deck.h"
#include "Players.h"


using namespace std;

int main()
{
    //utworzenie okna
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    //załadowanie grfiki menu
    sf::Texture menu;
    menu.loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/menu.png");
    sf::Sprite sprite;
    sprite.setTexture(menu);

    //ustawianie czcionmi
    sf::Font font;
    font.loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/czcionka/NEON____.ttf");

    //przypisywanie rysowania
    sf::RectangleShape button = Drawing().draw_button(300, 400);
    sf::Text write = Drawing().text("Start Game",320,420,font);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
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