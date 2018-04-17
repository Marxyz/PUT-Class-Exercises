#include <iostream>
#include <vector>
#include <list>
#include <chrono>
using namespace std;
using namespace chrono;


long long TestVector_PushBack(vector<int> &v, int elements_count)
{
	v.resize(elements_count);
	auto begin = steady_clock::now();
	for (int i = 0; i < elements_count; i++)
	{
		v.push_back(i);
	}
	auto end = steady_clock::now();
	return duration<double, milli>(end - begin).count();
}
long long TestVector_Insert(vector<int> &v, int elements_count)
{
	v.resize(elements_count);
	auto begin = steady_clock::now();
	for (int i = 0; i < elements_count; i++)
	{
		v.insert(v.begin(), i);
	}

	auto end = steady_clock::now();
	return duration<double, milli>(end - begin).count();
}
long long TestList_PushBack(list<int> &l, int elements_count)
{
	l.resize(elements_count);
	auto begin = steady_clock::now();
	for (int i = 0; i < elements_count; i++)
	{
		l.push_back(i);
	}

	auto end = steady_clock::now();
	return duration<double, milli>(end - begin).count();
}
long long TestList_PushFront(list<int> &l, int elements_count)
{
	l.resize(elements_count);
	auto begin = steady_clock::now();
	for (int i = 0; i < elements_count; i++)
	{
		l.push_front(i);
	}

	auto end = steady_clock::now();
	return duration<double,milli>(end - begin).count();
}


int main()
{
	vector<int> v;
	list<int> l;
	int count = 100000;
	cout << "TestVector_PushBack duration : " << TestVector_PushBack(v,count) << endl;
	cout << "TestVector_Insert duration : " << TestVector_Insert(v,count) << endl;
	cout << "TestList_PushBack duration : " << TestList_PushBack(l,count) << endl;
	cout << "TestList_PushFront duration : " << TestList_PushFront(l,count) << endl;
	return 0;
}
