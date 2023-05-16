//
// Created by Konkuker on 15.05.2023.
//

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
    sf::RenderWindow window(sf::VideoMode(1024, 600), "Casino");

    //wczytanie czcionki
    sf::Font font;
    font.loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/czcionka/NEON____.ttf");

    //utworzenie napisów
    sf::Text text[4];
    text[0] = Drawing().text("Blackjack",352,250,font);
    text[1] = Drawing().text("Hit",65,195,font);
    text[2] = Drawing().text("Stand",20,295,font);
    text[3] = Drawing().text("Menu",442,345,font);

    //yworzenie przycisków
    sf::RectangleShape button[4];
    button[0] = Drawing().draw_button(312, 230,400 , 100);
    button[1] = Drawing().draw_button(10, 200,200,50);
    button[2] = Drawing().draw_button(10, 300,200,50);
    button[3] = Drawing().draw_button(412, 350,200,50);


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

     //REWERS
     card[53].loadFromFile("C:/Users/Konkuker/Desktop/programowanie projekt/grafiki jpg/piki/rewers.jpg");

    sf::Sprite sprite[54];
    sprite[53].setTexture(card[53]);
    sprite[53].setPosition(934.f,230.f);

    //Ustawianie kart na ręce
    int x = 0;
    int y = 474;

    //Dobieranie kart i pokazywanie ich przez gracza
    Player->draw(*(deck_ptr->deck_ptr),2);
    show_hand_Player();

    //Dobranie karty i pokazanie jej przez krupiera
     Dealer->draw(*(deck_ptr->deck_ptr),1);
     show_hand_Dealer();

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
                if (button[3].getGlobalBounds().contains(mousePos))
                {
                    end_game();
                    window.close();
                    Game_selection::show_games();
                }
            }
        }
        window.clear();
        window.draw(button[0]);
        window.draw(button[1]);
        window.draw(button[2]);
        window.draw(button[3]);
        window.draw(text[0]);
        window.draw(text[1]);
        window.draw(text[2]);
        window.draw(text[3]);
        window.draw(sprite[53]);
        window.display();
    }
}

void Blackjack::end_game()
{
    Player->clear_hands(*deck_ptr->deck_ptr);
    Dealer->clear_hands(*deck_ptr->deck_ptr);
}

void Blackjack::show_hand_Player()
{
    for (int i = 0; i < Player->hand.size(); i++)
    {
        cout << Player->hand[i].sign << endl;
        cout << Player->hand[i].points << endl;
        cout << Player->hand[i].points_BJ << endl;
    }
}

void Blackjack::show_hand_Dealer()
{
    for (int i = 0; i < Dealer->hand.size(); i++)
    {
        cout << Dealer->hand[i].sign << endl;
        cout << Dealer->hand[i].points << endl;
        cout << Dealer->hand[i].points_BJ << endl;
    }
}
