/********************************************************************* 
** Author: Shawn Berg
** Date: 6/19/17
** Description: This program allows two users to play Connect Four
*********************************************************************/

#include <iostream>
#include "ConnectFour.hpp"

using namespace std;

int main()
{
    // Initialize variable for first player
    char firstPlayer;

    cout << "Welcome to Connect Four!" << endl;

    // Ask the player if X or O should go first
    // TODO change this to coin flip or loser of last round
    // TODO ask for player names

    cout << "Which player should go first? X or O?" << endl;
    cin >> firstPlayer;

    // Begin Connect Four
    ConnectFour newGame(firstPlayer);
    newGame.Play();

    return 0;
}

ConnectFour::ConnectFour() // Default Constructor
{}

ConnectFour::ConnectFour(char newPlayerTurn) // Overload Constructor
{
    PlayerTurn = toupper(newPlayerTurn);
}

ConnectFour::~ConnectFour() // Destructor
{}

void ConnectFour::Play()
{
    int Column = 0; // Declare Column

    int WinCond = 4; // Amount needed in a row to win

    while (board.gameState(WinCond) == UNFINISHED) // While game is ongoing
    {
        board.print(); // Print the board

        // Ask player which column
        cout << "Player " << PlayerTurn
             << ": which column would you like to place your disc?" << endl;
        cin >> Column;

        while (board.makeMove(Column, PlayerTurn) == false) // If column is full
        {
            cout << "That column is full, please choose another." << endl;
            cin >> Column;
        }

        if (PlayerTurn == 'X') // Change player
            PlayerTurn = 'O';
        else
            PlayerTurn = 'X';
    }

    if (board.gameState(WinCond) == X_WON) // If X wins
    {
        board.print();
        cout << "X wins!" << endl;
    }
    else if (board.gameState(WinCond) == O_WON) // If O wins
    {
        board.print();
        cout << "O wins!" << endl;
    }
    else if (board.gameState(WinCond) == DRAW) // If a draw
    {
        board.print();
        cout << "Draw!" << endl;
    }
}