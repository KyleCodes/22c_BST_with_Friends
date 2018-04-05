////////////////////////////////////////////
//				Kyle Muldoon
//				Jasraj Dhudwal
//					LAB 4
////////////////////////////////////////////
//		MAIN FILE
////////////////////////////////////////////


// THIS PROGRAM STORES INFORMATION ABOUT YOUR FRIENDS IN BINARY TREES.


#include <iostream>
#include <string>
#include "BST2.h"
#include "FriendInfo.h"
using namespace std;

int main()
{
	FileStorage <BST<FriendInfo>> FIO;		// FileStorage object handles FSTREAM operations for the project
	
	BST<FriendInfo> bstLN;					// Declaration of 2 BSTs, each one will sort data differently
	BST<FriendInfo> bstBR;
	bstLN.changeSortType(2);				// Change sort type modifies the behavior of the BSTs to sort by LAST NAME or BIRTHDAY
	bstBR.changeSortType(3);
	FriendInfo amigo;						// Creates FriendInfo object to temporarily hold valuse before being inserted into trees
	
	string tempFirstName;
	string tempLastName;			// <--- These store information used by the menu in this main.cpp
	bool status;
	int displayChoice;
	int menuSelect;
	int fileChoice;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "////////////////////////////////////////////////////////" << endl;
	cout << "          READ BEFORE LOADING YOUR OWN TXT FILES           " << endl;
	cout << "Friends are read line-by-line, attributes SEPERATED BY TABS" << endl;
	cout << "       FIRST NAME(tab) LAST NAME(tab) DOB(newline)         " << endl;
	cout << endl;
mainMenu:
	cout << "*********************************" << endl;
	cout << "             Main Menu           " << endl;
	cout << "_________________________________" << endl;						// Draws Menu on Screen
	if (bstLN.isEmpty())
		cout << "Friend List is currently empty" << endl << endl;
	else
		cout << endl;	
	cout << "    1) Load List from File       " << endl;
	cout << "    2) Save List to Files         " << endl;
	cout << "    3) View Friend List          " << endl;
	cout << "    4) Search for a Friend       " << endl;
	cout << "    5) Add Friend / Friends      " << endl;
	cout << "    6) Delete a Friend           " << endl;
	cout << "    7) Quit                      " << endl;
	cout << endl;
	cout << "             ";
getInput:
	cin >> menuSelect;
	cout << endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	switch (menuSelect)
	{
	case 1:		// CASE 1 LOADS A TEXT FILE STORING FRIEND INFROMATION INTO THE BINARY TREES
	{
		cout << "////////////////////////////////////////////////////////" << endl;
		cout << "Would you like to specify a File Path, or use Test File?" << endl;
		cout << "     ****This will delete any existing friends****     " << endl;
		cout << endl;
		cout << "    1)  Custom File Path       " << endl;
		cout << "    2)  InputDefault.txt       " << endl;
		cout << "    3)  Return                 " << endl;
		cout << endl;
		cout << "             ";
fileChoice:
		cin >> fileChoice;
		cout << endl;
		if (cin.fail() || menuSelect < 0 || menuSelect > 2)
		{
			cout << "invalid entry, Try again." << endl;
			goto fileChoice;
		}
		else if (fileChoice == 3)
			goto mainMenu;
		else if (fileChoice == 1)
		{
			string newFilePath;

			cout << "         Drag and drop your TXT file here" << endl;
			cout << "NOTICE: Please delete quotation marks at beginning and end" << endl;
			cout << endl;
			cout << "             " << endl;
			cin.ignore();
			getline(cin, newFilePath);
			FIO.changeFilePath(newFilePath);
		}
		else
		{
			FIO.changeFilePath("InputDefault.txt");
		}
		cout << "////////////////////////////////////////////////////////" << endl;
		cout << "Opening file" << endl;
		FIO.readFromFile(bstLN);
		FIO.readFromFile(bstBR);
		cout << "Closing file" << endl;
		cout << "Operation Successful!" << endl;
		cout << "Select option 3 to view Friends" << endl;
		cout << endl;
		goto mainMenu;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 2: // CASE 2 SAVES THE INFO IN EACH TREE INTO ITS OWN SORTED TEXT FILE
	{
		status = bstLN.isEmpty();
		if (status != true)
		{
			bstLN.savePostOrder();
			bstBR.breadthSave();
			cout << "////////////////////////////////////////////////////////" << endl;
			cout << "Saving to LastNameSort.txt" << endl;
			cout << "Saving to BirthdaySort.txt" << endl;
			cout << "Files located in LAB04-KM-JD " << endl << endl;
		}
		else
			cout << "ERROR - Trees are empty" << endl;
		goto mainMenu;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 3:		// CASE 3 DISPLAYS THE FRIEND LIST OT THE SCREEN ACCORDING TO USER SPECIFICATION 
	{
	caseFourMenu:
		cout << "////////////////////////////////////////////////////////" << endl;
		cout << "How do you want to display your friends Tree?:     " << endl;
		cout << "     1) Last Name  (Post Order)                  " << endl;
		cout << "     2) Birthday   (Breadth-First)               " << endl;
		cout << "             ";
		cin >> displayChoice;
		cout << endl;
		if (cin.fail() || displayChoice < 0 || displayChoice > 2)
		{
			cout << "invalid choice" << endl;
			goto caseFourMenu;
		}
		cout << "////////////////////////////////////////////////////////" << endl;
		if (displayChoice == 1)
			bstLN.printPostOrder();
		else if (displayChoice == 2)
			bstBR.breadthDisplay();
		goto mainMenu;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 4:		// CASE 4 PROVIDES SEARCH FEATURE TO SEE IF FRIENDS ARE IN THE TREE
	{
		cout << "////////////////////////////////////////////////////////" << endl;
		cout << "Enter a name to check if it's in the BSTs:" << endl << endl;
		cin.ignore();
		cout << "First Name:     ";
		getline(cin, tempFirstName);
		cout << "Last Name:      ";
		getline(cin, tempLastName);
		amigo.createFriend(tempFirstName, tempLastName, "");
		status = bstLN.search(amigo);
		cout << endl;
		cout << "////////////////////////////////////////////////////////" << endl;

		if (status == true)
			cout << "Friend was found in the Trees!" << endl;
		else
			cout << "Friend was not found in the Trees" << endl;
		cout << endl;

		goto mainMenu;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 5:		// CASE 5 ADDS NEW FRIENDS TO THE TREES
	{
		int friendCount;
		cout << "////////////////////////////////////////////////////////" << endl;
		cout << "How many Friends would you like to Add?" << endl;
		cout << "             ";
		cin >> friendCount;
		cin.ignore();

		for (int i = 0; i < friendCount; i++)
		{
			amigo.createFriend();
			bstLN.insertNode(amigo);
			bstBR.insertNode(amigo);
		}
		cout << "////////////////////////////////////////////////////////" << endl;
		cout << "Succssfully added!" << endl;
		goto mainMenu;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 6:		// CASE 6 DELETES FRIENDS FROM THE TREES	
	{
		cout << "////////////////////////////////////////////////////////" << endl;
		cout << "Enter a Friend to Delete:" << endl << endl;;
		cin.ignore();
		cout << "First Name:     ";
		getline(cin, tempFirstName);
		cout << "Last Name:      ";
		getline(cin, tempLastName);
		cout << endl;
		amigo.createFriend(tempFirstName, tempLastName, "");
		status = bstLN.search(amigo);
		cout << "////////////////////////////////////////////////////////" << endl;

		if (status == true)
		{
			bstLN.remove(amigo);
			bstBR.remove(amigo);
			cout << "Friend was Deleted from Trees" << endl;
		}
		else
			cout << "Friend was not found in the Trees" << endl;
		cout << endl;

		goto mainMenu;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 7:		// CASE 7 QUITS THE PROGRAM
		{
			cout << "////////////////////////////////////////////////////////" << endl;
			char quit;
			cout << "Are you sure you want to Quit? (Y/N)" << endl; 
			cout << "             ";
			cin >> quit;

			if (quit == 'Y' || quit == 'y')
				exit(0);
			else if (quit == 'N' || quit == 'n')
				goto getInput;
		}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	default:	// DEFAULT CASE PROVIDES INPUT VALIDATION
		{
			cout << "////////////////////////////////////////////////////////" << endl;
			cin.ignore();
			cout << "Invalid Selection. Try again" << endl;
			goto getInput;
		}
	}

	return 0;
}