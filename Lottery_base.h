//
// Created by Konkuker on 19.05.2023.
//

#ifndef CASINO_SFML__LOTTERY_BASE_H
#define CASINO_SFML__LOTTERY_BASE_H

#include <iostream>

class Lottery_base{
public:
    //stworzenie elementów losowanych
    struct elements
    {
        std::string typeS;
        int typeI;
    };

    //tablica elementów losujących
    elements lottery_base[8] = {
            {"seven",0},{"strawberry",1},{"banana",2},{"lemon",3},
            {"orange",4},{"plum",5},{"watermelon",6},{"cherry",7}
    };
};


#endif //CASINO_SFML__LOTTERY_BASE_H
