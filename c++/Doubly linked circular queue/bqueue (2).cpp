#include <iostream>
#include <string>
#include "bqueue.h"

using namespace std;
// Name:Default Constructor
//Precondition:	The bqueue object and member variable has not been initialized.
//Postcondition: The bqueue object is initialized
bqueue::bqueue() :front(0), count(0){
}
// Name:Destructor
//Precondition:	The bqueue object and member variables must be initialized
//Postcondition: removes all the nodes from the bqueue object
bqueue::~bqueue() {
	while (!empty()) {
		dequeue();
	}
}
//Name:Copy constructor
//Precondition:	The bqueue object and member variable have been initialized.
//Postcondition: The stack is filled with one operation.
//Description: copies all nodes from an existing queue to and existing queue
bqueue::bqueue(const bqueue & org) {
	front = new bqnode;
	bqnode* p1 = front;
	bqnode* p2 = org.front;
	count = org.count;


	for(int i = 0; i < org.count; i++) {
		p1->priority = p2->priority;
		p1->next = new bqnode;
		p1 = p1->next;
		p2 = p2->next;
	}
	front->prev = p1;
	p1->next = 0;
}
// Name:enqueue
//Precondition:	The bqueue object and member variable have been initialized.
//Postcondition: a node is added to the queue
//Description: takes an int and adds it to the back of the queue.
void bqueue::enqueue(int x) {
	if (empty()) {
		front = new bqnode;
		front->priority = x;
		front->next = front->prev = front;
		count++;
	}
	else {
		front->prev->next = new bqnode;
		front->prev->next->prev = front->prev;
		front->prev = front->prev->next;
		front->prev->priority = x;
		count++;
	}
}
// Name:dequeue
//Precondition:	The bqueue object and member variable have been initialized.
//Postcondition: node is removed from the front of the queue
//Description: removes the node in the front of queue. otherwise, cout to screen "cannot dequeue because queue is empty."
void bqueue::dequeue() {
	if (!empty()) {
		bqnode* p = front;
		front = front->next;
		delete p;
		count--;
		return;
	}
	else {
		cout << "Cannot deQueue because queue is empty\n";
		return;
	}
}
// Name:print
//Precondition:	The bqueue object and member variable hasve been initialized.
//Postcondition: the queue is printed to the screen.
//Description: loops through the nodes of bqueue object and prints them to the screen.
void bqueue::print() {
	bqnode* p = front;

	for(int i = 0; i < count; i++) {
		cout << p->priority << endl;
		p = p->next;
	}
}
