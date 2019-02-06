
#include <iostream>
#include "bag.h"        //Provide templatized defination of the bag class
#include "bag.tpp"      //Provides implementation of the templatized bag class
#include <string>

int main(){
    
    std::cout<<"Hello World "<<std::endl;
    bag<int> bag_int;
    
    //int a=2;
    cout<<"Inserting integer 2 into the bag using bag_int object:"<<endl;
    bag_int.insert(2);
    bag_int.print();
    
    //Adding string into the bag
    bag<string> bag_string;
    bag_string.insert("Aaditya Kharel");
    cout<<"Inserting string into the bag using bag_string object:"<<endl;
    bag_string.print();
    
    
    //Adding doubles into the bag
    bag<double> bag_double;
    bag_double.insert(3.1415);
    bag_double.insert(2.1415);
    bag_double.insert(5.38462845);
    cout<<"Inserting some double numbers into the bag using bag_double object"<<endl;
    bag_double.print();
    bag_double.erase(3.1415);
    
    cout<<"Erasing content from a bag of doubles and printing remaining items"<<endl;
    cout<<"Remaining Item in double bag"<<endl;
    bag_double.print();
    
    //Adding two bags of integer
    cout<<"Declaring, Inserting and Adding two bags of integers bag_int and bag_int2"<<endl;
    bag<int> bag_int2;
    bag_int2.insert(5);
    bag_int2.insert(17);
    bag_int2.insert(5);
    bag<int> bag_added_int;
    bag_added_int=bag_int+bag_int2;
    bag_added_int.print();
    
    cout<<"Counting number of occurence of integer 5 in the added bag"<<endl;
    cout<<bag_added_int.count(5)<<endl;

    bag_int=bag_int2;
    cout<<"Printing the contents of bag_int1 after assingment bag_int1=bag_int2"<<endl;
    bag_int.print();
    
    
    cout<<"Current size of bag_int "<<endl;;
    size_t a=bag_int.size();
    cout<<a<<endl;
    
    cout<<"Erasing one occurence of integer 5 from the bag_int object and printing remaining items"<<endl;
    bag_int.erase_one(5);
    bag_int.print();
    
    cout<<endl;
    cout<<"All functions have been succesfully TESTED!"<<endl;
    return 0;
}
