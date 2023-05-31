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
            {"two",   "hearts",   2,0},
            {"two",   "clubs",    2,1},
            {"two",   "diamonds", 2,2},
            {"two",   "spades",   2,3},
            {"three", "hearts",   3,4},
            {"three", "clubs",    3,5},
            {"three", "diamonds", 3,6},
            {"three", "spades",   3,7},
            {"four",  "hearts",   4,8},
            {"four",  "clubs",    4,9},
            {"four",  "diamonds", 4,10},
            {"four",  "spades",   4,11},
            {"five",  "hearts",   5,12},
            {"five",  "clubs",    5,13},
            {"five",  "diamonds", 5,14},
            {"five",  "spades",   5,15},
            {"six",   "hearts",   6,16},
            {"six",   "clubs",    6,17},
            {"six",   "diamonds", 6,18},
            {"six",   "spades",   6,19},
            {"seven", "hearts",   7,20},
            {"seven", "clubs",    7,21},
            {"seven", "diamonds", 7,22},
            {"seven", "spades",   7,23},
            {"eight", "hearts",   8,24},
            {"eight", "clubs",    8,25},
            {"eight", "diamonds", 8,26},
            {"eight", "spades",   8,27},
            {"nine",  "hearts",   9,28},
            {"nine",  "clubs",    9,29},
            {"nine",  "diamonds", 9,30},
            {"nine",  "spades",   9,31},
            {"ten",   "hearts",   10,32},
            {"ten",   "clubs",    10,33},
            {"ten",   "diamonds", 10,34},
            {"ten",   "spades",   10,35},
            {"jack",  "hearts",   10,36},
            {"jack",  "clubs",    10,37},
            {"jack",  "diamonds", 10,38},
            {"jack",  "spades",   10,39},
            {"queen", "hearts",   10,40},
            {"queen", "clubs",    10,41},
            {"queen", "diamonds", 10,42},
            {"queen", "spades",   10,43},
            {"king",  "hearts",   10,44},
            {"king",  "clubs",    10,45},
            {"king",  "diamonds", 10,46},
            {"king",  "spades",   10,47},
            {"ace",   "hearts",   11,48},
            {"ace",   "clubs",    11,49},
            {"ace",   "diamonds", 11,50},
            {"ace",   "spades",   11,51}
    };
    //stworzenia nowoczesnego wskaźnika na deck
    std::unique_ptr<std::vector<card>> deck_ptr = std::make_unique<std::vector<card>>(deck);

};


#endif //CASINO_SFML__DECK_H*/
