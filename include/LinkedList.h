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

	//Add a new element at the target position to the linked list
	void addElement(T element, int targetPos) {
		int id = 0;
		Link* target = first;
		while(id != targetPos-2) {
			target = target->next;
			id++;
		}
		Link* current = new Link(element, nullptr);
		current->content = element;
		current->next = target->next;
		target->next = current;
		length++;
	}

	//Remove an element from the target position from the linked list
	void removeElement(int targetPos) {
		int id = 0;
		Link* target = first;
		Link* prev = nullptr;
		while(id != targetPos-1) {
			prev = target;
			target = target->next;
			id++;
		}
		prev->next = target->next;
	}

	//Print the contents of all elements of the linked list
	void print() {
		Link* current = first;
		while(current != nullptr) {
			std::cout << current->content << '\n';
			current = current->next;
		}
	};
};