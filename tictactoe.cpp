#include <iostream>
using namespace std;

char field [9] = {'#','#','#','#','#','#','#','#','#'};
int isPlayer1 = true;

int changePlayer()
{
	if(isPlayer1)
	{
		isPlayer1 = false;
	}
	else
	{
		isPlayer1 = true;
	}
	return 0;
}
int drawField()
{
	unsigned char cornerLeftUp = 218; 
	for(int i = 0; i < 3; i++)
	{
		cout << "-------\n";
		cout << "|" <<field[i*3] << "|" << field[i*3+1] << "|" << field[i*3+2] << "|\n"; 
	}
	cout << "-------\n";
	return 0;
}
int playLocalMultiplayer()
{
	char player1;
	char player2;
	cout << "Player One choose your character:\n";
	cin>>player1;
	cout << "Player Two choose your character:\n";
	cin>>player2;
	while(player1 == player2)
	{
		cout << "Player Two: Please choose another symbol:\n";
		cin>>player2;
	}
	int pos = -1;
	for(int i = 0; i < 9; i++)
	{
		drawField();
		if(isPlayer1)
		{
			cout << "Player1 please choose your field:\n";
		}
		else
		{
			cout << "Player2 please choose your field:" << endl;
		}
		cin>>pos;
		while(pos < 1 || pos > 9 || field[pos-1] != '#')
		{
			cout << "Invalid input. Please type another number\n";
			cin>>pos;
		}
		if(isPlayer1)
		{
			field[pos-1] = player1;
		}
		else
		{
			field[pos-1] = player2;
		}
		changePlayer();
	}
	return 0;
}
int main()
{
	cout << "Welcome to TicTacToe by Alexander Joham!\n";
	playLocalMultiplayer();
	return 0;
}
