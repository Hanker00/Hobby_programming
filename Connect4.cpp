
#include <iostream>
using namespace std;

int rows = 6, columns = 7, i, col;
char board[10][10];
int over = 0;
//This is made to keep count of all the turns after each player moves if the count is 42 the board will be full and the game will end.
int turns = 0;

/* Both draws and displays the board */
void DisplayBoard ( char board[][10] )
{
	system ("clear");
	int rows = 6, columns = 7, row, col;
	cout << "Connect 4 game\n\n";
	cout << "  1 2 3 4 5 6 7\n";
	for(row = 1; row <= rows; row++)
	{
		cout << "|";
		for(col = 1; col <= columns; col++)
		{
			if(board[row][col] != 'X' && board[row][col] != 'O')
				board[row][col] = '*';
				cout << " ";

			cout << board[row][col];
			
		}

		cout << "|" << endl;
	}

}

/* This function loops through every column and row to find potential places where either player could
reach the end goal four in a row. This function is run after every player makes a turn. 
If the function finds a place where 4 spots in a row is occupied by either X or O it will give the 
over variable the value of the player who reached 4 in a row. */
void checkWin() 
{
	for(int l = 1; l <= 7; l++) 
	{
		/* win condition: X
   		 		          X
	 	   				  X
				          X
		*/
					
		for(int k = 1; k <= 3; k++) 
		{
			if(board[k][l] == 'X' &&
			board[k + 1][l] == 'X' && 
			board[k + 2][l] == 'X' &&
			board[k + 3][l] == 'X' ) 
			{
				over = 1;
				break;
			}
		}
		/* win condition: X X X X
		*/
		for(int k = 1; k <= 3; k++)
		{
			if(board[l][k] == 'X' &&
			board[l][k + 1] == 'X' &&
			board[l][k + 2] == 'X' &&
			board[l][k + 3] == 'X')
			{
				over = 1;
				break;
			}
			
		}
		/* win condition: X
							X
							  X
							    X
		*/
		for(int l = 1; l <= 3; l++)
		{
			for(int k = 6; k >= 0; k--) 
			{
				if(board[k][l] == 'X' &&
				board[k - 1][l + 1] == 'X' && 
				board[k - 2][l + 2] == 'X' &&
				board[k - 3][l + 3] == 'X' ) 
				{
					over = 1;
					break;
				}
			}
		}

		for(int k = 1; k <= 3; k++) 
		{
		if(board[k][l] == 'O' &&
		board[k + 1][l] == 'O' && 
		board[k + 2][l] == 'O' &&
		board[k + 3][l] == 'O' ) {
			over = 2;
			break;
			}
		}
		for(int k = 1; k <= 7; k++)
		{
			if(board[k][l] == 'O' &&
			board[k][l + 1] == 'O' &&
			board[k][l + 2] == 'O' &&
			board[k][l + 3] == 'O')
			{
				over = 2;
				break;
			}
		}
		for(int k = 1; k <= 3; k++) 
		{
			if(board[k][l] == 'O' &&
			board[k + 1][l + 1] == 'O' && 
			board[k + 2][l + 2] == 'O' &&
			board[k + 3][l + 3] == 'O' ) {
				over = 2;
				break;
			}
		}
	}
}





/* This function is the main function and this is the one that executes when you run the program.
It makes use of all previous function in order to build the program. */
int main() 
{
	/* This is the loop that determines wheter the game is over or not. If the variable "over"> is less or 
	equal to 0 the game is still going and the loop will continue to run */
	while(over <= 0) 
	{
		DisplayBoard(board);
		cout << "player1 pick a number from 1 - 7\n";
		int p1 = 0;
		int p2 = 0;
		int valid = 0;
		cin >> p1;
		// Make sures that input the user gives is a number from 1 - 7
		while(valid == 0) 
		{
			if(p1 == 1 || p1 == 2 || p1 == 3 || p1 == 4 || p1 == 5 || p1 == 6 || p1 == 7) 
			{
				valid = 1;
			}
			else {
				cout << "that is not a number from 1-7, please try again:\n";
				cin >> p1;
			}
		}
		turns += 1;
		for(int j = 6; j >= 0; j-- ) {
			cout << board[j][p1];
			if(board[j][p1] == 'X' || board[j][p1]== 'O') {
			}
			else {
				board[j][p1] = 'X';
				j = 0;
			}
		}
		
		checkWin();
		DisplayBoard(board);
		if(over != 0)
		{
			break;
		}
		cout << "player2 pick a number from 1 - 7\n";
		cin >> p2;
		if(p2 == 1 || p2== 2 || p2 == 3 || p2 == 4 || p2 == 5 || p2 == 6 || p2 == 7) 
			{
				valid = 1;
			}
			else {
				cout << "that is not a number from 1-7, please try again:\n";
				cin >> p2;
			}
		turns += 1;
		for(int j = 6; j >= 0; j-- ) 
		{
			if(board[j][p2] == 'X' || board[j][p2]== 'O') {
			}
			else 
			{
				board[j][p2] = 'O';
				j = 0;
			}
		}
		if(turns >= 42) {
			over = 3;
		}
		checkWin();
		DisplayBoard(board);
		checkWin();
		}
		if(over == 1)
		{
			cout << "\nPlayer1 wins!\n\n";
		}
		else if(over == 3) 
		{
			cout << "\nBoard is full, It is a tie!\n\n";
		}
		else 
		{
			cout << "\nPlayer 2 wins!\n\n";
		}
}