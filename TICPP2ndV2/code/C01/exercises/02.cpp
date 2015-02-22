#include <iostream>
#include <stdexcept>

using namespace std;
class WithException
{
public:
  class oneException : public runtime_error{
  public:
    oneException(const char* str) : runtime_error(str){
    }
  };

  void memFunc() throw(oneException) {
    throw oneException("oneException thrown");
  }
};

  int main()
  {
    WithException testException;
    try{
      testException.memFunc();
    }
    catch (WithException::oneException& oneExceptionObj){
      cout << oneExceptionObj.what() << endl;
    }
    return 0;
  }
