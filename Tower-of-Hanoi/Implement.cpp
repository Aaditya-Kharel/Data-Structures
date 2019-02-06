#include <iostream>
#include "Header.h"
#include<iomanip>
using namespace std;

//CONSTRUCTOR/DESTRUCTOR
peg::peg() {
}
peg::peg(int a) {
	numberOfRings = a;
	ringArray = new int[numberOfRings];	//Creating a dynamic array of size n for n rings
	for (int i = 0; i < numberOfRings; i++) {
		ringArray[i] = 0; //Initialized to zero
	}
}
void peg::delpeg() {
	delete [] ringArray;
}

//Initializes array to default game start position
void peg::initArray() {
		for (int i = 0; i < numberOfRings; i++) {
			ringArray[i] = i + 1;
	}
}

//Overloaded stream insertion operator
ostream& operator<<(ostream& outs, const peg& source) {
		for (int i = 0; i < source.numberOfRings; i++) {
			outs << source.ringArray[i] << endl;
			//cout << "|" << endl;

		}
		cout << endl;
		return outs;
	}

//CONSTANT MEMBER CONSTANTS
int peg::getTotalRingNumber() const {
		int increment = 0;
		while (true) {
	
			if (*ringArray != 0) {
				return numberOfRings;
				break;
			}
			//Starts from second last index array, if true returns previous element
			else if (ringArray[numberOfRings -increment-2]==0) {
				//return ringArray[i + numberOfRings - 1];
				return (increment + 1);
				break;
			}
			//Checks for last index of array
			else {
				increment = increment + 1;
			}
			
		}
	}
int peg::getTopRingDiameter() const {
		int i = 0;
		while (true) {
	
			if (ringArray[0] != 0) {
				return ringArray[0];
				break;
			}
			//Starts from second last index array, if true returns previous element
			else if (ringArray[numberOfRings-i - 2]==0) {
				return ringArray[numberOfRings -i-1];
				break;
			}
			//Checks for last index of array
			else {
				i = i + 1;
			}
			
		}
	}

// MODIFICATION MEMBER FUNCTIONS

void peg::removeTopRing() {
		int j = 0;
		while (true) {
			if (ringArray[numberOfRings - 1] == 0) {
				cout << "Nothing to remove" << endl;
				break;
			}
			else if (ringArray[0] != 0) {
				ringArray[0] = 0;
				break;
			}
			else if (ringArray[numberOfRings - j - 2] == 0) {
				ringArray[numberOfRings - j - 1] = 0;
				break; 
			}
		
			
			else {
				j = j + 1;
			}

		}
	}
bool peg::addRingToTop(int ringdia) {
		
		if (ringArray[numberOfRings - 1] == 0) {
			ringArray[numberOfRings - 1] = ringdia;
			return true; 
			//cout << "working"<<endl;

		}
		else if (ringdia < getTopRingDiameter()) {
				int jj = 0;
				while (true){
					if (ringArray[numberOfRings - jj - 1] == 0) {
						ringArray[numberOfRings - jj - 1] = ringdia;
						return true;
						break;
					}
					else {
						jj = jj + 1;
					}
				

			}
		}

		else{
			cout << "!! ILLEGAL MOVE: CANNOT ADD BIGGER RING ON TOP OF SMALLER !!" << endl;
			cout << "==============================================================" << endl;
			cout << "RETRY ANOTHER MOVE" << endl << endl;
			return false; 
		}
	}

	
