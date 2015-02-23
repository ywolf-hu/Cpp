#include <iostream>
#include <vector>

using namespace std;
class opNewClass;
vector<opNewClass*> m_vec;

class opNewClass
{
public:
  static void* operator new(size_t size){
    void* pa;
    for (int i = 0; i < 10; i++) {
      cout << size << endl;
      pa = ::operator new(size);
      cout << "address=" << pa << endl;
      m_vec.push_back(static_cast<opNewClass*>(pa));
    }
    // return pa;
    throw 1;
  }
  static void reclaimMem(){
    for (vector<opNewClass*>::iterator iter= m_vec.begin(); iter != m_vec.end(); iter++) {
      cout << "delete" << endl;
      delete (*iter);
    }
    m_vec.clear();
  }

  opNewClass(int i){
    cout << "Constructor" << endl;
    cout << "memaddress=" << &mem << endl;
    mem = i;
    cout << "mem=" << mem << endl;
  }
private:
  int mem;
};

int main()
{
  int loop = 0;
  while (loop < 2){
    try{
      new opNewClass(1);
    }
    catch (int& x){
      cout << "One exception thrown" << endl;
      cout << "Reclaim memory and continue" << endl;
      opNewClass::reclaimMem();
    }
    loop++;
  }
  return 0;
}
