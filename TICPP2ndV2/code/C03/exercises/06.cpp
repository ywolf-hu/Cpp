#include <iostream>
#include <fstream>

using namespace std;

#if 0
#define DEBUG(str) cout << str << endl;
#else
#define DEBUG(str)
#endif

int main(int argc, char *argv[])
{
  if (4 != argc ){
    cout << "The right usage should be " << argv[0] << " inputFile fromStr toStr" << endl;
    return 1;
  }

  string fileName(argv[1]);
  string fromStr(argv[2]);
  string toStr(argv[3]);

  ifstream inputFile(argv[1]);
  if(!inputFile){
    cout << "Open " << fileName << " failed" << endl;
    return 2;
  }

  string orgLineStr;
  while (getline(inputFile, orgLineStr)){
    string replacedLineStr;
    string remainStrPiece = orgLineStr;
    DEBUG(remainStrPiece);
    size_t fromStrPos = remainStrPiece.find(fromStr);
    while(string::npos != fromStrPos){
      size_t startPos = 0;
      string strPiece = remainStrPiece.substr(startPos, fromStrPos+fromStr.length());
      strPiece.replace(fromStrPos, fromStr.length(), toStr);
      replacedLineStr += strPiece;
      startPos = fromStrPos + fromStr.length();
      remainStrPiece = remainStrPiece.substr(startPos, remainStrPiece.length() - startPos);
      fromStrPos = remainStrPiece.find(fromStr);
    }
    replacedLineStr += remainStrPiece;
    cout << replacedLineStr << endl;
  }
  return 0;
}
