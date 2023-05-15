//
// Created by Konkuker on 15.05.2023.
//

#ifndef CASINO_SFML__BLACKJACK_H
#define CASINO_SFML__BLACKJACK_H
#include "Games.h"
#include "Players.h"

class Blackjack :public Games{
public:
    void start_game();
    void end_game();
};


#endif //CASINO_SFML__BLACKJACK_H
