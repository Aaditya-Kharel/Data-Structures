#include <iostream>
#include "Header.h"
#include "Header1.h"
#include <iomanip>
#include <cassert>
using namespace std;


int main() {
	cout << "WELCOME TO TOWERS OF HANOI"<<endl;
	cout << "==============================" << endl;
	cout << "Game Objective: You will only win the game if you stack all rings to the second peg" << endl;
	cout << "Game Rule: You CANNOT move a BIGGER RING on top of a SMALLER RING" << endl;
	cout << "====================================================================================" << endl;
	cout << "Enter the RING NUMBER to BEGIN THE GAME... " << endl;
	int ring_number;
	cin >> ring_number;
	
	cout << endl;
	cout << endl;
	towers t;
	peg p1(ring_number), p2(ring_number), p3(ring_number);
	p1.initArray();

	cout <<p1<< p2 << p3;

	while (true) {
		int source, destination; 
		cout << "Choose Peg to move FROM (1, 2 or 3): " << endl; 
		cin >> source; 
		cout << "Choose Peg to move TO (1, 2 or 3): " << endl; 
		cin >> destination; 
		cout << endl; 
		if (source == 1 && destination == 2) {
			t.move(p1, p2);
			cout << p1;
			
			cout << p2;
			
			cout << p3;
			
		}
		else if (source == 2 && destination == 1) {
			t.move(p2, p1);
			cout << p1 << endl;
			cout << p2 << endl;
			cout << p3 << endl;
		}
		else if (source == 2 && destination == 3) {
			t.move(p2, p3);
			cout << p1 << endl;
			cout << p2 << endl;
			cout << p3 << endl;
		}
		else if (source == 3 && destination == 2) {
			t.move(p3, p2);
			cout << p1 << endl;
			cout << p2 << endl;
			cout << p3 << endl;
		}
		else if (source == 1 && destination == 3) {
			t.move(p1, p3);
			cout << p1 << endl;
			cout << p2 << endl;
			cout << p3 << endl;
		}
		else if (source == 3 && destination == 1) {
			t.move(p3, p1);
			cout << p1 << endl;
			cout << p2 << endl;
			cout << p3 << endl;
		}

		if (t.many_rings(p2) == ring_number) {
			cout << "KUDOS!! YOU WON THE GAME" << endl;
			break; 
		}
	}

	p3.delpeg();
	p2.delpeg();
	p1.delpeg();
	return 0;
}

