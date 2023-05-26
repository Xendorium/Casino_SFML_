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
    //utworzenie okna
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    //załadowanie grfiki tlo
    sf::Texture tlo;
    tlo.loadFromFile("graphics_jpg/BJ.jpg");
    sf::Sprite spriteT;
    spriteT.setTexture(tlo);

    //utworzenie okna Lose i WIN
    sf::Texture LW[2];
    sf::Sprite spriteLW[2];

    LW[0].loadFromFile("graphics_jpg/LOSE.png");
    LW[1].loadFromFile("graphics_jpg/WIN.png");

    spriteLW[0].setTexture(LW[0]);
    spriteLW[1].setTexture(LW[1]);

    //wczytanie czcionki
    sf::Font font;
    font.loadFromFile("font/NEON____.ttf");

    //utworzenie napisów
    sf::Text text[3];
    text[0] = Drawing().text("Stand", 20, 295, font);
    text[1] = Drawing().text("Menu", 40, 195, font);
    text[2] = Drawing().text("Rules", 825, 390, font);

    //tworzenie przycisków
    sf::RectangleShape button[3];
    button[0] = Drawing().draw_button(10, 300, 200, 50);
    button[1] = Drawing().draw_button(10, 200, 200, 50);
    button[2] = Drawing().draw_button(800, 390, 210, 60);

    //zczytanie kart do gry

    //PIKI
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

    //SERCA
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

    //TREFL
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

    //KARO
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

    //tablica kart dla gracza
    sf::Sprite sprite[54];

    //REWERS
    card[53].loadFromFile("graphics_jpg/P/rewers.jpg");

    sprite[53].setTexture(card[53]);
    sprite[53].setPosition(870.f, 230.f);

    //tablica kart dla Dealera
    sf::Sprite Sprite[53];

    //rewers Dealera
    sf::Sprite Rsprite;
    Rsprite.setTexture(card[53]);
    Rsprite.setPosition(115.f, 0.f);

    //Dobieranie kart i pokazywanie ich przez gracza
    player->draw(*(deck_ptr->deck_ptr), 2);

    //Dobranie karty i pokazanie jej przez krupiera
    dealer->draw(*(deck_ptr->deck_ptr), 1);

    //rysowanie kart Dealera
    for (int i = 0; i < dealer->hand.size(); i++) {
        int x = 15 + 100 * i;
        if (dealer->hand[i].sign == "hearts") {
            if (dealer->hand[i].points == "two") {
                Sprite[i].setTexture(card[14]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "three") {
                Sprite[i].setTexture(card[15]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "four") {
                Sprite[i].setTexture(card[16]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "five") {
                Sprite[i].setTexture(card[17]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "six") {
                Sprite[i].setTexture(card[18]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "seven") {
                Sprite[i].setTexture(card[19]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "eight") {
                Sprite[i].setTexture(card[20]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "nine") {
                Sprite[i].setTexture(card[21]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "ten") {
                Sprite[i].setTexture(card[22]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "jack") {
                Sprite[i].setTexture(card[23]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "queen") {
                Sprite[i].setTexture(card[24]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "king") {
                Sprite[i].setTexture(card[25]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "ace") {
                Sprite[i].setTexture(card[26]);
                Sprite[i].setPosition(x, 0);
            }
        }
        if (dealer->hand[i].sign == "clubs") {
            if (dealer->hand[i].points == "two") {
                Sprite[i].setTexture(card[27]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "three") {
                Sprite[i].setTexture(card[28]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "four") {
                Sprite[i].setTexture(card[29]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "five") {
                Sprite[i].setTexture(card[30]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "six") {
                Sprite[i].setTexture(card[31]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "seven") {
                Sprite[i].setTexture(card[32]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "eight") {
                Sprite[i].setTexture(card[33]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "nine") {
                Sprite[i].setTexture(card[34]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "ten") {
                Sprite[i].setTexture(card[35]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "jack") {
                Sprite[i].setTexture(card[36]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "queen") {
                Sprite[i].setTexture(card[37]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "king") {
                Sprite[i].setTexture(card[38]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "ace") {
                Sprite[i].setTexture(card[39]);
                Sprite[i].setPosition(x, 0);
            }
        }
        if (dealer->hand[i].sign == "diamonds") {
            if (dealer->hand[i].points == "two") {
                Sprite[i].setTexture(card[40]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "three") {
                Sprite[i].setTexture(card[41]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "four") {
                Sprite[i].setTexture(card[42]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "five") {
                Sprite[i].setTexture(card[43]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "six") {
                Sprite[i].setTexture(card[44]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "seven") {
                Sprite[i].setTexture(card[45]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "eight") {
                Sprite[i].setTexture(card[46]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "nine") {
                Sprite[i].setTexture(card[47]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "ten") {
                Sprite[i].setTexture(card[48]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "jack") {
                Sprite[i].setTexture(card[49]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "queen") {
                Sprite[i].setTexture(card[50]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "king") {
                Sprite[i].setTexture(card[51]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "ace") {
                Sprite[i].setTexture(card[52]);
                Sprite[i].setPosition(x, 0);
            }
        }
        if (dealer->hand[i].sign == "spades") {
            if (dealer->hand[i].points == "two") {
                Sprite[i].setTexture(card[0]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "three") {
                Sprite[i].setTexture(card[1]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "four") {
                Sprite[i].setTexture(card[2]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "five") {
                Sprite[i].setTexture(card[3]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "six") {
                Sprite[i].setTexture(card[4]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "seven") {
                Sprite[i].setTexture(card[5]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "eight") {
                Sprite[i].setTexture(card[6]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "nine") {
                Sprite[i].setTexture(card[7]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "ten") {
                Sprite[i].setTexture(card[8]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "jack") {
                Sprite[i].setTexture(card[9]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "queen") {
                Sprite[i].setTexture(card[10]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "king") {
                Sprite[i].setTexture(card[11]);
                Sprite[i].setPosition(x, 0);
            }
            if (dealer->hand[i].points == "ace") {
                Sprite[i].setTexture(card[12]);
                Sprite[i].setPosition(x, 0);
            }
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
                            if (dealer->hand[i].sign == "hearts") {
                                if (dealer->hand[i].points == "two") {
                                    Sprite[i].setTexture(card[14]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "three") {
                                    Sprite[i].setTexture(card[15]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "four") {
                                    Sprite[i].setTexture(card[16]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "five") {
                                    Sprite[i].setTexture(card[17]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "six") {
                                    Sprite[i].setTexture(card[18]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "seven") {
                                    Sprite[i].setTexture(card[19]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "eight") {
                                    Sprite[i].setTexture(card[20]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "nine") {
                                    Sprite[i].setTexture(card[21]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "ten") {
                                    Sprite[i].setTexture(card[22]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "jack") {
                                    Sprite[i].setTexture(card[23]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "queen") {
                                    Sprite[i].setTexture(card[24]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "king") {
                                    Sprite[i].setTexture(card[25]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "ace") {
                                    Sprite[i].setTexture(card[26]);
                                    Sprite[i].setPosition(x, 0);
                                }
                            }
                            if (dealer->hand[i].sign == "clubs") {
                                if (dealer->hand[i].points == "two") {
                                    Sprite[i].setTexture(card[27]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "three") {
                                    Sprite[i].setTexture(card[28]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "four") {
                                    Sprite[i].setTexture(card[29]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "five") {
                                    Sprite[i].setTexture(card[30]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "six") {
                                    Sprite[i].setTexture(card[31]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "seven") {
                                    Sprite[i].setTexture(card[32]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "eight") {
                                    Sprite[i].setTexture(card[33]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "nine") {
                                    Sprite[i].setTexture(card[34]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "ten") {
                                    Sprite[i].setTexture(card[35]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "jack") {
                                    Sprite[i].setTexture(card[36]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "queen") {
                                    Sprite[i].setTexture(card[37]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "king") {
                                    Sprite[i].setTexture(card[38]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "ace") {
                                    Sprite[i].setTexture(card[39]);
                                    Sprite[i].setPosition(x, 0);
                                }
                            }
                            if (dealer->hand[i].sign == "diamonds") {
                                if (dealer->hand[i].points == "two") {
                                    Sprite[i].setTexture(card[40]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "three") {
                                    Sprite[i].setTexture(card[41]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "four") {
                                    Sprite[i].setTexture(card[42]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "five") {
                                    Sprite[i].setTexture(card[43]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "six") {
                                    Sprite[i].setTexture(card[44]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "seven") {
                                    Sprite[i].setTexture(card[45]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "eight") {
                                    Sprite[i].setTexture(card[46]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "nine") {
                                    Sprite[i].setTexture(card[47]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "ten") {
                                    Sprite[i].setTexture(card[48]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "jack") {
                                    Sprite[i].setTexture(card[49]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "queen") {
                                    Sprite[i].setTexture(card[50]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "king") {
                                    Sprite[i].setTexture(card[51]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "ace") {
                                    Sprite[i].setTexture(card[52]);
                                    Sprite[i].setPosition(x, 0);
                                }
                            }
                            if (dealer->hand[i].sign == "spades") {
                                if (dealer->hand[i].points == "two") {
                                    Sprite[i].setTexture(card[0]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "three") {
                                    Sprite[i].setTexture(card[1]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "four") {
                                    Sprite[i].setTexture(card[2]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "five") {
                                    Sprite[i].setTexture(card[3]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "six") {
                                    Sprite[i].setTexture(card[4]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "seven") {
                                    Sprite[i].setTexture(card[5]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "eight") {
                                    Sprite[i].setTexture(card[6]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "nine") {
                                    Sprite[i].setTexture(card[7]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "ten") {
                                    Sprite[i].setTexture(card[8]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "jack") {
                                    Sprite[i].setTexture(card[9]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "queen") {
                                    Sprite[i].setTexture(card[10]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "king") {
                                    Sprite[i].setTexture(card[11]);
                                    Sprite[i].setPosition(x, 0);
                                }
                                if (dealer->hand[i].points == "ace") {
                                    Sprite[i].setTexture(card[12]);
                                    Sprite[i].setPosition(x, 0);
                                }
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

            if (player->hand[i].sign == "hearts") {
                if (player->hand[i].points == "two") {
                    sprite[i].setTexture(card[14]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "three") {
                    sprite[i].setTexture(card[15]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "four") {
                    sprite[i].setTexture(card[16]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "five") {
                    sprite[i].setTexture(card[17]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "six") {
                    sprite[i].setTexture(card[18]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "seven") {
                    sprite[i].setTexture(card[19]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "eight") {
                    sprite[i].setTexture(card[20]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "nine") {
                    sprite[i].setTexture(card[21]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "ten") {
                    sprite[i].setTexture(card[22]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "jack") {
                    sprite[i].setTexture(card[23]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "queen") {
                    sprite[i].setTexture(card[24]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "king") {
                    sprite[i].setTexture(card[25]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "ace") {
                    sprite[i].setTexture(card[26]);
                    sprite[i].setPosition(x, 470);
                }
            }
            if (player->hand[i].sign == "clubs") {
                if (player->hand[i].points == "two") {
                    sprite[i].setTexture(card[27]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "three") {
                    sprite[i].setTexture(card[28]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "four") {
                    sprite[i].setTexture(card[29]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "five") {
                    sprite[i].setTexture(card[30]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "six") {
                    sprite[i].setTexture(card[31]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "seven") {
                    sprite[i].setTexture(card[32]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "eight") {
                    sprite[i].setTexture(card[33]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "nine") {
                    sprite[i].setTexture(card[34]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "ten") {
                    sprite[i].setTexture(card[35]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "jack") {
                    sprite[i].setTexture(card[36]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "queen") {
                    sprite[i].setTexture(card[37]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "king") {
                    sprite[i].setTexture(card[38]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "ace") {
                    sprite[i].setTexture(card[39]);
                    sprite[i].setPosition(x, 470);
                }
            }
            if (player->hand[i].sign == "diamonds") {
                if (player->hand[i].points == "two") {
                    sprite[i].setTexture(card[40]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "three") {
                    sprite[i].setTexture(card[41]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "four") {
                    sprite[i].setTexture(card[42]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "five") {
                    sprite[i].setTexture(card[43]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "six") {
                    sprite[i].setTexture(card[44]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "seven") {
                    sprite[i].setTexture(card[45]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "eight") {
                    sprite[i].setTexture(card[46]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "nine") {
                    sprite[i].setTexture(card[47]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "ten") {
                    sprite[i].setTexture(card[48]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "jack") {
                    sprite[i].setTexture(card[49]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "queen") {
                    sprite[i].setTexture(card[50]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "king") {
                    sprite[i].setTexture(card[51]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "ace") {
                    sprite[i].setTexture(card[52]);
                    sprite[i].setPosition(x, 470);
                }
            }
            if (player->hand[i].sign == "spades") {
                if (player->hand[i].points == "two") {
                    sprite[i].setTexture(card[0]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "three") {
                    sprite[i].setTexture(card[1]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "four") {
                    sprite[i].setTexture(card[2]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "five") {
                    sprite[i].setTexture(card[3]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "six") {
                    sprite[i].setTexture(card[4]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "seven") {
                    sprite[i].setTexture(card[5]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "eight") {
                    sprite[i].setTexture(card[6]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "nine") {
                    sprite[i].setTexture(card[7]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "ten") {
                    sprite[i].setTexture(card[8]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "jack") {
                    sprite[i].setTexture(card[9]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "queen") {
                    sprite[i].setTexture(card[10]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "king") {
                    sprite[i].setTexture(card[11]);
                    sprite[i].setPosition(x, 470);
                }
                if (player->hand[i].points == "ace") {
                    sprite[i].setTexture(card[12]);
                    sprite[i].setPosition(x, 470);
                }
            }

        }

        window.clear();
        window.draw(spriteT);
        //rysowanie przycisków
        for (int i = 0; i < 3; i++) {
            window.draw(button[i]);
        }

        //rysowanie kart Gracza
        for (int i = 0; i < player->hand.size(); i++) {
            window.draw(sprite[i]);
        }

        //rysowanie rewersów
        window.draw(sprite[53]);
        window.draw(Rsprite);

        //rysowanie pierwszej karty Dealera
        window.draw(Sprite[0]);

        //rysowanie tekstu
        for (int i = 0; i < 3; i++) {
            window.draw(text[i]);
        }

        window.display();

        //przegrana gracza
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
    //utworzenie okna
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    //wczytanie czcionki
    sf::Font font;
    font.loadFromFile("font/NEON____.ttf");

    //załadowanie zasad
    sf::Texture menu;
    menu.loadFromFile("graphics_jpg/rules.png");
    sf::Sprite sprite;
    sprite.setTexture(menu);

    //utworzenie napisów
    sf::Text text;
    text = Drawing().text("PLAY", 430, 495, font);

    //tworzenie przycisków
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
