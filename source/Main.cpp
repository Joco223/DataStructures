#include <iostream>

#include "LinkedList.h"
#include "Stack.h"

bool biggerThan10(int x) {return x>10;}

int square(int x) {return x*x;}
int addTen(int x) {return x+10;}

int addPairs(int x, int y) {return x + y;}

bool bigger(int x, int y) {return x > y;}
bool even(int x) {return x % 2 == 0;}
bool same(int x, int y) {return x == y;}

int main(int argc, char** argv) {

	Stack<int> test;
	test.push(5);
	test.push(-10);
	std::cout << test.peek() << '\n';
	std::cout << test.isFull() << '\n';
	std::cout << test.isEmpty() << '\n';
	test.pop();
	std::cout << test.peek() << '\n';

	return 0;
}