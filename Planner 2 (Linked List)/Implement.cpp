#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <memory>

using namespace std;


chores::chores() {

	ifstream inFile;				//input file stream object declaration
	string str;
	inFile.open("chores.txt");		//object calls open function


	used = 0;						//keeps track of occupied array element 
	capacity = 1000;			        //assigns initial dynamic array capacity

	if (used + 1 < capacity) {
		ptr1 = std::unique_ptr<string[]>(new string[capacity]);			//Dynamic array created using unique_ptr
	}
	else if (used + 1 > capacity) {
		ptr1 = std::unique_ptr<string[]>(new string[capacity*2]);
	}


	while (getline(inFile, str)) {	//takes input from file,  
		ptr1[used] = str;		    //stores in str &
		used = used + 1;			//assigns each file line to each array element
	}
	inFile.close();					//file is closed once data is read into array
}
	
//chores::~chores() {

	//delete [] choresPtr;

//}

void chores::menuItem() {

	cout << endl;
	cout << "=================================================" << endl;
	cout << "Welcome to the list of chores program: " << endl;
	cout << "=================================================" << endl;
	cout << "(Please SAVE and EXIT (OPTION 5) to WRITE CHANGES TO FILE)" << endl;
	cout << "=================================================" << endl;
	cout << "Enter 1 to ADD an item to the list" << endl;
	cout << "Enter 2 to DELETE an item from the list" << endl;
	cout << "Enter 3 to DISPLAY CHORES" << endl;
	cout << "Enter 4 to TOTAL CHORES ITEMS" << endl;
	cout << "Enter 5 to SAVE (write changes to file) and EXIT" << endl;

	int user_input;
	cin >> user_input;

	if (user_input == 1) {
		additem(); 	
	}

	else if (user_input == 2) {
		deleteitem();
		//Delete an item and replace the position with last item in the array
	}

	else if (user_input == 3) {
		printChores();
		//print current list of chores
	}

	else if (user_input == 4) {
		cout<<"Your TOTAL ITEMS in the CHORES is: "<<numberOfChores()<<endl<<endl;
		//print number of items in the list of chores
	}

	else if (user_input == 5) {
		//Exit Code + File Closing
		ofstream outFile("chores2.txt");

		for (int i = 0; i < used;i++) {
			outFile << ptr1[i]<<endl;
		}

		outFile.close();
		std::remove("chores.txt");
		std::rename("chores2.txt", "chores.txt");
		cout << "All changes SUCCESSFULLY written to the File and PROGRAM HAS EXITED"<<endl;
	}

	else {
		cout << "Invalid Entry! Enter again "<<endl;
		menuItem();
	}
	
}

void chores::additem(){

	cout << "Enter an ITEM to ADD to your TO-DO list"<<endl;
	std::string entry;
	cin.ignore();
	getline(cin, entry);
	cout << "||||||||||||||||||||||" << endl;
	cout << "ABOVE ENTRY SUCCEEDED" << endl;
	cout << "||||||||||||||||||||||" << endl;
	ptr1[used] = entry;
	used = used + 1;

	menuItem();

}

void chores::deleteitem() {
	cout << "Enter the list number to delete an item" << endl;
	int delete_position;
	cin >> delete_position;
	ptr1[delete_position - 1] = ptr1[used - 1];
	used = used - 1;
	cout << "Item Deleted successfully" << endl;
	menuItem();
}

void chores::printChores() {
	cout << "----------------------------------" << endl;
	cout << "Following are the chores list:" << endl;
	cout << "----------------------------------" << endl;
	for (int i=0; i < used; i++) {
		cout << i+1 << " "<<ptr1[i] << endl;
	}
	menuItem();
}

int chores::numberOfChores() {
	cout <<"The total number of chores in the list is: "<< used;
	menuItem();
	return used;
}

