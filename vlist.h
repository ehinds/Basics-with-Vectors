/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  4/10/2017                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 7: vlist.h

Description: Using vectors this program contains a default and copy constructor as well as destructor. The DB uses type string vectors
to insert values alphabetically and contains functions to remove, search, print, and check if the DB is empty or not.

The program is split into 3 files: A header file, a cpp file for the functions of call_class, and the test driver.
*************************************************************************************************************************/

#include <vector>
using namespace std;

#ifndef VLIST_H
#define VLIST_H


class vlist
{
public:
	vlist();                //default constructor
	vlist(const vlist  &);  //copy constructor
	~vlist();               //destructor
	bool Is_Empty();         //return true if empty; otherwise false
	vector<string>::iterator Search(const string &); //returns the location of the string in the dynamic //array
	void Insert(const string & key); //add key to dynamic array 
	void Remove(const string & key); //removes key from the vector if it is there; otherwise prints a //message stating it was not in vector; the function should use an iterator and the erase //function to //remove an item from the vector.
	void Print(); //Print every string in the vector
private:
	 vector<string> DB;  //vector
};

#endif
