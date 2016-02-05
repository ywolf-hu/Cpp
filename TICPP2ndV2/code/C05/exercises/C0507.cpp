//: C05:Exercise7.cpp {-xo}
#include <iostream>

using namespace std;

class Buddy {};

template<class T> class My {
	int i;
// public:
	friend void play(My<Buddy>& s) {
		s.i = 3;
	}
public:
	void go(My<Buddy>& s)
	{
		play(s);
	}
	friend ostream& operator<<(ostream& p_os, My<Buddy>& s)
	{
		p_os << s.i << endl;
		return p_os;
	}
};

int main() {
  // My<int> h;
  My<Buddy> bud;
  play(bud);
  // h.go(bud);
  cout << bud; //operator<<(cout, bud)
} ///:~