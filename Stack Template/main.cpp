#include "stack.h"
using namespace std;

int main(){
    
    stack<int> stackA;
    stack<int> stackB;
    
    stackA.push_a(1);
    stackA.push_a(2);
    stackA.push_a(3);
    stackA.push_a(4);
    stackA.push_a(5);
    stackA.push_a(6);
    stackA.push_a(7);
    stackA.push_a(8);
    stackA.push_a(9);
    stackA.push_a(10);
    
    
    stackB.push_b (51);
    stackB.push_b (52);
    stackB.push_b (53);
    stackB.push_b (54);
    stackB.push_b (55);
    stackB.push_b (56);
    stackB.push_b (57);
    stackB.push_b (58);
    stackB.push_b (59);
    stackB.push_b (60);
    
    
    //Printing initial stacks
    cout<<"Stack A: ";
    stackA.print_a();
    cout<<"Stack B: ";
    stackB.print_b();
    cout<<endl;
    
    
    //Operation Pop
    stackA.pop_a();
    cout<<"After pop operation in Stack A"<<endl;
    stackA.print_a();
    stackB.pop_b();
    cout<<"After pop operation in Stack B"<<endl;
    stackB.print_b();
    cout<<endl;
    
    
    //Operation Top
    cout<<"Top item in Stack A: ";
    cout<<stackA.top_a()<<endl;
    cout<<"Top item in Stack B: ";
    cout<<stackB.top_b()<<endl;
    cout<<endl;
    
    
    //Operation Pop
    stackA.pop_a();
    cout<<"After pop operation in Stack A"<<endl;
    stackA.print_a();
    stackB.pop_b();
    cout<<"After pop operation in Stack B"<<endl;
    stackB.print_b();
    stackA.pop_a();
    cout<<endl;
    cout<<"After pop operation in Stack A"<<endl;
    stackA.print_a();
    stackB.pop_b();
    cout<<"After pop operation in Stack B"<<endl;
    stackB.print_b();
    cout<<endl;
    
    
    return 0;
}
