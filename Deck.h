//
// Created by Konkuker on 15.05.2023.
//

/**
 * Created by Dominik Micor on 15/5/2023.
 *
 * @file Deck.h
 *
 *
 * This class represents a deck of cards
 */

#ifndef CASINO_SFML__DECK_H
#define CASINO_SFML__DECK_H

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Deck {
public:
    //stworzenie struktury karty
    struct card
    {
        string points;
        string sign;
        int points_BJ;
    };
    //stworzenie vectora kart
     vector <card> deck = {
            {"two","hearts",2},{"two","clubs",2},{"two","diamonds",2},{"two","spades",2},
            {"three","hearts",3},{"three","clubs",3},{"three","diamonds",3},{"three","spades",3},
            {"four","hearts",4},{"four","clubs",4},{"four","diamonds",4},{"four","spades",4},
            {"five","hearts",5},{"five","clubs",5},{"five","diamonds",5},{"five","spades",5},
            {"six","hearts",6},{"six","clubs",6},{"six","diamonds",6},{"six","spades",6},
            {"seven","hearts",7},{"seven","clubs",7},{"seven","diamonds",7},{"seven","spades",7},
            {"eight","hearts",8},{"eight","clubs",8},{"eight","diamonds",8},{"eight","spades",8},
            {"nine","hearts",9},{"nine","clubs",9},{"nine","diamonds",9},{"nine","spades",9},
            {"ten","hearts",10},{"ten","clubs",10},{"ten","diamonds",10},{"ten","spades",10},
            {"jack","hearts",10},{"jack","clubs",10},{"jack","diamonds",10},{"jack","spades",10},
            {"queen","hearts",10},{"queen","clubs",10},{"queen","diamonds",10},{"queen","spades",10},
            {"king","hearts",10},{"king","clubs",10},{"king","diamonds",10},{"king","spades",10},
            {"ace","hearts",11},{"ace","clubs",11},{"ace","diamonds",11},{"ace","spades",11}
    };
     //stworzenia nowoczesnego wskaźnika na deck
    unique_ptr<vector<card>> deck_ptr = make_unique<vector<card>>(deck);

};


#endif //CASINO_SFML__DECK_H*/
