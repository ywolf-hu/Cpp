#include <string>
#include <iostream>

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
  string inputStr;
  string punctuationSet = ".,:! ";
  string filterStr;
  bool palindromeFlag = true;
  cout << "Please input word: ";
  while(getline(cin, inputStr)) {
    for (string::iterator iter = inputStr.begin(); iter != inputStr.end(); iter++) {
      if((string::npos == punctuationSet.find(*iter))){
        filterStr += *iter;
      }
    }
    RevertString revertStr(filterStr);
    revertStr.convert();
    string convertedStr = revertStr.get();
    for(size_t i=0; i != filterStr.length(); i++){
      if (toupper(filterStr[i]) != toupper(convertedStr[i])){
        palindromeFlag = false;
        break;
      }
    }
    if(true == palindromeFlag){
      cout << inputStr << " is palindrome" << endl;
    }
    else {
      cout << inputStr << " is not palindrome" << endl;
    }
  }
  return 0;
}
