//: C05:Exercise4.cpp {-xo}
#include <iostream>

class Noncomparable
{
/*public:
  bool operator==(Noncomparable& p_nonComparableObj)
  {
    return true;
  }*/
};
/*
struct HardLogic {
  Noncomparable nc1, nc2;
  void compare() {
    return nc1 == nc2; // Compiler error
  }
};
*/
template<class T> struct SoftLogic {
  T nc1, nc2;
  void noOp() {}
  void compare() {
    nc1 == nc2;
  }
};

int main() {
  SoftLogic<Noncomparable> l;
  l.noOp();
  // std::cout << l.compare() << std::endl;
} ///:~