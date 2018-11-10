#include <iostream>

#include "LinkedList.h"
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"

bool biggerThan10(int x) {return x>10;}

int square(int x) {return x*x;}
int addTen(int x) {return x+10;}

int addPairs(int x, int y) {return x + y;}

bool bigger(int x, int y) {return x > y;}
bool even(int x) {return x % 2 == 0;}
bool same(int x, int y) {return x == y;}

int main(int argc, char** argv) {

	LinkedList<int> A = {1, 22, -123, 7777};
	std::cout << A.exists(11, same) << '\n';

	return 0;
}