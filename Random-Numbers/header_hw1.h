#ifndef HEADER_H
#define HEADER_H


namespace aaditya_kharel_hw1
{
class randomNumber {
public:
	//pre-condition: None
	//post-condition: Initializes the private member variables
	//This is a default constructor
	randomNumber();

	//pre-condition: None
	//post-condition: Initializes the private member variables as input by user
	//This is a parameterized constructor
	randomNumber(int a, int b, int c, int d);

	//pre-condition: None
	//post-condition: Sets seeder value as defined by user
	void changeseed(int a);


	//Pre-condition: All private member varibles are properly initialized
	//Post-condition: pseudo-random number is generated
	int generateNum();

	//Pre-condition: None
	//Post-condition: New random number is generated but returned by dividing by modulus
	double newRandom();

	//Pre-condition: pseudo-random generator has been called one million times
	//Post-condition: Table is displayed
	void printTable();

	//Pre-condition: None
	//Post-condition: Approx. 1 million Gaussian distribution sequence has been generated
	//Post-condition: The distribution table has been printed
	void randomGaussian();

	//Post-condition: Tests for Problem #11 requirement
	void test11();
	//Post-condition: Tests for Problem #12 requirement
	void test12();
	//Post-condition: Tests for Problem #13 requirement
	void test13();
	//Post-condition: Tests for Problem #14 requirement
	void test14();

private:
	int seed;
	int multiplier;
	int increment;
	int modulus;


};
}

#endif