/////////////////////////////////////////////////////////////////////
//			BST CLASS
/////////////////////////////////////////////////////////////////////
// BST.h
////////////////////////////////////////////

#ifndef BST_H
#define BST_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Node.h"
#include "FileStorage.h"
#include "FriendInfo.h"
using namespace std;

template < class T >
class BST
{
private:
	// SORT TYPE
	int sortType;

	// ROOT POINTER
	Node<T>* root;

	// FILE IO HELPER
	FileStorage<T> FIO;

	// BST PRIVATE STANDARD FUNCTIONS 
	void insert(Node<T>*&, Node<T>*&);
	void deleteSubTree(Node<T>*);
	void deleteNode(T, Node<T>*&);
	void makeDeletion(Node<T>*&);

	// BST PRIVATE DISPLAY FUNCTIONS 
	void inOrder(Node<T>*) const;
	void preOrder(Node<T>*) const;
	void postOrder(Node<T>*) const;
	void printLevelOrder(Node<T>*) const;
	void printGivenLevel(Node<T>*, int) const;
	int height(Node<T>*) const;

	// BST SAVE DISPLAY FUNCTIONS 
	void saveInOrder(Node<T>*) const;
	void savePreOrder(Node<T>*) const;
	void savePostOrder(Node<T>*);
	void saveLevelOrder(Node<T>*);
	void saveGivenLevel(Node<T>*, int);

public:
	// BST CONSTRUCTORS
	BST();
	~BST();

	// BST STANDARD FUNCTIONS 
	bool isEmpty();
	void insertNode(T);
	void remove(T);
	bool search(T);
	void removeAll();

	// BST DISPLAY FUNCTIONS
	void printInOrder();
	void printPreOrder();
	void printPostOrder();
	void breadthDisplay();

	// TREE SAVE FUNCTIONS
	void saveInOrder();
	void savePostOrder();
	void savePreOrder();
	void breadthSave();

	// COMPARE FUNCTIONS
	bool compareFriends(const FriendInfo&, const FriendInfo&);
	bool equalMembers(FriendInfo&, FriendInfo&);
	void changeSortType(int);
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//		FUNCTION DEFINITIONS
////////////////////////////////////////////

////////////////////////////////////////////
// BST CONSTRUCTOR
////////////////////////////////////////////
template < class T >
BST<T>::BST()
{
	root = NULL;
}

template < class T >
BST<T>::~BST()
{
	deleteSubTree(root);
}

////////////////////////////////////////////
// BST STANDARD FUNCTIONS
////////////////////////////////////////////

template < class T >
bool BST<T>::isEmpty()
{
	bool status;
	if (!root)
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}

template <class T>
void BST<T>::insertNode(T obj)
{
	Node<T>* newPtr = new Node<T>;

	newPtr->data = obj;
	newPtr->left = NULL;
	newPtr->right = NULL;

	insert(root, newPtr);
}

template < class T >
void BST<T>::insert(Node<T>*& currPtr, Node<T>*& newPtr)
{
	if (currPtr == NULL)
		currPtr = newPtr;
	//else if (newPtr->data < currPtr->data)
	else if (compareFriends(newPtr->data, currPtr->data))
		insert(currPtr->left, newPtr);
	else
		insert(currPtr->right, newPtr);
}

template < class T >
void BST<T>::remove(T obj)
{
	deleteNode(obj, root);
}

template < class T >
void BST<T>::deleteNode(T obj, Node<T>*& currPtr)
{
	//if (obj < currPtr->data)
	if (equalMembers(obj, currPtr->data) == true)
		makeDeletion(currPtr);
	else if (compareFriends(obj, currPtr->data))
		deleteNode(obj, currPtr->left);
	else if (compareFriends(currPtr->data, obj))
		deleteNode(obj, currPtr->right);
	else
	{
		cout << "compared succesffully, deleting" << endl;
		makeDeletion(currPtr);
	}
}

template < class T >
void BST<T>::makeDeletion(Node<T>*& currPtr)
{
	Node<T>* tempNode;

	if (currPtr == NULL)
		cout << "Node is already Empty" << endl;
	else if (currPtr->right == NULL)
	{
	//	cout << "currptr->right == NULL" << endl;
		tempNode = currPtr;
		currPtr = currPtr->left;
		delete tempNode;
	}
	else if (currPtr->left == NULL)
	{
	//	cout << "currptr->left == NULL" << endl;
		tempNode = currPtr;
		currPtr = currPtr->right;
		delete tempNode;
	}
	else
	{
	//	cout << "else" << endl;
		tempNode = currPtr->right;
		while (tempNode->left)
			tempNode = tempNode->left;
		tempNode->left = currPtr->left;
		tempNode = currPtr;

		currPtr = currPtr->right;
		delete tempNode;
	}
}

template < class T >
void BST<T>::removeAll()
{
	deleteSubTree(root);
}

template < class T >
void BST<T>::deleteSubTree(Node<T>* currPtr)
{
	if (currPtr != NULL)
	{
		if (currPtr->left)
			deleteSubTree(currPtr->left);
		if (currPtr->right)
			deleteSubTree(currPtr->right);
		delete currPtr;
	}
}

template < class T >
bool BST<T>::search(T obj)
{
	Node<T>* currPtr = root;

	while (currPtr)
	{
		if (equalMembers(obj, currPtr->data))
			return true;
		else if (compareFriends(obj, currPtr->data))
			currPtr = currPtr->left;
		else
			currPtr = currPtr->right;
	}
	return false;
}


////////////////////////////////////////////
// BST DISPLAY FUNCTIONS
////////////////////////////////////////////

template < class T >
void BST<T>::printInOrder()
{
	inOrder(root);
}

template < class T >
void BST<T>::inOrder(Node<T>* ptr) const
{
	cout << endl << endl;
	if (ptr != NULL)
	{
		inOrder(ptr->left);
		cout << ptr->data;
		inOrder(ptr->right);
	}
}

template < class T >
void BST<T>::printPreOrder()
{
	preOrder(root);
}

template < class T >
void BST<T>::preOrder(Node<T>* ptr) const
{
	if (ptr != NULL)
	{
		cout << ptr->data << endl;
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}

template < class T >
void BST<T>::printPostOrder()
{
	postOrder(root);
}

template < class T >
void BST<T>::postOrder(Node<T>* ptr) const
{
	if (ptr != NULL)
	{
		postOrder(ptr->left);
		postOrder(ptr->right);
		cout << ptr->data << endl;
	}
}

template <class T>
void BST<T>::breadthDisplay()
{
	printLevelOrder(root);
}


template < class T >
void BST<T>::printLevelOrder(Node<T>* ptr) const
{
	int h;
	h = height(ptr);
	for (int i = 1; i <= h; i++)
	{
		printGivenLevel(ptr, i);
	}
}

template < class T >
void BST<T>::printGivenLevel(Node<T>* ptr, int level) const
{
	if (ptr == NULL)
	{
		return;
	}
	if (level == 1){
		cout << ptr->data << endl;
	}
	else if (level > 1)
	{
		printGivenLevel(ptr->left, level - 1);
		printGivenLevel(ptr->right, level - 1);
	}
}

template < class T >
int BST<T>::height(Node<T>* node) const
{
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight)
		{
			return (lheight + 1);
		}
		else
		{
			return(rheight + 1);
		}
	}
}

////////////////////////////////////////////
// BST SAVE FUNCTIONS
////////////////////////////////////////////

template < class T >
void BST<T>::saveInOrder()
{
	saveInOrder(root);
}

template < class T >
void BST<T>::saveInOrder(Node<T>* ptr) const
{
	if (ptr != NULL)
	{
		FIO.changeOutputName("InOrderSort.txt");
		FIO.writeToFile(ptr->data);
		saveInOrder(ptr->left);
		saveInOrder(ptr->right);
	}
}

template < class T >
void BST<T>::savePreOrder()
{
	savePreOrder(root);
}

template < class T >
void BST<T>::savePreOrder(Node<T>* ptr) const
{
	if (ptr != NULL)
	{
		FIO.changeOutputName("PreOrderSort.txt");
		FIO.writeToFile(ptr->data);
		savePreOrder(ptr->left);
		savePreOrder(ptr->right);
	}
}

template < class T >
void BST<T>::savePostOrder()
{
	FIO.changeOutputName("LastNameSort.txt");
	FIO.deleteContents();
	savePostOrder(root);
}

template < class T >
void BST<T>::savePostOrder(Node<T>* ptr)
{
	if (ptr != NULL)
	{
		savePostOrder(ptr->left);
		savePostOrder(ptr->right);
		FIO.writeToFile(ptr->data);
	}
}

template <class T>
void BST<T>::breadthSave()
{
	saveLevelOrder(root);
}


template < class T >
void BST<T>::saveLevelOrder(Node<T>* ptr)
{
	FIO.changeOutputName("BirthdaySort.txt");
	FIO.deleteContents();

	int h;
	h = height(ptr);
	for (int i = 1; i <= h; i++)
	{
		saveGivenLevel(ptr, i);
	}
}

template < class T >
void BST<T>::saveGivenLevel(Node<T>* ptr, int level)
{
	if (ptr == NULL)
	{
		return;
	}
	if (level == 1){
		FIO.writeToFile(ptr->data);
	}
	else if (level > 1)
	{
		saveGivenLevel(ptr->left, level - 1);
		saveGivenLevel(ptr->right, level - 1);
	}
}

////////////////////////////////////////////
// COMPARE FUNCTIONS
////////////////////////////////////////////

template < class T >
bool BST<T>::compareFriends(const FriendInfo& left, const FriendInfo& right)
{
	switch (this->sortType)
	{
		case 1:
		{
			if (left.returnFirstName() < right.returnFirstName())
				return true;
			else
				return false;
		}
		case 2:
		{
			if (left.returnLastName() < right.returnLastName())
				return true;
			else
			return false;
		}
		case 3:
		{
			//cout << "inside case 3" << endl;


			//cout << "extracting strings for left side" << endl;
			//left bday
			string birthDay1 = left.returnBirthday();
			string birthDay1Year = birthDay1.substr(0, 4);
			string birthDay1Month = birthDay1.substr(5, 2);
			string birthDay1Day = birthDay1.substr(8, 2);

			//cout << "extracting strings for right side" << endl;
			 //right bday
			string birthDay2 = right.returnBirthday();
			string birthDay2Year = birthDay2.substr(0, 4);
			string birthDay2Month = birthDay2.substr(5, 2);
			string birthDay2Day = birthDay2.substr(8, 2);

			//cout << "converting left side strings to ints" << endl;
			int bDay1Year = stoi(birthDay1Year);
			int bDay1Month = stoi(birthDay1Month);
			int bDay1Day = stoi(birthDay1Day);

			//cout << "converting right side strings to ints" << endl;
			int bDay2Year = stoi(birthDay2Year);
			int bDay2Month = stoi(birthDay2Month);
			int bDay2Day = stoi(birthDay2Day);

			//cout << "making comparisons" << endl;
			//Final comparison, nested if-else statments
			if (bDay1Year < bDay2Year)
			{
				return true;
			}
			else if (bDay1Year == bDay2Year && bDay1Month < bDay2Month)
			{
				return true;
			}
			else if (bDay1Year == bDay2Year && bDay1Month == bDay2Month && bDay1Day < bDay2Day)
			{
				return true;
			}
			else
				return false;
		}
	}

}

template < class T >
bool BST<T>::equalMembers(FriendInfo& left, FriendInfo& right)
{
	if (left.returnFirstName() == right.returnFirstName() && left.returnLastName() == right.returnLastName())
		return true;
	else
		return false;
}

template < class T >
void BST<T>::changeSortType(int select)
{
	this->sortType = select;
}

# endif