#include <iostream>
#include<cstdlib>
#include<ctime>
#include "Header.h"

using namespace std;
using namespace aaditya_kharel_hw2;

char bag[9] = { '1','2','3','4','5','6','7','8','9' };

tictactoe::tictactoe() {

}

tictactoe::tictactoe(char a, char b)
{
	playerX = a;
	playerO = b;
}

void tictactoe::dispBoard() {
	cout << "+ + + + + + + + + + + + + + + + + + + " << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;
	cout << "+" << "     " << bag[0] << "     " << "+" << "     " << bag[1] << "     " << "+" << "     " << bag[2] << "     " << "+" << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;

	cout << "+ + + + + + + + + + + + + + + + + + + " << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;
	cout << "+" << "     " << bag[3] << "     " << "+" << "     " << bag[4] << "     " << "+" << "     " << bag[5] << "     " << "+" << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;

	cout << "+ + + + + + + + + + + + + + + + + + + " << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;
	cout << "+" << "     " << bag[6] << "     " << "+" << "     " << bag[7] << "     " << "+" << "     " << bag[8] << "     " << "+" << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;
	cout << "+" << "           " << "+" << "           " << "+" << "           " << "+" << endl;

	cout << "+ + + + + + + + + + + + + + + + + + + " << endl << endl;
}

void tictactoe::userMove(int boxNum) {
	if (bag[boxNum - 1] == 'O') {
		cout << "Place is occupied. Enter vacant spot." << endl;
		int a;
		cin >> a;
		userMove(a);
	}
	else if (bag[boxNum - 1] == 'X') {
		cout << "Place is occupied. Enter vacant spot." << endl;
		int a;
		cin >> a;
		userMove(a);
	}
	else {
		bag[boxNum - 1] = 'X';
	}
}

void tictactoe::computerMove() {
	int a;
	a = rand() % 9;

	if (bag[a] != 'X' && bag[a] != 'O') {
		bag[a] = 'O';

	}
	else if (bag[a] == 'X' || bag[a] == 'O') {
		computerMove();
	}
	else cout << "Unexpected error" << endl;
}

void tictactoe::computerMove1() {
	int b;
	b = rand() % 9;

	if (bag[b] != 'X' && bag[b] != 'O') {
		bag[b] = 'X';

	}
	else if (bag[b] == 'X' || bag[b] == 'O') {
		computerMove1();

	}
	else cout << "Unexpected error" << endl;
}

bool tictactoe::gameconclusion() {
	//Checks X win
	if (bag[0] == 'X'&& bag[4] == 'X' && bag[8] == 'X') {
		cout << "X wins the game" << endl << endl;
		return true;
	}
	else if (bag[2] == 'X' && bag[4] == 'X' && bag[6] == 'X') {
		cout << "X wins the game" << endl << endl;
		return true;
	}
	else if (bag[0] == 'X' && bag[1] == 'X' && bag[2] == 'X') {
		cout << "X wins the game" << endl << endl;
		return true;
	}
	else if (bag[3] == 'X' && bag[4] == 'X' && bag[5] == 'X') {
		cout << "X wins the game" << endl << endl;
		return true;
	}
	else if (bag[6] == 'X' && bag[7] == 'X' && bag[8] == 'X') {
		cout << "X wins the game" << endl << endl;
		return true;
	}
	else if (bag[0] == 'X' && bag[3] == 'X' && bag[6] == 'X') {
		cout << "X wins the game" << endl << endl;
		return true;
	}
	else if (bag[1] == 'X' && bag[4] == 'X' && bag[7] == 'X') {
		cout << "X wins the game" << endl << endl;
		return true;
	}
	else if (bag[2] == 'X' && bag[5] == 'X' && bag[8] == 'X') {
		cout << "X wins the game" << endl << endl;
		return true;
	}

	//Checks Y win
	else if (bag[0] == 'O'&& bag[4] == 'O' && bag[8] == 'O') {
		cout << "O wins the game" << endl << endl;
		return true;
	}
	else if (bag[2] == 'O' && bag[4] == 'O' && bag[6] == 'O') {
		cout << "O wins the game" << endl << endl;
		return true;
	}
	else if (bag[0] == 'O' && bag[1] == 'O' && bag[2] == 'O') {
		cout << "O wins the game" << endl << endl;
		return true;
	}
	else if (bag[3] == 'O' && bag[4] == 'O' && bag[5] == 'O') {
		cout << "O wins the game" << endl << endl;
		return true;
	}
	else if (bag[6] == 'O' && bag[7] == 'O' && bag[8] == 'O') {
		cout << "O wins the game" << endl << endl;
		return true;
	}
	else if (bag[0] == 'O' && bag[3] == 'O' && bag[6] == 'O') {
		cout << "O wins the game" << endl << endl;
		return true;
	}
	else if (bag[1] == 'O' && bag[4] == 'O' && bag[7] == 'O') {
		cout << "O wins the game" << endl << endl;
		return true;
	}
	else if (bag[2] == 'O' && bag[5] == 'O' && bag[8] == 'O') {
		cout << "O wins the game" << endl << endl;
		return true;
	}

	//Checks for Draw
	else if ((bag[0] == 'X' || bag[0] == 'O') && (bag[1] == 'X' || bag[1] == 'O') && (bag[2] == 'X' || bag[2] == 'O')
		&& (bag[3] == 'X' || bag[3] == 'O') && (bag[4] == 'X' || bag[4] == 'O') && (bag[5] == 'X' || bag[5] == 'O')
		&& (bag[6] == 'X' || bag[6] == 'O') && (bag[7] == 'X' || bag[7] == 'O') && (bag[8] == 'X' || bag[8] == 'O'))
	{
		cout << "The game is a draw." << endl << endl;
		return true;
	}

	else {
		return false;
	}
}

void tictactoe::gamePlay() {

	cout << "===========================" << endl;
	cout << "Welcome to TicTacToe Game" << endl;
	cout << "===========================" << endl;
	cout << "Please choose from the menu item below:" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Enter 1 to play the game against the computer" << endl;
	cout << "Enter 2 to play the game against two player" << endl;
	cout << "Enter 3 to EXIT" << endl;

	int menu_input;
	cin >> menu_input;

	if (menu_input == 1) {
		tictactoe user1;

		cout << "Game started. Your symbol is 'X'. Computer is 'O'" << endl;
		user1.dispBoard();

		//User move input
		cout << "Your turn. Enter the box number to make move." << endl << endl;
		int b;

		while (user1.gameconclusion() == false) {
			
			cin >> b;
			user1.userMove(b);
			bool check = user1.gameconclusion();

			if (check == false) {
				user1.computerMove();
				user1.dispBoard();	
				cout << "Your turn. Enter the box number to make move." << endl;
			}
	
			else {
				user1.dispBoard();
				break;
			}
		}
	}
	//ComputervsComputer
	else if (menu_input == 2) {

		cout << "The game has started" << endl;

		tictactoe computer1;

		computer1.dispBoard();


		while (computer1.gameconclusion() == false) {
			computer1.computerMove();
			computer1.dispBoard();

			bool check = computer1.gameconclusion();
			
			if (check == false) {
				computer1.computerMove1();
				computer1.dispBoard();
			}
			else {
				//computer1.dispBoard();
				break;
			}
		}
	}
	//Exit game
	else if (menu_input == 3) {
		exit(0);
	}
	//Invalid Entry
	else {
		cout << "Invalid Entry. Enter valid number." << endl;
		gamePlay();
	}

}

