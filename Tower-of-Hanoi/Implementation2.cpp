#include <iostream>
#include"Header.h"
#include"Header1.h"
using namespace std;

towers::towers() {
	
}
towers::~towers() {
	
}

int towers::many_rings(peg pegObj) const {
	int a = pegObj.getTotalRingNumber();
	return a;
}

int towers::top_diameter(peg pegObj) const {
	if (many_rings(pegObj) > 0) {
		int a = pegObj.getTopRingDiameter();
		return a;
	}
	else {
		int a = 0;
		return a;
	}
}

void towers::move(peg startPeg, peg endPeg) {
	int a = top_diameter(startPeg);
	startPeg.removeTopRing();
	bool addCheck; 
	addCheck=endPeg.addRingToTop(a);
	if (addCheck == false) {
		startPeg.addRingToTop(a);
	}
}

