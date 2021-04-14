#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef STACK
#define STACK

typedef string stack_element;

class stack_node
{
public:
	stack_element data;
	stack_node* next;
};

class stack
{
public:
	stack() {/*cout<<"Inside Default Constructor\n"*/; s_top = 0; }
	stack(const string& s); //explicit value constructor
	~stack(); // destructor
	stack(const stack&); // copy constructor
	stack_element top();
	void pop();
	void push(const stack_element& item);
	void print();
	int length(); //return size of stack

private:

	stack_node* s_top;
};

#endif
