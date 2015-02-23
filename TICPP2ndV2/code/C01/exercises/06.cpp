#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class anyClass
{
public:
  anyClass(){
    cout << "Constructor" << endl;
  }

  ~anyClass(){
    cout << "Destructor" << endl;
    throw 1;
  }

  void anyFunc() throw(int){
    throw 2;
  }
};

void terminator()
{
  cout << "Terminator" <<endl;
  exit(0);
}

void (*orgTerminator)() = set_terminate(terminator);

int main()
{
    try{
      anyClass anyclass;
      anyclass.anyFunc();
    }
    catch (...){
      cout << "One exception thrown" << endl;
    }
  return 0;
}
