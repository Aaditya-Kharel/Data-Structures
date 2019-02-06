

#ifndef BAG_H
#define BAG_H
#include <cstdlib>  // Provides size_t
#include <string>

    template <class T>
    class bag
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef T value_type;
        typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 30;
        // CONSTRUCTORS and DESTRUCTOR
        bag(size_type initial_capacity = DEFAULT_CAPACITY);
        bag(const bag& source);
        ~bag( );
        // MODIFICATION MEMBER FUNCTIONS
        void reserve(size_type new_capacity);
        bool erase_one(const T& target);
        size_type erase(const T& target);
        void insert(const T& entry);
        void operator +=(const bag& addend);
        void operator =(const bag& source);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return used; }
        size_type count(const T& target) const;
        // PRINT FUNCTION
        void print();
        
    private:
        T *data;     // Pointer to partially filled dynamic array
        size_type used;       // How much of array is being used
        size_type capacity;   // Current capacity of the bag
    };
    
    // NONMEMBER FUNCTIONS for the bag class
    template <class T>
    bag<T> operator +(const bag<T>& b1, const bag<T>& b2);


#endif
