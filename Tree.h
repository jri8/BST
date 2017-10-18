
#pragma once

#include "Node.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;


template <class T>
class Tree
{
private:


	void insert(Node<T>*&, const T&);

	int height(Node<T>*& x); //returns height given specific node
	void printInOrder(Node<T>*& x); //prints tree in order
	void printPreOrder(Node<T>*& x); //prints tree in pre order
	void printPostOrder(Node<T>*& x); //prints tree in post order
	bool find(Node<T>*& x, const T &rhsObj); //returns true if given value is in the tree
	void remove(const T &rhsObj, Node<T>*& x); //will remove the given value from the tree

public:
	Tree() { root = NULL; } //default constructor

	~Tree() { deleteAll(root); } //destructor





	Node<T> *root; //root variable points to top node in the tree


	void insert(const T& elem) { insert(root, elem); } //inserts given variable into tree in order


	int height(const T &rhsObj); //returns the height of a given value in tree
	int height() { return height(root); } //returns height of entire tree


	void printInOrder() { printInOrder(root); } //wrapper function prints the tree with in order
	void printPostOrder() { printPostOrder(root); } //wrapper function prints the tree in post order fashion
	void printPreOrder() { printPreOrder(root); } //wrapper function prints the tree with in pre order fashion

	bool find(const T &rhsObj) { return find(root, rhsObj); } //wrapper function returns true if given node is in tree

	void remove(const T &rhsObj) { remove(rhsObj, root); } //wrapper function removes given value from tree
	void deleteAll(Node<T>*& x); //wrapper function deletes all the nodes in the tree




};



template <typename T>
void Tree<T>::insert(Node<T>*& x, const T& elem)
{
	if (x == NULL) //if x points to NULL
	{
		//create a new node and have x point to it
		x = new Node<T>(elem);
		//cout << elem << " has been inserted" << endl;
		//outputting if element inserted for debugging
		//not practical for huge data sets
	}
	else if (x->val > elem) //if element to insert is smaller than x
	{
		insert(x->left, elem); //traverse left sub tree
	}
	else if (x->val < elem) //if element to insert is larger than x 
	{
		insert((x->right), elem); //traverse right sub tree
	}
	else //element is in the list
	{
		cout << elem << " already in list!" << endl; //output
	}


}

template <typename T>
int Tree<T>::height(const T& rhsObj)
{
	Node<T> *x = root; //creating temp pointer

	while (x->val != rhsObj) //iteratively moving through tree to find node to get height of
	{
		if (x->val < rhsObj)
			x = x->right;
		else
			x = x->left;
	}

	return height(x); //calling recursive height function below
}


template <typename T>
int Tree<T>::height(Node<T> *& x)
{
	if (x == NULL) //if tree is empty
	{
		return -1;
	}
	else
	{
		return max(height(x->left), height(x->right)) + 1; //return the bigger of the two subtrees
	}
}







template <typename T>
void Tree<T>::printInOrder(Node<T>*& x)
{
	if (x == NULL)
	{

	}
	else
	{
		printInOrder(x->left); //traverses left subtree

		cout << x->val << " "; //prints stored value

		printInOrder(x->right); //traverses right subtree
	}

}

template <typename T>
void Tree<T>::printPostOrder(Node<T>*& x)
{
	if (x == NULL)
	{

	}
	else
	{
		printPostOrder(x->left); //traverses left subtree
		printPostOrder(x->right); //traverses right subtree

		cout << x->val << " "; //prints value
	}
}


template <typename T>
void Tree<T>::printPreOrder(Node<T>*& x) //fix this
{

	if (x == NULL)
	{

	}
	else
	{
		cout << x->val << " "; //prints value

		printPreOrder(x->left); //traverses left subtree
		printPreOrder(x->right); //traverses right subtree
	}
}


template <typename T>
bool Tree<T>::find(Node<T>*& x, const T &rhsObj)
{
	if (x == NULL) //if x points to nothing
	{
		return false;
	}
	else if (x->val == rhsObj) //if value is found in tree
	{
		return true;
	}
	else if (x->val > rhsObj) //if value is smaller than current location
	{
		find(x->left, rhsObj); //traverse left subtree
	}
	else //if value is larger than current location
	{
		find(x->right, rhsObj); //traverse right subtree
	}
}







template <typename T>
void Tree<T>::remove(const T &rhsObj, Node<T>*& x)
{
	if (x == NULL) //if x points to nothing
	{
		//do nothing
	}
	else
	{
		if (x->val > rhsObj) //if value at x is greater than value to delete
		{
			remove(rhsObj, x->left); //traverse left subtree
		}

		else if (x->val < rhsObj)//if value at x is less than value to delete
		{
			remove(rhsObj, x->right); //traverse right subtree
		}

		else if (x->left != NULL && x->right != NULL) //if x has two child nodes
		{
			Node<T>* swap = x->left; //temporary pointer swap
			if (swap != NULL) //if swap is not empty
			{
				while (swap->right != NULL) //traverse right subtree
					swap = swap->right;
			}
			x->val = swap->val; //swap values
			remove(swap->val, x->left); //remove swap from tree
		}

		else //if x has one or less child nodes
		{
			Node<T> *old = x;
			if (x->left != NULL) //change values with whichever is not NULL
				x = x->left;
			else
				x = x->right;

			//cout << "value has been removed from Tree" << endl;
			//outputting if element removed for debugging
			//not practical for huge data sets
			delete old;
		}
	}


}

template <typename T>
void Tree<T>::deleteAll(Node<T>*& x)
{
	if (x != NULL) //if x is pointing to something
	{
		deleteAll(x->left);  //pre order call to delete
		deleteAll(x->right);

		delete x; //delete x
	}
	x = NULL;
}

