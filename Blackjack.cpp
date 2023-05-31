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

    sf::Texture card[53];
    //Hearths
    card[0].loadFromFile("graphics_jpg/H/2S.jpg");
    card[4].loadFromFile("graphics_jpg/H/3S.jpg");
    card[8].loadFromFile("graphics_jpg/H/4S.jpg");
    card[12].loadFromFile("graphics_jpg/H/5S.jpg");
    card[16].loadFromFile("graphics_jpg/H/6S.jpg");
    card[20].loadFromFile("graphics_jpg/H/7S.jpg");
    card[24].loadFromFile("graphics_jpg/H/8S.jpg");
    card[28].loadFromFile("graphics_jpg/H/9S.jpg");
    card[32].loadFromFile("graphics_jpg/H/10S.jpg");
    card[36].loadFromFile("graphics_jpg/H/JS.jpg");
    card[40].loadFromFile("graphics_jpg/H/DS.jpg");
    card[44].loadFromFile("graphics_jpg/H/KS.jpg");
    card[48].loadFromFile("graphics_jpg/H/AS.jpg");

    //Clubs
    card[1].loadFromFile("graphics_jpg/T/2T.jpg");
    card[5].loadFromFile("graphics_jpg/T/3T.jpg");
    card[9].loadFromFile("graphics_jpg/T/4T.jpg");
    card[13].loadFromFile("graphics_jpg/T/5T.jpg");
    card[17].loadFromFile("graphics_jpg/T/6T.jpg");
    card[21].loadFromFile("graphics_jpg/T/7T.jpg");
    card[25].loadFromFile("graphics_jpg/T/8T.jpg");
    card[29].loadFromFile("graphics_jpg/T/9T.jpg");
    card[33].loadFromFile("graphics_jpg/T/10T.jpg");
    card[37].loadFromFile("graphics_jpg/T/JT.jpg");
    card[41].loadFromFile("graphics_jpg/T/DT.jpg");
    card[45].loadFromFile("graphics_jpg/T/KT.jpg");
    card[49].loadFromFile("graphics_jpg/T/AT.jpg");

    //Diamonds
    card[2].loadFromFile("graphics_jpg/K/2K.jpg");
    card[6].loadFromFile("graphics_jpg/K/3K.jpg");
    card[10].loadFromFile("graphics_jpg/K/4K.jpg");
    card[14].loadFromFile("graphics_jpg/K/5K.jpg");
    card[18].loadFromFile("graphics_jpg/K/6K.jpg");
    card[22].loadFromFile("graphics_jpg/K/7K.jpg");
    card[26].loadFromFile("graphics_jpg/K/8K.jpg");
    card[30].loadFromFile("graphics_jpg/K/9K.jpg");
    card[34].loadFromFile("graphics_jpg/K/10K.jpg");
    card[38].loadFromFile("graphics_jpg/K/JK.jpg");
    card[42].loadFromFile("graphics_jpg/K/DK.jpg");
    card[46].loadFromFile("graphics_jpg/K/KK.jpg");
    card[50].loadFromFile("graphics_jpg/K/AK.jpg");

    //Spades
    card[3].loadFromFile("graphics_jpg/P/2P.jpg");
    card[7].loadFromFile("graphics_jpg/P/3P.jpg");
    card[11].loadFromFile("graphics_jpg/P/4P.jpg");
    card[15].loadFromFile("graphics_jpg/P/5P.jpg");
    card[19].loadFromFile("graphics_jpg/P/6P.jpg");
    card[23].loadFromFile("graphics_jpg/P/7P.jpg");
    card[27].loadFromFile("graphics_jpg/P/8P.jpg");
    card[31].loadFromFile("graphics_jpg/P/9P.jpg");
    card[35].loadFromFile("graphics_jpg/P/10P.jpg");
    card[39].loadFromFile("graphics_jpg/P/JP.jpg");
    card[43].loadFromFile("graphics_jpg/P/DP.jpg");
    card[47].loadFromFile("graphics_jpg/P/KP.jpg");
    card[51].loadFromFile("graphics_jpg/P/AP.jpg");

    card[52].loadFromFile("graphics_jpg/P/rewers.jpg");

    sf::Sprite sprite[52];

    sf::Sprite Sprite[52];

    //R
    sf::Sprite Rsprite[2];
    Rsprite[0].setTexture(card[52]);
    Rsprite[0].setPosition(115.f, 0.f);
    Rsprite[1].setTexture(card[52]);
    Rsprite[1].setPosition(870.f, 230.f);

    player->draw(*(deck_ptr->deck_ptr), 2);

    dealer->draw(*(deck_ptr->deck_ptr), 1);

    for (int i = 0; i < dealer->hand.size(); i++) {
        int x = 15 + 100 * i;
        Sprite[i].setTexture(card[dealer->hand[i].card_type]);
        Sprite[i].setPosition(x, 0);
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
                if (Rsprite[1].getGlobalBounds().contains(mousePos)) {
                    player->draw(*(deck_ptr->deck_ptr), 1);
                }
                if (button[0].getGlobalBounds().contains(mousePos)) {
                    do {
                        dealer->draw(*(deck_ptr->deck_ptr), 1);
                        for (int i = 0; i < dealer->hand.size(); i++) {
                            int x = 15 + 100 * i;
                            Sprite[i].setTexture(card[dealer->hand[i].card_type]);
                            Sprite[i].setPosition(x, 0);
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
            sprite[i].setTexture(card[player->hand[i].card_type]);
        }

        window.clear();
        window.draw(spriteT);

        for (int i = 0; i < 3; i++) {
            window.draw(button[i]);
        }

        for (int i = 0; i < player->hand.size(); i++) {
            window.draw(sprite[i]);
        }

        window.draw(Rsprite[0]);
        window.draw(Rsprite[1]);
        window.draw(Sprite[0]);

        for (int i = 0; i < 3; i++) {
            window.draw(text[i]);
        }
        window.display();

       /* if (player->sum() > 21) {
            end_game();
            wait(2);
            window.draw(spriteLW[0]);
            window.display();
            wait(1);
            window.close();
            Game_selection::show_games();
        }*/
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
