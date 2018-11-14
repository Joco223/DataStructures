#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>

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

	/* jci::Array Tests compared to std::vector:
	Add elements to front - (Standard first: +68% - Custom First: +57%)
	*/

	int loopCount = 50;
	int sampleSize = 40000;

	std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
	for(int i = 0; i < loopCount; i++) {
		std::vector<int> standard;
		for(int j = 0; j < sampleSize; j++) {standard.insert(standard.begin(), j);}
		for(int j = 0; j < sampleSize; j++) {standard.erase(standard.begin());}
		std::cout << "Standard implementation round: " << i << " finished." << '\r';
	}
	std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeSpan2 = std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3);
	std::cout << "Standard implementation average took: " << timeSpan2.count()/loopCount << " seconds." << '\n';

	/*std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	for(int i = 0; i < loopCount; i++) {
		jci::Array<int> mine;
		for(int j = 0; j < sampleSize; j++) {mine.addElementFront(j);}
		for(int j = 0; j < sampleSize; j++) {mine.removeFrontElement();}
		std::cout << "Custom implementation round: " << i << " finished." << '\r';
	}
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
	std::cout << "Custom implementation average took: " << timeSpan.count()/loopCount << " seconds." << '\n';*/

	

	/*int amount = timeSpan2.count()/timeSpan.count()*100 - 100;
	
	std::cout << "Custom implementation speed is: ";
	if(amount < 0) {std::cout << "-";}else{std::cout << "+";};
	std::cout << amount << "% standard implementation speed." << '\n';*/

	return 0;
}