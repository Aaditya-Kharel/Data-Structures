
#include <iostream>
#include <algorithm>    // Provides copy function
#include <cassert>       // Provides assert function
#include "bag.h"
using namespace std;


    template <class T>
    const typename bag<T>::size_type bag<T>::DEFAULT_CAPACITY;


    template <class T>
    bag<T>::bag(size_type initial_capacity)
    {
        data = new T[initial_capacity];
        capacity = initial_capacity;
        used = 0;
    }

    template <class T>
    void bag<T>::print(){
        for (int i=0; i<used; i++){
            cout<<data[i]<<endl;
        }
    }

    template <class T>
    bag<T>::bag(const bag<T>& source)
    // Library facilities used: algorithm
    {
        data = new T[source.capacity];
        capacity = source.capacity;
        used = source.used;
        copy(source.data, source.data + used, data);
    }

    template <class T>
    bag<T>::~bag( )
    {
        delete [ ] data;
    }


    template <class T>
void bag<T>::reserve(bag<T>::size_type new_capacity)
    // Library facilities used: algorithm
    {
        T *larger_array;
        
        if (new_capacity == capacity)
            return; // The allocated memory is already the right size.
                if (new_capacity < used)
            new_capacity = used; // Can’t allocate less than we are using.
        
        larger_array = new T[new_capacity];
        copy(data, data + used, larger_array);
        delete [ ] data;
        data = larger_array;
        capacity = new_capacity;
    }

    template <class T>
    typename bag<T>::size_type bag<T>::erase(const T& target)
    {
        size_type index = 0;
        size_type many_removed = 0;
        
        while (index < used)
        {
            if (data[index] == target)
            {
                --used;
                data[index] = data[used];
                ++many_removed;
            }
            else
                ++index;
        }
        
        return many_removed;
    }
    template <class T>
    bool bag<T>::erase_one(const T& target)
    {
        size_type index; // The location of target in the data array
        
        // First, set index to the location of target in the data array,
        // which could be as small as 0 or as large as used-1.
        // If target is not in the array, then index will be set equal to used.
        index = 0;
        while ((index < used) && (data[index] != target))
            ++index;
        
        if (index == used) // target isn't in the bag, so no work to do
            return false;
        
        // When execution reaches here, target is in the bag at data[index].
        // So, reduce used by 1 and copy the last item onto data[index].
        --used;
        data[index] = data[used];
        return true;
    }
    template <class T>
    void bag<T>::insert(const T& entry)
    {
        if (used == capacity)
            reserve(used+1);
        data[used] = entry;
        ++used;
    }
    template <class T>
    void bag<T>::operator +=(const bag<T>& addend)
    // Library facilities used: algorithm
    {
        if (used + addend.used > capacity)
            reserve(used + addend.used);
        
        copy(addend.data, addend.data + addend.used, data + used);
        used += addend.used;
    }
    template <class T>
    void bag<T>::operator =(const bag<T>& source)
    // Library facilities used: algorithm
    {
        T *new_data;
        
        // Check for possible self-assignment:
        if (this == &source)
            return;
        
        // If needed, allocate an array with a different size:
        if (capacity != source.capacity)
        {
            new_data = new T[source.capacity];
            delete [ ] data;
            data = new_data;
            capacity = source.capacity;
        }
        
        // Copy the data from the source array:
        used = source.used;
        copy(source.data, source.data + used, data);
    }
    template <class T>
    typename bag<T>::size_type bag<T>::count(const T& target) const
    {
        size_type answer;
        size_type i;
        
        answer = 0;
        for (i = 0; i < used; ++i)
            if (target == data[i])
                ++answer;
        return answer;
    }
    template <class T>
    bag<T> operator +(const bag<T>& b1, const bag<T>& b2)
    {
        bag<T> answer(b1.size( ) + b2.size( ));
        
        answer += b1; 
        answer += b2;
        return answer;
    }
