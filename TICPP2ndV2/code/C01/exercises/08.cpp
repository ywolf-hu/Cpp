#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class anyClass
{
public:
  anyClass(){
    cout << "anyClass Constructor" << endl;
  }

  ~anyClass(){
    cout << "anyClass Destructor" << endl;
  }
class exceptionClass
{
public:
  exceptionClass(){
    cout << "exceptionClass Constructor" << endl;
  }
  ~exceptionClass(){
    cout << "exceptionClass Destructor" << endl;
  }
};
  void anyFunc(){
    exceptionClass* pexceptionObj = new exceptionClass;
    throw pexceptionObj;
  }
};

int main()
{
    try{
      anyClass anyclass;
      anyclass.anyFunc();
    }
    catch (anyClass::exceptionClass* x){
      cout << "One exception thrown" << endl;
    }
  return 0;
}
