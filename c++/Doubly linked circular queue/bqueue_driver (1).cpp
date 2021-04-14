/*
 File: bqueue_driver.cpp (provided in assignment description)
 Name: Matheus Leal

 Description: This reviews how to work with doubly linked circular queues with just a reference to the front of the queue.

 */
#include<iostream>
#include "bqueue.h"

using namespace std;

int main()
{
	bqueue k;
	k.enqueue(60);
	cout << "---------Added 60 to Queue----------" << endl;
	k.print();
	k.enqueue(20);
	k.enqueue(30);
	cout << "----------Added 20, 30 to Queue---------" << endl;
	k.print();
	k.enqueue(10);
	cout << "----------Added 10 to Queue---------" << endl;
	k.print();
	k.enqueue(50);
	k.enqueue(40);
	cout << "----------Added 50, 40 to Queue---------" << endl;
	k.print();
	bqueue j = k;
	cout << "----------Remove from front of queue 1 number---------" << endl;
	j.dequeue();
	j.print();
	j.dequeue();
	j.dequeue();
	j.dequeue();
	cout << "---------Remove from front of queue 3 numbers----------" << endl;
	j.print();
	j.dequeue();
	j.dequeue();
	cout << "---------Empty Queue----------" << endl;
	j.print();
	j.dequeue();
	j.dequeue();
	return 0;
}
