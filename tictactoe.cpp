#include <iostream>
using namespace std;

char field [9] = {'#','#','#','#','#','#','#','#','#'};
int isPlayer1 = true;
char player1;
char player2;

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

bool isWinner() {
	char player;
	if(isPlayer1)
	{
		player = player1;
	}
	else
	{
		player = player2;
	}
	//horizontal
	for(int i = 0; i < 7; i += 3)
	{
		if(field[i] == player && field[i+1] == player && field[i+2] == player)
		{
			return true;
		}
	}

	//vertical
	for(int i = 0; i < 3; i++)
	{
		if(field[i] == player && field[i+3] == player && field[i+6] == player)
		{
			return true;
		}
	}

	//diagonal
	if(field[0] == player && field[4] == player && field[8] == player)
	return true;
	if(field[2] == player && field[4] == player && field[6] == player)
	return true;

	return false;
}

int playLocalMultiplayer()
{
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
		if(isWinner())
		{
			int winner;
			if(isPlayer1)
				winner = 1;
			else
				winner = 2;
			cout << "Player" << winner << " is the winner";
			drawField();
			return 0;
		}
		changePlayer();
	}
	return 0;
}


int main()
{
	cout << "\033[32mWelcome to TicTacToe by Alexander Joham!\033[0m\n";
	playLocalMultiplayer();
	return 0;
}
