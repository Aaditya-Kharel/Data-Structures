#ifndef HEADER_H
#define HEADER_H

#include <string>
#include<iostream>

namespace aaditya_kharel_hw3 {
	class chores {

	public:
		//Pre condition: None
		//Post condition: Allocates dynamic array and initializes the array capacity
		chores();

		//Pre-condition: Dynamic array has been allocated in the memory
		//Post-condition: Dynamic array has been deleted to avoid memory leak
		~chores();

		//Pre-condition: None
		//Post-condition: Displays menu options and performs respective task
		void menuItem();

		//Pre-condition: Dynamic array has been created
		//Post-condition: Desired chores string has been added
		void additem();

		//Pre-condition: Existing chores list is displayed to user
		//Post-condition: Desired chores string is deleted from chores list using (user_input-1)
		void deleteitem();

		//Pre-condition: None
		//Post-condition: Current List of chores is printed on the screen
		void printChores();

		//Pre-condition: None
		//Post-condition: Returns number of chores in the list
		int numberOfChores();

	private:
		std::string* choresPtr;
		int used;
		int capacity;
	};
}
#endif

