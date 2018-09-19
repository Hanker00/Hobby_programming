#include <iostream>
using namespace std;

int rows = 6, columns = 7, i, ix;
char board[10][10];
int over = 0;

void choice() {
	cout << "player1 pick a number between 1 - 7\n";
	int p1 = 0;
	int p2 = 0;
	cin >> p1;
	for(int j = 1; j <= columns; j++ ) {
		cout << board[j][p1];
		if(board[j][p1] == 'X' || board[j][p1]== 'O') {
		}
		else {
			board[j][p1] = 'X';
			j = 10;
		}
	}
	cout << "player2 pick a number between 1 - 7\n";
	cin >> p2;
	for(int j = 1; j <= columns; j++ ) {
		if(board[j][p2] == 'X' || board[j][p2]== 'O') {
		}
		else {
			board[j][p2] = 'O';
			j = 10;
		}
	}
}

void DisplayBoard ( char board[][10] )
{
	system ("clear");
	int rows = 6, columns = 7, i, ix;
	cout << "Connect 4 game\n\n";
	for(i = 1; i <= rows; i++)
	{
		cout << "|";
		for(ix = 1; ix <= columns; ix++)
		{
			if(board[i][ix] != 'X' && board[i][ix] != 'O')
				board[i][ix] = '*';

			cout << board[i][ix];
			
		}

		cout << "|" << endl;
	}

}

void checkwin() 
{
	for(int l = 1; l <= 7; l++) 
	{
		for(int k = 1; k <= 3; k++) 
		{
			if(board[k][l] == 'X' &&
			board[k + 1][l] == 'X' && 
			board[k + 2][l] == 'X' &&
			board[k + 3][l] == 'X' ) {
				over = 1;
			}
		}
		for(int k = 1; k <= 3; k++) 
		{
			if(board[k][l] == 'X' &&
			board[k + 1][l + 1] == 'X' && 
			board[k + 2][l + 2] == 'X' &&
			board[k + 3][l + 3] == 'X' ) {
				over = 1;
			}
		}
		for(int k = 1; k <= 3; k++) 
		{
		if(board[k][l] == 'O' &&
		board[k + 1][l] == 'O' && 
		board[k + 2][l] == 'O' &&
		board[k + 3][l] == 'O' ) {
			over = 2;
			}
		}
		for(int k = 1; k <= 3; k++) 
		{
			if(board[k][l] == 'O' &&
			board[k + 1][l + 1] == 'O' && 
			board[k + 2][l + 2] == 'O' &&
			board[k + 3][l + 3] == 'O' ) {
				over = 2;
			}
		}
	}
}

int main() 
{
	while(over <= 0) 
	{
	DisplayBoard(board);
	choice();
	checkwin();
	DisplayBoard(board);
	checkwin();
	}
	if(over == 1)
	{
		cout << "player1 wins";
	}
	else {
		cout << "player2 wins";
	}
}