#pragma once
#ifndef STACK_H
#define STACK_H
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

#endif // !STACK_H
