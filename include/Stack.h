#pragma once

#include "LinkedList.h"

template<typename T>
class Stack {
private:
	LinkedList<T> stack;
	int maxSize, length;
public:
	//Constructors
	Stack() {maxSize = -1; length = 0;};
	Stack(int maxLength) {maxSize = maxLength; length = 0;};

	//Push new element to top of the stack
	int push(T element) {
		if(maxSize == -1) {
			stack.addElement(element, 0);
			length++;
			return 1;
		}else if(maxSize - length > 0) {
			stack.addElement(element, 0);
			length++;
			return 1;
		}else{
			return 0;
		}
	};

	//Pop an element from the top of the stack
	int pop() {
		if(length > 0) {
			stack.removeElement(0);
			length--;
			return 1;
		}else{
			return 0;
		}
	};

	//Get the value from the top element of the stack
	T peek() {return stack.getElement(0)->content;};

	//Check if the stack is full
	bool isFull() {
		if(maxSize == -1) {
			return 0;
		}else if(maxSize - length > 0) {
			return 0;
		}else{
			return 1;
		}
	};

	//Check if the stack is empty
	bool isEmpty() {
		if(length == 0) {return 1;}else{return 0;}
	};
};