#include "queue.h"
//#include "stack.h"
#include <iostream>
#include <time.h>
using namespace std;
void pause(const char* ch = " ");//pause cross system
void test(int,int);
int queueArray(int,int);//return time of executing queue base array
int queueLinkedList(int, int);//base linked list
int main() {
	// max 500 000 int numbers using for test
	//using random generation from 0 to 1000
	//methods 'add' and 'extract' using random too. 
	const int iter = 500000;//count exe add+extract
	const int range = 10;//random int from 0 to 9
	//test(iter,range);
	{
		QueueLinkedListArray quLLA(5);
		for (int i = 1; i <= 7; i++)
			quLLA.add(i);
		for(int i=1;i<=10;i++)
			cout<<'#'<<quLLA.extract()<<endl;
		
		quLLA.show();
		
		pause("End QueueLinkedListArray TEST");
	}
	
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
