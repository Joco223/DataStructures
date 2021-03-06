#pragma once

#include <functional>
#include <iostream>

namespace jci {
	template<typename T>
	class BinaryTree {
	private:
		struct Node {
			Node* parent;
			T content;
			Node* left;
			Node* right;
		};
		Node* root;
		std::function<bool(T, T)> comparison;

		//Recursive delete function
		//Param branch -> branch to delete from downwards
		void delete_branch(Node* branch) {
			if(branch != nullptr) {
				delete_branch(branch->left);
				delete_branch(branch->right);
				delete branch;
				branch = nullptr;
			}	
		};

		//Recursive insert function
		//Param item -> element to be addded
		//Param branch -> current branch being check if it fits the new element
		void insert(T item, Node* branch) {
			if(comparison(item, branch->content)) {
				if(branch->left == nullptr) {
					branch->left = new Node;
					branch->left->parent = branch;
					branch->left->content = item;
					branch->left->left = nullptr;
					branch->left->right = nullptr;
				}else{
					insert(item, branch->left);
				}
			}else{
				if(branch->right == nullptr) {
					branch->right = new Node;
					branch->right->parent = branch;
					branch->right->content = item;
					branch->right->left = nullptr;
					branch->right->right = nullptr;
				}else{
					insert(item, branch->right);
				}
			}
		};

		//Recursive search function
		//Param item -> element to be searched for
		//Param branch -> current branch where the element is being searched for
		//Param f -> function to compare the element to the rest of the tree
		//Returns nullptr if the element is not found, pointer to its branch otherwise
		Node* search(T item, Node* branch, bool f(T, T)) {
			if(branch == nullptr) {
				return nullptr;
			}else{
				if(f(item, branch->content)) {
					return branch;
				}else if(comparison(item, branch->content)) {
					return search(item, branch->left, f);
				}else{
					return search(item, branch->right, f);
				}
			}
		};

		//Recursive print function
		//Param branch -> branch to print from downwards
		void print(Node* branch) {
			if(branch != nullptr) {
				if(branch->parent != nullptr) {std::cout << "Parent: " << branch->parent->content;}else{std::cout << "Parent: Null";}
				std::cout << '\n' << "Branch: " << branch->content << '\n';
				if(branch->left != nullptr) {std::cout << "Left: " << branch->left->content << ", ";}else{std::cout << "Left: Null, ";}
				if(branch->right != nullptr) {std::cout << "Right: " << branch->right->content;}else{std::cout << "Right: Null";}
				std::cout << '\n' << '\n';
				print(branch->left);
				print(branch->right);
			}	
		}

	public:
		//Constructors
		//Param f -> function used to compare elements
		BinaryTree(bool f(T, T)) {root = nullptr; comparison = f;};

		//Param input -> elements to be added
		//Param f -> function used to compare elements
		BinaryTree(std::initializer_list<T> input, bool f(T, T)) {
			root = nullptr;
			comparison = f;
			for(T item : input) {
				if(root == nullptr) {
					root = new Node;
					root->parent = nullptr;
					root->content = item;
					root->left = nullptr;
					root->right = nullptr;
				}else{
					insert(item, root);
				}
			}
		};

		//Deconstructor
		~BinaryTree() {delete_branch(root);}

		//Recursive insert caller
		//Param item -> element to be added
		void insert(T item) {
			if(root == nullptr) {
				root = new Node;
				root->parent = nullptr;
				root->content = item;
				root->left = nullptr;
				root->right = nullptr;
			}else{
				insert(item, root);
			}
		};

		//Recursive search caller
		//Param item -> element to be searched for
		//Param f -> function to compare it with the rest of the tree
		Node* search(T item, bool f(T, T)) {search(item, root, f);}

		//Recursive print caller
		void print() {print(root);}
	};
}