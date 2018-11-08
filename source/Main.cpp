#include <iostream>

#include "LinkedList.h"

int main(int argc, char** argv) {

	LinkedList<int> testLL = {5, 11, 345, 999, 1010101};
	testLL.addElement(525, 3);
	testLL.removeElement(3);
	testLL.print();

	return 0;
}