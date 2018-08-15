// TestCollection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


void traverse_sequence();
void test_references();
template<typename T> void traverse_vector(const vector<T> &v);

int main()
{
	cout << "Hello, World!\n";
	test_references();
	traverse_sequence();
	traverse_vector<double>({ 1.1, 2.2, 3.3, 4.4 });
	traverse_vector<int>({ 1, 2, 3, 4 });
	return 0;
}

void test_references()
{
	cout << '\n';
	auto x = 7;
	auto& rx{ x };
	cout << rx << '\n';
	rx = 8;
	cout << rx << '\n';
	
	auto& rx2 = x;
	rx2++;
	cout << rx2 << '\n';
}
void traverse_sequence()
{
	cout << '\n';
	int v[] = { 0,1,2,3,4,5,6,7,8,9 };

	for (auto x : v)
		cout << x << '\n';

	cout << '\n';
	for (auto x : { 10,21,32,43,54,65,76 })
		cout << x << '\n';
}

template<typename T> void traverse_vector(const vector<T> &v)
{
	cout << '\n';
	for (auto x : v)
		cout << x << '\n';

	cout << '\n';
	for (auto& x : v)
		cout << x << '\n';
	//for (auto& x : v) ++x; // cannot do this with const modifier on argument
}
