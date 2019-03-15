// TestCollection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "ChapterHandlers.h"

using namespace std;


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
	case 13:
		ChapterHandler(HandleChapter13);
		break;
	default:
		cout << "No such chapter";
		break;
	}
	return 0;
}



