#include <vector>
#include <stdexcept>
#include "Test.h"

using namespace std;
class TestVector: public TestSuite::Test {
public:
  TestVector(){}

  ~TestVector(){}

  void run(){
    vector<int> vector_int;
    vector_int.push_back(1);
    test_(1 == vector_int.back());
    test_(1 == vector_int.front());
    test_(1 == vector_int.at(0));
    test_(1 == vector_int.size());

    vector_int.push_back(2);
    test_(2 == vector_int.back());
    test_(1 == vector_int.front());
    test_(2 == vector_int.at(1));
    test_(2 == vector_int.size());

    try{
      vector_int.at(2);
      fail_("No exception");
    }
    catch(out_of_range& x){
      succeed_();
    }
  }
};

int main()
{
  TestVector testvector;

  testvector.run();

  testvector.report();

  return 0;
}
