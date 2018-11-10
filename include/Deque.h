#pragma once

#include "LinkedList.h"

template<typename T>
class Deque {
private:
	LinkedList<T> deque;
public:
	Deque() {};

	void push_back(T element) {deque.addElement(element, deque.getLength());};
	void push_front(T element) {deque.addElement(element, 0);};

	void pop_back() {deque.removeElement(deque.getLength()-1);};
	void pop_front() {deque.removeElement(0);};

	T peek_back() {return deque.getElement(deque.getLength()-1)->content;};
	T peek_front() {return deque.getElement(0)->content;};
};