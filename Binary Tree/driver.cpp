#include <iostream>  
#include <cstring>   
#include "bag6.h"
#include <ctime>
#include <cstdlib>   

using namespace std;


int main() {
	
	
	bag<int> bag;

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0; 

	int n = 2000;

	srand(time(NULL));

	a = clock();
	for (int i = 0; i<n; i++)
	{
		bag.insert((rand() % n) + 1);
	}

	b = clock();
	for (int i = 1; i < n + 1; ++i)
	{
		bag.count(i);
	}
	b = clock() - b;

    cout << "% % % % % Time  Needed for Tree Data Structure % % % % %" << endl<<endl;

	cout << "Time required to insert using Tree Data Structure: " << clock() - a << endl;

	cout << "Time required for counting using Tree Data Structure: " << b << endl;

    cout<<endl;
	cout << "% % % % % Time  Needed for Non - Tree Data Structure % % % % %" << endl;
    cout<<endl;

	int * generatedNums = new int[n];
	d = clock();
	for (int i(0); i < n; ++i)
	{
		generatedNums[i] = (rand() % n) + 1;
	}
	

	c = clock();
	int count = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == generatedNums[j])
				++count;
		}
	}

	c = clock() - c;

	cout << "Time Required for non tree insert: " << clock() - d << endl;
	cout << "Time Required for non tree counting:  " << c << endl;


	return 0;
}
