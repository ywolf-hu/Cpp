#include <iostream>
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


int main()
{
  string inputWord;
  cout << "Please input word: "<< endl;
  while(cin >> inputWord) {
    RevertString revertString(inputWord);
    revertString.convert();
    if(inputWord == revertString.get()){
      cout << inputWord << " is palindrome" << endl;
    }
    else {
      cout << inputWord << " is not palindrome" << endl;
    }
  }

  return 0;
}
