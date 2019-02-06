#ifndef HEADER_H
#define HEADER_H

namespace aaditya_kharel_hw2
{
	class tictactoe {

	public:

		//Default constructor
		tictactoe();

		//Parameterized Constructor to specify game symbol to each user.
		tictactoe(char a, char b);

		//Pre-condition: None
		//Post-condition: Displays menu items on the welcome screen
		void gamePlay();

		//Pre-condition: None
		//Post-condition: Game board has been displayed.
		void dispBoard();


		//Pre-condition: None
		//Post-condition: User move has been updated in the game board as input by user.
		void userMove(int boxNum);

		//Pre-condition: User has made a move.
		//Post-condition: Computer has made a move and game board has been updated.
		void computerMove();

		//Pre-condition: computerMove() has made its move.
		//Post-condition: computerMove1() has made its move and game board has been updated.
		void computerMove1();

		//Pre-condition: None
		//Post-condition: Returns true if either Player 'X' or Player 'O' wins the game, else returns false
		bool gameconclusion();

	private:
		char playerX;
		char playerO;
	};
}
#endif