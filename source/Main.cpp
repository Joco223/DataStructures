#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>

#include "LinkedList.h"
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "Array.h"

bool biggerThan10(int x) {return x>10;}

int square(int x) {return x*x;}
int addTen(int x) {return x+10;}

int addPairs(int x, int y) {return x + y;}

bool bigger(int x, int y) {return x < y;}
bool even(int x) {return x % 2 == 0;}
bool same(int x, int y) {return x == y;}

int main(int argc, char** argv) {

	int loopCount = 50;
	int sampleSize = 1000000;

	std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
	for(int i = 0; i < loopCount; i++) {
		std::list<int> standard;
		for(int j = 0; j < sampleSize; j++) {standard.push_back(j);}
		for(auto& i : standard) {i = square(i);}
		std::cerr << "Standard implementation round: " << i << " finished." << '\r';
	}
	std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeSpan2 = std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3);
	std::cerr << "Standard implementation average took: " << timeSpan2.count()/loopCount << " seconds." << '\n';

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	for(int i = 0; i < loopCount; i++) {
		jci::LinkedList<int> mine;
		for(int j = 0; j < sampleSize; j++) {mine.addElementBack(j);}
		mine.applyFunction(square);
		std::cerr << "Custom implementation round: " << i << " finished." << '\r';
	}
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
<<<<<<< HEAD
	std::cerr << "Custom implementation average took: " << timeSpan.count()/loopCount << " seconds." << '\n';
=======
	std::cout << "Custom implementation average took: " << timeSpan.count()/loopCount << " seconds." << '\n';
>>>>>>> b9a3ae5715e138425a3cb2559c254a29391b3b60

	std::cerr.precision(2);

<<<<<<< HEAD
	float amount = timeSpan2.count()/timeSpan.count()*100 - 100;
	
	std::cerr << "Custom implementation speed is: ";
	if(amount > 0) {std::cerr << "+";}
	std::cerr << amount << "% standard implementation speed." << '\n';
=======
	int amount = timeSpan2.count()/timeSpan.count()*100 - 100;
	
	std::cout << "Custom implementation speed is: ";
	if(amount < 0) {std::cout << "-";}else{std::cout << "+";};
	std::cout << amount << "% standard implementation speed." << '\n';
>>>>>>> b9a3ae5715e138425a3cb2559c254a29391b3b60

	return 0;
}
