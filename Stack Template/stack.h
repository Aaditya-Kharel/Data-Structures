#include <iostream>
#include <cstdlib>
#include <cassert>
//using namespace std;

template <class T>
class stack{
    
public:
    //CONSTRUCTOR
    stack();
    
    //TYPEDEF
    typedef std::size_t size_type;
    
    
    //MODIFICATION
    void pop_a();
    void pop_b();
    
    void push_a(const T& entry_a);
    void push_b(const T& entry_b);
    
    
    //CONSTANT MEMBERS FUNCTIONS
    bool empty_a() const {return (used_a==0);}
    bool empty_b() const {return (used_b==capacity);}
    
    T top_a() const{
        assert(size_a()>0);
        return data[used_a-1];}
    
    T top_b() const{
        assert(size_b()>0);
        return data[used_b];
    }
    
    size_type size_a() const {return used_a;}
    size_type size_b() const {return (capacity-used_b);}
    
    void print_a();
    void print_b();
    
    
    
    
private:
    static const size_type capacity=100;     //const capacity
    static T data[capacity];    //static array of type T
    size_type used_a;         //how much of array is used from top
    size_type used_b;      //how much of array is used from bottom
    
};


template <class T>
const typename stack<T>::size_type stack<T>::capacity;

template <class T>
T stack<T>::data[];

template <class T>
stack<T>::stack(){
    used_a=0;
    used_b=capacity;
}

template <class T>
void stack<T>::pop_a(){
    assert(!empty_a());
    --used_a;
}

template <class T>
void stack<T>::pop_b(){
    assert(!empty_b());
    ++used_b;
}

template <class T>
void stack<T>::push_a(const T& entry_a){
    assert(size_a()+size_b()<capacity);
    data[used_a]=entry_a;
    ++used_a;
    
}

template <class T>
void stack<T>::push_b(const T& entry_b){
    assert(size_a()+size_b()<capacity);
    data[used_b-1]=entry_b;
    --used_b;
}

template <class T>
void stack<T>::print_a(){
    //cout<<"STACK A"<<endl;
    for(int i=0; i<used_a; i++){
        std::cout<<data[i];
        std::cout<<" ";
    }
    std::cout<<std::endl;
}
template <class T>
void stack<T>::print_b(){
    //cout<<"STACK B"<<endl;
    for (std::size_t i=capacity-1; i>=used_b; i--){
        std::cout<<data[i];
        std::cout<<" ";
    }
    std::cout<<std::endl;
}
