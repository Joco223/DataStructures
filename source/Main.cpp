#include <iostream>

#include "LinkedList.h"
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"
#include "BTree.h"

bool biggerThan10(int x) {return x>10;}

int square(int x) {return x*x;}
int addTen(int x) {return x+10;}

int addPairs(int x, int y) {return x + y;}

bool bigger(int x, int y) {return x < y;}
bool even(int x) {return x % 2 == 0;}
bool same(int x, int y) {return x == y;}

int main(int argc, char** argv) {

	BTree<int> test({11, 123, 2, 66, 44}, bigger);
	test.print();
	std::cout << "New tree" << '\n' << '\n';
	test.insert(55);
	test.print();
	std::cout << '\n' << test.search(55, same)->parent->content << '\n';

	return 0;
}