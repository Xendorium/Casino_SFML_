//
// Created by Konkuker on 15.05.2023.
//

#ifndef CASINO_SFML__BLACKJACK_H
#define CASINO_SFML__BLACKJACK_H
#include "Games.h"
#include "Players.h"
#include "Drawing.h"

/// Subclass Blackjack
class Blackjack :public Games{
public:

    ///<summary>
    /// start_game() method
    /// </summary>
    ///<example>
    /// <code>
    /// void Game_selection::show_games()
    /// {
    ///     Blackjack B1;
    ///     wsk = &B1;
    ///     wsk->start_game();
    /// }
    /// </code>
    /// </example>
    void start_game();

    ///<summary>
    /// end_game() method
    /// </summary>
    void end_game();
private:

    ///<summary>
    /// rules() method
    /// </summary>
    void rules();

    ///<summary>
    /// wait() method
    /// </summary>
    void wait(int seconds);
};


#endif //CASINO_SFML__BLACKJACK_H
