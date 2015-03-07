#include <iostream>
#include <fstream>

using namespace std;

#if 0
#define DEBUG(str) cout << str << endl;
#else
#define DEBUG(str)
#endif

string toUpper(string& str)
{
  string upperStr;
  for(string::iterator iter=str.begin(); iter!=str.end(); iter++){
    upperStr += toupper(*iter);
  }
  return upperStr;
}

int main(int argc, char *argv[])
{
  if (4 != argc ){
    cout << "The right usage should be " << argv[0] << " inputFile fromStr toStr" << endl;
    return 1;
  }

  string fileName(argv[1]);
  string fromStr(argv[2]);
  string toStr(argv[3]);

  string upperFromStr = toUpper(fromStr);
  DEBUG(upperFromStr);
  ifstream inputFile(argv[1]);
  if(!inputFile){
    cout << "Open " << fileName << " failed" << endl;
    return 2;
  }

  string orgLineStr;
  while (getline(inputFile, orgLineStr)){
    string replacedLineStr;
    string remainStrPiece = orgLineStr;
    string upperRemainStrPiece = toUpper(remainStrPiece);
    DEBUG(upperRemainStrPiece);
    size_t fromStrPos = upperRemainStrPiece.find(upperFromStr);
    DEBUG(fromStrPos);
    while(string::npos != fromStrPos){
      size_t startPos = 0;
      string strPiece = remainStrPiece.substr(startPos, fromStrPos+fromStr.length());
      strPiece.replace(fromStrPos, fromStr.length(), toStr);
      replacedLineStr += strPiece;
      startPos = fromStrPos + fromStr.length();
      remainStrPiece = remainStrPiece.substr(startPos, remainStrPiece.length() - startPos);
      upperRemainStrPiece = toUpper(remainStrPiece);
      fromStrPos = upperRemainStrPiece.find(upperFromStr);
    }
    replacedLineStr += remainStrPiece;
    cout << replacedLineStr << endl;
  }
  return 0;
}
