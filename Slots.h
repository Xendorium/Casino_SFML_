//
// Created by Konkuker on 19.05.2023.
//

/**
 * Created by Dominik Micor on 19/5/2023.
 *
 * @file Slots.h
 *
 * Declaration of methods implemented in "Slots.cpp".
 *
 * This class represents the slots machine
 */


#ifndef CASINO_SFML__SLOTS_H
#define CASINO_SFML__SLOTS_H
#include "Games.h"

/// Subclass Games
class Slots: public Games {
public:

    /**<summary>
    /// loading the main loop
    /// load font, graphics
    /// checking the results
    /// creating array for randomized elements
    /// </summary>
    */
    void start_game();


    /**<summary>
    /// end_game();
    /// </summary>
    */
    void end_game();
private:
    /**<summary>
    /// drawing a number
    /// </summary>
    */
    int random_number();
};


#endif //CASINO_SFML__SLOTS_H
