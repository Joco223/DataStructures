#include <iostream>
#include <time.h>
#include <forward_list>

#include "LinkedList.h"
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"
#include "BinaryTree.h"

bool biggerThan10(int x) {return x>10;}

int square(int x) {return x*x;}
int addTen(int x) {return x+10;}

int addPairs(int x, int y) {return x + y;}

bool bigger(int x, int y) {return x < y;}
bool even(int x) {return x % 2 == 0;}
bool same(int x, int y) {return x == y;}

int main(int argc, char** argv) {

	clock_t t;
	float tot = 0;
	float tot1A = 0;
	float tot2A = 0;
	volatile int sum1 = 0;
	volatile int sum2 = 0;
	
	for(int j = 0; j < 100; j++) {
		LinkedList<int> mine;
		std::forward_list<int> standard;

		t = clock();
		for(int i = 0; i < 1000000; i++) {mine.addElementFront(i);}
		//mine.unique_seq(same);
		mine.filterFunction(even);
		t = clock() - t;
		float tot1 = t;
		tot1A += tot1;

		t = clock();
		for(int i = 0; i < 1000000; i++) {standard.push_front(i);}
		//standard.unique(same);
		standard.remove_if(even);
		t = clock() - t;
		float tot2 = t;
		tot2A += tot2;
		
		tot += (tot2/tot1);
		std::cout << "Round " << j << " complete." << '\n';
	}
	std::cout << '\n';
	float avg = tot/100;
	std::cout << "Custom implementation average took: " << tot1A/100.0 << " ticks." << '\n'; 
	std::cout << "Standard implementation average took: " << tot2A/100.0 << " ticks." << '\n';
	std::cout << "Custom implementation speed is " << avg*100 << "% standard implementation speed." << '\n';

	return 0;
}