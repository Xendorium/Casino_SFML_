//
// Created by Konkuker on 15.05.2023.
//

/**
 * Created by Dominik Micor on 15/5/2023.
 *
 * @file Players.h
 *
 * Declaration of methods implemented in "Players.cpp".
 *
 * This class represents Blackjack players
 */


#ifndef CASINO_SFML__PLAYERS_H
#define CASINO_SFML__PLAYERS_H

#include <vector>
#include "Deck.h"
#include <random>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/// Class Players
class Players {
public:

    /**<summary>
    /// a method for drawing a card from the deck
    /// </summary>
    */
    void draw(vector<Deck::card>& deck,int ilosc);

    /**<summary>
    /// a method for cleaning the hands of player
    /// </summary>
    */
    void clear_hands(vector<Deck::card>& deck);

    /**<summary>
    /// sums up the points from the cards
    /// </summary>
    */
    int sum();
    vector <Deck::card> hand = {};
    vector <Deck::card> P_and_D_hand = {};
private:

    /**<summary>
    /// drawing a number
    /// </summary>
    */
    int random_number();
};


#endif //CASINO_SFML__PLAYERS_H
