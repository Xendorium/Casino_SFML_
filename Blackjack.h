//
// Created by Konkuker on 15.05.2023.
//

/**
 * Created by Dominik Micor on 15/5/2023.
 *
 * @file Blackjack.h
 *
 * Declaration of methods implemented in "Blackjack.cpp".
 *
 * This class represents game Blackjack
 */


#ifndef CASINO_SFML__BLACKJACK_H
#define CASINO_SFML__BLACKJACK_H
#include "Games.h"
#include "Players.h"
#include "Drawing.h"

/// Subclass Blackjack
class Blackjack :public Games{
public:

    /**<summary>
    /// creating the main window
    /// loading font, graphics
    /// creating arrays for players cards
    /// drawing player cards
    /// checking the results
    /// </summary>
    */
    void start_game();

    ///<summary>
    /// cleaning the "hands" of players
    /// </summary>
    void end_game();
private:

    /**<summary>
    /// showing the rules of the game
    /// </summary>
    */
    void rules();

    /**<summary>
    /// method used to create a break
    /// </summary>
     */
    void wait(int seconds);
};


#endif //CASINO_SFML__BLACKJACK_H
