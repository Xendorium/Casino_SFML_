//
// Created by Konkuker on 15.05.2023.
//

#include "Deck.h"
#include "Players.h"
#include <random>
#include <vector>

using namespace std;

void Players::draw(unique_ptr<vector<Deck::card>>&deck_ptr)
{
    int j;
    j = random_number();
    Deck::card C1 = (*deck_ptr)[j];
    hand.push_back(C1);
    deck_ptr->erase(deck_ptr->begin()+j);
}

int Players::random_number()
{
    int j;
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0, 51 - hand.size());
    j = dist(mt);
    return j;
}
