#include <iostream>
#include <cctype>      
#include <cstdlib>  

#include "table.h" 

using namespace std;

using namespace main_savitch_6B;

struct record
{
	int key;
	double data;
};

record getRecord();
int getKey();


int main() {
	table<record> test;
	char choice;
	bool found;
	record result;

	do {
		
		std::cout << " 1   Print the result" << std::endl;
		std::cout << " 2   Insert a new record " << std::endl;
		std::cout << " 3   Remove a record" << std::endl;
		std::cout << " 4   Check whether a key is present" << std::endl;
		std::cout << " 5   Find the data with the key" << std::endl;
		std::cout << " 6   Quit program" << std::endl;


		std::cout << "Enter choice: " << std::endl;
		std::cin >> choice;

		

		if (choice == '1') {

			std::cout << "Size of the table is: " << test.size() << std::endl;
		}
		else if (choice == '2') {
			test.insert(getRecord());
			std::cout << "Insertion is complete. " << std::endl;
		}
		else if (choice == '3') {
			test.remove(getKey());
			std::cout << "Removed the Item. " << std::endl;
		}
		else if (choice == '4') {
			if (test.is_present(getKey()))
				std::cout << "Key is present." << std::endl;
			else
				std::cout << "Key is not present." << std::endl;
		}
		else if (choice == '5') {
			test.find(getKey(), found, result);
			if (found)
				std::cout << "The data of the Key is: " << result.data << std::endl;
			else
				std::cout << "That key is not present." << std::endl;
		}
		else if (choice == '6') {

			std::cout << "End of the program " << std::endl;
		}
		else {
			std::cout << "Invalid" << std::endl;
		}


	} while (choice != '6');

	
	return 0;

}

record getRecord()

{
	record result;

	std::cout << "Enter a number to store in hash table:  ";
	std::cin >> result.data;
	std::cout << result.data << " has been read." << std::endl;
	result.key = getKey();
	return result;
}

int getKey()
{
	int key;

	do
	{
		std::cout << "Enter the hash key: ";
		std::cin >> key;
	} while (key < 0);
	std::cout << key << " has been read." << std::endl;
	return key;
}
