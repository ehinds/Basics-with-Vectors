/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  4/10/2017                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 7: vector_test_driver.cpp

Description: Using vectors this program contains a default and copy constructor as well as destructor. The DB uses type string vectors
to insert values alphabetically and contains functions to remove, search, print, and check if the DB is empty or not.

The program is split into 3 files: A header file, a cpp file for the functions of call_class, and the test driver.
*************************************************************************************************************************/

#include <iostream>
#include <string>
#include "vlist.h"
using namespace std;

int main()
{

	//Testing default constructor
	cout << "Test1:Testing the default constructor for string\n";
	vlist String_List;

	//Testing functionality for string list
	cout << "Test2: Testing Insert \n";
	String_List.Insert("Hello");
	String_List.Insert("Zebra");
	String_List.Insert("Good_Bye");
	String_List.Insert("Space");
	String_List.Insert("No_One");
	String_List.Print();



	cout << "Test 3: Testing copy constructor for string \n";
	vlist Copied_String = String_List;
	Copied_String.Print();

	cout << "Test 4: Testing Remove for string \n";
	cout << "Testing Search and IsEmpty also\n";
	String_List.Remove("Zebra");
	String_List.Remove("Good_Bye");
	String_List.Remove("Hello");
	String_List.Remove("No_One");
	String_List.Remove("Space");
	String_List.Remove("Hello");
	String_List.Print();
	Copied_String.Print();


	cout << "\nWhen leave main destructor will be called" << endl;

	return 0;
}