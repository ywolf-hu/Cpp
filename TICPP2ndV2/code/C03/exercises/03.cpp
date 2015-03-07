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
  string inputWord;
  bool palindromeFlag = true;
  cout << "Please input word: "<< endl;
  while(cin >> inputWord) {
    RevertString revertString(inputWord);
    revertString.convert();
    string convertedWord = revertString.get();
    for(size_t i=0; i != inputWord.length(); i++){
      if (toupper(inputWord[i]) != toupper(convertedWord[i])){
        palindromeFlag = false;
        break;
      }
    }
    if(true == palindromeFlag){
      cout << inputWord << " is palindrome" << endl;
    }
    else {
      cout << inputWord << " is not palindrome" << endl;
    }
  }
  return 0;
}
