#include "stack.h"
#include <iostream>
using namespace std;
Stack::Stack(int size) {//size - size of inner array
	array = new int[size];
	this->size = size;
	pos = -1;//if array is empty
	//cout << "new Stack\t" << (int)this << endl;
}
Stack::~Stack() {
	delete[] array;
	//cout << "free Stack\t" << (int)this << endl;
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
		cout << "[empty stack]\n";
	else {
		for (int i = 0; i <= pos; i++)
			cout << array[i] << ' ';
		cout << endl;
	}
	cout << "count=" << count() << endl;
}
int Stack::count() {
	return pos + 1;
}
bool Stack::isEmpty() {
	return pos == -1;
}