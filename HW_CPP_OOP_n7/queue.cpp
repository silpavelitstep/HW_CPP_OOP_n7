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

//queue (simple) base linked_list
//one elem contains int array[100..10 000]
QueueLinkedListArray::QueueLinkedListArray(int size) {//size=100
	head = last = 0;
	sizeArr = size;
	lastPos = sizeArr-1;
	headPos = 0;
	cout << "quLLA add " << (int)this << endl;
}
QueueLinkedListArray::~QueueLinkedListArray() {
	cout << "quLLA free " << (int)this << endl;
	if (head == 0)
		return;
	ElemArray* tmp;
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}
QueueLinkedListArray::ElemArray::ElemArray(int sizeArr) {
	if (sizeArr <= 0)
		sizeArr = 100;
	cout << "ElemA added " << (int)this << endl;
	arr = new int[sizeArr];
	next = 0;
}
QueueLinkedListArray::ElemArray::~ElemArray() {
	cout << "del ElemA " << (int)this << endl;
	delete[] arr;
}
void QueueLinkedListArray::add(int data) {
	if (lastPos < sizeArr-1) {//array is not full
		last->arr[++lastPos] = data;
	}
	else {//lastPos == sizeArr-1
		//added new container
		ElemArray *ea=new ElemArray(sizeArr);
		if (head) {//not empty list
			last->next = ea;
			last = last->next;
		}
		else {//empty
			head = last = ea;
		}
		//put data in container
		lastPos = 0;
		ea->arr[lastPos] = data;
	}
	
}
int QueueLinkedListArray::extract() {//take from head
	int resault = 0;
	if (head) {//list is not empty
		//one container only
		if (head == last) { //00110 or 00010 or 00000_11000
			if (headPos <= lastPos)
				resault = head->arr[headPos++];
			else {
				resault = 0;//because arr empty then list empty
				delete head;
				head = last = 0;
				lastPos = sizeArr - 1;
				headPos = 0;
			}
		}
		else {// head != last 00111_11111_10000 
			if(headPos<sizeArr)
				resault = head->arr[headPos++];
			else {//headPos==sizeArr 00000_11111_10000
				ElemArray* tmp = head; //00000 adress
				head = head->next;// 11111_10000
				delete tmp;//del empty container
				headPos = 0;
				resault= head->arr[headPos++];
			}
		}
	}
	return resault;
}
void QueueLinkedListArray::show() {
	ElemArray* tmp=head;
	if (head == 0) return;
	if (head == last) {// 01100
		for (int i = headPos; i <= lastPos; i++)
			cout << tmp->arr[i]<<' ';
		cout << "\n***\n";
	}
	else {
		// 00011
		for (int i = headPos; i < sizeArr;i++)
			cout << tmp->arr[i] << ' ';
		cout << "\n***\n";
		// 11111 11111 11111
		tmp = tmp->next;
		while (tmp!=last){
			for(int i=0;i<sizeArr;i++)
				cout << tmp->arr[i] << ' ';
			tmp = tmp->next;
		}
		cout << "\n***\n";
		// 11100
		for (int i = 0; i <= lastPos; i++) {
			cout << tmp->arr[i] << ' ';
		}
		cout << "\n***\n";
	}

	
}