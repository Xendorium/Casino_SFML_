//
// Created by Konkuker on 19.05.2023.
//

#ifndef CASINO_SFML__SLOTS_H
#define CASINO_SFML__SLOTS_H
#include "Games.h"


class Slots: public Games {
public:
    void start_game();
    void end_game();
private:
    void spin();
    int random_number();
    void wait(int seconds);
};


#endif //CASINO_SFML__SLOTS_H