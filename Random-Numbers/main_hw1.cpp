#include<iostream>
#include<cmath>
#include "header_hw1.h"
using namespace std;
using namespace aaditya_kharel_hw1;

int main() {	
	//Creates an object and invokes the parameterized constructor
	randomNumber a(1, 40, 725, 729);

	//Tests Problem 11
	a.test11();

	//Changes seed value
	a.changeseed(5);
	cout << "Random Number when seed is changed to 5: " << a.generateNum()<<endl;
	a.changeseed(7);
	cout << "Random Number when seed is changed to 7: " << a.generateNum() << endl;
	a.changeseed(1);
	cout << "Random Number when seed is changed to 1: " << a.generateNum() << endl << endl;

	//Tests Problem 12
	a.test12();

	//Tests Problem 13
	a.test13();

	//Tests Problem 14
	a.test14();

	return 0;
}
 
