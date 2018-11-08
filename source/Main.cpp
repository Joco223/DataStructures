#include <iostream>

#include "LinkedList.h"

bool biggerThan10(int x) {return x>10;}

int square(int x) {return x*x;}
int addTen(int x) {return x+10;}

int addPairs(int x, int y) {return x + y;}

int main(int argc, char** argv) {

	LinkedList<int> A = {12, 55, 1, 88, -10};
	A.filterFunction(biggerThan10);
	A.print();
	/*LinkedList<int> B = {5 , 11, 5, 2 ,  20};
	LinkedList<int> C = LinkedList<int>::applyFunctionToPairs(A, B, addPairs);
	C.print();*/

	return 0;
}