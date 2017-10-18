
#include "Tree.h"
#include "Node.h"
#include "Struct.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
void Load(string, Tree<T> &); //Loads the data from file into a BST

int main(int argc, const char * argv[])
{
	string fname; //file name taken from command line
	fname = argv[1];


	//three different binary search trees
	Tree<INT> intBST;	//binary search tree for ints
	Tree<CHAR> charBST; //binary search tree for c style strings
	

	//when changing data types, change which tree is loadeds
	Load(fname, intBST);
	

	//When input type from file changes, make sure to load data into correct Tree
	//Load(fname, intBST);

	//outputs when using the int tree
	cout << "Printing Tree in order:" << endl;
	intBST.printInOrder();
	cout << endl;
	cout << "Printing Tree in post order:" << endl;
	intBST.printPostOrder();
	cout << endl;
	cout << "Printing Tree in pre order: " << endl;
	intBST.printPreOrder();
	cout << endl;
	cout << "Height of the tree: " << endl;
	cout << intBST.height() << endl;
	//intBST.remove(<INT struct obj>);
	//intBST.printInOrder();
	//cout << endl;
	
	//outputs when using the char tree
	//cout << "Printing Tree in order:" << endl;
	//charBST.printInOrder();
	//cout << endl;
	//cout << "Printing Tree in post order:" << endl;
	//charBST.printPostOrder();
	//cout << endl;
	//cout << "Printing Tree in pre order: " << endl;
	//charBST.printPreOrder();
	//cout << endl;
	//cout << "Height of the tree: " << endl;
	//cout << charBST.height() << endl;
	//charBST.remove(<CHAR struct obj>);
	//charBST.printInOrder();
	//cout << endl;









	cin.get();  //for keeping window open in visual studio
	return 0;
}





template <typename T>
void Load(string filename, Tree<T> &bst)
{
	ifstream inFileStream;
	T input;

	inFileStream.open(filename);

	if (!inFileStream) //checking if file opened
	{
		cout << "The input file failed to open. ";
		cout << "Check to ensure the file:\n" << filename << "\nis valid." << endl;
	}

	else //if file opened
	{
		while (inFileStream >> input)
		{
			bst.insert(input);
		}
	}

	inFileStream.close();
}