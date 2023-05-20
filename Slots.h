//
// Created by Konkuker on 19.05.2023.
//

#ifndef CASINO_SFML__SLOTS_H
#define CASINO_SFML__SLOTS_H
#include "Games.h"


class Slots: public Games {
public:

    ///<summary>
    /// start_game method
    /// </summary>
    ///<example>
    /// <code>
    /// void Game_selection::show_games()
    /// {
    ///     Slots S1;
    ///     wsk = &S1;
    ///     wsk->start_game();
    /// }
    /// </code>
    /// </example>
    void start_game();


    ///<summary>
    /// start_game method
    /// </summary>
    void end_game();
private:
    int random_number();
};


#endif //CASINO_SFML__SLOTS_H
