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
	void push_back(T element) {deque.addElement(element, deque.getLength());};
	void push_front(T element) {deque.addElement(element, 0);};

	//Pop an element from the back or the front of the deque
	void pop_back() {deque.removeElement(deque.getLength()-1);};
	void pop_front() {deque.removeElement(0);};

	//Get the value of the back oor the front element of the deque
	T peek_back() {return deque.getElement(deque.getLength()-1)->content;};
	T peek_front() {return deque.getElement(0)->content;};
};