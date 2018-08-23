#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

enum class plant { tree, bush, flower, grass };

plant& operator++(plant & t)
{
	switch (t) {
		case plant::tree : return t=plant::bush;
		case plant::bush : return t = plant::flower;
		case plant::flower : return t = plant::grass;
		case plant::grass : return t = plant::tree;
		default: throw new exception("unknown type");
	}
}

template<typename Target = string, typename Source = plant> Target to(Source t)
{
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
{
	lhs << to(rhs);
	return lhs;
}

void HandleSection2_5()
{
	cout << '\n';

	auto v = plant::bush;
	cout << v << '\n';

	++v;
	cout << to(v) << '\n';

	++v;
	cout << to(v) << '\n';

	v = plant::tree;

}

