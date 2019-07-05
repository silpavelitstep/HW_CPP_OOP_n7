#include "queue.h"
//#include "stack.h"
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
int main() {
	// max 500 000 int numbers using for test
	//using random generation from 0 to 1000
	//methods 'add' and 'extract' using random too. 
	const int iter = 500;//count exe add+extract
	const int range = 10;//random int from 0 to 9
	//testQueue(iter,range);
	//testQueueRing(iter, range);
	testQueuePriority(iter, range);
	/*
	{
		QueuePriorityLinkedList quPriLL;
		quPriLL.add(0, 1);
		quPriLL.add(1, 11);
		quPriLL.add(2, 21);
		quPriLL.add(1, 12);
		quPriLL.show();
		cout << '>' << quPriLL.extract() << endl;
		cout << '>' << quPriLL.extract() << endl;
		cout << '>' << quPriLL.extract() << endl;
		cout << '>' << quPriLL.extract() << endl;
		cout << '>' << quPriLL.extract() << endl;
		cout << '>' << quPriLL.extract() << endl;
		cout << '>' << quPriLL.extract() << endl;
		quPriLL.show();

	}
	*/
	
	
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
	QueuePriorityLinkedList quPLL;
	for (int i = 0; i < iter; i++) {
		if (rand() % 2) {
			quPLL.add(rand() % range, rand() % range);
		}
		else {
			if (rand() % 2) {
				quPLL.extract(rand() % range);
			}
			else {
				//quPLL.extract();
			}
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
