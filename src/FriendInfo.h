/////////////////////////////////////////////////////////////////////
//			FRIENDINFO CLASS
/////////////////////////////////////////////////////////////////////
// FriendInfo.h
////////////////////////////////////////////


// FriendInfo is a module that creates the FriendInfo DATA TYPE


#ifndef FRIENDINFO_H
#define FRIENDINFO_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FriendInfo
{
private:
	// FRIEND INFORMATION
	string firstName;
	string lastName;
	string birthday;
	int tempNum = 1;

public:
	// CONSTRUCTORS
	FriendInfo();										// Sets values to Null
	FriendInfo(string, string, string);             // Collects pre established data and uses to construct

	// DESTRUCTOR
	~FriendInfo();

	// SETTER FUNCTIONS
	void setFirstName(string);
	void setLastName(string);
	void setBirthday(string);
	void createFriend();							// Collects user input and returns a FriendInfo object with that information 
	void createFriend(string, string, string);
	void changeTempNum();

	// GETTER FUNCTIONS
	string returnFirstName() const;
	string returnLastName() const;
	string returnBirthday() const;

	// DISPLAY FUNCTION
	void printFriend();							// Prints contents of a FriendInfo object to screen	

	// OPERATOR OVERLOADS                       
	friend ostream& operator<<(ostream& out, FriendInfo& s);			// For use with stream outputting
	friend ofstream& operator<<(ofstream& out, FriendInfo& s);		// For use with FSTREAM Storage
	friend ifstream& operator>>(ifstream& in, FriendInfo& s);
	//bool operator < (const FriendInfo &right);
	//bool operator > (const FriendInfo &right);
	//bool operator == (const FriendInfo &right);

};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//		FUNCTION DEFINITIONS
////////////////////////////////////////////

////////////////////////////////////////////
// FRIENDINFO CONSTRUCTORS
////////////////////////////////////////////


FriendInfo::FriendInfo()
{
	this->firstName = " ";
	this->lastName = " ";
	this->birthday = " ";
}

FriendInfo::FriendInfo(string fn, string ln, string birth)
{
	setFirstName(fn);
	setLastName(ln);
	setBirthday(birth);
}

FriendInfo::~FriendInfo()
{}

////////////////////////////////////////////
// SETTER FUNCTIONS
////////////////////////////////////////////

void FriendInfo::setFirstName(string fn)
{
	this->firstName = fn;
}

void FriendInfo::setLastName(string ln)
{
	this->lastName = ln;
}

void FriendInfo::setBirthday(string bir)
{
	this->birthday = bir;
}

void FriendInfo::createFriend()
{
	cout << "----------" << endl;
	cout << "Friend " << tempNum << endl;
	cout << "----------" << endl;
	cout << "First Name:        ";
	getline(cin, firstName);
	cout << "Last Name:         ";
	getline(cin, lastName);
	cout << "DOB (YYYY-MM-DD)   ";
	getline(cin, birthday);
	cout << endl;
	tempNum++;

}

void FriendInfo::createFriend(string fn, string ln, string bir)
{
	firstName = fn;
	lastName = ln;
	birthday = bir;
}

void FriendInfo::changeTempNum()
{
	tempNum--;
}

////////////////////////////////////////////
// GETTER FUNCTIONS
////////////////////////////////////////////

void FriendInfo::printFriend()
{
	cout << firstName << endl;
	cout << lastName << endl;
	cout << birthday << endl;
}

string FriendInfo::returnFirstName() const
{
	return firstName;
}

string FriendInfo::returnLastName() const
{
	return lastName;
}

string FriendInfo::returnBirthday() const
{
	return birthday;
}

////////////////////////////////////////////
// OPERATOR OVERLOADS
////////////////////////////////////////////

ofstream& operator<<(ofstream& out, FriendInfo& b)
{
	const char tab = '\t';
	out << b.returnFirstName() << tab;
	out << b.returnLastName() << tab;
	out << b.returnBirthday() << endl;
	return out;
}

ifstream& operator>>(ifstream& in, FriendInfo& b)
{
	const char tab = '\t';
	char c[500];
	in.getline(c, 500, tab);
	b.setFirstName(c);
	in.getline(c, 500, tab);
	b.setLastName(c);
	in.getline(c, 500, '\n');
	b.setBirthday(c);
	return in;
}

ostream& operator<<(ostream& out, FriendInfo& s)
{
	s.printFriend();
	return out;
}

//bool FriendInfo::operator < (const FriendInfo &right)
//{
//	bool status;
//
//	if (this->lastName < right.lastName)
//		status = true;
//	else
//		status = false;
//
//	return status;
//}

//bool FriendInfo::operator > (const FriendInfo &right)
//{
//	bool status;
//
//	if (this->lastName > right.lastName)
//		status = true;
//	else
//		status = false;
//
//	return status;
//}

//bool FriendInfo::operator == (const FriendInfo &right)
//{
//	bool status;
//
//	if (this->lastName == right.lastName)
//		status = true;
//	else
//		status = false;
//
//	return status;
//}

#endif