#include<iostream>
#include<cmath>
#include "header_hw1.h"

using namespace std;

int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0, r7 = 0, r8 = 0, r9 = 0, r10 = 0;
int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0, c10 = 0;

namespace aaditya_kharel_hw1
{
	randomNumber::randomNumber() {
		seed = 1;
		multiplier = 40;
		increment = 725;
		modulus = 729;
	}

	randomNumber::randomNumber(int s, int mult, int inc, int mod) {
		seed = s;
		multiplier = mult;
		increment = inc;
		modulus = mod;
	}

	void randomNumber::changeseed(int a) {
		seed = a;
	}

	int randomNumber::generateNum() {
		int randomNum = (multiplier*seed + increment) % modulus;
		seed = randomNum;
		return randomNum;
	}

	double randomNumber::newRandom() {
		int randomNum = (multiplier*seed + increment) % modulus;
		seed = randomNum;
		double rand = (seed / static_cast<double>(modulus));

		if (rand >= 0 && rand < 0.1) {

			r1 = r1 + 1;
		}
		else if (rand >= 0.1 && rand < 0.2) {

			r2 = r2 + 1;
		}
		else if (rand >= 0.2 && rand < 0.3) {

			r3 = r3 + 1;
		}
		else if (rand >= 0.3 && rand < 0.4) {

			r4 = r4 + 1;
		}
		else if (rand >= 0.4 && rand < 0.5) {

			r5 = r5 + 1;
		}
		else if (rand >= 0.5 && rand < 0.6) {
			r6 = r6 + 1;
		}
		else if (rand >= 0.6 && rand < 0.7) {
			r7 = r7 + 1;
		}
		else if (rand >= 0.7 && rand < 0.8) {
			r8 = r8 + 1;
		}
		else if (rand >= 0.8 && rand < 0.9) {
			r9 = r9 + 1;
		}
		else if (rand >= 0.9 && rand < 1.0) {
			r10 = r10 + 1;
		}
		return rand;
	}

	void randomNumber::printTable() {
		cout << "Range" << "                        " << "Number of Occurrence" << endl;
		cout << "[0.0 ... 0.1)" << "                        " << r1 << endl;
		cout << "[0.1 ... 0.2)" << "                        " << r2 << endl;
		cout << "[0.2 ... 0.3)" << "                        " << r3 << endl;
		cout << "[0.3 ... 0.4)" << "                        " << r4 << endl;
		cout << "[0.4 ... 0.5)" << "                        " << r5 << endl;
		cout << "[0.5 ... 0.6)" << "                        " << r6 << endl;
		cout << "[0.6 ... 0.7)" << "                        " << r7 << endl;
		cout << "[0.7 ... 0.8)" << "                        " << r8 << endl;
		cout << "[0.8 ... 0.9)" << "                        " << r9 << endl;
		cout << "[0.9 ... 1.0)" << "                        " << r10 << endl;
	}

	void randomNumber::randomGaussian() {
		for (int i = 0; i<500000; i++) {

			double x1, x2, w, y1, y2;
			do {


				x1 = 2.0 * newRandom() - 1.0;
				x2 = 2.0 * newRandom() - 1.0;
				w = x1 * x1 + x2 * x2;
			} while (w >= 1);

			w = sqrt((-2.0 * log(w)) / w);
			y1 = x1 * w;
			y2 = x2 * w;

			if (y1 >= -3 && y1 < -2.4) {
				c1 = c1 + 1;

			}
			else if (y1 >= -2.4 && y1 < -1.8) {
				c2 = c2 + 1;

			}
			else if (y1 >= -1.8 && y1 < -1.2) {
				c3 = c3 + 1;

			}
			else if (y1 >= -1.2 && y1 < -0.6) {
				c4 = c4 + 1;

			}
			else if (y1 >= -0.6 && y1 < 0) {
				c5 = c5 + 1;

			}
			else if (y1 >= 0 && y1 < 0.6) {
				c6 = c6 + 1;

			}
			else if (y1 >= 0.6 && y1 < 1.2) {
				c7 = c7 + 1;

			}
			else if (y1 >= 1.2 && y1 < 1.8) {
				c8 = c8 + 1;

			}
			else if (y1 >= 1.8 && y1 < 2.4) {
				c9 = c9 + 1;

			}
			else if (y1 >= 2.4 && y1 <= 3.0) {
				c10 = c10 + 1;

			}

			if (y2 >= -3 && y2 < -2.4) {
				c1 = c1 + 1;
			}
			else if (y2 >= -2.4 && y2 < -1.8) {
				c2 = c2 + 1;
			}
			else if (y2 >= -1.8 && y2 < -1.2) {
				c3 = c3 + 1;
			}
			else if (y2 >= -1.2 && y2 < -0.6) {
				c4 = c4 + 1;
			}
			else if (y2 >= -0.6 && y2 < 0) {
				c5 = c5 + 1;
			}
			else if (y2 >= 0 && y2 < 0.6) {
				c6 = c6 + 1;
			}
			else if (y2 >= 0.6 && y2 < 1.2) {
				c7 = c7 + 1;
			}
			else if (y2 >= 1.2 && y2 < 1.8) {
				c8 = c8 + 1;
			}
			else if (y2 >= 1.8 && y2 < 2.4) {
				c9 = c9 + 1;
			}
			else if (y2 >= 2.4 && y2 <= 3.0) {
				c10 = c10 + 1;
			}

		}


		cout << "Range" << "                        " << "Number of Occurrence" << endl;
		cout << "[-3.0 ... -2.4)" << "                        " << c1 << endl;
		cout << "[-2.4 ... -1.8)" << "                        " << c2 << endl;
		cout << "[-1.8 ... -1.2)" << "                        " << c3 << endl;
		cout << "[-1.2 ... -0.6)" << "                        " << c4 << endl;
		cout << "[-0.6 ...  0.0)" << "                        " << c5 << endl;
		cout << "[0.0 ...   0.6)" << "                        " << c6 << endl;
		cout << "[0.6 ...   1.2)" << "                        " << c7 << endl;
		cout << "[1.2 ...   1.8)" << "                        " << c8 << endl;
		cout << "[1.8 ...   2.4)" << "                        " << c9 << endl;
		cout << "[2.4 ...   3.0)" << "                        " << c10 << endl;
	}

	void randomNumber::test11() {
		cout << "===================" << endl;
		cout << "Testing Problem 11" << endl;
		cout << "===================" << endl;
		cout << "Random Number when seed=1, multiplier=40, increment=725, modulus=729: "<<generateNum()<<endl;
	}

	void randomNumber::test12() {
		cout << "===================" << endl;
		cout << "Testing Problem 12" << endl;
		cout << "===================" << endl;
		cout <<"Random number divided by casted modulus: "<< newRandom();
		cout << endl << endl;
	}

	void randomNumber::test13() {
		cout << "===================" << endl;
		cout << "Testing Problem 13" << endl;
		cout << "===================" << endl << endl;
		for (int i = 0; i < 1000000; i++) {
			newRandom();
		}

		cout << "This is a Uniform Distribution" << endl;
		cout << endl << endl;
		printTable();
		cout << endl << endl;
	}

	void randomNumber::test14() {
		cout << "===================" << endl;
		cout << "Testing Problem 14" << endl;
		cout << "===================" << endl << endl;
		cout << "This is a Gaussian (Normal) Distribution" << endl << endl;
		randomGaussian();
		cout << endl << endl;
	}
}