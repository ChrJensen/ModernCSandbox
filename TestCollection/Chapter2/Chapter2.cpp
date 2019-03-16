#include "stdafx.h"
#include "Chapter2.h"

#include <variant>
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int i;
	double d;
	Node() : i{ -1 }, d{ 2 } {}
	~Node() {  }
};

void print_type(const variant<double, int, Node*> v)
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

Chapter2NS::Chapter2::Chapter2()
{
}


Chapter2NS::Chapter2::~Chapter2()
{
}

void Chapter2NS::Chapter2::HandleSection2_1()
{
}

void Chapter2NS::Chapter2::HandleSection2_4()
{
	cout << '\n';

	variant<double, int, Node*> v = 2.0;
	print_type(v);
	v = 0;
	print_type(v);
	const variant<double, int, Node*> w(new Node);
	print_type(w);

}

enum class plant { tree, bush, flower, grass };

plant& operator++(plant & t)
{
	switch (t) {
	case plant::tree: return t = plant::bush;
	case plant::bush: return t = plant::flower;
	case plant::flower: return t = plant::grass;
	case plant::grass: return t = plant::tree;
	default: throw new exception("unknown type");
	}
}

template<typename Target = string, typename Source = plant> Target to(Source t)
{ // Returns next value it will get if incremented!!!
	string res;
	switch (t) {
	case plant::tree: return res = "plant::bush";
	case plant::bush: return res = "plant::flower";
	case plant::flower: return res = "plant::grass";
	case plant::grass: return res = "plant::tree";
	default: return "unknown";
	}
}


ostream &operator<<(ostream& lhs, const plant& rhs)
{  // this streams out next value it will get if incremented!!!
	lhs << to(rhs);
	return lhs;
}

void Chapter2NS::Chapter2::HandleSection2_5()
{
	cout << '\n';

	auto v = plant::bush;
	cout << v << '\n';

	++v;
	cout << v << '\n';
	
	++v;
	cout << v << '\n';
	
	++v;
	cout << v << '\n';
	auto bb = v == plant::tree;
	
	cout << (bb ? "True" : "false") << '\n';
}
