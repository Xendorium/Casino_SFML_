//
// Created by Konkuker on 15.05.2023.
//

/**
 * Created by Dominik Micor on 15/5/2023.
 *
 * @file Games.h
 *
 * Declaration of abstract methods
 */

#ifndef CASINO_SFML__GAMES_H
#define CASINO_SFML__GAMES_H

/// Abstraction Class Games
class Games {
public:

    /**<summary>
    /// virtual start_game() metod
    ///<summary>
    */
    virtual void start_game() = 0;

    /**<summary>
    /// virtual end_game() method
    ///<summary>
    */
    virtual void end_game() = 0;
};


#endif //CASINO_SFML__GAMES_H
