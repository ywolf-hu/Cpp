#include "Test.h"
#include <string>

using namespace std;

class RevertString {
public:
  RevertString(string orgStr){
    m_str = orgStr;
  }
  ~RevertString(){}

  void convert(){
    string tmpString(m_str.rbegin(), m_str.rend());
    m_str = tmpString;
  }

  string get(){
    return m_str;
  }
private:
  string m_str;
};

class RevertString;

class TestRevertString: public TestSuite::Test {
public:
  TestRevertString(){}

  ~TestRevertString(){}

  void run(){
    RevertString revertString("abcdefg");
    revertString.convert();
    string expectedRevertedString = "gfedcba";
    test_(expectedRevertedString == revertString.get());
  }
};

int main()
{
  TestRevertString testRevertString;

  testRevertString.run();

  testRevertString.report();

  return 0;
}
