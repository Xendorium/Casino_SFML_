//
// Created by Konkuker on 19.05.2023.
//

#include "Slots.h"
#include "Game_selection.h"
#include "Drawing.h"

void Slots::start_game()
{
    //utworzenie okna
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    //załadowanie grfiki tlo
    sf::Texture tlo;
    tlo.loadFromFile("grafiki jpg//slotmachine.png");
    sf::Sprite spriteT;
    spriteT.setTexture(tlo);

    //wczytanie czcionki
    sf::Font font;
    font.loadFromFile("czcionka/NEON____.ttf");

    //utworzenie przycisku i napisu SPIN
    sf::RectangleShape button = Drawing().draw_button(437, 522,130 , 60);
    sf::Text text = Drawing().text("Spin",450,520,font);








    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                /*sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (button.getGlobalBounds().contains(mousePos)) {
                    window.close();
                    Game_selection *Game_selection1 = new Game_selection;
                    Game_selection1->show_games();
                }*/
            }
            window.clear();
            window.draw(spriteT);
            window.draw(button);
            window.draw(text);
            window.display();
        }
    }
}

void Slots::end_game()
{

}

void Slots::spin()
{

}
