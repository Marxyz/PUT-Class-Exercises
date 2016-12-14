#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<list>
#include <ctime>
using namespace std;

void fillList(list<int>&l) {
	for (auto itr = l.begin(); itr != l.end(); itr++) {
		*itr = rand();
	}
}

void showList(const list<int>&l) {
	for (auto itr = l.begin(); itr != l.end(); itr++) {
		cout << *itr << endl;
	}
}

void mergeList(list<int> &l1, const list<int> &l2) {
	for (auto itr = l2.begin(); itr != l2.end(); itr++) {
		l1.push_back(*itr);
	}
}

int main() {
	srand(time(NULL));

	list<int> firstList;
	list<int> secList;
	int size;

	cin >> size;
	firstList.resize(size);
	secList.resize(size);

	fillList(firstList);
	showList(firstList);
	cout << endl;
	fillList(secList);
	showList(secList);
	cout << endl;
	
	mergeList(firstList, secList);
	showList(firstList);

	system("PAUSE");
	return 0;
}