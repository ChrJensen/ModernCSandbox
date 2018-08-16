#include "stdafx.h"

#include <variant>
#include <iostream>

using namespace std;

class Node
{
public:
	int i;
	double d;
	Node() : i{ -1 }, d{ 2 } {}
	~Node() {  }
};

void print_type(const std::variant<double, int, Node*> v)
{
	if (holds_alternative<int>(v))
		cout << "Variants holds int\n";
	else if (holds_alternative<double>(v))
		cout << "Variants holds double\n";
	else if (holds_alternative<Node*>(v))
		cout << "Variants holds Node\n";
	else
		cout << "Variants holds unknown\n";
}

void HandleSection2_4()
{
	cout << '\n';

	variant<double, int, Node*> v = 2.0;
	print_type(v);
	v = 0;
	print_type(v);
	const variant<double, int, Node*> w(new Node);
	print_type(w);

}

