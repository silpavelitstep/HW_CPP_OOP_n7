#pragma once
#ifndef STACK_H
#define STACK_H
//stack base static array
class Stack {
	int* array;
	int pos;//current possition of pointer in array
	int size;
public:
	int push(int);//set
	int pop();//get
	void show();
	int count();
	bool isEmpty();
	Stack(int);
	~Stack();
};
//stack base linked list
class StackList {
	class Elem {
	public:
		int value;
		Elem* next;
		Elem(int,Elem*);
		~Elem();
	};
	Elem *head;
	int cnt;//count elem in list(stack)
public:
	StackList();
	~StackList();
	int push(int);//set
	int pop();//get
	void show();
	int count();
	bool isEmpty();
};
//stack base linked list base stack
class StackListStack {
	class Elem {
	public:
		Stack* stack;//int value;
		Elem* next;
		Elem(int);
		~Elem();
	};
	Elem* head;
	int cnt;//count elems in all inner stacks
	int size;
public:
	StackListStack(int);//send size of any inner stack
	~StackListStack();
	int push(int);//set
	int pop();//get
	void show();
	int count();
	bool isEmpty();
};


#endif // !STACK_H
