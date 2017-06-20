/********************************************************************* 
** Author: Shawn Berg
** Date: 5/27/17
** Description: Header file for the Board class
*********************************************************************/

#ifndef TICTACTOE_BOARD_HPP
#define TICTACTOE_BOARD_HPP

enum Result {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
private:
    // Member Variables
    char board[7][6];
    Result GameState;

public:
    // Default Constructor
    Board();

    // Destructor
    ~Board();

    // Methods
    bool makeMove(int, char);

    Result gameState(int);

    void print();

};


#endif //TICTACTOE_BOARD_HPP
