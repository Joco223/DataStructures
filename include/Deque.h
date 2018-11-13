#pragma once

#include "LinkedList.h"

template<typename T>
class Deque {
private:
	LinkedList<T> deque;
public:
	//Constructor
	Deque() {};

	//Push a new elment to the back or the front of the deque
	//Param element -> element to be pushed
	void push_back(T element) {deque.addElementBack(element);};
	void push_front(T element) {deque.addElementFront(element);};

	//Pop an element from the back or the front of the deque
	void pop_back() {deque.removeElementBack();};
	void pop_front() {deque.removeElementFront();};

	//Get the value of the back oor the front element of the deque
	//Returns the content of the front/back element
	T peek_back() {return deque.getElementBack()->content;};
	T peek_front() {return deque.getElementFront()->content;};
};