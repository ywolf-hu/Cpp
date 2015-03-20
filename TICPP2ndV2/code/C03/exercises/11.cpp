// for word in file
// count substr number in word
// sum += count
// if substr in word
//   sum += count
//   sumwordlen += wordlength
//   wordcount += 1

//  output sum
//   output sumwordlen/wordcount

#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

#if 0
#define DEBUG(str) cout << #str << " is " << str << "#"<< endl;
#else
#define DEBUG(str)
#endif

vector<string> extractWordsInSep(string& line, string& delimiter)
{
  vector<string> wordsList;
  size_t startPos = 0;
  size_t endPos = 0;
  endPos = line.find(delimiter, 0);
  while(string::npos != endPos){
    string word = line.substr(startPos, endPos-startPos);
    DEBUG(startPos);
    DEBUG(endPos);
    DEBUG(endPos-startPos);
    startPos = endPos + 1;
    wordsList.push_back(word);
    endPos = line.find(delimiter, startPos);
  }
  return wordsList;
}

int countStrInWord(string& word, string& subStr)
{
  int count = 0;
  size_t pos = 0;
  while (string::npos != pos) {
    pos = word.find(subStr, pos);
    if(string::npos != pos){
      count += 1;
      pos += subStr.size();
    }
    DEBUG(pos);
  }

  return count;
}

int main(int argc, char *argv[])
{
  if(3 != argc){
    cout << "Right Usage should be: "<< endl;
    cout << "\t"<< argv[0] << " fileName findString" << endl;
    return 1;
  }
  DEBUG(argv[2]);

  ifstream inputFile(argv[1]);
  string findStr(argv[2]);
  string lineStr;
  string delimiter(" ");
  vector<string> wordsList;
  vector<int> wordsLen;
  int totalCount = 0;
  while (getline(inputFile, lineStr)){
    DEBUG(lineStr);
    wordsList = extractWordsInSep(lineStr, delimiter);
    for (vector<string>::iterator it=wordsList.begin(); it!=wordsList.end();it++){
      string word = *it;
      if(string::npos != word.find(findStr)){
        totalCount += countStrInWord(word, findStr);
        wordsLen.push_back(word.size());
        DEBUG(word);
        DEBUG(word.size());
      }
    }
  }

  int totalWordsLen = 0;
  for (vector<int>::iterator it=wordsLen.begin(); it!=wordsLen.end(); it++) {
    totalWordsLen += *it;
  }

  int avgWordLen = totalWordsLen/wordsLen.size();
  cout << "Total occurrences are " << totalCount << endl;
  cout << "Average length is " << avgWordLen << endl;
  return 0;
}
