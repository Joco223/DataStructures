#pragma once

namespace jci {
	template<typename T>
	class Array {
	private:
		T* data;
		int length;
		int reserved;
	public:
		//Constructors
		Array() {data = nullptr; length = 0; reserved = 0;}
		//Param input -> elements to be added
		Array(std::initializer_list<T> input) {
			data = new T[input.size()];
			length = input.size();
			reserved = input.size();
			int i = 0;
			for(auto item : input) {
				data[i] = item;
				i++;
			}
		}

		//Deconstructor
		~Array() {delete[] data;}

		//[] operator, returns the element at pos
		T operator[](int pos) {return data[pos];}

		//Returns the element at pos if the pos is in the bounds of the array
		T at(int pos) {if(pos >= 0 && pos < length) {return data[pos];}else{throw std::out_of_range("Invalid index: " + pos);}}

		//Adds element to the front of the array
		void addElementFront(T element) {
			if(length + 1 <= reserved) {
				T* newData = new T[length+1];
				newData[0] = element;
				memcpy(newData+1, data, length*sizeof(T));
				length++;
				delete[] data;
				data = newData;
			}else{
				reserved++;
				T* newData = new T[length+1];
				newData[0] = element;
				memcpy(newData+1, data, length*sizeof(T));
				length++;
				delete[] data;
				data = newData;
			}
		}

		//Add element to the back of the array
		void addElementBack(T element) {			
			if(length + 1 <= reserved) {
				data[length] = element;
				length++;
			}else{
				if(reserved == 0) {reserved++;}
				reserved = reserved*2;
				T* newData = new T[reserved];
				memcpy(newData, data, length*sizeof(T));
				newData[length] = element;
				length++;
				delete[] data;
				data = newData;
			}		
		}

		//Add element to some position in the array
		void addElement(T element, int pos) {
			if(length + 1 <= reserved) {
				memcpy(data+pos+1, data+pos, (length-pos)*sizeof(T));
				data[pos] = element;
				length++;
			}else{
				if(reserved == 0) {reserved++;}
				reserved = reserved*2;
				T* newData = new T[reserved];
				memcpy(newData, data, pos*sizeof(T));
				newData[pos] = element;
				memcpy(newData+pos+1, data+pos, (length-pos)*sizeof(T));
				length++;
				delete[] data;
				data = newData;
			}
		}

		//Removes first element of the array
		void removeFrontElement() {
			if(length > 0) {
				if(length - 1 <= reserved && length - 1 >= reserved/2) {
					memcpy(data, data+1, (length-1)*sizeof(T));
					length--;
				}else{		
					reserved = reserved / 2;
					T* newData = new T[reserved];
					memcpy(newData, data+1, (length-1)*sizeof(T));
					length--;		
					delete data;
					data = newData;
				}
			}	
		}

		//Removes last element of the array
		void removeBackElement() {
			if(length > 0) {
				if(length - 1 <= reserved && length - 1 >= reserved/2) {
					data[length] = 0;
					length--;
				}else{
					reserved = reserved / 2;
					T* newData = new T[reserved];
					memcpy(newData, data, (length-1)*sizeof(T));
					length--;
					delete[] data;
					data = newData;
				}
			}
		}

		//Remove element from pos from the array
		void removeElement(int pos) {
			if(length > 0) {
				if(length - 1 <= reserved && length - 1 >= reserved/2) {
					memcpy(data+pos, data+pos+1, (length-1-pos)*sizeof(T));
					length--;
				}else{
					reserved = reserved / 2;
					T* newData = new T[reserved];
					memcpy(newData, data, pos*sizeof(T));
					memcpy(newData+pos, data+pos+1, (length-1-pos)*sizeof(T));
					length--;
					delete[] data;
					data = newData;
				}
			}
		}

		//Applies a function to all elements of the array
		void applyFunction(T f(T)) {
			for(int i = 0; i < length; i++) {
				data[i] = f(data[i]);
			}
		}

		//Removes elements that return false on the given function
		void filterFunction(bool f(T)) {
			bool* tempData = new bool[length];
			for(int i = 0; i < length; i++) {
				tempData[i] = f(data[i]);
			}
			int oldLength = length;
			int offset = 0;
			for(int i = 0; i < oldLength; i++) {
				if(tempData[i] == 0) {
					removeElement(i - offset);
					offset++;
				}
			}
			delete[] tempData;
		}

		//Prints the contents of the array
		void print() {
			for(int i = 0; i < length; i++) {
				std::cout << data[i] << " ";
			}
			std::cout << '\n';
		}
	};
}