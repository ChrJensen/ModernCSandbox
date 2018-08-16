// TestCollection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ChapterHandler(void hdlr(const int &));
void HandleChapter1(const int &);
void HandleSection1_1();
void HandleSection1_2();
void HandleSection2_1();
void HandleSection2_4();
void HandleChapter2(const int &);
void traverse_sequence();
void test_references();
template<typename T> void traverse_vector(const vector<T> &v);

int main()
{
	cout << "Hello, World!\n";
	cout << "enter chapter";
	auto chap = 0;
	cin >> chap;

	switch (chap)
	{
	case 1:
		ChapterHandler(HandleChapter1);
		break;
	case 2:
		ChapterHandler(HandleChapter2);
		break;
	default:
		cout << "No such chapter";
		break;
	}
	return 0;
}

void ChapterHandler(void hdlr(const int &))
{
	cout << "enter section";
	auto sect = 0;
	cin >> sect;
	if (0 < sect)
		hdlr(sect);
}

void HandleChapter1(const int &sect)
{
	switch (sect)
	{
	case 1:
		HandleSection1_1();
		break;
	case 2:
		HandleSection1_2();
		break;
	default:
		cout << "No such section or not implemented ";
		break;
	}

}
void HandleSection1_1()
{
	test_references();
}
void HandleSection1_2()
{
	traverse_sequence();
	traverse_vector<double>({ 1.1, 2.2, 3.3, 4.4 });
	traverse_vector<int>({ 1, 2, 3, 4 });
}

void HandleChapter2(const int &sect)
{
	switch (sect)
	{
	case 1:
		HandleSection2_1();
		break;
	case 4:
		HandleSection2_4();
		break;
	default:
		cout << "No such section";
		break;
	}
}

void HandleSection2_1()
{
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
