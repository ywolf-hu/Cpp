#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string puncSet(",.:!");

#if 0
#define DEBUG(str) cout << str << endl;
#else
#define DEBUG(str)
#endif

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
  DEBUG(__FUNCTION__);
  RevertString revertString(word);
  revertString.convert();
  string convertedWord = revertString.get();
  for(size_t i=0; i != word.length(); i++){
    if (toupper(word[i]) != toupper(convertedWord[i])){
      return false;
    }
  }
  DEBUG("true");
  return true;
}

vector<string> splitInSpace(string str)
{
  DEBUG(__FUNCTION__);
  vector<string> wordLists;
  size_t startPos = 0;
  string delim(" ");
  string word;
  size_t delimPos = str.find(delim);
  while(string::npos != delimPos){
    string word = str.substr(startPos, delimPos-startPos);
    wordLists.push_back(word);
    DEBUG(word);
    startPos = delimPos + delim.length();
    DEBUG(startPos);
    delimPos = str.find(delim, startPos);
    DEBUG(delimPos);
  }
  word = str.substr(startPos, str.length()-startPos);
  wordLists.push_back(word);

  return wordLists;
}

bool isWordExist(string word, vector<string>& wordsList)
{
  DEBUG(__FUNCTION__);
  for(vector<string>::iterator iter=wordsList.begin(); iter!=wordsList.end(); iter++){
    if(*iter == word){
      return true;
    }
  }
  DEBUG("false");
  return false;
}

string toUpper(string word)
{
  string upperStr;
  for(string::iterator iter=word.begin(); iter!=word.end(); iter++){
    upperStr += toupper(*iter);
  }
  return upperStr;
}

bool isWordExistIgnoreCase(string word, vector<string>& wordsList)
{
  DEBUG(__FUNCTION__);
  for(vector<string>::iterator iter=wordsList.begin(); iter!=wordsList.end(); iter++){
    if(toUpper(*iter) == toUpper(word)){
      return true;
    }
  }
  DEBUG("false");
  return false;
}

void displayWords(vector<string>& wordsList)
{
  DEBUG(__FUNCTION__);
  for(vector<string>::iterator iter=wordsList.begin(); iter!=wordsList.end(); iter++){
    cout << *iter << " ";
  }
  cout << endl;
}

void remOneKindPuncInStr(string& str, const char punc)
{
  DEBUG(__FUNCTION__);
  DEBUG(punc);
  string::iterator beginIter = str.begin();
  string::iterator endIter = str.end();
    for(string::iterator iter=beginIter; iter!=endIter; iter++){
    if(punc == *iter){
      str.erase(iter);
    }
  }
  DEBUG(str);
}

void remAllPuncInStr(string& str, const string puncSet)
{
  for (string::const_iterator iter=puncSet.begin(); iter!=puncSet.end(); iter++){
    remOneKindPuncInStr(str, *iter);
  }
}

vector<string> genPalindromeWords(ifstream& ifileStream)
{
  DEBUG(__FUNCTION__);
  string line;
  vector<string> wordsList;
  vector<string> palindromeWords;
  while(getline(ifileStream, line)){
    remAllPuncInStr(line, puncSet);
    wordsList = splitInSpace(line);
    for(vector<string>::iterator iter=wordsList.begin(); iter!=wordsList.end(); iter++){
      DEBUG(*iter);
      if(isPalindromeWord(*iter)){
        if (!isWordExistIgnoreCase(*iter, palindromeWords)){
          DEBUG("push back");
          palindromeWords.push_back(*iter);
        }
      }
    }
  }

  return palindromeWords;
}

int main(int argc, char *argv[])
{
  if(2 != argc){
    string progName(argv[0]);
    cout << "Right usage should be: " << endl;
    cout << "\t" << progName << " fileName" << endl;
    return 1;
  }

  string fileName(argv[1]);
  ifstream ifileStream(fileName.c_str());
  if(!ifileStream){
    cout << "Open " << fileName << "failed" << endl;
    return 2;
  }

  vector<string> palindromeWords = genPalindromeWords(ifileStream);

  displayWords(palindromeWords);
  return 0;
}
