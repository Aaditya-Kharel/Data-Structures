#ifndef HEADER1_H
#define HEADER1_H

#include <iostream>
#include "Header.h"


class towers {

public:
	towers();
	~towers();
	int many_rings(peg pegObj) const;
	int top_diameter(peg pegObj) const;
	void move(peg startPeg, peg endPeg);

private:
	peg peg2, peg3, peg4;

};
#endif