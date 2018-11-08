#include <iostream>

#include "LinkedList.h"

bool biggerThan10(int x) {return x>10;}

int square(int x) {return x*x;}
int addTen(int x) {return x+10;}

int addPairs(int x, int y) {return x + y;}

int main(int argc, char** argv) {

	LinkedList<int> A = {12, 55, 1, 88, -10};
	A.reverseElements();
	A.print();

	return 0;
}