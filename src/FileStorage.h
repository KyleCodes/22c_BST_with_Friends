/////////////////////////////////////////////////////////////////////
//			FILESTORAGE CLASS
/////////////////////////////////////////////////////////////////////
// FileStorage.h
////////////////////////////////////////////


#ifndef FILESTORAGE_H
#define FILESTORAGE_H
#include <iostream>
#include <fstream>
#include <string>
#include "FriendInfo.h">
#include "BST2.h"
using namespace std;

template < class T >
class FileStorage
{
private:
	string inputfileName;
	string outputFileName;

public:
	// CONSTRUCTORS
	FileStorage();
	FileStorage(string);
	~FileStorage();

	// SETTERS
	void changeFilePath(string);
	void changeOutputName(string);

	// FILE OPERATIONS
	void readFromFile(T&);
	void writeToFile(T&) const;
	void deleteContents();
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//		FUNCTION DEFINITIONS
////////////////////////////////////////////

////////////////////////////////////////////
// FILESTORAGE CONSTRUCTORS
////////////////////////////////////////////

template < class T >
FileStorage<T>::FileStorage()
{
	inputfileName = "testfile.txt";
}

template < class T >
FileStorage<T>::FileStorage(string newName)
{
	inputfileName = newName;
}

template < class T >
FileStorage<T>::~FileStorage()
{}

////////////////////////////////////////////
// FILENAME OPERATIONS
////////////////////////////////////////////

template < class T >
void FileStorage<T>::changeFilePath(string newFile)
{
	inputfileName = newFile;
}

template < class T >
void FileStorage<T>::changeOutputName(string newFile)
{
	outputFileName = newFile;
}
////////////////////////////////////////////
// INPUT OPERATIONS
////////////////////////////////////////////

template < class T >
void FileStorage<T>::readFromFile(T& tree)
{
	tree.removeAll();
	ifstream in;
	//cout << "Opening file" << endl;
	in.open(inputfileName, ios::in);
	while (!in.eof())
	{
		FriendInfo f;
		in >> f;
		if (in.fail())										
		{
			cout << "Import Complete" << endl;
			return;
		}
		//cout << "Inserting node" << endl;
		tree.insertNode(f);
	}
	//cout << "Closing file" << endl;
	in.close();
}

////////////////////////////////////////////
// OUTPUT OPERATIONS
////////////////////////////////////////////

template < class T >
void FileStorage<T>::writeToFile(T& obj) const
{
	ofstream out;
	out.open(outputFileName, ios::out | ios::app);
	out << obj;
	//out << '\n';
	out.close();
}

template < class T >
void FileStorage<T>::deleteContents()
{
	ofstream del;
	del.open(outputFileName, ios::out | ios::trunc);
	del.close();
}

#endif