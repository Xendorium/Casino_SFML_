//
// Created by Konkuker on 15.05.2023.
//

#include "Deck.h"
#include "Players.h"
#include <random>
#include <vector>
#include <chrono>
#include <iostream>
#include <cstdlib>

using namespace std;

//funkcja dobierająca karte
void Players::draw(vector<Deck::card>& deck,int ilosc)
{
    int j,i,k;
    if (ilosc == 2)
    {
        do
        {
            j = random_number();
            i = random_number();
        } while (j==i);
        Deck::card C1 = deck[j];
        hand.push_back(C1);
        P_and_D_hand.push_back(C1);
        deck.erase(deck.begin()+j);

        Deck::card C2 = deck[i];
        hand.push_back(C2);
        P_and_D_hand.push_back(C2);
        deck.erase(deck.begin()+i);
    }
    if (ilosc == 1)
    {
       k = (rand()%(51-P_and_D_hand.size()));
       Deck::card C3 = deck[k];
       hand.push_back(C3);
       P_and_D_hand.push_back(C3);
       deck.erase(deck.begin()+k);
    }
}

//funkcja sumujaca punkty do Blackjacka
int Players::sum()
{
    int sum=0;
    for(int i = 0; i < hand.size(); i++)
    {
       sum = sum + hand[i].points_BJ;

    }
    return sum;
}

//funkcja czyszczaca rece graczy
void Players::clear_hands(vector<Deck::card>& deck)
{
    for (int i = 0; i < P_and_D_hand.size(); i++)
    {
        Deck::card C1 = {P_and_D_hand[i].points,P_and_D_hand[i].sign, P_and_D_hand[i].points_BJ};
        deck.push_back(C1);
    }
    hand.clear();
    P_and_D_hand.clear();
}

//funkcja losująca liczbe
int Players::random_number()
{
    int j;
    do {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        mt19937 gen(seed);
        uniform_int_distribution<int> dist(0, 51 - P_and_D_hand.size());
        j = dist(gen);
        cout << j << endl;
        }while (j>=51-P_and_D_hand.size()||j<0);
    return j;
}

