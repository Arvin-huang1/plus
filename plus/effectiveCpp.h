#include "iostream"
using namespace std;
class member {
public:

	member(string name) :name(name) {
	}
	string name;
};
class Empty {
public:
	Empty(string name, int val) :name(name),val(val){};
	Empty(const Empty &rhs) {};
	Empty& operator=(const Empty &rhs) {};
	~Empty() {};
	int val;
	string name;
};