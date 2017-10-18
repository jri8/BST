
#pragma once
#include <stdio.h>


template <class T>
class Node  //convert to template
{


private:




public:

	Node() { val = 0; right = NULL; left = NULL; } //default constructor
	Node(T n) { val = n; right = NULL; left = NULL; } //overloaded constructor

	Node<T>(Node<T> &n) { this = &n; } //copy constructor calls overloaded equals operator

	~Node() {   } //destructor (empty)

	T val; //stores the value to be held in the node 

	Node<T> *right; //points to the node on the right
	Node<T>* left;  //points to node on the left


	bool operator>(const Node<T>* &rhsobj); //overloaded > operator
	bool operator<(const Node<T>* &rhsobj); //overloaded < operator
	bool operator==(const Node<T>* &rhsobj); //overloaded == operator
	bool operator!=(const Node<T>* &rhsobj); //overloaded != operator
	Node<T> operator=(const Node<T> &rhsobj); //overloaded = operator

};




//below are all the implementations of the overloaded operators

template<typename T>
bool Node<T>::operator>(const Node<T>* &rhsobj)
{
	if (this->val > rhsobj->val)
		return true;
	else
		return false;
}


template<typename T>
bool Node<T>::operator<(const Node<T>* &rhsobj)
{
	if (this->val < rhsobj->val)
		return true;
	else
		return false;
}


template<typename T>
bool Node<T>::operator==(const Node<T>* &rhsobj)
{
	if (this->val == rhsobj->val)
		return true;
	else
		return false;
}

template<typename T>
bool Node<T>::operator!=(const Node<T>* &rhsobj)
{
	if (this->val != rhsobj->val)
		return true;
	else
		return false;
}

template<typename T>
Node<T> Node<T>::operator=(const Node<T> &rhsobj)
{
	this->val = n.val;
	this->left = n.left;
	this->right = n.right;
}
