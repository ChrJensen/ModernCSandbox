// TestCollection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ChapterHandler(void hdlr(const int &));
void HandleChapter1(const int &);
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



