//  main.cpp
//  hw10
//
//  Created by Aaditya Kharel on 10/25/17.
//  Copyright © 2017 Aaditya Kharel. All rights reserved.
//

#include <iostream>
using namespace std;

void guess(int low, int high);

int main(){
    int low=0;
    int high=1000000;
    cout<<"Welcome to guessing game."<<endl;
    cout<<"Think of a number between 0 and 1,000,000"<<endl;
    cout<<"I will guess your number within 20 attempts"<<endl<<endl;
    guess(low, high);
    return 0;
}

void guess(int low, int high){
    
    int midvalue=(low+high)/2;
    
    if(low<high){
        
        cout<<"Is your number "<<midvalue<<"?"<<" Enter y or n"<<endl;
        char choice;
        cin>>choice;
        if (choice=='y'){
            cout<<"BINGO! I guessed your number"<<endl;
        }
        else{
            cout<<"Is your number higher than "<<midvalue<<"?"<<" Enter y or n"<<endl;
            char choice;
            cin>>choice;
            if (choice=='y'){
                guess(midvalue+1, high);
            }
            else{
                guess(low, midvalue-1);
            }
        }
    }
        else{
            cout<<"BINGO!!!! I finally guessed your number"<<endl;
            cout<<"The number is "<<low<<endl;
        }
    }
