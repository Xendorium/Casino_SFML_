//
// Created by Konkuker on 15.05.2023.
//

#include "Deck.h"
#include "Players.h"
#include <random>
#include <vector>
#include <chrono>

using namespace std;

//funkcja dobierająca karte
void Players::draw(vector<Deck::card>& deck)
{
    int j;
    j = random_number();
    Deck::card C1 = deck[j];
    hand.push_back(C1);
    deck.erase(deck.begin()+j);
}
//funkcja pokazująca karty
void Players::show_cards()
{
    for (int i = 0; i < hand.size(); i++)
    {
        cout << hand[i].sign << endl;
        cout << hand[i].points << endl;
        cout << hand[i].points_BJ << endl;
    }
    cout << "Suma twoich kart " << sum() << endl;
}

//funkcja sumujaca punkty do Blackjacka
int Players::sum()
{   int sum;
    for(int i = 0; i < hand.size(); i++)
    {
       sum = sum + hand[i].points_BJ;
    }
    return sum;
}

//funkcja losująca liczbe
int Players::random_number()
{
    int j;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<int> dist(0, 51 - hand.size());
    j = dist(gen);
    return j;
}
