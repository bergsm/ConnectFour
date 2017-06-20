/********************************************************************* 
** Author: Shawn Berg
** Date: 6/19/17
** Description: Header file for Connect Four
*********************************************************************/

#ifndef CONNECTFOUR_CONNECTFOUR_HPP
#define CONNECTFOUR_CONNECTFOUR_HPP

#include <iostream>
#include "Board.hpp"


class ConnectFour
{
private:
    // Member Variables
    Board board;
    char PlayerTurn;

public:
    // Overload Constructor
    ConnectFour();

    // Default Constructor
    ConnectFour(char);

    // Destructor
    ~ConnectFour();

    // Methods
    void Play();
};


#endif //CONNECTFOUR_CONNECTFOUR_HPP
