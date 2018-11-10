#pragma once

#include "LinkedList.h"

template<typename T>
class Queue {
private:
	LinkedList<T> queue;
public:
	Queue() {};

	void push(T element) {queue.addElement(element, queue.getLength());};

	void pop() {queue.removeElement(0);};

	T peek_back() {return queue.getElement(queue.getLength()-1)->content;};
	T peek_front() {return queue.getElement(0)->content;};
};