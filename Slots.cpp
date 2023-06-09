//
// Created by Konkuker on 19.05.2023.
//

/**
 * Created by Dominik Micor on 19/5/2023.
 *
 * @file Slots.cpp
 *
 * Implementation of methods declared in "Slots.h".
 */


#include "Slots.h"

void Slots::start_game() {
    int S1 = 0, S3 = 2, S2 = 1;

    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    sf::Texture tlo;
    tlo.loadFromFile("graphics_jpg//slotmachine.png");

    sf::Texture WIN;
    WIN.loadFromFile("graphics_jpg//WIN.png");

    sf::Sprite spriteTW[2];
    spriteTW[0].setTexture(tlo);
    spriteTW[1].setTexture(WIN);

    sf::Font font;
    font.loadFromFile("font/NEON____.ttf");

    sf::RectangleShape button[3];
    button[0] = Drawing().draw_button(437, 517, 130, 60);
    button[1] = Drawing().draw_button(10, 30, 200, 50);

    sf::Text text[3];
    text[0] = Drawing().text("Spin", 450, 515, font);
    text[1] = Drawing().text("Menu", 40, 25, font);

    sf::Texture element[8];
    element[0].loadFromFile("graphics_jpg/slots/7.png");
    element[1].loadFromFile("graphics_jpg/slots/strawberry.png");
    element[2].loadFromFile("graphics_jpg/slots/banana.png");
    element[3].loadFromFile("graphics_jpg/slots/lemon.png");
    element[4].loadFromFile("graphics_jpg/slots/orange.png");
    element[5].loadFromFile("graphics_jpg/slots/plum.png");
    element[6].loadFromFile("graphics_jpg/slots/watermelon.png");
    element[7].loadFromFile("graphics_jpg/slots/cherry.png");

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

    sf::Sprite Sprite[3];
    for (int i = 0; i < 3; i++) {
        Sprite[i].setTexture(element[0]);
    }
    Sprite[0].setPosition(191, 223);
    Sprite[1].setPosition(410, 223);
    Sprite[2].setPosition(628, 223);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (button[0].getGlobalBounds().contains(mousePos)) {
                    int k = 0;
                    int ilosc[3] = {0, 0, 0};
                    ilosc[0] = random_number();
                    for (int i = 0; i < ilosc[0]; i++, k++) {
                        if (i == 8 || i == 16 || i == 24 || i == 32) {
                            k = 0;
                        }
                        sprite[k].setPosition(191, 223);
                        window.draw(sprite[k]);
                        window.display();
                        Sleep(300);
                        Sprite[0] = sprite[k];
                        S1 = k;
                    }
                    ilosc[1] = random_number();
                    int j = 0;
                    for (int i = 0; i < ilosc[1]; i++, j++) {
                        if (i == 8 || i == 16 || i == 24 || i == 32) {
                            j = 0;
                        }
                        sprite[j].setPosition(410, 223);
                        window.draw(Sprite[0]);
                        window.draw(Sprite[1]);
                        window.draw(sprite[j]);
                        window.display();
                        Sleep(300);
                        Sprite[1] = sprite[j];
                        S2 = j;
                    }
                    ilosc[2] = random_number();
                    int l = 0;
                    for (int i = 0; i < ilosc[2]; i++, l++) {
                        if (i == 8 || i == 16 || i == 24 || i == 32) {
                            l = 0;
                        }
                        sprite[l].setPosition(628, 223);
                        window.draw(Sprite[1]);
                        window.draw(sprite[l]);
                        window.display();
                        Sleep(300);
                        Sprite[2] = sprite[l];
                        S3 = l;
                    };
                }
                if (button[1].getGlobalBounds().contains(mousePos)) {
                    window.close();
                    end_game();
                }
            }

            if ((S1 == S2 && S2 == S3)) {
                Sleep(1000);
                window.draw(spriteTW[1]);
                window.display();
                Sleep(1000);
                window.close();
                end_game();
            }
            window.clear();
            window.draw(spriteTW[0]);
            window.draw(Sprite[0]);
            window.draw(Sprite[1]);
            window.draw(Sprite[2]);
            window.draw(button[1]);
            window.draw(text[1]);
            window.draw(button[0]);
            window.draw(text[0]);
            window.display();
        }
    }
}

int Slots::random_number() {
    int k = (rand() % (33) + 1);
    return k;
}

void Slots::end_game() {
    Game_selection::show_games();
}
