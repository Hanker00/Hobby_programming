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

void ai_horwin()
{
    for (int a = 1; a < 8; a++)
    {
        if (square[a] == 'O' && square[a + 1] == 'O')
        {
            if (a == 2)
            {
                square[1] = 'O';
                turn = 1;
                break;
            }
            else if (a == 5)
            {
                square[4] = 'O';
                turn = 1;
                break;
            }
            else if (a == 8)
            {
                square[7] = 'O';
                turn = 1;
                break;
            }
            else if (a != 3 || a != 6)
            {
                square[a + 2] = 'O';
                turn = 1;
                break;
            }
        }
    }

    if (square[1] == 'O' && square[3] == 'O' && square[2] == '2')
    {
        square[2] = 'O';
        turn = 1;
    }
    else if (square[4] == 'O' && square[6] == 'O' && square[5] == '5')
    {
        square[5] = 'O';
        turn = 1;
    }
    else if (square[7] == 'O' && square[9] == 'O' && square[8] == '8')
    {
        square[8] = 'O';
        turn = 1;
    }
    else if (square[1] == 'X' && square[3] == 'X' && square[2] == '2')
    {
        square[2] = 'O';
        turn = 1;
    }
    else if (square[4] == 'X' && square[6] == 'X' && square[5] == '5')
    {
        square[5] = 'O';
        turn = 1;
    }
    else if (square[7] == 'X' && square[9] == 'X' && square[8] == '8')
    {
        square[8] = 'O';
        turn = 1;
    }
}

void ai_horstop()
{
    if (turn == 0)
    {
        for (int a = 1; a < 8; a++)
        {
            if (square[a] == 'X' && square[a + 1] == 'X')
            {
                if (a == 2)
                {
                    square[1] = 'O';
                    turn = 1;
                    break;
                }
                else if (a == 5)
                {
                    square[4] = 'O';
                    turn = 1;
                    break;
                }
                else if (a == 8)
                {
                    square[7] = 'O';
                    turn = 1;
                    break;
                }
                if (a != 3 || a != 6)
                {
                    if (square[a + 2] != 'O')
                    {
                        square[a + 2] = 'O';
                        turn = 1;
                    }
                    break;
                }
            }
        }
    }
}

void ai_vertwin()
{
    for (int a = 1; a < 3; a++)
    {
        if (square[a] == 'O' && square[a + 3] == 'O')
        {
            if(square[a + 6] == a + 6)
            {
                square[a + 6] = 'O';
                turn = 1;
                break;
            }
        }
    }
     if(square[1] == 'O' && square[7] == 'O' && square[4] == '4') 
    {
        square[4] = 'O';
        turn = 1;
    }
    else if(square[2] == 'O' && square[8] == 'O' && square[5] == '5') 
    {
        square[5] = 'O';
        turn = 1;
    }
    else if(square[3] == 'O' && square[9] == 'O' && square[6] == '6') 
    {
        square[6] = 'O';
        turn = 1;
    }
    else if(square[4] == 'O' && square[7] == 'O' && square[1] == '1') 
    {
        square[1] = 'O';
        turn = 1;
    }
    else if(square[5] == 'O' && square[8] == 'O' && square[2] == '2') 
    {
        square[2] = 'O';
        turn = 1;
    }
    else if(square[6] == 'O' && square[9] == 'O' && square[3] == '3') 
    {
        square[3] = 'O';
        turn = 1;
    }
}

void ai_vertstop()
{
    for (int a = 1; a < 3; a++)
    {
        if (square[a] == 'X' && square[a + 3] == 'X')
        {

            {
                square[a + 6] = 'O';
                turn = 1;
                break;
            }
        }
    }
    if(square[1] == 'X' && square[7] == 'X' && square[4] == '4') 
    {
        square[4] = 'O';
        turn = 1;
    }
    else if(square[2] == 'X' && square[8] == 'X' && square[5] == '5') 
    {
        square[5] = 'O';
        turn = 1;
    }
    else if(square[3] == 'X' && square[9] == 'X' && square[6] == '6') 
    {
        square[6] = 'O';
        turn = 1;
    }
    else if(square[4] == 'X' && square[7] == 'X' && square[1] == '1') 
    {
        square[1] = 'O';
        turn = 1;
    }
    else if(square[5] == 'X' && square[8] == 'X' && square[2] == '2') 
    {
        square[2] = 'O';
        turn = 1;
    }
    else if(square[6] == 'X' && square[9] == 'X' && square[3] == '3') 
    {
        square[3] = 'O';
        turn = 1;
    }

}
void ai_diagwin()
{
    if (square[1] == 'O' && square[5] == 'O' && square[9] == '9')
    {
        square[9] = 'O';
        turn = 1;
    }
    else if (square[1] == 'O' && square[9] == 'O' && square[5] == '5')
    {
        square[5] = 'O';
        turn = 1;
    }
    else if (square[3] == 'O' && square[7] == 'O' && square[5] == '5')
    {
        square[5] = 'O';
        turn = 1;
    }
    else if (square[3] == 'O' && square[5] == 'O' && square[7] == '7')
    {
        square[7] = 'O';
        turn = 1;
    }
    else if (square[5] == 'O' && square[7] == 'O' && square[3] == '3')
    {
        square[3] = 'O';
        turn = 1;
    }
    else if (square[5] == 'O' && square[9] == 'O' && square[1] == '1')
    {
        square[1] = 'O';
        turn = 1;
    }
}

void ai_diagstop()
{
    if (square[1] == 'X' && square[5] == 'X' && square[9] == '9')
    {
        square[9] = 'O';
        turn = 1;
    }
    else if (square[1] == 'X' && square[9] == 'X' && square[5] == '5')
    {
        square[5] = 'O';
        turn = 1;
    }
    else if (square[3] == 'X' && square[7] == 'X' && square[5] == '5')
    {
        square[5] = 'O';
        turn = 1;
    }
    else if (square[3] == 'X' && square[5] == 'X' && square[7] == '7')
    {
        square[7] = 'O';
        turn = 1;
    }
    else if (square[5] == 'X' && square[7] == 'X' && square[3] == '3')
    {
        square[3] = 'O';
        turn = 1;
    }
    else if (square[5] == 'X' && square[9] == 'X' && square[1] == '1')
    {
        square[1] = 'O';
        turn = 1;
    }
}

void ai()
{
    turn = 0;
    ai_horwin();
    ai_vertwin();
    ai_diagwin();
    ai_horstop();
    ai_vertstop();
    ai_diagstop();
    //if everything else is false run this.
    if (turn == 0)
    {
        if (square[5] == '5')
        {
            square[5] = 'O';
        }
        else if (square[3] == '3')
        {
            square[3] = 'O';
        }
        else if (square[1] == '1')
        {
            square[1] = 'O';
        }
        else if (square[7] == '7')
        {
            square[7] = 'O';
        }
        else if (square[9] == '9')
        {
            square[9] = 'O';
        }
        else if (square[6] == '6')
        {
            square[6] = 'O';
        }
        else if (square[2] == '2')
        {
            square[2] = 'O';
        }
        else if (square[4] == '4')
        {
            square[4] = 'O';
        }
        else if (square[8] == '8')
        {
            square[8] = 'O';
        }
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
        turns += 1;
        if (turns >= 9)
        {
            break;
        }
        board();
        CheckWin();
        ai();
        turns += 1;
        CheckWin();
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