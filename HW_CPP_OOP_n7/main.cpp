#include "queue.h"
//#include "stack.h"
#include <iostream>
#include <time.h>
using namespace std;
void pause(const char* ch = " ");//pause cross system
void test(int,int);
int queueArray(int,int);//return time of executing queue base array
int queueLinkedList(int, int);//base linked list
int queueLinkedListArray(int, int, int);//base linked list which base on array
int main() {
	// max 500 000 int numbers using for test
	//using random generation from 0 to 1000
	//methods 'add' and 'extract' using random too. 
	const int iter = 500000;//count exe add+extract
	const int range = 10;//random int from 0 to 9
	test(iter,range);
	/*{
		QueueLinkedListArray quLLA(10);
		for (int i = 1; i <= 50; i++) {
			if (rand() % 2)
				cout << '+' << quLLA.add(rand() % range) << endl;
			else
				cout <<'-' <<quLLA.extract() << endl;
		}
		
		pause("End QueueLinkedListArray TEST");
	}*/
	
	pause("End program! ");
	return 0;
}
void test(int iter, int range) {
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
