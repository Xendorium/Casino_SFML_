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

class Deck {
public:
    //stworzenie struktury karty
    struct card {
        std::string points;
        std::string sign;
        int points_BJ;
        int card_type;
    };
    //stworzenie vectora kart
    std::vector<card> deck = {
            {"two",   "hearts",   2,1},
            {"two",   "clubs",    2,2},
            {"two",   "diamonds", 2,3},
            {"two",   "spades",   2,4},
            {"three", "hearts",   3,5},
            {"three", "clubs",    3,6},
            {"three", "diamonds", 3,7},
            {"three", "spades",   3,8},
            {"four",  "hearts",   4,9},
            {"four",  "clubs",    4,10},
            {"four",  "diamonds", 4,11},
            {"four",  "spades",   4,12},
            {"five",  "hearts",   5,13},
            {"five",  "clubs",    5,14},
            {"five",  "diamonds", 5,15},
            {"five",  "spades",   5,16},
            {"six",   "hearts",   6,17},
            {"six",   "clubs",    6,18},
            {"six",   "diamonds", 6,19},
            {"six",   "spades",   6,20},
            {"seven", "hearts",   7,21},
            {"seven", "clubs",    7,22},
            {"seven", "diamonds", 7,23},
            {"seven", "spades",   7,24},
            {"eight", "hearts",   8,25},
            {"eight", "clubs",    8,26},
            {"eight", "diamonds", 8,27},
            {"eight", "spades",   8,28},
            {"nine",  "hearts",   9,29},
            {"nine",  "clubs",    9,30},
            {"nine",  "diamonds", 9,31},
            {"nine",  "spades",   9,32},
            {"ten",   "hearts",   10,33},
            {"ten",   "clubs",    10,34},
            {"ten",   "diamonds", 10,35},
            {"ten",   "spades",   10,36},
            {"jack",  "hearts",   10,37},
            {"jack",  "clubs",    10,38},
            {"jack",  "diamonds", 10,39},
            {"jack",  "spades",   10,40},
            {"queen", "hearts",   10,41},
            {"queen", "clubs",    10,42},
            {"queen", "diamonds", 10,43},
            {"queen", "spades",   10,44},
            {"king",  "hearts",   10,45},
            {"king",  "clubs",    10,46},
            {"king",  "diamonds", 10,47},
            {"king",  "spades",   10,48},
            {"ace",   "hearts",   11,49},
            {"ace",   "clubs",    11,50},
            {"ace",   "diamonds", 11,51},
            {"ace",   "spades",   11,52}
    };
    //stworzenia nowoczesnego wskaźnika na deck
    std::unique_ptr<std::vector<card>> deck_ptr = std::make_unique<std::vector<card>>(deck);

};


#endif //CASINO_SFML__DECK_H*/
