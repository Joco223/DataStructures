#pragma once

#include "LinkedList.h"

template<typename T>
class Queue {
private:
	LinkedList<T> queue;
public:
	//Constructor
	Queue() {};

	//Push new element to the back of the queue
	void push(T element) {queue.addElement(element, queue.getLength());};

	//Pop an element from the fron of the queue
	void pop() {queue.removeElement(0);};

	//Get the value from the back or the front of the queue
	T peek_back() {return queue.getElement(queue.getLength()-1)->content;};
	T peek_front() {return queue.getElement(0)->content;};
};