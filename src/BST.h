///////////////////////////////////////////////////////////////////////
////			BST CLASS
///////////////////////////////////////////////////////////////////////
//// BST.h
//////////////////////////////////////////////
//
//#ifndef BST_H
//#define BST_H
//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include "Node.h"
//#include "FileStorage.h"
//#include "FriendInfo.h"
////using namespace std;
//
//template < class T >
//class BST
//{
//private:
//	// ROOT POINTER
//	Node<T>* root;
//
//	// FILE IO HELPER
//	FileStorage<T> FIO;
//
//	// BST PRIVATE FUNCTIONS 
//	void insert(Node<T>*&, Node<T>*&);//	void deleteSubTree(Node<T>*);//	void deleteNode(T, Node<T>*&);//	void makeDeletion(Node<T>*&);
//	void inOrder(Node<T>*) const;
//	void preOrder(Node<T>*) const;
//	void postOrder(Node<T>*) const;
//	void saveInOrder(Node<T>*) const;
//	void savePreOrder(Node<T>*) const;
//	void savePostOrder(Node<T>*) const;
//
//public:
//	// BST CONSTRUCTORS
//	BST();
//	~BST();
//	
//	// BST STANDARD FUNCTIONS 
//	bool isEmpty();
//	void insertNode(T);
//	void remove(T);
//	bool search(T);
//
//	// BST DISPLAY FUNCTIONS
//	void printInOrder();
//	void printPreOrder();
//	void printPostOrder();
//
//	// TREE SAVE FUNCTIONS
//	void saveInOrder();
//	void savePostOrder();
//	void savePreOrder();
//};
//
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
////		FUNCTION DEFINITIONS
//////////////////////////////////////////////
//
//////////////////////////////////////////////
//// BST CONSTRUCTOR
//////////////////////////////////////////////
//template < class T >
//BST<T>::BST()
//{
//	root = NULL;
//}
//
//template < class T >
//BST<T>::~BST()
//{
//	deleteSubTree(root);
//}
//
//////////////////////////////////////////////
//// BST STANDARD FUNCTIONS
//////////////////////////////////////////////
//
//template < class T >
//bool BST<T>::isEmpty()
//{
//	bool status;
//	if (!root)
//	{
//		status = true;
//	}
//	else
//	{
//		status = false;
//	}
//	return status;
//}
//
//template <class T>
//void BST<T>::insertNode(T obj)
//{
//	Node<T>* newPtr = new Node<T>;
//
//	newPtr->data = obj;
//	newPtr->left = NULL;
//	newPtr->right = NULL;
//
//	insert(root, newPtr);
//}
//
//template < class T >
//void BST<T>::insert(Node<T>*& currPtr, Node<T>*& newPtr)
//{
//	if (currPtr == NULL)
//		currPtr = newPtr;
//	else if (newPtr->data < currPtr->data)
//		insert(currPtr->left, newPtr);
//	else
//		insert(currPtr->right, newPtr);
//}
//
//template < class T >
//void BST<T>::remove(T obj)
//{
//	deleteNode(obj, root);
//}
//
//template < class T >
//void BST<T>::deleteNode(T obj, Node<T>*& currPtr)
//{
//	if (obj < currPtr->data)
//		deleteNode(obj, currPtr->left);
//	else if (currPtr->data < obj)
//		deleteNode(obj, currPtr->right);
//	else
//		makeDeletion(currPtr);
//}
//
//template < class T >
//void BST<T>::makeDeletion(Node<T>*& currPtr)
//{
//	Node<T>* tempNode;
//
//	if (currPtr == NULL)
//		cout << "Node is already Empty" << endl;
//	else if (currPtr->right == NULL)
//	{
//		tempNode = currPtr;
//		currPtr = currPtr->left;
//		delete tempNode;
//	}
//	else if (currPtr->left == NULL)
//	{
//		tempNode = currPtr;
//		currPtr = currPtr->right;
//		delete tempNode;
//	}
//	else
//	{
//		tempNode = currPtr->right;
//		while (tempNode->left)
//			tempNode = tempNode->left;
//		tempNode->left = currPtr->left;
//		tempNode = currPtr;
//
//		currPtr = currPtr->right;
//		delete tempNode;
//	}
//}
//
//template < class T >
//void BST<T>::deleteSubTree(Node<T>* currPtr)
//{
//	if (currPtr != NULL)
//	{
//		if (currPtr->left)
//			deleteSubTree(currPtr->left);
//		if (currPtr->right)
//			deleteSubTree(currPtr->right);
//		delete currPtr;
//	}
//}
//
//template < class T >
//bool BST<T>::search(T obj)
//{
//	Node<T>* currPtr = root;
//
//	while (currPtr != NULL)
//	{
//		if (currPtr->data == obj)
//			return true;
//		else if (obj < currPtr->data)
//			currPtr = currPtr->left;
//		else
//			currPtr = currPtr->right;
//	}
//	return false;
//}
//
//////////////////////////////////////////////
//// BST DISPLAY FUNCTIONS
//////////////////////////////////////////////
//
//template < class T >
//void BST<T>::printInOrder()
//{
//	inOrder(root);
//}
//
//template < class T >
//void BST<T>::inOrder(Node<T>* ptr) const
//{
//	if (ptr != NULL)
//	{
//		inOrder(ptr->left);
//		cout << ptr->data;
//		inOrder(ptr->right);
//	}
//}
//
//template < class T >
//void BST<T>::printPreOrder()
//{
//	preOrder(root);
//}
//
//template < class T >
//void BST<T>::preOrder(Node<T>* ptr) const
//{
//	if (ptr != NULL)
//	{
//		cout << ptr->data << endl;
//		preOrder(ptr->left);
//		preOrder(ptr->right);
//	}
//}
//
//template < class T >
//void BST<T>::printPostOrder()
//{
//	postOrder(root);
//}
//
//template < class T >
//void BST<T>::postOrder(Node<T>* ptr) const
//{
//	if (ptr != NULL)
//	{
//		postOrder(ptr->left);
//		postOrder(ptr->right);
//		cout << ptr->data << endl;
//	}
//}
//
//////////////////////////////////////////////
//// BST SAVE FUNCTIONS
//////////////////////////////////////////////
//
//template < class T >
//void BST<T>::saveInOrder()
//{
//	saveInOrder(root);
//}
//
//template < class T >
//void BST<T>::saveInOrder(Node<T>* ptr) const
//{
//	if (ptr != NULL)
//	{
//		FIO.writeToFile(ptr->data);
//		saveInOrder(ptr->left);
//		saveInOrder(ptr->right);
//	}
//}
//
//template < class T >
//void BST<T>::savePreOrder()
//{
//	savePreOrder(root);
//}
//
//template < class T >
//void BST<T>::savePreOrder(Node<T>* ptr) const
//{
//	if (ptr != NULL)
//	{
//		FIO.writeToFile(ptr->data);
//		savePreOrder(ptr->left);
//		savePreOrder(ptr->right);
//	}
//}
//
//template < class T >
//void BST<T>::savePostOrder()
//{
//	savePostOrder(root);
//}
//
//template < class T >
//void BST<T>::savePostOrder(Node<T>* ptr) const
//{
//	if (ptr != NULL)
//	{
//		savePostOrder(ptr->left);
//		savePostOrder(ptr->right);
//		FIO.writeToFile(ptr->data);
//	}
//}
//
//
//# endif