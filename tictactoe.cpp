#include <iostream>
using namespace std;

int playLocalMultiplayer()
{
	char player1;
	char player2;
	cout << "Player One choose your character:\n";
	cin>>player1;
	cout << "Player Two choose your character:\n";
	cin>>player2;
	cout << player1 << player2;
	return 0;
}
int main()
{
	cout << "Welcome to TicTacToe!\n";
	playLocalMultiplayer();
	return 0;
}
