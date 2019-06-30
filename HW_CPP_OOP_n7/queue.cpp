#include "queue.h"
#include <iostream>
using namespace std;

//queue (simple) base array (from education)
Queue::Queue(int m) {
	maxQueueLenght = m;
	wait = new int[maxQueueLenght];
	queueLenght = 0;
	first = 0;
}
Queue::~Queue() { delete[] wait; }
void Queue::clear() { queueLenght = 0; };
bool Queue::isEmpty() { return queueLenght == 0; }
bool Queue::isFull() { return queueLenght == maxQueueLenght; }
int Queue::getCount() { return queueLenght; }
int Queue::add(int c) {
	if (!isFull()) {
		wait[queueLenght++] = c;
		return 1;
	}
	else
		return 0;
}
int Queue::extract() {
	if (!isEmpty()) {
		int tmp = wait[0];
		for (int i = 1; i < queueLenght; i++) {
			wait[i - 1] = wait[i];
		}
		queueLenght--;
		return tmp;
	}
	else
		return -1;
}
void Queue::show() {
	for (int i = 0; i < queueLenght; i++)
		cout << wait[i] << ' ';
	cout << endl;
}

//queue (simple) base linked_list
//one elem contain one int numbers
QueueLinkedList::QueueLinkedList() {
	head = last = 0;
	//cout << "quLL add " << (int)this << endl;
}
QueueLinkedList::~QueueLinkedList() {
	//cout << "quLL free " << (int)this << endl;
	if (head == 0)
		return;
	Elem* tmp;
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
		
	}
}

void QueueLinkedList::add(int i) {
	Elem* tmp= new Elem(i);
	if( head ){//not empty list
		last->next = tmp;
		last = last->next;
	}
	else {//empty
		head = last = tmp;
	}
}
int QueueLinkedList::extract() {
	if (head) {
		Elem* tmp = head;
		int i = head->i;
		head = head->next;
		delete tmp;
		if (head == 0)
			last = 0;//list is empty
		return i;
	}
	else//list is empty
		return 0;

}