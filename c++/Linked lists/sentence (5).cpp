#include <iostream>
#include <string>
#include "sentence.h"

using namespace std;

// Name:Default constructor
//Precondition:	The sentence object and member variable has not been initialized.
//Postcondition: The member variables are now initiliazed.
//Description: This is the default constructor which will be called automatically when an object is declared,Initiliazes the private member variables.
sentence::sentence() {
	front = back = 0;
}

// Name:Explicit value constructor
//Precondition:	The sentence object and member variable has not been initialized.
//Postcondition: The member variables are now initiliazed to a string.
//Description: This is the overloaded constructor and can be called by passing string value.
sentence::sentence(const string& s) {
	front = 0;
	back = 0;
	int length = s.length();
	if (length == 0) {
		front = 0;
		back = 0;
		return;
	}
	front = new word;
	word* p = front;

	int count = 0;
	int i = 0;
	while (s[i] != NULL) {
		if (isalpha(s[i]) || isdigit(s[i])) {
			while (isalpha(s[i]) || isdigit(s[i])) {
				count++;
				i++;
			}
			p->term = s.substr(i - count, count);
			p->next = new word;
			p = p->next;
			count = 0;
		}
		else if (s[i] == NULL || !isalpha(s[i]) || !isdigit(s[i])) {
			p->term = s[i];
			p->next = new word;
			p = p->next;
			i++;
		}

	}
	back = p;
	p->next = 0;
}

// Name:length()
//Precondition:	A sentence object has been created.
//Postcondition: return length of sentence.
//Description: This is a function that loops through each node of word type and adds up all their lengths.
int sentence::length() {
	word* p = front;
	int length = 0;

	while (p != 0) {
		length += p->term.length();
		p = p->next;
	}


	return length;
}

//Name:operator << (Overload loaded << Operator with chaining(Friend Function))
// pre condition:  A sentence object must exist and the private member variables must be initialized
// post condition: overloads the << operator.
ostream& operator<<(ostream& out, const sentence& sentenceObj) {
	word* p = sentenceObj.front;

	while (p != 0) {
		out << p->term;
		p = p->next;
	}
	return out;
}

//Name:Copy Constructor
// pre condition:  The sentence object that is being copied must exist, and its private member variables must be initialized
// post condition: a copy of a sentence object is created
sentence::sentence(const sentence& org) {
	front = new word;
	back = 0;
	word* p1 = front;
	word* p2 = org.front;

	while (p2 != 0) {
		p1->term = p2->term;
		p1->next = new word;
		p1 = p1->next;
		p2 = p2->next;
	}
}

//Name:isEqual
// pre condition:  A sentence class object must exist and the private member variables must be initialized
// post condition: overloads the << operator.
//Description: This is a function that loops through each node of two sentence objects and compares their size & contents. returns true if they are equal.
bool sentence::isEqual(sentence& B) {
	word* p1 = front;
	word* p2 = B.front;


	if (p1 == 0 && p2 != 0 || p1 != 0 && p2 == 0) {
		return false;
	}
	while (p1 != 0 && p2 != 0) {
		if (p1->term.length() != p2->term.length()) {
			return false;
		}
		for (int i = 0; i < p1->term.length(); i++) {
			if (p1->term[i] != p2->term[i] && p1->term[i] != ' ' && p2->term[i] != ' ') {
				return false;
			}
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}

//Name:operator = (Overload loaded =)
// pre condition:  A sentence object must exist and the private member variables must be initialized.
// post condition: overloads the = operator.
//Description: overloads the = operator and takes a string as an argument and assigns it to value A, current object.
void sentence::operator=(const string& s) {
	front = 0;
	back = 0;
	int length = s.length();
	if (length == 0) {
		front = 0;
		back = 0;
		return;
	}
	front = new word;
	word* p = front;

	int count = 0;
	int i = 0;
	while (s[i] != NULL) {
		if (isalpha(s[i]) || isdigit(s[i])) {
			while (isalpha(s[i]) || isdigit(s[i])) {
				count++;
				i++;
			}
			p->term = s.substr(i - count, count);
			p->next = new word;
			p = p->next;
			count = 0;
		}
		else if(!isalpha(s[i]) || !isdigit(s[i])){
			p->term = s[i];
			p->next = new word;
			p = p->next;
			i++;
		}

	}
	back = p;
	p->next = 0;
}

//Name:operator+ (Overload loaded +)
// pre condition:  A sentence object must exist and the private member variables must be initialized.
// post condition: overloads the + operator.
//Description: Overload the ‘+” operator as a member function without chaining to add word B
//(adds the set of symbols that makep B's linked list to the back of A's linked list) to the back of word A.
void sentence::operator+(sentence& B) {
	word* p1 = B.front;

	if (front == 0) {
		front = new word;
		word* p = front;
		while (p1 != 0) {
			p->term = p1->term;
			p->next = new word;
			p = p->next;
			p1 = p1->next;
		}
		back = p;
		p->next = 0;
	}
	else {
		word* p = back;

		while (p1 != 0) {
			p->term = p1->term;
			p->next = new word;
			p = p->next;
			p1 = p1->next;
		}
		back = p;
		p->next = 0;
	}
}

//Name:remove
// pre condition:  A sentence class object must exist and the private member variables must be initialized
// post condition: removes the string s from the sentence object.
//Description: This is a function that loops through each node a sentence and checks if it matches the argument s. If it does,
//delete the first node that matches and break loop.
void sentence::remove(const string& s) {
	word* p = front;
	bool found = false;

	while (p != 0) {
		if (p->term == s) {

			found = true;
			if (p == front && p == back) {
				delete p;
				front = back = 0;
				break;
			}
			else if (p == front) {
				front = front->next;
				delete p;
				break;
			}
			else {
				word* back_ptr = front;
				while (back_ptr != 0 && back_ptr->next != p) {
					back_ptr = back_ptr->next;
				}
				if (p == back) {
					back = back_ptr;
				}
				back_ptr->next = p->next;
				delete p;
				break;
			}
		}
		p = p->next;
	}
}

//Name:operator= (Overload loaded =)
// pre condition:  A sentence object must exist and the private member variables must be initialized.
// post condition: overloads the = operator.
//Description: overloads the = operator and takes a sentence object as an argument. loops through the object B and object A, copying all nodes into object A from B.
sentence& sentence::operator=(const sentence& w) {
	front = new word;
	back = 0;
	word* p1 = front;
	word* p2 = w.front;

	while (p2 != 0) {
		p1->term = p2->term;
		p1->next = new word;
		p1 = p1->next;
		p2 = p2->next;
	}

	return *this;
}

//Name:Destructor
// pre condition:  A sentence object must exist and the private member variables must be initialized.
// post condition: deletes the object and it's member variables.
sentence::~sentence() {
	cout << "Destructor has been called \n";

	while (front != 0) {
		word* p = front;
		front = front->next;
		delete p;
	}
}


//Name:add_back
// pre condition:  A sentence class object must exist and the private member variables must be initialized
// post condition: string s is added to back of sentence object as a node.
void sentence::add_back(string& s) {
	if (front == 0) {
		front = new word;
		front->term = s;
		front->next = 0;
		back = front;
	}
	else {
		word* p = new word;
		p->next = 0;
		p->term = s;
		back->next = p;
		back = p;
	}
}
