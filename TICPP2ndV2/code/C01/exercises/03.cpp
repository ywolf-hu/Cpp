#include <iostream>
//#include <stdexcept>

using namespace std;

int main()
{
  try{
    throw 1;
  }
  catch (...){
    cout << "One exception thrown" << endl;
  }
  return 0;
}
