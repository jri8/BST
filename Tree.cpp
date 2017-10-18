//#include "Tree.h";
//#include <stdlib.h>
//#include <iostream>
//
//using std::cout;
//using std::endl;
//
//
//
//
////template<typename T>
////void Tree<T>::insert(const T & elem)
////{
////	insert(root, elem);
////}
//
//
//template <typename T>
//void Tree<T>::insert(Node<T>*& x, const T& elem)
//{
//	if (x == NULL)
//	{
//		x = new Node<T>(elem);
//		//insert new node
//	}
//
//	if (elem < x->val)
//	{
//		insert(x->left, elem);
//	}
//	else if (elem > x->val)
//	{
//		insert((x->right), elem);
//	}
//
//
//}
//
//template <typename T>
//int Tree<T>::height(Node<T> *& x, const T& rhsObj, int count)
//{
//	if (x == NULL)
//	{
//		return -1;
//	}
//
//	else if (x->val == rhsObj)
//	{
//		return count;
//	}
//
//	else if (rhsObj < x->val)
//	{
//		count++;
//		height(x->left, rhsObj, count);
//	}
//
//	else
//	{
//		count++;
//		height(x->right, rhsObj, count);
//	}
//
//}
//
//template <typename T>
//void Tree<T>::printInOrder(Node<T>*& x)
//{
//	if (x == NULL)
//	{
//
//	}
//	else
//	{
//		printInOrder(x->left);
//
//		cout << x->val << " ";
//
//		printInOrder(x->right);
//	}
//	
//}
//
//template <typename T>
//void Tree<T>::printPostOrder(Node<T>*& x)
//{
//	if (x == NULL)
//	{
//		
//	}
//	else
//	{
//		printPostOrder(x->left);
//		printPostOrder(x->right);
//
//		cout << x->val << " ";
//	}
//}
//
//
//template <typename T>
//void Tree<T>::printPreOrder(Node<T>*& x) //fix this
//{
//	if (x == NULL)
//	{
//
//	}
//	else
//	{
//		cout << x->val << " ";
//		
//		printPreOrder(x->left);
//		printPreOrder(x->right);
//	}
//}
//
//
//template <typename T>
//bool Tree<T>::find(const T &rhsObj)
//{
//	int inList = 0;
//	inList = height(root, rhsObj, 0);
//	if (inList == -1)
//		return false;
//	else
//		return true;
//}
//
//template <typename T>
//void Tree<T>::remove(const T &rhsObj, Node<T>*& x)
//{
//	if (x == NULL)
//	{
//
//	}
//	else
//	{
//		if (rhsObj < x->val)
//		{
//			remove(rhsObj, x->left);
//		}
//
//		else if (rhsObj > x->val)
//		{
//			remove(rhsObj, x->right);
//		}
//
//		else if (x->left != NULL && x->right != NULL)
//		{
//			Node<T>* swap = x->left;
//			if (swap != NULL)
//			{
//				while (swap->right != NULL)
//					swap = swap->right;
//			}
//			x->val = swap->val;
//			remove(x->val, x->left);
//		}
//
//		else
//		{
//			Node<T> *old = x;
//			if (x->left != NULL)
//				x = x->left;
//			else
//				x = x->right;
//			delete old;
//		}
//	}
//
//
//}
//
//template <typename T>
//void Tree<T>::deleteAll(Node<T>*& x)
//{
//	if (x != NULL)
//	{
//		deleteAll(x->left);
//		deleteAll(x->right);
//
//		delete x;
//	}
//	x = NULL;
//}
//
//
//
