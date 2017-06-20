/********************************************************************* 
** Author: Shawn Berg
** Date: 5/27/17
** Description: This class creates and manages a game board
*********************************************************************/

#include <iostream>
#include "Board.hpp"

using namespace std;

Board::Board()
{
    // Initialize empty board
    for (int i=0; i<7; i++)
    {
        for(int j=0; j<6; j++)
            board[i][j] = '.';
    }
}

Board::~Board()
{}

bool Board::makeMove(int Column, char PlayerTurn)
{

    bool space_empty = false;
    int j = 5;

    while (j>=0 && space_empty == false)
    {
        if (board[Column][j] != '.') // check column from bottom up for free space
            j--;

        else if (j == -1) // if column is full
            return false;

        else space_empty = true;
    }
    if (space_empty == true) // if space is empty
    {
        board[Column][j] = tolower(PlayerTurn); // place piece
        return true;
    }
}

Result Board::gameState(int WinCond)
{
    int count = 0;

    for (int i=0; i<7; i++)
    {
        for(int j=0; j<6; j++)
        {
            if (board[i][j] == 'x')
            {
                count = 1;

                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i][j + k] == 'x') // Check vertical down
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return X_WON;
                }

                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i][j - k] == 'x') // Check vertical up
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return X_WON;
                }


                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i + k][j] == 'x') // Check horizontal right
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return X_WON;
                }

                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i - k][j] == 'x') // Check horizontal left
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return X_WON;
                }

                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i + k][j + k] == 'x') // Check diagonal down
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return X_WON;
                }

                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i - k][j - k] == 'x') // Check diagonal up
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return X_WON;
                }
            }

            if (board[i][j] == 'o')
            {
                count = 1;

                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i][j + k] == 'o') // Check vertical up
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return O_WON;
                }

                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i][j - k] == 'o') // Check vertical down
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return O_WON;
                }


                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i + k][j] == 'o') // Check horizontal up
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return O_WON;
                }

                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i - k][j] == 'o') // Check horizontal down
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return O_WON;
                }

                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i + k][j + k] == 'o') // Check diagonal up
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return O_WON;
                }

                for (int k = 1; k < WinCond; k++)
                {
                    if (board[i - k][j - k] == 'x') // Check diagonal down
                        count++;

                    else count = 1;

                    if (count == WinCond)
                        return X_WON;
                }
            }
        }
    }
    // Draw Condition
    int occupiedCount = 0;

    for (int i=0; i<7; i++)
     {
         for (int j=0; j<6; j++)
         {
             if (board[i][j] != '.')
                 occupiedCount++;
         }
     }

    if (occupiedCount == 42)
        return DRAW;

    // Unfinished
    else return UNFINISHED;
}

void Board::print() // Prints board to screen
{
    //TODO clear screen
    //TODO animate player move

    cout << " 0 1 2 3 4 5 6" << endl;

    for (int i=0; i<6; i++)
    {
        cout << " ";
        for (int j=0; j<7; j++)
        {
            cout << board[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
