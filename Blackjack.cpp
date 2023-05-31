//
// Created by Konkuker on 15.05.2023.
//

/**
 * Created by Dominik Micor on 15/5/2023.
 *
 * @file Blackjack.cpp
 *
 * Implementation of methods declared in "Blackjack.h".
 */

#include "Blackjack.h"

Players *player = new Players;
Players *dealer = new Players;

std::unique_ptr<Deck> deck_ptr = std::make_unique<Deck>();

void Blackjack::start_game() {
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    sf::Texture tlo;
    tlo.loadFromFile("graphics_jpg/BJ.jpg");
    sf::Sprite spriteT;
    spriteT.setTexture(tlo);

    sf::Texture LW[2];
    sf::Sprite spriteLW[2];

    LW[0].loadFromFile("graphics_jpg/LOSE.png");
    LW[1].loadFromFile("graphics_jpg/WIN.png");

    spriteLW[0].setTexture(LW[0]);
    spriteLW[1].setTexture(LW[1]);

    sf::Font font;
    font.loadFromFile("font/NEON____.ttf");

    sf::Text text[3];
    text[0] = Drawing().text("Stand", 20, 295, font);
    text[1] = Drawing().text("Menu", 40, 195, font);
    text[2] = Drawing().text("Rules", 825, 390, font);

    sf::RectangleShape button[3];
    button[0] = Drawing().draw_button(10, 300, 200, 50);
    button[1] = Drawing().draw_button(10, 200, 200, 50);
    button[2] = Drawing().draw_button(800, 390, 210, 60);

    //P
    sf::Texture card[54];
    card[0].loadFromFile("graphics_jpg/P/2P.jpg");
    card[1].loadFromFile("graphics_jpg/P/3P.jpg");
    card[2].loadFromFile("graphics_jpg/P/4P.jpg");
    card[3].loadFromFile("graphics_jpg/P/5P.jpg");
    card[4].loadFromFile("graphics_jpg/P/6P.jpg");
    card[5].loadFromFile("graphics_jpg/P/7P.jpg");
    card[6].loadFromFile("graphics_jpg/P/8P.jpg");
    card[7].loadFromFile("graphics_jpg/P/9P.jpg");
    card[8].loadFromFile("graphics_jpg/P/10P.jpg");
    card[9].loadFromFile("graphics_jpg/P/JP.jpg");
    card[10].loadFromFile("graphics_jpg/P/DP.jpg");
    card[11].loadFromFile("graphics_jpg/P/KP.jpg");
    card[12].loadFromFile("graphics_jpg/P/AP.jpg");
    card[13].loadFromFile("graphics_jpg/P/rewers.jpg");

    //H
    card[14].loadFromFile("graphics_jpg/H/2S.jpg");
    card[15].loadFromFile("graphics_jpg/H/3S.jpg");
    card[16].loadFromFile("graphics_jpg/H/4S.jpg");
    card[17].loadFromFile("graphics_jpg/H/5S.jpg");
    card[18].loadFromFile("graphics_jpg/H/6S.jpg");
    card[19].loadFromFile("graphics_jpg/H/7S.jpg");
    card[20].loadFromFile("graphics_jpg/H/8S.jpg");
    card[21].loadFromFile("graphics_jpg/H/9S.jpg");
    card[22].loadFromFile("graphics_jpg/H/10S.jpg");
    card[23].loadFromFile("graphics_jpg/H/JS.jpg");
    card[24].loadFromFile("graphics_jpg/H/DS.jpg");
    card[25].loadFromFile("graphics_jpg/H/KS.jpg");
    card[26].loadFromFile("graphics_jpg/H/AS.jpg");

    //T
    card[27].loadFromFile("graphics_jpg/T/2T.jpg");
    card[28].loadFromFile("graphics_jpg/T/3T.jpg");
    card[29].loadFromFile("graphics_jpg/T/4T.jpg");
    card[30].loadFromFile("graphics_jpg/T/5T.jpg");
    card[31].loadFromFile("graphics_jpg/T/6T.jpg");
    card[32].loadFromFile("graphics_jpg/T/7T.jpg");
    card[33].loadFromFile("graphics_jpg/T/8T.jpg");
    card[34].loadFromFile("graphics_jpg/T/9T.jpg");
    card[35].loadFromFile("graphics_jpg/T/10T.jpg");
    card[36].loadFromFile("graphics_jpg/T/JT.jpg");
    card[37].loadFromFile("graphics_jpg/T/DT.jpg");
    card[38].loadFromFile("graphics_jpg/T/KT.jpg");
    card[39].loadFromFile("graphics_jpg/T/AT.jpg");

    //K
    card[40].loadFromFile("graphics_jpg/K/2K.jpg");
    card[41].loadFromFile("graphics_jpg/K/3K.jpg");
    card[42].loadFromFile("graphics_jpg/K/4K.jpg");
    card[43].loadFromFile("graphics_jpg/K/5K.jpg");
    card[44].loadFromFile("graphics_jpg/K/6K.jpg");
    card[45].loadFromFile("graphics_jpg/K/7K.jpg");
    card[46].loadFromFile("graphics_jpg/K/8K.jpg");
    card[47].loadFromFile("graphics_jpg/K/9K.jpg");
    card[48].loadFromFile("graphics_jpg/K/10K.jpg");
    card[49].loadFromFile("graphics_jpg/K/JK.jpg");
    card[50].loadFromFile("graphics_jpg/K/DK.jpg");
    card[51].loadFromFile("graphics_jpg/K/KK.jpg");
    card[52].loadFromFile("graphics_jpg/K/AK.jpg");

    sf::Sprite sprite[54];

    //R
    card[53].loadFromFile("graphics_jpg/P/rewers.jpg");

    sprite[53].setTexture(card[53]);
    sprite[53].setPosition(870.f, 230.f);

    sf::Sprite Sprite[53];

    sf::Sprite Rsprite;
    Rsprite.setTexture(card[53]);
    Rsprite.setPosition(115.f, 0.f);

    player->draw(*(deck_ptr->deck_ptr), 2);

    dealer->draw(*(deck_ptr->deck_ptr), 1);

    for (int i = 0; i < dealer->hand.size(); i++) {
        int x = 15 + 100 * i;
        Sprite[i].setPosition(x, 0);
        //spades
        if (dealer->hand[i].card_type == 4) {
            Sprite[i].setTexture(card[0]);
        }
        if (dealer->hand[i].card_type == 8) {
            Sprite[i].setTexture(card[1]);
        }
        if (dealer->hand[i].card_type == 12) {
            Sprite[i].setTexture(card[2]);
        }
        if (dealer->hand[i].card_type == 16) {
            Sprite[i].setTexture(card[3]);
        }
        if (dealer->hand[i].card_type == 20) {
            Sprite[i].setTexture(card[4]);
        }
        if (dealer->hand[i].card_type == 24) {
            Sprite[i].setTexture(card[5]);
        }
        if (dealer->hand[i].card_type == 28) {
            Sprite[i].setTexture(card[6]);
        }
        if (dealer->hand[i].card_type == 32) {
            Sprite[i].setTexture(card[7]);
        }
        if (dealer->hand[i].card_type == 36) {
            Sprite[i].setTexture(card[8]);
        }
        if (dealer->hand[i].card_type == 40) {
            Sprite[i].setTexture(card[9]);
        }
        if (dealer->hand[i].card_type == 44) {
            Sprite[i].setTexture(card[10]);
        }
        if (dealer->hand[i].card_type == 48) {
            Sprite[i].setTexture(card[11]);
        }
        if (dealer->hand[i].card_type == 52) {
            Sprite[i].setTexture(card[12]);
        }
        //diamonds
        if (dealer->hand[i].card_type == 3) {
            Sprite[i].setTexture(card[40]);
        }
        if (dealer->hand[i].card_type == 7) {
            Sprite[i].setTexture(card[41]);
        }
        if (dealer->hand[i].card_type == 11) {
            Sprite[i].setTexture(card[42]);
        }
        if (dealer->hand[i].card_type == 15) {
            Sprite[i].setTexture(card[43]);
        }
        if (dealer->hand[i].card_type == 19) {
            Sprite[i].setTexture(card[44]);
        }
        if (dealer->hand[i].card_type == 23) {
            Sprite[i].setTexture(card[45]);
        }
        if (dealer->hand[i].card_type == 27) {
            Sprite[i].setTexture(card[46]);
        }
        if (dealer->hand[i].card_type == 31) {
            Sprite[i].setTexture(card[47]);
        }
        if (dealer->hand[i].card_type == 35) {
            Sprite[i].setTexture(card[48]);
        }
        if (dealer->hand[i].card_type == 39) {
            Sprite[i].setTexture(card[49]);
        }
        if (dealer->hand[i].card_type == 43) {
            Sprite[i].setTexture(card[50]);
        }
        if (dealer->hand[i].card_type == 47) {
            Sprite[i].setTexture(card[51]);
        }
        if (dealer->hand[i].card_type == 51) {
            Sprite[i].setTexture(card[52]);
        }
        //clubs
        if (dealer->hand[i].card_type == 2) {
            Sprite[i].setTexture(card[27]);
        }
        if (dealer->hand[i].card_type == 6) {
            Sprite[i].setTexture(card[28]);
        }
        if (dealer->hand[i].card_type == 10) {
            Sprite[i].setTexture(card[29]);
        }
        if (dealer->hand[i].card_type == 14) {
            Sprite[i].setTexture(card[30]);
        }
        if (dealer->hand[i].card_type == 18) {
            Sprite[i].setTexture(card[31]);
        }
        if (dealer->hand[i].card_type == 22) {
            Sprite[i].setTexture(card[32]);
        }
        if (dealer->hand[i].card_type == 26) {
            Sprite[i].setTexture(card[33]);
        }
        if (dealer->hand[i].card_type == 30) {
            Sprite[i].setTexture(card[34]);
        }
        if (dealer->hand[i].card_type == 34) {
            Sprite[i].setTexture(card[35]);
        }
        if (dealer->hand[i].card_type == 38) {
            Sprite[i].setTexture(card[36]);
        }
        if (dealer->hand[i].card_type == 42) {
            Sprite[i].setTexture(card[37]);
        }
        if (dealer->hand[i].card_type == 46) {
            Sprite[i].setTexture(card[38]);
        }
        if (dealer->hand[i].card_type == 50) {
            Sprite[i].setTexture(card[39]);
        }
        //hearts
        if (dealer->hand[i].card_type == 1) {
            Sprite[i].setTexture(card[14]);
        }
        if (dealer->hand[i].card_type == 5) {
            Sprite[i].setTexture(card[15]);
        }
        if (dealer->hand[i].card_type == 9) {
            Sprite[i].setTexture(card[16]);
        }
        if (dealer->hand[i].card_type == 13) {
            Sprite[i].setTexture(card[17]);
        }
        if (dealer->hand[i].card_type == 17) {
            Sprite[i].setTexture(card[18]);
        }
        if (dealer->hand[i].card_type == 21) {
            Sprite[i].setTexture(card[19]);
        }
        if (dealer->hand[i].card_type == 25) {
            Sprite[i].setTexture(card[20]);
        }
        if (dealer->hand[i].card_type == 29) {
            Sprite[i].setTexture(card[21]);
        }
        if (dealer->hand[i].card_type == 33) {
            Sprite[i].setTexture(card[22]);
        }
        if (dealer->hand[i].card_type == 37) {
            Sprite[i].setTexture(card[23]);
        }
        if (dealer->hand[i].card_type == 41) {
            Sprite[i].setTexture(card[24]);
        }
        if (dealer->hand[i].card_type == 45) {
            Sprite[i].setTexture(card[25]);
        }
        if (dealer->hand[i].card_type == 49) {
            Sprite[i].setTexture(card[26]);
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                end_game();
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (button[1].getGlobalBounds().contains(mousePos)) {
                    end_game();
                    window.close();
                    Game_selection::show_games();
                }
                if (button[2].getGlobalBounds().contains(mousePos)) {
                    rules();
                }
                if (sprite[53].getGlobalBounds().contains(mousePos)) {
                    player->draw(*(deck_ptr->deck_ptr), 1);
                }
                if (button[0].getGlobalBounds().contains(mousePos)) {
                    do {
                        dealer->draw(*(deck_ptr->deck_ptr), 1);
                        for (int i = 0; i < dealer->hand.size(); i++) {
                            int x = 15 + 100 * i;
                            Sprite[i].setPosition(x, 0);
                            //spades
                            if (dealer->hand[i].card_type == 4) {
                                Sprite[i].setTexture(card[0]);
                            }
                            if (dealer->hand[i].card_type == 8) {
                                Sprite[i].setTexture(card[1]);
                            }
                            if (dealer->hand[i].card_type == 12) {
                                Sprite[i].setTexture(card[2]);
                            }
                            if (dealer->hand[i].card_type == 16) {
                                Sprite[i].setTexture(card[3]);
                            }
                            if (dealer->hand[i].card_type == 20) {
                                Sprite[i].setTexture(card[4]);
                            }
                            if (dealer->hand[i].card_type == 24) {
                                Sprite[i].setTexture(card[5]);
                            }
                            if (dealer->hand[i].card_type == 28) {
                                Sprite[i].setTexture(card[6]);
                            }
                            if (dealer->hand[i].card_type == 32) {
                                Sprite[i].setTexture(card[7]);
                            }
                            if (dealer->hand[i].card_type == 36) {
                                Sprite[i].setTexture(card[8]);
                            }
                            if (dealer->hand[i].card_type == 40) {
                                Sprite[i].setTexture(card[9]);
                            }
                            if (dealer->hand[i].card_type == 44) {
                                Sprite[i].setTexture(card[10]);
                            }
                            if (dealer->hand[i].card_type == 48) {
                                Sprite[i].setTexture(card[11]);
                            }
                            if (dealer->hand[i].card_type == 52) {
                                Sprite[i].setTexture(card[12]);
                            }
                            //diamonds
                            if (dealer->hand[i].card_type == 3) {
                                Sprite[i].setTexture(card[40]);
                            }
                            if (dealer->hand[i].card_type == 7) {
                                Sprite[i].setTexture(card[41]);
                            }
                            if (dealer->hand[i].card_type == 11) {
                                Sprite[i].setTexture(card[42]);
                            }
                            if (dealer->hand[i].card_type == 15) {
                                Sprite[i].setTexture(card[43]);
                            }
                            if (dealer->hand[i].card_type == 19) {
                                Sprite[i].setTexture(card[44]);
                            }
                            if (dealer->hand[i].card_type == 23) {
                                Sprite[i].setTexture(card[45]);
                            }
                            if (dealer->hand[i].card_type == 27) {
                                Sprite[i].setTexture(card[46]);
                            }
                            if (dealer->hand[i].card_type == 31) {
                                Sprite[i].setTexture(card[47]);
                            }
                            if (dealer->hand[i].card_type == 35) {
                                Sprite[i].setTexture(card[48]);
                            }
                            if (dealer->hand[i].card_type == 39) {
                                Sprite[i].setTexture(card[49]);
                            }
                            if (dealer->hand[i].card_type == 43) {
                                Sprite[i].setTexture(card[50]);
                            }
                            if (dealer->hand[i].card_type == 47) {
                                Sprite[i].setTexture(card[51]);
                            }
                            if (dealer->hand[i].card_type == 51) {
                                Sprite[i].setTexture(card[52]);
                            }
                            //clubs
                            if (dealer->hand[i].card_type == 2) {
                                Sprite[i].setTexture(card[27]);
                            }
                            if (dealer->hand[i].card_type == 6) {
                                Sprite[i].setTexture(card[28]);
                            }
                            if (dealer->hand[i].card_type == 10) {
                                Sprite[i].setTexture(card[29]);
                            }
                            if (dealer->hand[i].card_type == 14) {
                                Sprite[i].setTexture(card[30]);
                            }
                            if (dealer->hand[i].card_type == 18) {
                                Sprite[i].setTexture(card[31]);
                            }
                            if (dealer->hand[i].card_type == 22) {
                                Sprite[i].setTexture(card[32]);
                            }
                            if (dealer->hand[i].card_type == 26) {
                                Sprite[i].setTexture(card[33]);
                            }
                            if (dealer->hand[i].card_type == 30) {
                                Sprite[i].setTexture(card[34]);
                            }
                            if (dealer->hand[i].card_type == 34) {
                                Sprite[i].setTexture(card[35]);
                            }
                            if (dealer->hand[i].card_type == 38) {
                                Sprite[i].setTexture(card[36]);
                            }
                            if (dealer->hand[i].card_type == 42) {
                                Sprite[i].setTexture(card[37]);
                            }
                            if (dealer->hand[i].card_type == 46) {
                                Sprite[i].setTexture(card[38]);
                            }
                            if (dealer->hand[i].card_type == 50) {
                                Sprite[i].setTexture(card[39]);
                            }
                            //hearts
                            if (dealer->hand[i].card_type == 1) {
                                Sprite[i].setTexture(card[14]);
                            }
                            if (dealer->hand[i].card_type == 5) {
                                Sprite[i].setTexture(card[15]);
                            }
                            if (dealer->hand[i].card_type == 9) {
                                Sprite[i].setTexture(card[16]);
                            }
                            if (dealer->hand[i].card_type == 13) {
                                Sprite[i].setTexture(card[17]);
                            }
                            if (dealer->hand[i].card_type == 17) {
                                Sprite[i].setTexture(card[18]);
                            }
                            if (dealer->hand[i].card_type == 21) {
                                Sprite[i].setTexture(card[19]);
                            }
                            if (dealer->hand[i].card_type == 25) {
                                Sprite[i].setTexture(card[20]);
                            }
                            if (dealer->hand[i].card_type == 29) {
                                Sprite[i].setTexture(card[21]);
                            }
                            if (dealer->hand[i].card_type == 33) {
                                Sprite[i].setTexture(card[22]);
                            }
                            if (dealer->hand[i].card_type == 37) {
                                Sprite[i].setTexture(card[23]);
                            }
                            if (dealer->hand[i].card_type == 41) {
                                Sprite[i].setTexture(card[24]);
                            }
                            if (dealer->hand[i].card_type == 45) {
                                Sprite[i].setTexture(card[25]);
                            }
                            if (dealer->hand[i].card_type == 49) {
                                Sprite[i].setTexture(card[26]);
                            }
                        }
                        for (int i = 0; i < dealer->hand.size(); i++) {
                            window.draw(Sprite[i]);
                        }
                        window.display();
                        wait(1);
                        if (dealer->sum() > 21) {
                            window.clear();
                            end_game();
                            wait(2);
                            window.draw(spriteLW[1]);
                            window.display();
                            wait(1);
                            window.close();
                            Game_selection::show_games();
                            break;
                        }
                        if (dealer->sum() >= player->sum()) {
                            window.clear();
                            end_game();
                            wait(2);
                            window.draw(spriteLW[0]);
                            window.display();
                            wait(1);
                            window.close();
                            Game_selection::show_games();
                            break;
                        }
                    } while (dealer->sum() < 17);
                    if (dealer->sum() > player->sum()) {
                        window.clear();
                        end_game();
                        wait(2);
                        window.draw(spriteLW[0]);
                        window.display();
                        wait(1);
                        window.close();
                        Game_selection::show_games();
                        break;
                    }
                    if (player->sum() > dealer->sum()) {
                        window.clear();
                        end_game();
                        wait(2);
                        window.draw(spriteLW[1]);
                        window.display();
                        wait(2);
                        window.close();
                        Game_selection::show_games();
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < player->hand.size(); i++) {
            int x = 15 + 100 * i;
            sprite[i].setPosition(x, 470);
            //spades
            if (player->hand[i].card_type == 4) {
                sprite[i].setTexture(card[0]);
            }
            if (player->hand[i].card_type == 8) {
                sprite[i].setTexture(card[1]);
            }
            if (player->hand[i].card_type == 12) {
                sprite[i].setTexture(card[2]);
            }
            if (player->hand[i].card_type == 16) {
                sprite[i].setTexture(card[3]);
            }
            if (player->hand[i].card_type == 20) {
                sprite[i].setTexture(card[4]);
            }
            if (player->hand[i].card_type == 24) {
                sprite[i].setTexture(card[5]);
            }
            if (player->hand[i].card_type == 28) {
                sprite[i].setTexture(card[6]);
            }
            if (player->hand[i].card_type == 32) {
                sprite[i].setTexture(card[7]);
            }
            if (player->hand[i].card_type == 36) {
                sprite[i].setTexture(card[8]);
            }
            if (player->hand[i].card_type == 40) {
                sprite[i].setTexture(card[9]);
            }
            if (player->hand[i].card_type == 44) {
                sprite[i].setTexture(card[10]);
            }
            if (player->hand[i].card_type == 48) {
                sprite[i].setTexture(card[11]);
            }
            if (player->hand[i].card_type == 52) {
                sprite[i].setTexture(card[12]);
            }
            //diamonds
            if (player->hand[i].card_type == 3) {
                sprite[i].setTexture(card[40]);
            }
            if (player->hand[i].card_type == 7) {
                sprite[i].setTexture(card[41]);
            }
            if (player->hand[i].card_type == 11) {
                sprite[i].setTexture(card[42]);
            }
            if (player->hand[i].card_type == 15) {
                sprite[i].setTexture(card[43]);
            }
            if (player->hand[i].card_type == 19) {
                sprite[i].setTexture(card[44]);
            }
            if (player->hand[i].card_type == 23) {
                sprite[i].setTexture(card[45]);
            }
            if (player->hand[i].card_type == 27) {
                sprite[i].setTexture(card[46]);
            }
            if (player->hand[i].card_type == 31) {
                sprite[i].setTexture(card[47]);
            }
            if (player->hand[i].card_type == 35) {
                sprite[i].setTexture(card[48]);
            }
            if (player->hand[i].card_type == 39) {
                sprite[i].setTexture(card[49]);
            }
            if (player->hand[i].card_type == 43) {
                sprite[i].setTexture(card[50]);
            }
            if (player->hand[i].card_type == 47) {
                sprite[i].setTexture(card[51]);
            }
            if (player->hand[i].card_type == 51) {
                sprite[i].setTexture(card[52]);
            }
            //clubs
            if (player->hand[i].card_type == 2) {
                sprite[i].setTexture(card[27]);
            }
            if (player->hand[i].card_type == 6) {
                sprite[i].setTexture(card[28]);
            }
            if (player->hand[i].card_type == 10) {
                sprite[i].setTexture(card[29]);
            }
            if (player->hand[i].card_type == 14) {
                sprite[i].setTexture(card[30]);
            }
            if (player->hand[i].card_type == 18) {
                sprite[i].setTexture(card[31]);
            }
            if (player->hand[i].card_type == 22) {
                sprite[i].setTexture(card[32]);
            }
            if (player->hand[i].card_type == 26) {
                sprite[i].setTexture(card[33]);
            }
            if (player->hand[i].card_type == 30) {
                sprite[i].setTexture(card[34]);
            }
            if (player->hand[i].card_type == 34) {
                sprite[i].setTexture(card[35]);
            }
            if (player->hand[i].card_type == 38) {
                sprite[i].setTexture(card[36]);
            }
            if (player->hand[i].card_type == 42) {
                sprite[i].setTexture(card[37]);
            }
            if (player->hand[i].card_type == 46) {
                sprite[i].setTexture(card[38]);
            }
            if (player->hand[i].card_type == 50) {
                sprite[i].setTexture(card[39]);
            }
            //hearts
            if (player->hand[i].card_type == 1) {
                sprite[i].setTexture(card[14]);
            }
            if (player->hand[i].card_type == 5) {
                sprite[i].setTexture(card[15]);
            }
            if (player->hand[i].card_type == 9) {
                sprite[i].setTexture(card[16]);
            }
            if (player->hand[i].card_type == 13) {
                sprite[i].setTexture(card[17]);
            }
            if (player->hand[i].card_type == 17) {
                sprite[i].setTexture(card[18]);
            }
            if (player->hand[i].card_type == 21) {
                sprite[i].setTexture(card[19]);
            }
            if (player->hand[i].card_type == 25) {
                sprite[i].setTexture(card[20]);
            }
            if (player->hand[i].card_type == 29) {
                sprite[i].setTexture(card[21]);
            }
            if (player->hand[i].card_type == 33) {
                sprite[i].setTexture(card[22]);
            }
            if (player->hand[i].card_type == 37) {
                sprite[i].setTexture(card[23]);
            }
            if (player->hand[i].card_type == 41) {
                sprite[i].setTexture(card[24]);
            }
            if (player->hand[i].card_type == 45) {
                sprite[i].setTexture(card[25]);
            }
            if (player->hand[i].card_type == 49) {
                sprite[i].setTexture(card[26]);
            }
        }

        window.clear();
        window.draw(spriteT);

        for (int i = 0; i < 3; i++) {
            window.draw(button[i]);
        }

        for (int i = 0; i < player->hand.size(); i++) {
            window.draw(sprite[i]);
        }

        window.draw(sprite[53]);
        window.draw(Rsprite);

        window.draw(Sprite[0]);

        for (int i = 0; i < 3; i++) {
            window.draw(text[i]);
        }

        window.display();

        if (player->sum() > 21) {
            end_game();
            wait(2);
            window.draw(spriteLW[0]);
            window.display();
            wait(1);
            window.close();
            Game_selection::show_games();
        }
    }
}

void Blackjack::end_game() {
    player->clear_hands(*deck_ptr->deck_ptr);
    dealer->clear_hands(*deck_ptr->deck_ptr);
}

void Blackjack::rules() {
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    sf::Font font;
    font.loadFromFile("font/NEON____.ttf");

    sf::Texture menu;
    menu.loadFromFile("graphics_jpg/rules.png");
    sf::Sprite sprite;
    sprite.setTexture(menu);

    sf::Text text;
    text = Drawing().text("PLAY", 430, 495, font);

    sf::RectangleShape button;
    button = Drawing().draw_button(398, 500, 200, 50);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (button.getGlobalBounds().contains(mousePos)) {
                    window.close();
                }
            }
            window.clear();
            window.draw(sprite);
            window.draw(button);
            window.draw(text);
            window.display();
        }
    }

}

void Blackjack::wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}
