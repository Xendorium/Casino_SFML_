//
// Created by Konkuker on 15.05.2023.
//

#ifndef CASINO_SFML__GAMES_H
#define CASINO_SFML__GAMES_H

/// Abstraction Class Games
class Games {
public:

    ///<summary>
    /// virtual start_game() method
    ///<summary>
    virtual void start_game() = 0 ;

    ///<summary>
    /// virtual end_game() method
    ///<summary>
    virtual void end_game() = 0;
};


#endif //CASINO_SFML__GAMES_H
