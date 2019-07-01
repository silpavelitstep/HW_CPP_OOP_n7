#pragma once
#include <iostream>
using namespace std;
#ifndef QUEUE_H
#define QUEUE_H
//queue (simple) base array (from education)
class Queue {
	int* wait;
	int maxQueueLenght;
	int queueLenght;
	int first;
public:
	Queue(int);
	~Queue();
	int add(int c);
	int extract();
	void clear();
	bool isEmpty();
	bool isFull();
	int getCount();
	void show();
};
//queue (simple) base linked_list
//one elem contains one int numbers
class QueueLinkedList {
	//low effective using memory
	//Elem: int i(4Byte), next(4Byte x86), effective ~50% 
	class Elem {
	public:
		int i;//data, any base type
		Elem* next;//pointer to next
		Elem(int i) :next(0), i(i) {
			//cout << "Elem add " << (int)this << endl;
		}
		~Elem() {
			//cout << "del Elem" << (int)this << endl;
		}//extract or end program
		
	};
	Elem* head;
	Elem* last;
public:
	QueueLinkedList();
	~QueueLinkedList();
	void add(int);//add to end list
	int extract();//take and dell from head
};
//queue (simple) base linked_list
//one elem contains int array[100..10 000]
class QueueLinkedListArray {
protected:
	class ElemArray {
	public:
		int *arr;//data, any base type
		ElemArray* next;//pointer to next elem
		ElemArray(int);//array is full
		~ElemArray();//array is empty

	};
	ElemArray* head;//head of queue
	ElemArray* last;//end of queue
	int headPos;//head of queue in array in head container
	int lastPos;//end of queue in array in last container
	int sizeArr;//size inner array
public:
	QueueLinkedListArray(int size=100);
	~QueueLinkedListArray();
	int add(int);//add to end list
	int extract();//take and dell from head
	void show();
};
//queue ring base linked list
class QueueRingLLA:public QueueLinkedListArray{
public:
	int extract();

};
#endif // !QUEUE_H

