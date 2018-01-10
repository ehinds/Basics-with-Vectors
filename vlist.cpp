/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  4/10/2017                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 7: vlist.cpp

Description: Using vectors this program contains a default and copy constructor as well as destructor. The DB uses type string vectors
to insert values alphabetically and contains functions to remove, search, print, and check if the DB is empty or not.

The program is split into 3 files: A header file, a cpp file for the functions of call_class, and the test driver.
*************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "vlist.h"

using namespace std;

/************************************************************************************************************************************/
//Name: default constructor
//Precondition: DB has not been initialized 
//Postcondition: DB has been initialized
//Decription: Initializes the DB with an empty vector
/************************************************************************************************************************************/
vlist::vlist()
{
	cout << "\nDefault Constructor Invoked. \n\n";
	//nothing to do, automatically constructed when declared under private for the vlist class
}

/************************************************************************************************************************************/
//Name: copy constructor
//Precondition: DB has not been copied
//Postcondition: DB has been copied
//Decription: Performs a deep copy of the DB
/************************************************************************************************************************************/
vlist::vlist(const vlist & Org) : DB(Org.DB)
{
	cout << "\nCopy Constructor Invoked. \n\n";
	//Copy constructor is called using ": DB(Org.DB)"
}

/***********************************************************************************************************************************/
//Name: Is_Empty
//Precondition: DB has not been checked to see if it is empty
//Postcondition: DB has been checked to see if it is empty
//Decription: returns true if DB is empty
/**********************************************************************************************************************************/
bool vlist::Is_Empty()
{
	return DB.empty();
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: Data has not been searched for
//Postcondition: Data has been searched for and was either found or not found
//Decription: locates key in DB if it is there. Searches every entry except for the last entry.
//Returns the last entry if it is not found. Says whether item is found or not. (Search last entry separately).
/*********************************************************************************************************************************/
vector<string>::iterator vlist::Search(const string & key)
{ 
	cout << "\nSearch has been invoked. \n";
	if (!Is_Empty())
	{
		for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++)
		{
			if (key == *i)
			{
				cout << "\nThe item '" << *i << "' has been found successfully. \n";
				return i;
			}
		}
	}
	cout << "\nItem Not Found\n";
	return DB.end();
}

/*********************************************************************************************************************************/
//Name: Insert
//Precondition: The database has not been added to
//Postcondition: Adds an entry to the database as specified by the user.
//Decription: insert a key into DB that is sorted alphabetically
/********************************************************************************************************************************/
void vlist::Insert(const string & key) 
{
	if (Is_Empty())
	{
		DB.push_back(key);
		return;
	}
	else if (key <= *DB.begin())
	{
		DB.insert(DB.begin(), key);
		return;
	}
	else
	{
		for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++)
		{
			if (key <= *i)
			{
				DB.insert(i, key);
				return;
			}
		}
		DB.insert(DB.end(), key);
	}
}

/********************************************************************************************************************************/
//Name: Remove
//Precondition: No data has been removed
//Postcondition: Single data matching a specific key will be removed 
//Decription: remove single instances of key from DB if it is there. Runs the search function and searches the last entry separately.
/*******************************************************************************************************************************/
void vlist::Remove(const string & key)
{
	if (Is_Empty())
	{
		cout << "\nVector is empty, nothing to delete. \n";
		return;
	}
	else if (Search(key) != DB.end())
	{
		DB.erase(Search(key));
		cout << "\nThe item '" << key << "' has been deleted successfully. \n";
		return;
	}
	else if (key == *DB.end())
	{
		DB.erase(DB.end());
		cout << "\nThe item '" << key << "' has been found successfully. \n";
		return;
	}
	else
	{
		cout << "\nItem was Not Found\n";
	}	
}

/****************************************************************************************************************************/
//Name: Print
//Precondition: Information hasn't been printed to the screen
//Postcondition: Information has been printed to the screen
//Decription: Prints contents of DB to the screen
/***************************************************************************************************************************/
void vlist::Print() 
{
	if (Is_Empty())
	{
		cout << "\nVector is empty, nothing to print.\n\n";
	}
	else
	{
		for (vector<string>::iterator i = DB.begin(); i != DB.end(); i++)
		{
			cout << (*i) << endl;
		}
		cout << endl;
	}
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: memory for DB is still allocated
//Postcondition: memory for DB is no longer allocated
//Decription: de-allocates all memory allocated to DB.
/***************************************************************************************************************************/
vlist::~vlist()
{
	cout << "Destructor Invoked. \n";
	//nothing to add, vectors auto destruct
}



