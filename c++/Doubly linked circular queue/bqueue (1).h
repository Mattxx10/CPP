#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef BQNODE
#define BQNODE

class bqnode
{
public:
	int priority;
	bqnode* prev, * next;
};
class bqueue
{
public:
	bqueue(); //default constructor
	~bqueue(); // destructor
	bqueue(const bqueue & org); // copy constructor
	void enqueue(int x);
	void dequeue();
	void print();
	bool empty() {return count == 0;} //return if queue is empty
private:
	bqnode* front;
	int count;//useONLYone pointer
};

#endif
