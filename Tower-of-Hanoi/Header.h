#ifndef HEADER_H
#define HEADER_H
#include <iostream>

	class peg {

		friend std::ostream& operator<<(std::ostream& outs, const peg& source);

	public:
		 peg(int a);
		 void delpeg();
		 peg();

		int getTotalRingNumber() const;
		int getTopRingDiameter() const;
		bool addRingToTop(int ringdia);
		void removeTopRing();
		void initArray();		

	private:

		int ringDiameter;
		int numberOfRings;
		int* ringArray;


	};
#endif