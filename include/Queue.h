#pragma once

#include "LinkedList.h"

namespace jci {
	template<typename T>
	class Queue {
	private:
		LinkedList<T> queue;
	public:
		//Constructor
		Queue() {};

		//Push new element to the back of the queue
		//Param element -> new element to be pushed
		void push(T element) {queue.addElementBack(element);};

		//Pop an element from the fron of the queue
		void pop() {queue.removeElementFront();};

		//Get the value from the back or the front of the queue
		//Returns the content of the front/back element
		T peek_back() {return queue.getElementBack()->content;};
		T peek_front() {return queue.getElementFront()->content;};
	};
}

