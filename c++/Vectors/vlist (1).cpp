#include <iostream>
#include <vector>
#include <string>
#include "vlist.h"
using namespace std;
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: Constructor has not been invoked.
//Postcondition: count = 0; vector size is 9.
//Description: Constructs an instance of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist()
{
	cout << "default constructor invoked." << endl;
	DB.reserve(9);
	count = 0;
}



///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: A vlist object is being passed by reference.
//Postcondition: A hard copy of a vlist object has been created.
//Description: Creates a hard copy of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist(const vlist& Org) {
	DB.reserve(9);
	count = Org.count;
	for (int i = 0; i < Org.count; i++) {
		DB.push_back(Org.DB[i]);
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~vlist
//Precondition: Destructor has not been invoked.
//Postcondition: array DB deleted.
//Description: Deallocates memory of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::~vlist() {
	cout << "destructor invoked." << endl;
	DB.clear();
	DB.shrink_to_fit();
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: isEmpty()
//Precondition: a vlist object has been created and its member variables have been initialized
//Postcondition: return true vector is empty
///////////////////////////////////////////////////////////////////////////////////////////////
bool vlist::isEmpty() {
	if (DB.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: iterator search();
//Precondition:  a vlist object has been created and its member variables have been initialized
//Postcondition: array DB deleted.
//Description: searches the vector and returns the pointer of string key inside vector.
///////////////////////////////////////////////////////////////////////////////////////////////
vector<string>::iterator vlist::search(const string& key) {
	vector<string>::iterator it;
	for (it = DB.begin(); it != DB.end(); it++) {
		if (*it == key) {
			cout << "Item Found." << endl;
			return it;
		}
	}
	cout << "Item Not Found." << endl;
	return DB.end();
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: insert()
//Precondition:  a vlist object has been created and its member variables have been initialized
//Postcondition: inserts string key in alphabetical order inside vector DB
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::insert(const string& key) {
	vector<string>::iterator iter1;
	if (count == 0) {
		DB.push_back(key);
		count++;
		return;
	}
	else {
		for (iter1 = DB.begin(); iter1 != DB.end(); iter1++) {
			if (key <= *iter1) {
				DB.insert(iter1, key);
				count++;
				return;
			}
		}
		DB.push_back(key);
		count++;
		return;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: remove()
//Precondition:  a vlist object has been created and its member variables have been initialized
//Postcondition: removed the key string from vector DB.
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::remove(const string& key) {
	vector<string>::iterator itcopy = search(key);
	if (itcopy != DB.end()) {

		DB.erase(itcopy);
		return;
	}
	else {

		return;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print()
//Precondition:  a vlist object has been created and its member variables have been initialized
//Postcondition: vector is looped through and its elements are printed to screen.
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::print() {
	for (vector <string>::iterator i = DB.begin(); i != DB.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
