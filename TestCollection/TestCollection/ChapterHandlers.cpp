#include "stdafx.h"
#include "ChapterHandlers.h"
#include "..\Chapter1\Chapter1.h"
#include "..\Chapter2\Chapter2.h"
#include "..\Chapter13\Chapter13.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
	using namespace Chapter1NS;
	auto p = make_unique<Chapter1>();
	switch (sect)
	{
	case 1:
		p->HandleSection1_1();
		break;
	case 2:
		p->HandleSection1_2();
		break;
	default:
		cout << "No such section or not implemented ";
		break;
	}

}

void HandleChapter2(const int &sect)
{
	using namespace Chapter2NS;
	auto p = make_unique<Chapter2>();
	switch (sect)
	{
	case 1:
		p->HandleSection2_1();
		break;
	case 4:
		p->HandleSection2_4();
		break;
	case 5:
		p->HandleSection2_5();
		break;
	default:
		cout << "No such section";
		break;
	}
}

void HandleChapter13(const int &sect)
{
	using namespace Chapter13NS;
	auto p = make_unique<Chapter13>();
	switch (sect)
	{
	case 1:
		p->HandleSection13_1();
		break;
	case 2:
		p->HandleSection13_2();
		break;
	case 3:
		p->HandleSection13_3();
		break;
	default:
		cout << "No such section or not implemented ";
		break;
	}

}

