#include <iostream>
#include <vector>
#include <cstdlib>

extern "C"{

}

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
  void anyFunc(int i) throw(char, int, bool, exceptionClass){
    switch (i){
    case 1 :
      throw 'a';
      break;
    case 2 :
      throw 99;
      break;
    case 3 :
      throw true;
      break;
    case 4 :
      throw 1.0;
      break;
    default:
      exceptionClass* pexceptionObj = new exceptionClass;
      throw *pexceptionObj;
      break;
    }
  }
};

void my_unexpected_handler()
{
  cout << "unexpected handler" << endl;
  exit(0);
}

int main(int argc, char* argv[])
{
  set_unexpected(my_unexpected_handler);
    try{
      anyClass anyclass;
      anyclass.anyFunc(atoi(argv[1]));
    }
    catch (char& x){
      cout << "One char thrown" << endl;
    }
    catch (int& x){
      cout << "One int thrown" << endl;
    }
    catch (bool& x){
      cout << "One bool thrown" << endl;
    }
    catch (anyClass::exceptionClass& x){
      cout << "One exceptionClass thrown" << endl;
    }
  return 0;
}
