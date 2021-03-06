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
	S(S&src)
	{
		s = "copy of ";
		s.append(src.s);
		j = 666;
		d = 6.66;
		cout << s.c_str() << "S created" << '\n';

	}
	S(S *src)
	{
		s = "ref copy of ";
		s.append(src->s);
		j = src->j;
		d = src->j;
		cout << s.c_str() << "S created" << '\n';

	}
	//S() = delete;

	S(int i, string s1, double d1) {
		j = i;
		s = s1;
		d = d1;
		cout << s.c_str() << " created" << '\n';
	}
	~S() 
	{
		cout << s.c_str() << " destroyed" << '\n';
	}
};

void usePtr(S &s)
{
	cout << "Using " << s.s.c_str() << '\n';
}

void Chapter13NS::Chapter13::HandleSection13_2()
{
	auto p1 = make_shared<S>(1, "P1 Acme Inc", 1.2);
	auto p2 = make_unique<S>(2, "P2 Ron Weasley", 3.2);

	cout << '\n';

	cout << "p1.d : =" << p1->d << '\n';
	cout << "p2   : =" << p2 << '\n';
	cout << "p2.j : =" << p2->j << '\n';

	{	
		auto p3 = move(p2);  // transfer ownership to p3 

		cout << "p3   : =" << p3 << '\n';
		cout << "p3.s : =" << p3->s.c_str() << '\n';
		cout << "p2   : =" << p2 << '\n';
		usePtr(*p3);
		shared_ptr<S> p4 = p1; // share owership with p1
		usePtr(*p4);
	}

	usePtr(*p1);

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

void useSpanS(span<S> p)
{
	cout << '\n';
//	for (S x : p)		x.d = 1.2;

	for (S y : p)
		cout <<" d = " << y.d << '\n';
}

void Chapter13NS::Chapter13::HandleSection13_3()
{

	int a[5];
	useSpan(a);
	useSpan({ a ,10 });
	useSpan({ a + 2,2 });

	auto p1 = new S(1, "P1 Acme Inc", 1.2);
	auto p2 = new S(2, "P2 Acme Inc", 3.2);
	auto p3 = new S(3, "P3 Acme Inc", 5.2);
	auto p4 = new S(4, "P4 Acme Inc", 133.2);

	cout << '\n';
	S a2[] =  { p1,p2,p3,p4 };
	useSpanS(a2);

}
