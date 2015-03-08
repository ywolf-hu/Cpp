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

bool isPalindromeWord(string word)
{
    RevertString revertString(word);
    revertString.convert();
    string convertedWord = revertString.get();
    for(size_t i=0; i != word.length(); i++){
      if (toupper(word[i]) != toupper(convertedWord[i])){
      return false;
      }
    }
    return true;
}

int main()
{
  string inputWord;
  cout << "Please input word: "<< endl;
  while(cin >> inputWord) {
    if(true == isPalindromeWord(inputWord)){
      cout << inputWord << " is palindrome" << endl;
    }
    else {
      cout << inputWord << " is not palindrome" << endl;
    }
  }
  return 0;
}
