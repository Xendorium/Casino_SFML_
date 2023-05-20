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

/// Class Players
class Players {
public:

    ///<summary>
    /// draw(vector<Deck::card>& deck,int ilosc) method
    /// </summary>
    ///<example>
    /// <code>
    /// void Blackjack::start_game()
    /// {
    ///    Players *player = new Players;
    ///    player->draw(*(deck_ptr->deck_ptr), 2);
    /// }
    /// </code>
    /// </example>
    void draw(vector<Deck::card>& deck,int ilosc);

    ///<summary>
    /// clear_hands(vector<Deck::card>& deck) method
    /// </summary>
    ///<example>
    /// <code>
    ///void Blackjack::end_game()
    ///{
    ///    player->clear_hands(*deck_ptr->deck_ptr);
    ///}
    /// </code>
    /// </example>
    void clear_hands(vector<Deck::card>& deck);
    int sum();
    vector <Deck::card> hand = {};
    vector <Deck::card> P_and_D_hand = {};
private:

    ///<summary>
    /// random_number() method
    /// </summary>
    ///<example>
    /// <code>
    ///void Players::draw(vector<Deck::card>& deck,int ilosc)
    ///{
    ///    j = random_number();
    ///}
    /// </code>
    /// </example>
    int random_number();
};


#endif //CASINO_SFML__PLAYERS_H
