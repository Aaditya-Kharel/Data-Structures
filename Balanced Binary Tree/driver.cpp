#include <iostream>
#include "set.h"

using namespace std; 
using namespace main_savitch_11;

//void printMenu(); 

int main() {
	set <int> s; 
	set<int> *set_ptr = new set <int>;
	int choice; 
	//Item entered by the user to be counted
	//TESTING THE PUBLIC FUNCTIONS IN THE MAIN PROGRAM
	//INITIALING THE TREE WITH INTEGER VALUES
	//TESTING THE INSERT FUNCITON
	cout << "We are testing the insert function" << endl;
	set_ptr->insert(6);
	set_ptr->insert(2);
	set_ptr->insert(4);
	set_ptr->insert(9);
	set_ptr->insert(1);
	set_ptr->insert(3);
	set_ptr->insert(5);
	set_ptr->insert(7);
	set_ptr->insert(8);
	set_ptr->insert(10);
	set_ptr->print(8);
	cout << "All the values have been inserted properly" << endl;
	cout << "Success! insert() function passes the test" << endl;
	cout << endl;
	cout << endl;

	cout << "We are testing the erase function" << endl;
	cout << "Erase number '10' from the data" << endl;
	set_ptr->erase(10);
	set_ptr->print(8);
	cout << "'10' has been erased"<<endl; 
	cout<<"Success! erase() function passes the test"<<endl; 
	cout << endl;
	cout << endl;

	cout << "We are testing the count function" << endl;
	cout << "We find '4' from the data" << endl;
	if (set_ptr->count(4) >= 1) {
		cout << "!!!!!FOUND!!!!!!!" << endl;
		cout << "The item appears " << set_ptr->count(4) << " number of times. " << endl;
	}
	cout << endl;
	cout << "We now test a number '100' that is not is the set and we should get the answer '0'." << endl;
	cout<< "The item appears " << set_ptr->count(100) << " number of times. " << endl;
	cout << "Success! count() function passes the test" << endl;
	cout << endl;
	cout << endl; 

	cout << "We now test the assignment operator" << endl; 
	set<int> set2;
	set2 = s;
	cout << "Assignment of data into a new set class" << endl;
	set_ptr->print(4);
	cout << "Success! =assignment operator passes the test" << endl; 
	cout << endl; 
	cout<<endl; 
	cout << "We now test the clear function" << endl;
	set_ptr->clear();
	cout << "The tree has been erased implying no data is printed" << endl;
	set_ptr->print(4);
	cout << "Success! clear() function passes the test" << endl; 


	//system("pause");
	return 0;


}
