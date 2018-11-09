#include <iostream>

#include "LinkedList.h"

bool biggerThan10(int x) {return x>10;}

int square(int x) {return x*x;}
int addTen(int x) {return x+10;}

int addPairs(int x, int y) {return x + y;}

bool bigger(int x, int y) {return x > y;}
bool even(int x) {return x % 2 == 0;}
bool same(int x, int y) {return x == y;}

int main(int argc, char** argv) {

	LinkedList<int> A = {12, 55, 12, 88, 12};
	//A.sort(bigger);
	//A.filterFunction(even);
	A.unique(same);
	A.print();

	return 0;
}