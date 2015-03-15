#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#if 0
#define DEBUG(str) cout << str << endl;
#else
#define DEBUG(str)
#endif

string replaceFromStrToToStr(string line, string from, string to)
{
  size_t fromPos = line.find(from);
  while(string::npos != fromPos){
    line.replace(fromPos, from.length(), to);
    fromPos = line.find(from, fromPos+to.length());
  }
  return line;
}

void filterBothStrFromFile(ifstream& fileName, string& oneStr, string& anotherStr)
{
  string lineStr;
  string convLineStr;
  while (getline(fileName, lineStr)){
    if ((string::npos != lineStr.find(oneStr)) && (string::npos != lineStr.find(anotherStr))){
      DEBUG(lineStr);
      convLineStr = replaceFromStrToToStr(lineStr, oneStr, "*"+oneStr+"*");
      convLineStr = replaceFromStrToToStr(convLineStr, anotherStr, "*"+anotherStr+"*");
      cout << convLineStr << endl;
    }
  }
}

void filterEitherStrFromFile(ifstream& fileName, string& oneStr, string& anotherStr)
{
  string lineStr;
  string convLineStr;
  while (getline(fileName, lineStr)){
    if ((string::npos != lineStr.find(oneStr)) || (string::npos != lineStr.find(anotherStr))){
      DEBUG(lineStr);
      convLineStr = replaceFromStrToToStr(lineStr, oneStr, "*"+oneStr+"*");
      convLineStr = replaceFromStrToToStr(convLineStr, anotherStr, "*"+anotherStr+"*");
      cout << convLineStr << endl;
    }
  }
}

void filterOnlyOneStrFromFile(ifstream& fileName, string& oneStr, string& anotherStr)
{
  string lineStr;
  string convLineStr;

  while (getline(fileName, lineStr)){
    if (((string::npos != lineStr.find(oneStr)) && (string::npos == lineStr.find(anotherStr)))
        || ((string::npos != lineStr.find(anotherStr)) && (string::npos == lineStr.find(oneStr)))){
      DEBUG(lineStr);
      convLineStr = replaceFromStrToToStr(lineStr, oneStr, "*"+oneStr+"*");
      convLineStr = replaceFromStrToToStr(convLineStr, anotherStr, "*"+anotherStr+"*");
      cout << convLineStr << endl;
    }
  }
}

void filterNeitherStrFromFile(ifstream& fileName, string& oneStr, string& anotherStr)
{
  string lineStr;
  while (getline(fileName, lineStr)){
    if ((string::npos == lineStr.find(oneStr)) && (string::npos == lineStr.find(anotherStr))){
      cout << lineStr << endl;
    }
  }
}

int main(int argc, char *argv[])
{
  if(5 != argc ){
    cout << "Right Usage should be " << argv[0] << " " << "fileName string1 string2 filter" << endl;
    cout << "filter can be both/either/onlyOne/neither"<< endl;
    return 1;
  }

  ifstream fileName(argv[1]);

  if(!fileName){
    cout << "Open "<< argv[1] << "failed" << endl;
    return 2;
  }

  string inStr1 = argv[2];
  string inStr2 = argv[3];

  string filterStr = argv[4];

  string bothStr = "both";
  string eitherStr = "either";
  string onlyStr = "onlyOne";
  string neitherStr = "neither";

  if (filterStr == bothStr){
  filterBothStrFromFile(fileName, inStr1, inStr2);
  }
  else if (filterStr == eitherStr){
  filterEitherStrFromFile(fileName, inStr1, inStr2);
  }
  else if (filterStr == onlyStr){
  filterOnlyOneStrFromFile(fileName, inStr1, inStr2);
  }
  else if (filterStr == neitherStr){
  filterNeitherStrFromFile(fileName, inStr1, inStr2);
  }
  else {
    cout << "Wrong filter option input" << endl;
  }

  return 0;
}
