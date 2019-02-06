//
//  main.cpp
//  aaditya_hw9
//
//  Created by Aaditya Kharel on 10/15/17.
//  Copyright © 2017 Aaditya Kharel. All rights reserved.
//

#include <iostream>
#include "queue.h"
using namespace std;
int main() {
    
    queue<int> a;
    
    cout<<"Pushing items into the queue"<<endl;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    
    a.print();
    
    cout<<"Popping two items"<<endl;
    
    a.pop();
    a.pop();
    a.print();
    
    
    
    cout<<"Testing for the front item in the queue"<<endl;
    cout<<a.front()<<endl<<endl;
    
    cout<<"TEST COMPLETED FOR QUEUE CLASS!"<<endl;
    
    return 0;
}
