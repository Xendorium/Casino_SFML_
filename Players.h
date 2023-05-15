//
// Created by Konkuker on 15.05.2023.
//

#ifndef CASINO_SFML__PLAYERS_H
#define CASINO_SFML__PLAYERS_H

#include <vector>
#include "Deck.h"
#include <random>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Drawing.h"

class Players {
public:
    void draw(vector<Deck::card>& deck);
    void clear_hand();
    void show_cards();
    int sum();
    vector <Deck::card> hand = {};
private:
    int random_number();
};


#endif //CASINO_SFML__PLAYERS_H
