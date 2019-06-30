#include "queue.h"
#include "stack.h"
#include <iostream>
using namespace std;
void pause();
int main() {
	pause();
	return 0;
}
void pause() {
	cout << "<Press [Enter] for closing!>";
	char ps[100];
	cin.getline(ps,'\n');
}