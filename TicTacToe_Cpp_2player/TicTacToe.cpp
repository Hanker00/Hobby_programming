//
//  Tic Tac Toe 2-player
//
//  Created by Timothy Nilsson
//  Copyright © 2018 Timothy Nilsson. All rights reserved.
//
#include <iostream>
using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char winner = 'p';
int turn = 0;
void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl
         << endl;
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl
         << endl;
}

void CheckWin()
{
    if (square[1] == square[2] && square[2] == square[3])
    {
        winner = square[1];
    }
    else if (square[4] == square[5] && square[5] == square[6])
    {
        winner = square[4];
    }
    else if (square[7] == square[8] && square[8] == square[9])
    {
        winner = square[7];
    }
    else if (square[1] == square[4] && square[4] == square[7])
    {
        winner = square[1];
    }
    else if (square[2] == square[5] && square[5] == square[8])
    {
        winner = square[2];
    }
    else if (square[3] == square[6] && square[6] == square[9])
    {
        winner = square[3];
    }
    else if (square[1] == square[5] && square[5] == square[9])
    {
        winner = square[1];
    }
    else if (square[3] == square[5] && square[5] == square[7])
    {
        winner = square[3];
    }
}


int main()
{
    int turns = 0;
    while (winner == 'p' || turns < 9)
    {
        board();
        if (winner != 'p')
        {
            break;
        }
        cout << "Player1 Please enter a number from 1 - 9: \n";
        int p1 = 0;
        cin >> p1;
        while (!((p1 <= 9) && (p1 >= 1)) || square[p1] == 'X' || square[p1] == 'O')
        {
            cout << "That spot is already taken or you did not enter a number from 1 - 9 Please put a valid number from 1-9. \n";
            cin >> p1;
        }
        square[p1] = 'X';
        CheckWin();
        turns += 1;
        if (turns >= 9)
        {
            break;
        }
        board();
        cout << "Player2 Please enter a number from 1 - 9: \n";
        int p2 = 0;
        cin >> p2;
        while (!((p2 <= 9) && (p2 >= 1)) || square[p2] == 'X' || square[p2] == 'O')
        {
            cout << "That spot is already taken or you did not enter a number from 1 - 9 Please put a valid number from 1-9. \n";
            cin >> p2;
        }
        square[p2] = 'O';
        CheckWin();
        turns += 1;
        if (turns >= 9 && winner == 'p')
        {
            break;
        }
        cout << winner;
    }
    if (winner == 'X')
    {
        cout << "\nPlayer 1 wins! \n";
    }
    else if (winner == 'O')
    {
        cout << "\nPlayer 2 wins! \n";
    }
    else
    {
        cout << "\nThe board is full! It is a tie! \n";
    }
}