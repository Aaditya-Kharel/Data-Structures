#include <cstdlib>    // Provides size_t
#include "node2.h"    // Provides the node type, from Figure 6.5 on page 306
#include <iostream>
// using namespace std;

template <class RecordType>
class table
{
public:
	// MEMBER CONSTANT -- See Appendix E if this fails to compile.
	static const std::size_t TABLE_SIZE = 811;
	// CONSTRUCTORS AND DESTRUCTOR
	table();
	table(const table& source);
	~table();
	// MODIFICATION MEMBER FUNCTIONS
	void insert(const RecordType& entry);
	void remove(int key);
	void operator =(const table& source);
	// CONSTANT MEMBER FUNCTIONS
	void find(int key, bool& found, RecordType& result) const;
	bool is_present(int key) const;
	std::size_t size() const { return total_records; }
private:
	main_savitch_6B::node<RecordType> *data[TABLE_SIZE];
	std::size_t total_records;
	// HELPER MEMBER FUNCTION
	std::size_t hash(int key) const;
};


#include "table.template" // Include the implementation




