//
// Created by Konkuker on 19.05.2023.
//

#include "Slots.h"
#include "Game_selection.h"
#include "Drawing.h"
#include <time.h>
#include <memory>

using namespace std;

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

    //utworzenie przycisków i napisów
    sf::RectangleShape button[2];
    button[0] = Drawing().draw_button(437, 517,130 , 60);
    button[1] = Drawing().draw_button(10, 30,200,50);

    sf::Text text[2];
    text[0] = Drawing().text("Spin",450,515,font);
    text[1] = Drawing().text("Menu",40,25,font);

    //załadowanie grafik do losowań
    sf::Texture element[8];
    element[0].loadFromFile("grafiki jpg/slots/7.png");
    element[1].loadFromFile("grafiki jpg/slots/truskawka.png");
    element[2].loadFromFile("grafiki jpg/slots/banan.png");
    element[3].loadFromFile("grafiki jpg/slots/cytryna.png");
    element[4].loadFromFile("grafiki jpg/slots/pomarancza.png");
    element[5].loadFromFile("grafiki jpg/slots/sliwka.png");
    element[6].loadFromFile("grafiki jpg/slots/arbuz.png");
    element[7].loadFromFile("grafiki jpg/slots/wisnia.png");

    sf::Sprite sprite[11];
    sprite[0].setTexture(element[0]);
    sprite[1].setTexture(element[1]);
    sprite[2].setTexture(element[2]);
    sprite[3].setTexture(element[3]);
    sprite[4].setTexture(element[4]);
    sprite[5].setTexture(element[5]);
    sprite[6].setTexture(element[6]);
    sprite[7].setTexture(element[7]);
    sprite[8].setTexture(element[0]);
    sprite[9].setTexture(element[0]);
    sprite[10].setTexture(element[0]);

    sprite[8].setPosition(191,223);
    sprite[9].setPosition(410,223);
    sprite[10].setPosition(628,223);

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
                if (button[0].getGlobalBounds().contains(mousePos))
                {
                    int j,k,l = 0;
                    for (int i =0; i< random_number(); i++)
                    {
                        sprite[k].setPosition(191, 223);
                        window.draw(sprite[k]);

                        sprite[j].setPosition(410, 223);
                        window.draw(sprite[j]);

                        sprite[l].setPosition(628, 223);
                        window.draw(sprite[l]);

                        window.display();
                        //wait(1);
                        sprite[8] = sprite[k];
                        sprite[9] = sprite[j];
                        sprite[10] = sprite[l];
                        k++;
                        j++;
                        l++;
                        if (i == 7)
                        {
                            k = 0;
                            j = 0;
                            l = 0;
                        }
                    }
                }
                if (button[1].getGlobalBounds().contains(mousePos))
                {
                    window.close();
                    Game_selection::show_games();
                }
            }

            window.clear();
            window.draw(spriteT);
            window.draw(sprite[8]);
            window.draw(sprite[9]);
            window.draw(sprite[10]);
            window.draw(button[1]);
            window.draw(text[1]);
            window.draw(button[0]);
            window.draw(text[0]);
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

int Slots::random_number()
{
    int k = (rand()%(30)+0);
    return k;
}

void Slots::wait(int seconds)
{

    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}
