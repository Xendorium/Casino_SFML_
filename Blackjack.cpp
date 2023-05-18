//
// Created by Konkuker on 15.05.2023.
//

#include <time.h>
#include <memory>
#include "Blackjack.h"
#include "Players.h"
#include "Game_selection.h"

using namespace std;

Players *Player = new Players;
Players *Dealer = new Players;

std::unique_ptr<Deck> deck_ptr = make_unique<Deck>();

void Blackjack::start_game()
{
    //utworzenie okna
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino 100");

    //utworzenie okna Lose i WIN
    sf::Texture LW[2];
    sf::Sprite spriteLW[2];

    LW[0].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/LOSE.png");
    LW[1].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/WIN.png");

    spriteLW[0].setTexture(LW[0]);
    spriteLW[1].setTexture(LW[1]);

    //wczytanie czcionki
    sf::Font font;
    font.loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/czcionka/NEON____.ttf");

    //utworzenie napisów
    sf::Text text[3];
    text[0] = Drawing().text("Stand",20,295,font);
    text[1] = Drawing().text("Menu",40,195,font);
    text[2] = Drawing().text("Zasady",805,390,font);

    //tworzenie przycisków
    sf::RectangleShape button[3];
    button[0] = Drawing().draw_button(10, 300,200,50);
    button[1] = Drawing().draw_button(10, 200,200,50);
    button[2] = Drawing().draw_button(800, 390, 210,60);

    //zczytanie kart do gry

    //PIKI
    sf::Texture card[54];
    card[0].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/2P.jpg");
    card[1].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/3P.jpg");
    card[2].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/4P.jpg");
    card[3].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/5P.jpg");
    card[4].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/6P.jpg");
    card[5].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/7P.jpg");
    card[6].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/8P.jpg");
    card[7].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/9P.jpg");
    card[8].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/10P.jpg");
    card[9].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/JP.jpg");
    card[10].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/DP.jpg");
    card[11].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/KP.jpg");
    card[12].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/AP.jpg");
    card[13].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/rewers.jpg");

     //SERCA
    card[14].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/2S.jpg");
    card[15].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/3S.jpg");
    card[16].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/4S.jpg");
    card[17].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/5S.jpg");
    card[18].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/6S.jpg");
    card[19].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/7S.jpg");
    card[20].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/8S.jpg");
    card[21].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/9S.jpg");
    card[22].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/10S.jpg");
    card[23].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/JS.jpg");
    card[24].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/DS.jpg");
    card[25].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/KS.jpg");
    card[26].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/serca/AS.jpg");

     //TREFL
    card[27].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/2T.jpg");
    card[28].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/3T.jpg");
    card[29].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/4T.jpg");
    card[30].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/5T.jpg");
    card[31].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/6T.jpg");
    card[32].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/7T.jpg");
    card[33].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/8T.jpg");
    card[34].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/9T.jpg");
    card[35].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/10T.jpg");
    card[36].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/JT.jpg");
    card[37].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/DT.jpg");
    card[38].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/KT.jpg");
    card[39].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/trefl/AT.jpg");

     //KARO
    card[40].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/2K.jpg");
    card[41].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/3K.jpg");
    card[42].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/4K.jpg");
    card[43].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/5K.jpg");
    card[44].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/6K.jpg");
    card[45].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/7K.jpg");
    card[46].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/8K.jpg");
    card[47].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/9K.jpg");
    card[48].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/10K.jpg");
    card[49].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/JK.jpg");
    card[50].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/DK.jpg");
    card[51].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/KK.jpg");
    card[52].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/karo/AK.jpg");

    //tablica kart dla gracza
    sf::Sprite sprite[54];

     //REWERS
     card[53].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/rewers.jpg");

    sprite[53].setTexture(card[53]);
    sprite[53].setPosition(870.f,230.f);

    //tablica kart dla Dealera
    sf::Sprite Sprite[53];

    //rewers Dealera
    sf::Sprite Rsprite;
    Rsprite.setTexture(card[53]);
    Rsprite.setPosition(115.f,0.f);

    //Dobieranie kart i pokazywanie ich przez gracza
    Player->draw(*(deck_ptr->deck_ptr),2);

    //Dobranie karty i pokazanie jej przez krupiera
     Dealer->draw(*(deck_ptr->deck_ptr),1);

    //rysowanie kart Dealera
    for(int i = 0; i < Dealer->hand.size();i++)
    {
        int x = 15 + 100*i;
        if(Dealer->hand[i].sign == "hearts")
        {
            if (Dealer->hand[i].points == "two")
            {
                Sprite[i].setTexture(card[14]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "three")
            {
                Sprite[i].setTexture(card[15]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "four")
            {
                Sprite[i].setTexture(card[16]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "five")
            {
                Sprite[i].setTexture(card[17]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "six")
            {
                Sprite[i].setTexture(card[18]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "seven")
            {
                Sprite[i].setTexture(card[19]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "eight")
            {
                Sprite[i].setTexture(card[20]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "nine")
            {
                Sprite[i].setTexture(card[21]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "ten")
            {
                Sprite[i].setTexture(card[22]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "jack")
            {
                Sprite[i].setTexture(card[23]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "queen")
            {
                Sprite[i].setTexture(card[24]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "king")
            {
                Sprite[i].setTexture(card[25]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "ace")
            {
                Sprite[i].setTexture(card[26]);
                Sprite[i].setPosition(x,0);
            }
        }
        if(Dealer->hand[i].sign == "clubs")
        {
            if (Dealer->hand[i].points == "two")
            {
                Sprite[i].setTexture(card[27]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "three")
            {
                Sprite[i].setTexture(card[28]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "four")
            {
                Sprite[i].setTexture(card[29]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "five")
            {
                Sprite[i].setTexture(card[30]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "six")
            {
                Sprite[i].setTexture(card[31]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "seven")
            {
                Sprite[i].setTexture(card[32]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "eight")
            {
                Sprite[i].setTexture(card[33]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "nine")
            {
                Sprite[i].setTexture(card[34]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "ten")
            {
                Sprite[i].setTexture(card[35]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "jack")
            {
                Sprite[i].setTexture(card[36]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "queen")
            {
                Sprite[i].setTexture(card[37]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "king")
            {
                Sprite[i].setTexture(card[38]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "ace")
            {
                Sprite[i].setTexture(card[39]);
                Sprite[i].setPosition(x,0);
            }
        }
        if(Dealer->hand[i].sign == "diamonds")
        {
            if (Dealer->hand[i].points == "two")
            {
                Sprite[i].setTexture(card[40]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "three")
            {
                Sprite[i].setTexture(card[41]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "four")
            {
                Sprite[i].setTexture(card[42]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "five")
            {
                Sprite[i].setTexture(card[43]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "six")
            {
                Sprite[i].setTexture(card[44]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "seven")
            {
                Sprite[i].setTexture(card[45]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "eight")
            {
                Sprite[i].setTexture(card[46]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "nine")
            {
                Sprite[i].setTexture(card[47]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "ten")
            {
                Sprite[i].setTexture(card[48]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "jack")
            {
                Sprite[i].setTexture(card[49]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "queen")
            {
                Sprite[i].setTexture(card[50]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "king")
            {
                Sprite[i].setTexture(card[51]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "ace")
            {
                Sprite[i].setTexture(card[52]);
                Sprite[i].setPosition(x,0);
            }
        }
        if(Dealer->hand[i].sign == "spades")
        {
            if (Dealer->hand[i].points == "two")
            {
                Sprite[i].setTexture(card[0]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "three")
            {
                Sprite[i].setTexture(card[1]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "four")
            {
                Sprite[i].setTexture(card[2]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "five")
            {
                Sprite[i].setTexture(card[3]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "six")
            {
                Sprite[i].setTexture(card[4]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "seven")
            {
                Sprite[i].setTexture(card[5]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "eight")
            {
                Sprite[i].setTexture(card[6]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "nine")
            {
                Sprite[i].setTexture(card[7]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "ten")
            {
                Sprite[i].setTexture(card[8]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "jack")
            {
                Sprite[i].setTexture(card[9]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "queen")
            {
                Sprite[i].setTexture(card[10]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "king")
            {
                Sprite[i].setTexture(card[11]);
                Sprite[i].setPosition(x,0);
            }
            if (Dealer->hand[i].points == "ace")
            {
                Sprite[i].setTexture(card[12]);
                Sprite[i].setPosition(x,0);
            }
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                end_game();
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (button[1].getGlobalBounds().contains(mousePos))
                {
                    end_game();
                    window.close();
                    Game_selection::show_games();
                }
                if (button[2].getGlobalBounds().contains(mousePos))
                {
                    rules();
                }
                if (sprite[53].getGlobalBounds().contains(mousePos))
                {
                    Player->draw(*(deck_ptr->deck_ptr),1);
                }
                if (button[0].getGlobalBounds().contains(mousePos))
                {
                    do
                    {
                        Dealer->draw(*(deck_ptr->deck_ptr),1);
                        for(int i = 0; i < Dealer->hand.size();i++)
                        {
                            int x = 15 + 100*i;
                            if(Dealer->hand[i].sign == "hearts")
                            {
                                if (Dealer->hand[i].points == "two")
                                {
                                    Sprite[i].setTexture(card[14]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "three")
                                {
                                    Sprite[i].setTexture(card[15]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "four")
                                {
                                    Sprite[i].setTexture(card[16]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "five")
                                {
                                    Sprite[i].setTexture(card[17]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "six")
                                {
                                    Sprite[i].setTexture(card[18]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "seven")
                                {
                                    Sprite[i].setTexture(card[19]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "eight")
                                {
                                    Sprite[i].setTexture(card[20]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "nine")
                                {
                                    Sprite[i].setTexture(card[21]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "ten")
                                {
                                    Sprite[i].setTexture(card[22]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "jack")
                                {
                                    Sprite[i].setTexture(card[23]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "queen")
                                {
                                    Sprite[i].setTexture(card[24]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "king")
                                {
                                    Sprite[i].setTexture(card[25]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "ace")
                                {
                                    Sprite[i].setTexture(card[26]);
                                    Sprite[i].setPosition(x,0);
                                }
                            }
                            if(Dealer->hand[i].sign == "clubs")
                            {
                                if (Dealer->hand[i].points == "two")
                                {
                                    Sprite[i].setTexture(card[27]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "three")
                                {
                                    Sprite[i].setTexture(card[28]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "four")
                                {
                                    Sprite[i].setTexture(card[29]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "five")
                                {
                                    Sprite[i].setTexture(card[30]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "six")
                                {
                                    Sprite[i].setTexture(card[31]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "seven")
                                {
                                    Sprite[i].setTexture(card[32]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "eight")
                                {
                                    Sprite[i].setTexture(card[33]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "nine")
                                {
                                    Sprite[i].setTexture(card[34]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "ten")
                                {
                                    Sprite[i].setTexture(card[35]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "jack")
                                {
                                    Sprite[i].setTexture(card[36]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "queen")
                                {
                                    Sprite[i].setTexture(card[37]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "king")
                                {
                                    Sprite[i].setTexture(card[38]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "ace")
                                {
                                    Sprite[i].setTexture(card[39]);
                                    Sprite[i].setPosition(x,0);
                                }
                            }
                            if(Dealer->hand[i].sign == "diamonds")
                            {
                                if (Dealer->hand[i].points == "two")
                                {
                                    Sprite[i].setTexture(card[40]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "three")
                                {
                                    Sprite[i].setTexture(card[41]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "four")
                                {
                                    Sprite[i].setTexture(card[42]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "five")
                                {
                                    Sprite[i].setTexture(card[43]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "six")
                                {
                                    Sprite[i].setTexture(card[44]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "seven")
                                {
                                    Sprite[i].setTexture(card[45]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "eight")
                                {
                                    Sprite[i].setTexture(card[46]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "nine")
                                {
                                    Sprite[i].setTexture(card[47]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "ten")
                                {
                                    Sprite[i].setTexture(card[48]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "jack")
                                {
                                    Sprite[i].setTexture(card[49]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "queen")
                                {
                                    Sprite[i].setTexture(card[50]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "king")
                                {
                                    Sprite[i].setTexture(card[51]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "ace")
                                {
                                    Sprite[i].setTexture(card[52]);
                                    Sprite[i].setPosition(x,0);
                                }
                            }
                            if(Dealer->hand[i].sign == "spades")
                            {
                                if (Dealer->hand[i].points == "two")
                                {
                                    Sprite[i].setTexture(card[0]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "three")
                                {
                                    Sprite[i].setTexture(card[1]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "four")
                                {
                                    Sprite[i].setTexture(card[2]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "five")
                                {
                                    Sprite[i].setTexture(card[3]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "six")
                                {
                                    Sprite[i].setTexture(card[4]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "seven")
                                {
                                    Sprite[i].setTexture(card[5]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "eight")
                                {
                                    Sprite[i].setTexture(card[6]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "nine")
                                {
                                    Sprite[i].setTexture(card[7]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "ten")
                                {
                                    Sprite[i].setTexture(card[8]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "jack")
                                {
                                    Sprite[i].setTexture(card[9]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "queen")
                                {
                                    Sprite[i].setTexture(card[10]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "king")
                                {
                                    Sprite[i].setTexture(card[11]);
                                    Sprite[i].setPosition(x,0);
                                }
                                if (Dealer->hand[i].points == "ace")
                                {
                                    Sprite[i].setTexture(card[12]);
                                    Sprite[i].setPosition(x,0);
                                }
                            }
                        }
                        for (int i=0; i < Dealer->hand.size(); i++)
                        {
                            window.draw(Sprite[i]);
                        }
                        window.display();
                        wait(1);
                        if(Dealer->sum() > 21)
                        {
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
                        if (Dealer->sum() >= Player->sum())
                        {
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
                    }while(Dealer->sum()<17);
                    if (Dealer->sum()>Player->sum())
                    {
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
                    if (Player->sum()>Dealer->sum())
                    {
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
        for(int i = 0; i < Player->hand.size();i++)
            {
                int x = 15 + 100*i ;

                if(Player->hand[i].sign == "hearts")
                {
                    if (Player->hand[i].points == "two")
                    {
                        sprite[i].setTexture(card[14]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "three")
                    {
                        sprite[i].setTexture(card[15]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "four")
                    {
                        sprite[i].setTexture(card[16]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "five")
                    {
                        sprite[i].setTexture(card[17]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "six")
                    {
                        sprite[i].setTexture(card[18]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "seven")
                    {
                        sprite[i].setTexture(card[19]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "eight")
                    {
                        sprite[i].setTexture(card[20]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "nine")
                    {
                        sprite[i].setTexture(card[21]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "ten")
                    {
                        sprite[i].setTexture(card[22]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "jack")
                    {
                        sprite[i].setTexture(card[23]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "queen")
                    {
                        sprite[i].setTexture(card[24]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "king")
                    {
                        sprite[i].setTexture(card[25]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "ace")
                    {
                        sprite[i].setTexture(card[26]);
                        sprite[i].setPosition(x,470);
                    }
                }
                if(Player->hand[i].sign == "clubs")
                {
                    if (Player->hand[i].points == "two")
                    {
                        sprite[i].setTexture(card[27]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "three")
                    {
                        sprite[i].setTexture(card[28]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "four")
                    {
                        sprite[i].setTexture(card[29]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "five")
                    {
                        sprite[i].setTexture(card[30]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "six")
                    {
                        sprite[i].setTexture(card[31]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "seven")
                    {
                        sprite[i].setTexture(card[32]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "eight")
                    {
                        sprite[i].setTexture(card[33]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "nine")
                    {
                        sprite[i].setTexture(card[34]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "ten")
                    {
                        sprite[i].setTexture(card[35]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "jack")
                    {
                        sprite[i].setTexture(card[36]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "queen")
                    {
                        sprite[i].setTexture(card[37]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "king")
                    {
                        sprite[i].setTexture(card[38]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "ace")
                    {
                        sprite[i].setTexture(card[39]);
                        sprite[i].setPosition(x,470);
                    }
                }
                if(Player->hand[i].sign == "diamonds")
                {
                    if (Player->hand[i].points == "two")
                    {
                        sprite[i].setTexture(card[40]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "three")
                    {
                        sprite[i].setTexture(card[41]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "four")
                    {
                        sprite[i].setTexture(card[42]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "five")
                    {
                        sprite[i].setTexture(card[43]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "six")
                    {
                        sprite[i].setTexture(card[44]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "seven")
                    {
                        sprite[i].setTexture(card[45]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "eight")
                    {
                        sprite[i].setTexture(card[46]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "nine")
                    {
                        sprite[i].setTexture(card[47]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "ten")
                    {
                        sprite[i].setTexture(card[48]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "jack")
                    {
                        sprite[i].setTexture(card[49]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "queen")
                    {
                        sprite[i].setTexture(card[50]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "king")
                    {
                        sprite[i].setTexture(card[51]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "ace")
                    {
                        sprite[i].setTexture(card[52]);
                        sprite[i].setPosition(x,470);
                    }
                }
                if(Player->hand[i].sign == "spades")
                {
                    if (Player->hand[i].points == "two")
                    {
                        sprite[i].setTexture(card[0]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "three")
                    {
                        sprite[i].setTexture(card[1]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "four")
                    {
                        sprite[i].setTexture(card[2]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "five")
                    {
                        sprite[i].setTexture(card[3]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "six")
                    {
                        sprite[i].setTexture(card[4]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "seven")
                    {
                        sprite[i].setTexture(card[5]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "eight")
                    {
                        sprite[i].setTexture(card[6]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "nine")
                    {
                        sprite[i].setTexture(card[7]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "ten")
                    {
                        sprite[i].setTexture(card[8]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "jack")
                    {
                        sprite[i].setTexture(card[9]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "queen")
                    {
                        sprite[i].setTexture(card[10]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "king")
                    {
                        sprite[i].setTexture(card[11]);
                        sprite[i].setPosition(x,470);
                    }
                    if (Player->hand[i].points == "ace")
                    {
                        sprite[i].setTexture(card[12]);
                        sprite[i].setPosition(x,470);
                    }
                }

            }

        window.clear();
        //rysowanie przycisków
        for (int i=0; i < 3; i++)
        {
            window.draw(button[i]);
        }

        //rysowanie kart Gracza
        for (int i=0; i < Player->hand.size(); i++)
        {
            window.draw(sprite[i]);
        }

        //rysowanie rewersów
        window.draw(sprite[53]);
        window.draw(Rsprite);

        //rysowanie pierwszej karty Dealera
         window.draw(Sprite[0]);

        //rysowanie tekstu
        for (int i=0; i<3; i++)
        {
            window.draw(text[i]);
        }

        window.display();

        //przegrana gracza
        if(Player->sum()>21)
        {
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

void Blackjack::end_game()
{
    Player->clear_hands(*deck_ptr->deck_ptr);
    Dealer->clear_hands(*deck_ptr->deck_ptr);
}

void Blackjack::rules()
{
    //utworzenie okna
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    //wczytanie czcionki
    sf::Font font;
    font.loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/czcionka/NEON____.ttf");

    //załadowanie zasad
    sf::Texture menu;
    menu.loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/zasady.png");
    sf::Sprite sprite;
    sprite.setTexture(menu);

    //utworzenie napisów
    sf::Text text;
    text = Drawing().text("GRAJ",430,495,font);

    //tworzenie przycisków
    sf::RectangleShape button;
    button = Drawing().draw_button(398, 500,200,50);

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
                if (button.getGlobalBounds().contains(mousePos))
                {
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

void Blackjack::wait(int seconds)
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}
