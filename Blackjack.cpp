//
// Created by Konkuker on 15.05.2023.
//

#include <memory>
#include "Blackjack.h"
#include "Players.h"

void Blackjack::start_game()
{

    Players *Players1 = new Players;
    unique_ptr<vector<Deck::card>> Deck::deck_ptr;
    Players1->draw(unique_ptr<vector<Deck::card>> deck_ptr);

}

void Blackjack::end_game()
{

}
