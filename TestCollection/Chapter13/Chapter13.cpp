// Chapter13.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Chapter13.h"
#include <iostream>
#include <vector>
#include "gsl\span"


using namespace std;

Chapter13NS::Chapter13::Chapter13()
{
}

Chapter13NS::Chapter13::~Chapter13()
{
}

void Chapter13NS::Chapter13::HandleSection13_1()
{
}

class S
{
public:
	int j;
	string s;
	double d;
	S(int i, string s1, double d1) {
		j = i;
		s = s1;
		d = d1;
	}
};

void usePtr(S s)
{
	cout << s.s.c_str() << '\n';
}

void Chapter13NS::Chapter13::HandleSection13_2()
{
	auto p1 = make_shared<S>(1, "Acme Inc", 1.2);
	auto p2 = make_unique<S>(2, "Ron Weasley", 3.2);

	cout << '\n';

	cout << p1->d << '\n';
	cout << p2 << '\n';
	cout << p2->j << '\n';

	auto p3 = move(p2);
	cout << p3 << '\n';
	cout << p3->s.c_str() << '\n';
	cout << p2 << '\n';


	usePtr(*p1);
	usePtr(*p3);

}
using namespace gsl;

void useSpan(span<int> p)
{
	cout << '\n';
	for (int x : p)
		x = 1;

	for (int y : p)
		cout << y << '\n';
}

void Chapter13NS::Chapter13::HandleSection13_3()
{

	int a[5];
	useSpan(a);
	useSpan({ a ,10 });
	useSpan({ a + 2,2 });

}
