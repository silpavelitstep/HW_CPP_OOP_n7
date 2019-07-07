#include "queue.h"
#include "stack.h"
#include <iostream>
#include <time.h>
using namespace std;
void pause(const char* ch = " ");//pause cross system
// simple
void testQueue(int,int);
int queueArray(int,int);//return time of executing queue base array
int queueLinkedList(int, int);//base linked list
int queueLinkedListArray(int, int, int);//base linked list which base on array
//
void testQueueRing(int, int);
int queueArrayRingLinkedList(int, int);
int queuePriority(int, int);
void testQueuePriority(int, int);
void testStack(int, int);
int stack(int, int);
int stackList(int, int);
int stackListStack(int, int);

int main() {
	// max 500 000 int numbers using for test
	//using random generation from 0 to 1000
	//methods 'add' and 'extract' using random too. 
	const int iter = 500000;//count exe add+extract
	const int range = 100;//random int from 0 to 9
	{
		testQueue(iter, range);
		//testQueueRing(iter, range);
		testQueuePriority(iter, range);
		testStack(iter, range);
		
		
		
	}
	
	pause("End program! ");
	return 0;
}
//
void testQueue(int iter, int range) {
	srand(time('\0'));
	cout << "middle executing time:\n";
	
	cout << "queueArray: "
		<<(queueArray(iter,range)+ queueArray(iter, range)+ queueArray(iter, range))/3
		<<" ms"<< endl;
	
	cout << "queueLList: "
		<< (queueLinkedList(iter, range) + queueLinkedList(iter, range) + queueLinkedList(iter, range)) / 3
		<< " ms" << endl;
	cout << "queue List Array (size array 100,1000,10.000):\n"
		<< queueLinkedListArray(iter, range, 100) << " ms" << ' '
		<< queueLinkedListArray(iter, range, 1000) << " ms" << ' '
		<< queueLinkedListArray(iter, range, 10000) << " ms" << ' ' << endl;


}
void pause(const char* ch) {
	cout << "\n>>>"<<ch<<"\n<Press [Enter] for closing!>";
	char ps[100];
	cin.getline(ps,'\n');
}
int queueArray(int iter,int range) {
	int startTime = clock();
	Queue qu(iter);
	for (int i = 0; i < iter; i++) {
		if (rand() % 2)
			qu.add(rand() % range);
		else
			qu.extract();
	}
	return clock() - startTime;
}
int queueLinkedList(int iter, int range) {
	int startTime = clock();
	QueueLinkedList quLL;
	for (int i = 0; i < iter; i++) {
		if (rand() % 2)
			quLL.add(rand() % range);
		else
			quLL.extract();
	}
	return clock() - startTime;

}
int queueLinkedListArray(int iter, int range, int sizeArr) {
	int startTime = clock();
	QueueLinkedListArray quLLA(sizeArr);
	for (int i = 0; i < iter; i++) {
		if (rand() % 2)
			quLLA.add(rand() % range);
		else
			quLLA.extract();
	}
	return clock() - startTime;
}
//

int queueArrayRingLinkedList(int iter, int range) {
	int startTime = clock();
	QueueRingLLA qu;
	for (int i = 0; i < iter; i++) {
		if (rand() % 2)
			qu.add(rand() % range);
		else
			qu.extract();
	}
	return clock() - startTime;
}
void testQueueRing(int iter, int range) {
	srand(time('\0'));
	cout << "middle executing time:\n";

	cout << "queueRingLLA: "
		<< (queueArrayRingLinkedList(iter, range)
			+ queueArrayRingLinkedList(iter, range)
			+ queueArrayRingLinkedList(iter, range))/3
		<< " ms" << endl;
}
int queuePriority(int iter, int range) {
	int startTime = clock();
	QueuePri qupri;
	int pri;
	for (int i = 0; i < iter; i++) {
		if (rand() % 2) {
			pri = rand() % 10;
			//cout << '+' << qupri.add(rand() % range, pri) << endl;
			qupri.add(rand() % range, pri);
		}
		else {
			//qupri.show();
			//cout << "-" << qupri.extract() << endl;
			qupri.extract();
		}
	}
	


	return clock() - startTime;
}
void testQueuePriority(int iter, int range) {
	srand(time('\0'));
	cout << "middle executing time:\n";
	cout << "queuePriority: "
		<< (queuePriority(iter, range) 
			+ queuePriority(iter, range) 
			 + queuePriority(iter, range)) / 3
		<< " ms" << endl;
}
//
int stack(int iter, int range) {
	int startTime = clock();
	Stack st(iter);
	for (int ir = 1; ir <= iter; ir++) {
		if (rand() % 2)
			st.push(rand() % range);
		else
			st.pop();
	}
	//st.show();
	return clock() - startTime;
}
void testStack(int iter, int range) {
	srand(time('\0'));
	cout << "middle executing time:\n";
	cout << "Stack: "
		<< (stack(iter, range)
			+ stack(iter, range)
			 + stack(iter, range)) / 3
		<< " ms" << endl;
	cout << "StackList: "
		<< (stackList(iter, range)
			+ stackList(iter, range)
			+ stackList(iter, range)) / 3
		<< " ms" << endl;
	cout << "StackListStack: "
		<< (stackListStack(iter, range)
			+ stackListStack(iter, range)
			+ stackListStack(iter, range)) / 3
		<< " ms" << endl;

}
int stackList(int iter, int range) {
	int startTime = clock();
	StackList st;
	for (int ir = 1; ir <= iter; ir++) {
		if (rand() % 2)
			st.push(rand() % range);
		else {
			//st.show();
			st.pop();
			//st.show();
		}
	}
	
	return clock() - startTime;

}
int stackListStack(int iter, int range) {
	int startTime = clock();
	StackListStack st(1000);
	for (int ir = 1; ir <= iter; ir++) {
		if (rand() % 2)
			st.push(rand() % range);
		else {
			//st.show();
			st.pop();
			//st.show();
		}
	}

	return clock() - startTime;
}