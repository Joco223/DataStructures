#include <iostream>

template<class T>
class LinkedList {
private:
	struct Link {
		T content;
		Link* next;
		Link(T t, Link* l) {content = t; next = l;};
	};
	Link* first;
	int length;
public:

	//Constructor without parameters
	LinkedList() {
		first = nullptr;
		length = 0;
	}

	//Constructor, create a linked list with given elements
	LinkedList(std::initializer_list<T> input) {
		first = nullptr;
		length = 0;
		for(auto item = std::rbegin(input); item != std::rend(input); ++item) {
			Link* current = new Link(*item, nullptr);
			current->content = *item;
			current->next = first;
			first = current;
			length++;
		}	
	};

	//Get pointer to first element
	Link* getFirst() {return first;}

	//Get the length of the linked list
	int getLength() {return length;}

	//Add a new element after the target position to the linked list
	void addElement(T element, int targetPos) {
		int i = 0;
		Link* target = first;
		Link* prev = nullptr;
		while(i < targetPos) {
			if(prev == nullptr) {prev = first;}else{prev = prev->next;}
			target = target->next;
			i++;
		}
		Link* current = new Link(element, nullptr);
		current->content = element;
		current->next = target;
		if(prev != nullptr) {prev->next = current;}
		if(i == 0) {first = current;}
		length++;
	}

	//Remove an element from the target position from the linked list
	void removeElement(int targetPos) {
		int i = 0;
		Link* target = first;
		Link* prev = nullptr;
		while(i < targetPos) {
			if(prev == nullptr) {prev = first;}else{prev = prev->next;}
			target = target->next;
			i++;
		}
		if(i == 0) {first = first->next;}else{prev->next = target->next;}
	}

	//Apply a function to all elements of the linked list
	void applyFunction(T f(T)) {
		Link* current;
		while(current != nullptr) {
			current->content = f(current->content);
			current = current->next;
		}
	}

	//Apply a function to pairs of elements from two linked lists
	static LinkedList<T> applyFunctionToPairs(LinkedList<T> A, LinkedList<T> B, T f(T, T)) {
		LinkedList<T> newLL;
		Link* currentA = A.first;
		Link* currentB = B.first;
		while(currentA != nullptr || currentB != nullptr) {
			newLL.addElement(f(currentA->content, currentB->content), newLL.getLength());
			currentA = currentA->next;
			currentB = currentB->next;
		}
		return newLL;
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