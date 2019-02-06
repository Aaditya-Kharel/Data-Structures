// FILE: set.h (part of the namespace main_savitch_11)
// TEMPLATE CLASS PROVIDED: set<Item>
//   (a container template class for a set of items)
//
// TYPEDEFS for the set<Item> class:
//   set<Item>::value_type
//     set<Item>::value_type is the data type of the items in the set. It may be
//     any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
// CONSTRUCTOR for the set<Item> class:
//   set( )
//     Postcondition: The set is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the set<Item> class:
//   void clear( )
//     Postcondition: The set is empty.
//
//   bool insert(const Item& entry)
//     Postcondition: If an equal entry was already in the set, the set is
//     unchanged and the return value is false. Otherwise, entry was added
//     to the set and the return value is true. This is slightly different than
//     the C++ Standard Library set (see Appendix H).
//
//   size_t erase(const Item& target)
//     Postcondition: If target was in the set, then it has been removed from
//     the set and the return value is 1. Otherwise the set is unchanged and the
//     return value is zero.
//
// CONSTANT MEMBER FUNCTIONS for the Set<Item> class:
//   size_t count(const Item& target) const
//     Postcondition: Returns the number of items equal to the target
//     (either 0 or 1 for a set).
//
//  bool empty( ) const 
//     Postcondition: Returns true if the set is empty; otherwise returns false.
//
// VALUE SEMANTICS for the set<Item> class:
//   Assignments and the copy constructor may be used with set<Item> objects.
//
// DYNAMIC MEMORY USAGE by the set<Item> class:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: 
//   The constructors, insert, and the assignment operator.

#ifndef MAIN_SAVITCH_SET_H
#define MAIN_SAVITCH_SET_H
#include <iostream>
#include <cstdlib>   // Provides size_t
#include <iomanip>

namespace main_savitch_11
{
	template <class Item>
	class set
	{
	public:
		// TYPEDEFS
		typedef Item value_type;
		// CONSTRUCTORS and DESTRUCTOR
		set();
		set(const set& source);
		~set() { clear(); }
		// MODIFICATION MEMBER FUNCTIONS
		void operator =(const set& source);
		void clear();
		bool insert(const Item& entry);
		std::size_t erase(const Item& target);
		// CONSTANT MEMBER FUNCTIONS
		std::size_t count(const Item& target);// const;
		bool empty() const { return (data_count == 0); }
		// SUGGESTED FUNCTION FOR DEBUGGING
		void print(int indent) const;
	private:
		// MEMBER CONSTANTS
		static const std::size_t MINIMUM = 2;
		static const std::size_t MAXIMUM = 2 * MINIMUM;
		// MEMBER VARIABLES
		std::size_t data_count;
		Item data[MAXIMUM + 1];
		std::size_t child_count;
		set *subset[MAXIMUM + 2];
		// HELPER MEMBER FUNCTIONS
		bool is_leaf() const { return (child_count == 0); }
		bool loose_insert(const Item& entry);
		std::size_t get_index(const Item& entry);
		bool loose_erase(const Item& target);
		void remove_biggest(Item& removed_entry);
		void fix_excess(std::size_t i);
		void fix_shortage(std::size_t i);
		set* b_tree_copy(const set* root_ptr);
		void b_tree_clear(set*& root_ptr);
		// NOTE: The implementor may want to have additional helper functions
	};
}
//#include "set.template" // Include the implementation.

namespace main_savitch_11 {

	template <class Item>
	set<Item>::set() {
		data_count = 0;
		child_count = 0;
		for (auto& p : subset) {
			p = nullptr;
		}
	}

	template <class Item>
	set<Item>::set(const set<Item>& source) {
		data_count = source.data_count;
		child_count = source.child_count;
		for (int i = 0; i < data_count; i++) {
			data[i] = source.data[i];
		}
		for (int i = 0; i < child_count; i++) {
			subset[i] = source.subset[i];
		}
		//this = b_tree_copy(&source);
	}


	template <class Item>
	set<Item>* set<Item>::b_tree_copy(const set<Item>* root_ptr) {
		if (root_ptr == nullptr) {
			return nullptr;
		}
		set<Item>* set_ptr = new set<Item>;
		set_ptr->data_count = root_ptr->data_count;
		set_ptr->child_count = root_ptr->child_count;
		for (int i = 0; i < data_count; i++) {
			set_ptr->data[i] = root_ptr->data[i];
		}
		for (int i = 0; i < set_ptr->child_count; i++) {
			set_ptr->subset[i] = b_tree_copy(root_ptr->subset[i]);
		}
		return set_ptr;
	}

	template <class Item>
	void set<Item>::clear() {
		for (auto& v : data) {
			v = Item();
		}
		for (auto& p : subset) {
			b_tree_clear(p);
		}
		data_count = 0;
		child_count = 0;
	}

	template <class Item>
	void set<Item>::b_tree_clear(set<Item>*& root_ptr) {

		if (root_ptr != nullptr) {
			for (auto& v : root_ptr->data) {
				v = Item();
			}
			for (int i = 0; i < root_ptr->child_count; i++) {
				b_tree_clear(root_ptr->subset[i]);
			}
			delete root_ptr;
			root_ptr = nullptr;
		}
	}

	template <class Item>
	void set<Item>::operator=(const set<Item>& source) {
		if (this == &source) {
			return;
		}
		clear();

		data_count = source.data_count;
		child_count = source.child_count;
		for (int i = 0; i < data_count; i++) {
			data[i] = source.data[i];
		}
		for (int i = 0; i < child_count; i++) {
			subset[i] = source.subset[i];
		}
		//this = b_tree_copy(&source);
	}

	template <class Item>
	std::size_t set<Item>::count(const Item& target) {
		std::size_t i = get_index(target);
		if (i < data_count && !(target < data[i])) {
			return 1;
		}
		if (child_count == 0) {
			return 0;
		}
		return subset[i]->count(target);
	}

	template <class Item>
	std::size_t set<Item>::get_index(const Item& entry) {
		for (std::size_t i = 0; i < data_count; i++) {
			if (!(data[i] < entry)) {
				return i;
			}
		}
		return data_count;
	}

	template <class Item>
	bool set<Item>::insert(const Item& entry) {
		if (!loose_insert(entry)) {
			return false;
		}
		if (data_count > MAXIMUM) {
			set<Item>* pset = new set<Item>; // make new object

											 //reset root saving contents in pset
			for (int i(0); i < child_count; i++)// copy ptr's
			{
				pset->subset[i] = subset[i];
				pset->child_count++;
				subset[i] = nullptr;			// set old ptr's to null

			}
			for (int i(0); i < data_count; i++)	// copy data
			{
				pset->data[i] = data[i];
				pset->data_count++;
				data[i] = 0;

			}
			data_count = 0;
			child_count = 1;
			subset[0] = pset;


			fix_excess(0);
		}
		return true;
	}
	template <class Item>
	bool set<Item>::loose_insert(const Item& entry) {
		int i = get_index(entry);
		if (i < data_count && !(entry < data[i])) {
			return false;
		}
		if (child_count == 0) {
			for (int ix = data_count - 1; ix >= i; ix--) {
				data[ix + 1] = data[ix];
			}
			data[i] = entry;
			data_count++;
			return true;
		}
		bool b = subset[i]->loose_insert(entry);
		if (subset[i]->data_count == MAXIMUM + 1) {
			fix_excess(i);
		}
		return b;
	}

	template <class Item>
	void set<Item>::fix_excess(std::size_t i) {
		for (std::size_t ix = child_count - 1; ix > i; ix--) {
			subset[ix + 1] = subset[ix];
		}
		subset[i + 1] = new set<Item>;
		child_count++;
		for (std::size_t ix = MINIMUM + 1; ix < MAXIMUM + 1; ix++) {
			subset[i + 1]->data[ix - MINIMUM - 1] = subset[i]->data[ix];
		}
		subset[i]->data_count = MINIMUM;
		subset[i + 1]->data_count = MINIMUM;

		if (!(subset[i]->is_leaf()))
		{
			for (std::size_t ix = MINIMUM + 1; ix < MAXIMUM + 2; ix++) {
				subset[i + 1]->subset[ix - MINIMUM - 1] = subset[i]->subset[ix];
				subset[i]->subset[ix] = nullptr;
			}
			subset[i]->child_count = MINIMUM + 1;
			subset[i + 1]->child_count = MINIMUM + 1;
		}

		for (int ix(data_count - 1); ix >= static_cast<int>(i); --ix) {
			data[ix + 1] = data[ix];
		}
		data_count++;
		data[i] = subset[i]->data[MINIMUM];
	}

	

	template <class Item>
	void set<Item>::remove_biggest(Item& removed_entry) {
		if (child_count == 0)
		{
			removed_entry = data[data_count - 1];
			data_count--;
		}
		else
		{
			subset[child_count - 1]->remove_biggest(removed_entry);
			if (subset[child_count - 1]->data_count < MINIMUM)
				fix_shortage(subset[child_count - 1]->data_count + 1);
		}
	}

	template<class Item>
	std::size_t set<Item>::erase(const Item& target) {
		if (!loose_erase(target)) {
			return false;
		}

		if ((child_count == 1) && (data_count == 0)) {
			set<Item>* temp_ptr;

			temp_ptr = subset[0];


			for (int i = 0; i < temp_ptr->data_count; i++) {
				data[i] = temp_ptr->data[i];
			}

			for (int i = 0; i < temp_ptr->child_count; i++)
			{
				subset[i] = temp_ptr->subset[i];
			}

			data_count = temp_ptr->data_count;
			child_count = temp_ptr->child_count;

			for (int i = 0; i < temp_ptr->child_count; i++) {
				temp_ptr->subset[i] = nullptr;
			}
			delete temp_ptr;

		}
		return true;

	}

	template<class Item>
	void set<Item>::print(int indent) const
	{
		const int EXTRA_INDENTATION = 4;
		size_t i;

		std::cout << std::setw(indent) << "";

		for (i = 0; i < data_count; ++i)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;

		for (i = 0; i < child_count; ++i)
		{
			subset[i]->print(indent + EXTRA_INDENTATION);
		}
	}

	template <class Item>
	bool set<Item>::loose_erase(const Item& target) {
		std::size_t i = get_index(target);

		if (child_count == 0 && data[i] != target)
		{
			return false;
		}

		if (child_count != 0 && data[i] != target) {
			bool b = subset[i]->loose_erase(target);
			if (subset[i]->data_count < MINIMUM) {
				fix_shortage(i);
			}
			return b;
		}

		if (child_count == 0 && data[i] == target) {

			for (std::size_t ix = i + 1; ix < data_count; ++ix)
			{
				data[ix - 1] = data[ix];
			}
			--data_count;
			return true;
		}

		

		if (child_count != 0 && data[i] == target) {
			subset[i]->remove_biggest(data[i]);
			if (subset[i]->data_count < MINIMUM) {
				fix_shortage(i);
			}
			return true;
		}
	}

	template <class Item>
	void set<Item>::fix_shortage(std::size_t i) {

		//TRANSFER DATA TO FROM THE LEFT CHILD TREE
		if (subset[i - 1]->data_count > MINIMUM && i > 0) {
			
			for (std::size_t ix = subset[i]->data_count; ix > 0; --ix)
			{
				subset[i]->data[ix] = subset[i]->data[ix - 1];
			}
			subset[i]->data[0] = data[i - 1];
			subset[i]->data_count++;

			data[i - 1] = subset[i - 1]->data[subset[i - 1]->data_count - 1];
			subset[i - 1]->data_count--;

			if (!(subset[i - 1]->is_leaf()))
			{
				for (std::size_t is = subset[i]->child_count; is > 0; --is)
				{
					subset[i]->subset[is] = subset[i]->subset[is - 1];
				}
				subset[i]->subset[0] = subset[i - 1]->subset[subset[i - 1]->child_count - 1];
				subset[i - 1]->subset[subset[i - 1]->child_count - 1] = nullptr;
				subset[i - 1]->child_count--;
				subset[i]->child_count++;
			}
		}

		//MERGE WITH THE LEFT CHILD TREE
		if ( subset[i - 1]->data_count == MINIMUM && i > 0) {

			subset[i - 1]->data[subset[i - 1]->data_count] = data[i - 1]; 
			subset[i - 1]->data_count++;

			for (std::size_t ix = i - 1; ix < data_count; ++ix) 
			{
				data[ix] = data[ix + 1];
			}
			data_count--;

			for (std::size_t id = 0; id < subset[i]->data_count; ++id)
			{
				subset[i - 1]->data[subset[i - 1]->data_count] = subset[i]->data[id];
				subset[i - 1]->data_count++;
			}
			subset[i]->data_count = 0;
			for (std::size_t is = 0; is < subset[i]->child_count; ++is)
			{
				subset[i - 1]->subset[subset[i - 1]->child_count] = subset[i]->subset[is];
				subset[i]->subset[is] = nullptr;
				subset[i - 1]->child_count++;
			}
			subset[i]->child_count = 0;

			delete subset[i];
			for (std::size_t ix = i; ix < child_count - 1; ++ix)
			{
				subset[ix] = subset[ix + 1];
			}
			subset[child_count - 1] = nullptr;
			child_count--;
		}


		//TRANSFER DATA FROM THE RIGHT CHILD TREE
		if (subset[i + 1]->data_count>MINIMUM && i<child_count - 1) {
			
			subset[i]->data[subset[i]->data_count] = data[0];
			subset[i]->data_count++;

			data[0] = subset[i + 1]->data[0];
			for (std::size_t ix = 0; ix < subset[i + 1]->data_count; ++ix)
			{
				subset[i + 1]->data[ix] = subset[i + 1]->data[ix + 1];
			}
			subset[i + 1]->data_count--;

			if (!(subset[i + 1]->is_leaf()))
			{
				subset[i]->subset[subset[i]->child_count] = subset[i + 1]->subset[0];//move child 

				for (std::size_t is = 0; is < subset[i + 1]->child_count; ++is) //remove gap 
				{
					subset[i + 1]->subset[is] = subset[i + 1]->subset[is + 1];
				}
				subset[i + 1]->subset[subset[i + 1]->child_count - 1] = nullptr;
				subset[i + 1]->child_count--;
				subset[i]->child_count++;
			}
		}

		

	//MERGE DATA WITH THE RIGHT CHILD TREE
		if ( subset[i + 1]->data_count == MINIMUM && i < child_count - 1) {

			subset[i]->data[subset[i]->data_count] = data[i];
			subset[i]->data_count++;
			for (std::size_t id = 0; id < data_count; ++id)
			{
				data[id] = data[id + 1];
			}
			data_count--;

			for (std::size_t id = 0; id < subset[i + 1]->data_count; ++id)
			{
				subset[i]->data[subset[i]->data_count] = subset[i + 1]->data[id];
				subset[i]->data_count++;
			}
			subset[i + 1]->data_count = 0;
			for (std::size_t is = 0; is < subset[i + 1]->child_count; ++is)
			{
				subset[i]->subset[subset[i]->child_count] = subset[i + 1]->subset[is];
				subset[i + 1]->subset[is] = nullptr;
				subset[i]->child_count++;
			}
			subset[i + 1]->child_count = 0;

			delete subset[i + 1];
			for (std::size_t ix = i + 1; ix < child_count; ++ix)
			{
				subset[ix] = subset[ix + 1];
			}
			subset[child_count - 1] = nullptr;
			child_count--;
		}
		//bool loose_erase(const Item& target);

	}


	
}
#endif
