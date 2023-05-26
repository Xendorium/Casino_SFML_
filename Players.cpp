//
// Created by Konkuker on 15.05.2023.
//

/**
 * Created by Dominik Micor on 15/5/2023.
 *
 * @file Players.cpp
 *
 * Implementation of methods declared in "Players.h".
 */

#include "Players.h"

void Players::draw(std::vector<Deck::card> &deck, int ilosc) {
    int j, i, k;
    if (ilosc == 2) {
        do {
            j = random_number();
            i = random_number();
        } while (j == i);
        Deck::card C1 = deck[j];
        hand.push_back(C1);
        P_and_D_hand.push_back(C1);
        deck.erase(deck.begin() + j);

        Deck::card C2 = deck[i];
        hand.push_back(C2);
        P_and_D_hand.push_back(C2);
        deck.erase(deck.begin() + i);
    }
    if (ilosc == 1) {
        k = (rand() % (51 - P_and_D_hand.size()) + 0);
        Deck::card C3 = deck[k];
        hand.push_back(C3);
        P_and_D_hand.push_back(C3);
        deck.erase(deck.begin() + k);
    }
}

int Players::sum() {
    int sum = 0;
    for (int i = 0; i < hand.size(); i++) {
        sum = sum + hand[i].points_BJ;
    }
    if (sum > 21) {
        for (int i = 0; i < hand.size(); i++) {
            if (hand[i].points == ("ace") && (hand[i].points_BJ == 11)) {
                hand[i].points_BJ = 1;
                sum = sum - 10;
            }
        }
    }
    return sum;
}

void Players::clear_hands(std::vector<Deck::card> &deck) {
    for (int i = 0; i < P_and_D_hand.size(); i++) {
        Deck::card C1 = {P_and_D_hand[i].points, P_and_D_hand[i].sign, P_and_D_hand[i].points_BJ};
        deck.push_back(C1);
    }
    hand.clear();
    P_and_D_hand.clear();
}

int Players::random_number() {
    int j;
    do {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 gen(seed);
        std::uniform_int_distribution<int> dist(0, 51 - P_and_D_hand.size());
        j = dist(gen);
    } while (j >= 51 - P_and_D_hand.size() || j < 0);
    return j;
}

enum card_type {

};