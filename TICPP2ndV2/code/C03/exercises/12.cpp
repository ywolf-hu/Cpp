#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#if 0
#define DEBUG(str) cout << #str << " : " << str << endl;
#else
#define DEBUG(str)
#endif

struct charInfo
{
  char name;
  int count;
};

struct sortInSeq
{
  bool operator() (charInfo oneCharInfo, charInfo anotherCharInfo){
    return (oneCharInfo.name < anotherCharInfo.name);
  }
} sortInSeqObj;

struct sortInAscend
{
  bool operator() (charInfo oneCharInfo, charInfo anotherCharInfo){
      return (oneCharInfo.count < anotherCharInfo.count);
  }
} sortInAscendObj;

struct sortIndescend
{
  bool operator() (charInfo oneCharInfo, charInfo anotherCharInfo){
      return (oneCharInfo.count > anotherCharInfo.count);
  }
} sortInDescendObj;

vector<charInfo> charInfoList;

void updateCharCount(string line)
{
  for(string::iterator it=line.begin(); it!=line.end(); it++){
    bool found = false;
    for(vector<charInfo>::iterator iter=charInfoList.begin(); iter!=charInfoList.end(); iter++){
      DEBUG(*it);
      DEBUG(iter->name);
      if(*it == iter->name){
        iter->count++;
        found = true;
        break;
      }
    }
    DEBUG(found);

    if(!found){
      charInfo newCharInfo = {*it, 1};
      charInfoList.push_back(newCharInfo);
    }
  }
}

void displayCharUsage()
{
  for(vector<charInfo>::iterator iter=charInfoList.begin(); iter!=charInfoList.end(); iter++){
    if(' ' == iter->name){
      cout << "Space" << " : " << iter->count << endl;
    }
    else{
      cout << iter->name << " : " << iter->count << endl;
    }
  }
}

int main(int argc, char *argv[])
{
  if(3 != argc){
    cout << "Right Usage should be: " << endl;
    cout << argv[0] << " filename order" << endl;
    return 1;
  }
  ifstream fileStream(argv[1]);
  if(!fileStream){
    cout << "Open " << argv[1] << " failed" << endl;
    return 2;
  }

  charInfo firstCharInfo = {'a', 0};
  charInfoList.push_back(firstCharInfo);
  string line;
  while (getline(fileStream, line)){
    updateCharCount(line);
  }

  char order = toupper(*argv[2]);
  if(order == 'A'){
    sort(charInfoList.begin(), charInfoList.end(), sortInAscendObj);
  }
  else if (order == 'D'){
    sort(charInfoList.begin(), charInfoList.end(), sortInDescendObj);
  }
  else{
    sort(charInfoList.begin(), charInfoList.end(), sortInSeqObj);
  }
  displayCharUsage();
  return 0;
}
