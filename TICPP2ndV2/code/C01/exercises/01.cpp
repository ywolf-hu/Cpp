#include <iostream>
#include <cstdio>
#include <exception>

extern "C"{
#include <errno.h>
#include <string.h>
#include <signal.h>
}

using namespace std;
typedef int error_t;
error_t func1();
void func2();

error_t func1()
{
  return 1;
}

void func2()
{
  errno = EIO;
}

void func3(int signo)
{
  switch(signo){
    case SIGHUP:
      cout << "Catch SIGHUP" << endl;
      break;
    }
}

class testException
{
public:
  testException(string whatString){
    m_whatString = whatString;
  }
  string what() {
    return m_whatString;
  }
private:
  string m_whatString;
};

void func4()
{
  testException tstException("testException");
  throw tstException;
}

int main()
{
  error_t ret_val;
  ret_val = func1();
  if (1 == ret_val){
  cout << "func1 error" << endl;
}
  func2();
  if (EIO == errno){
  cout << "func2 error" << endl;
  perror("func2 errno: ");
  cout << strerror(errno) << endl;
}
  try {
    func4();
  }
  catch (testException& tstException){
    cout << tstException.what() << endl;
  }
  signal(SIGHUP, func3);
  for(;;){}
  return 0;
}
