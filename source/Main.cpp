#include <iostream>
#include <time.h>
#include <forward_list>
#include <list>

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

	/*LinkedList<int> test = {1, 0, 2, 9, 3, 8, 4, 7, 5, 6};
	test.sort(bigger);
	test.print();*/

	clock_t t;
	float tot = 0;
	float tot1A = 0;
	float tot2A = 0;
	volatile int sum1 = 0;
	volatile int sum2 = 0;
	float loopCount = 50;
	
	for(int j = 0; j < loopCount; j++) {
		LinkedList<int> mine;
		std::list<int> standard;

		t = clock();
		for(int i = 0; i < 2000000; i++) {mine.addElementFront(i);}
		mine.sort(bigger);
		//mine.applyFunction(square);
		//mine.filterFunction(even);
		//mine.unique_seq(same);
		//mine.reverseElements();
		t = clock() - t;
		float tot1 = t;
		tot1A += tot1;

		t = clock();
		for(int i = 0; i < 2000000; i++) {standard.push_front(i);}
		//for(auto& i : standard) {i = square(i);}
		//standard.unique(same);
		//standard.remove_if(even);
		//standard.reverse();
		standard.sort(bigger);
		t = clock() - t;
		float tot2 = t;
		tot2A += tot2;
		
		tot += (tot2/tot1);
		std::cout << "Round " << j << " complete." << '\n';
	}
	std::cout << '\n';
	float avg = tot/loopCount;
	std::cout << "Custom implementation average took: " << tot1A/loopCount << " ticks." << '\n'; 
	std::cout << "Standard implementation average took: " << tot2A/loopCount << " ticks." << '\n';
	std::cout << "Custom implementation speed is " << avg*100 << "% standard implementation speed." << '\n';

	return 0;
}