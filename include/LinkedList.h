#pragma once

#include <iostream>
#include <vector>

template<class T>
class LinkedList {
public:
	struct Link;
private:
	Link* first;
	Link* last;
	int length;
public:
	struct Link {
		T content;
		Link* next;
		Link* last;
		Link() {next = nullptr; last = nullptr;};
		Link(T t, Link* n, Link* l) {content = t; next = n; last = l;};
	};

	//Constructor without parameters
	LinkedList() {
		first = nullptr;
		last = nullptr;
		length = 0;
	}

	//Constructor, create a linked list with given elements
	LinkedList(std::initializer_list<T> input) {
		first = nullptr;
		last = nullptr;
		length = 0;
		bool firstL = true;
		Link* prev = nullptr;
		for(auto item = std::rbegin(input); item != std::rend(input); ++item) {
			Link* current = new Link(*item, first, nullptr);
			if(prev != nullptr) {prev->last = current;}
			if(firstL) {last = current; firstL = false;}
			first = current;
			prev = current;
			length++;
		}
	};

	//Destructor
	~LinkedList() {
		Link* current = first;
		while(current != nullptr) {
			Link* tmp = current;
			current = current->next;
			delete tmp;
			length--;
		}
		first = nullptr;
		last = nullptr;
	};

	//Clears the whole linked list
	void clear() {
		Link* current = first;
		while(current != nullptr) {
			Link* tmp = current;
			current = current->next;
			delete tmp;
			length--;
		}
		first = nullptr;
		last = nullptr;
	};

	//Get pointer to first element
	Link* getFirst() {return first;}

	//Get the length of the linked list
	int getLength() {return length;}

	//Get first element
	Link* getElementFront() {
		return first;
	}

	//Get last element
	Link* getElementBack() {
		return last;
	}

	//Iterate an iterator trough the linked list
	Link* getElement(Link* it) {
		if(it == nullptr) {
			return first;
		}else{
			return it->next;
		}	
	}

	//Get a pointer to an element from target position from the linked list
	Link* getElement(int targetPos) {
		int i = 0;
		Link* target;
		if(targetPos < 0) {target = nullptr;}else{target = first;}
		if(targetPos == length-1) {
			target = last;
		}else{
			if(targetPos < length/2) {
				while(i < targetPos) {
					target = target->next;
					i++;
				}
			}else{
				while(i < targetPos) {
					target = target->last;
					i++;
				}
			}	
		}
		return target;
	}

	//Swap two elements in the linked list by indexes
	void swapElements(int targetPos1, int targetPos2) {
		int i = 0;
		Link* target = getElement(targetPos1);
		Link* target2 = getElement(targetPos2);
		T temp = target->content;
		target->content = target2->content;
		target2->content = temp;
	}

	//Swap two elements in the linked list by pointers
	void swapElements(Link* targetPos1, Link* targetPos2) {
		T temp = targetPos1->content;
		targetPos1->content = targetPos2->content;
		targetPos2->content = temp;
	}

	//Reverse the elements in the linked list
	void reverseElements() {
		Link* fCurrent = first;
		Link* lCurrent = last;

		int half = length/2;
		int i = 0;
		while(i < half) {
			swapElements(fCurrent, lCurrent);
			fCurrent = fCurrent->next;
			lCurrent = lCurrent->last;
			i++;
		}
		
	}

	//Sort elements in the linked list using bubble sort
	void sort(bool f(T, T)) {
		for(int i = 0; i < length-1; i++){
			for(int j = 0; j < length-i-1; j++){
				Link* current = getElement(j);
				Link* next = getElement(j+1);
				if(current != nullptr && next != nullptr) {
					if(f(current->content, next->content)) {
						swapElements(current, next);
					} 
				}
			}
		}
	}

	//Connect ends of to lists
	static LinkedList<T> connect(LinkedList<T>& A, LinkedList<T>& B) {
		LinkedList<T> newLL;
		int offset = 0;
		Link* AL = A.first;
		Link* BL = B.first;
		while(AL != nullptr) {newLL.addElementBack(AL->content); AL = AL->next;}
		while(BL != nullptr) {newLL.addElementBack(BL->content); BL = BL->next;}
		return newLL;
	}

	//Add a new element to the front of the linked list
	void addElementFront(T element) {
		Link* node = new Link(element, first);
		if(first == nullptr) {last = node;}
		first = node;
		length++;
	}

	//Add a new element to the front of the linked list
	void addElementBack(T element) {
		Link* node = new Link(element, nullptr, last);
		if(last != nullptr) {last->next = node; node->last = last;}
		if(first == nullptr) {first = node;}
		last = node;
		length++;
	}

	//Add a new element after the target position to the linked list
	void addElement(T element, int targetPos) {
		Link* prev = getElement(targetPos-1);
		Link* target = prev->next;
		Link* current = new Link(element, target, prev);
		if(prev != nullptr) {prev->next = current;}
		if(targetPos == 0) {first = current;}
		if(targetPos == length-1) {last = current;}
		length++;
	}

	//Remove last element from the linked list
	void removeElementBack() {
		last = last->prev; 
		last->next = nullptr;
	}

	//Remove the first element from the list
	void removeElementFront() {
		first = first->next;
	}

	//Remove an element from the target position from the linked list
	void removeElement(int targetPos) {
		Link* prev = getElement(targetPos-1);
		Link* target = prev->next;
		if(targetPos == 0) {
			first = first->next;
		}else{
			prev->next = target->next;
		}
		if(targetPos == length-1) {
			last = prev; prev->next = nullptr;
		}
		length--;
	}

	//Remove an element from the linked list
	void removeElement(Link* target) {
		Link* prev = target->last;
		if(prev == nullptr) {
			first = first->next;
		}else{
			prev->next = target->next;
		}
		if(prev == last) {
			last = prev; 
			prev->next = nullptr;
		}
		length--;
	}

	//Apply a function to all elements of the linked list
	void applyFunction(T f(T)) {
		Link* current = first;
		while(current != nullptr) {
			current->content = f(current->content);
			current = current->next;
		}
	}

	//Apply a function to all elements of the linked list and remove ones that return false
	void filterFunction(bool f(T)) {
		Link* current = first;
		while(current != nullptr) {
			bool result = f(current->content);
			if(!result) {removeElement(current);}
			current = current->next;		
		}
	}

	//Apply a function to pairs of elements from two linked lists
	static LinkedList<T> pairs(LinkedList<T>& A, LinkedList<T>& B, T f(T, T)) {
		LinkedList<T> newLL;
		Link* currentA = A.first;
		Link* currentB = B.first;
		while(currentA != nullptr || currentB != nullptr) { 
			newLL.addElementFront(f(currentA->content, currentB->content));
			currentA = currentA->next;
			currentB = currentB->next;
		}
		return newLL;
	}

	//Remove duplicates from sequences in the linked list
	void unique_seq(bool f(T, T)) {
		Link* prev = nullptr;
		Link* current = first;
		while(current != nullptr) {
			Link* temp = current->next;
			if(temp != nullptr) {
				while(f(temp->content, current->content)) {
					removeElement(temp);
				}
				temp = temp->next;
			}
			prev = current;
			current = current->next;
		}
	}

	//Remove duplicates from the linked list
	void unique(bool f(T, T)) {
		std::vector<T> seen;
		Link* current = first;
		while(current != nullptr) {
			bool exists = false;
			for(auto v : seen) {
				if(f(current->content, v)) {exists = true; break;}
			}
			if(exists) {
				removeElement(current);
			}else{
				seen.push_back(current->content);
			}
			current = current->next;
		}
	}

	//Find if element exists in the linked list
	bool exists(T x, bool f(T, T)) {
		bool exists = false;
		Link* current = first;
		while(current != nullptr) {
			if(f(x, current->content)) {exists = true; break;}
			current = current->next;
		}
		return exists;
	}

	//Print all of the elements of the linked list
	void print() {
		Link* current = first;
		while(current != nullptr) {
			std::cout << current->content << '\n';
			current = current->next;
		}
	};
};