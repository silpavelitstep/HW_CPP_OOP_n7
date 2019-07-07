#include "stack.h"
#include <iostream>
using namespace std;
//stack
Stack::Stack(int size) {//size - size of inner array
	array = new int[size];
	this->size = size;
	pos = -1;//if array is empty
	//cout << "new Stack\t" << (int)this << endl;//--------------
}
Stack::~Stack() {
	//cout << "free Stack\t" << (int)this << endl;//-------------
	delete[] array;
	
}
int Stack::push(int value) {
	if (pos < size)
		array[++pos] = value;
	return value;
}
int Stack::pop() {
	if (pos == -1)
		return 0;
	else
		return array[pos--];
}
void Stack::show() {
	if (pos == -1)
		cout << "empty stack";
	else {
		for (int i = pos; i >= 0; i--)
			cout << array[i] << ' ';
		//cout << endl;
	}
	//cout << "count=" << count() << endl;
}
int Stack::count() {
	return pos + 1;
}
bool Stack::isEmpty() {
	return pos == -1;
}
//stack base linked list
StackList::StackList() {
	head = 0;//empty list
	cnt = 0;//empty list
	//cout << "new StackList\t" << (int)this << endl;
}
StackList::~StackList() {
	Elem* temp=head;
	while (head) {
		temp = head->next;
		delete head;
		head = temp;
	}
	//cout << "free StackList\t" << (int)this << endl;
}
StackList::Elem::Elem(int value, Elem *next ) {
	this->value = value;
	this->next = next;
	//cout << "new StackList::Elem\t" << (int)this << endl;
}
StackList::Elem::~Elem() {
	//cout << "free StackList::Elem\t" << (int)this << endl;
}
int StackList::push(int value) {
	head = new Elem(value,head);
	cnt++;
	return value;
}
int StackList::pop() {
	if (head) {
		Elem* temp = head->next;//save next elem
		int resault = head->value;//save value
		delete head;//free memory
		head = temp;
		cnt--;
		return resault;
	}
	else
		return -1;
}
int StackList::count() {
	return cnt;
}
void StackList::show() {
	cout << " [";
	if (cnt) {
		Elem* current = head;
		while (current) {
			cout << current->value << ' ';
			current = current->next;
		}
}
	else
		cout << "empty stack";
	cout << "] ";
	cout << "count= " << count() << endl;

}
bool StackList::isEmpty() {
	return cnt == 0;
}
//stack base linked list base stack
StackListStack::StackListStack(int size) {
	head = 0;
	cnt = 0;
	this->size = size;//
	//cout << "new StackListStack\t" << (int)this << endl;//-------------
}
StackListStack::~StackListStack() {
	//cout << "free StackListStack\t" << (int)this << endl;//-------------
	Elem* temp = head;
	while (head) {
		temp = head->next;
		delete head;
		head = temp;
	}
	
}
StackListStack::Elem::Elem(int size) {
	stack = new Stack(size);
	next = 0;
	//cout << "new StackListStack::Elem\t" << (int)this << endl;//----
}
StackListStack::Elem::~Elem() {
	//cout << "free StackListStack::Elem\t" << (int)this << endl;//---
	delete stack;
	
}
int StackListStack::push(int value) {
	if (cnt == 0) {//empty list (empty stack)
		head = new Elem(size);
	}
	//inner stack can be filled
	if (head->stack->count() == size) {
		Elem* temp = head;
		head=new Elem(size);
		head->next = temp;
	}
	head->stack->push(value);
	cnt++;
	return value;
}
void StackListStack::show() {
	if (cnt == 0)
		cout << "empty stack ";
	else {
		Elem* temp = head;
		while (temp) {
			if(!temp->stack->isEmpty())
				temp->stack->show();
			temp = temp->next;
		}
	}
}
int StackListStack::pop() {
	if (cnt == 0) {//empty list (empty stack)
		return -1;
	}
	int resault = head->stack->pop();
	cnt--;
	if (head->stack->count() == 0) {
		Elem* temp = head->next;
		delete head;
		head = temp;
	}
	return resault;
}
int StackListStack::count() {
	return cnt;
}
bool StackListStack::isEmpty() {
	return cnt == 0 && head == 0;
}