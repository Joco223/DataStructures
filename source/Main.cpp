#include <iostream>

#include "LinkedList.h"

bool biggerThan10(int x) {return x>10;}

int square(int x) {return x*x;}
int addTen(int x) {return x+10;}

int addPairs(int x, int y) {return x + y;}

bool bigger(int x, int y) {return x > y;}
bool even(int x) {return x % 2 == 0;}

int main(int argc, char** argv) {

	LinkedList<int> A = {12, 55, 1, 88, -10};
	A.sort(bigger);
	A.filterFunction(even);
	A.reverseElements();
	LinkedList<int> C = LinkedList<int>::applyFunctionToPairs(A, A, addPairs);
	C.applyFunction(square);
	LinkedList<int> D = LinkedList<int>::connect(A, C);
	D.print();

	return 0;
}