//
// Created by Konkuker on 15.05.2023.
//

#ifndef CASINO_SFML__PLAYERS_H
#define CASINO_SFML__PLAYERS_H

#include <vector>
#include "Deck.h"

class Players {
public:
    void draw(unique_ptr<vector<Deck::card>>& deck_ptr);
    void clear_hand();
    void show_cards();
    vector <Deck::card> hand = {};
    int sum = 0;
private:
    int random_number();
};


#endif //CASINO_SFML__PLAYERS_H
