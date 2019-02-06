#include "Header.h"
#include<cstdlib>
#include<ctime>

using namespace std;
using namespace aaditya_kharel_hw2;

int main() {
	srand(time(NULL));

	tictactoe('X', 'O');      // Parameterized constructor to specify game symbol
	tictactoe start;          // Declaring object 


	start.gamePlay();		  //Calls gamePlay() function to display menu items and initiates desired game

	return 0;
}





