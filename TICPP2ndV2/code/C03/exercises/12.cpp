// for line in file:
// count charactor num
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#define DEBUG(str) cout << #str << " : " << str << endl;

struct charInfo
{
  char name;
  int count;
};

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
  ifstream fileStream(argv[1]);
  if(!fileStream){
    cout << "Open " << argv[1] << " failed" << endl;
    return 1;
  }

  charInfo firstCharInfo = {'a', 0};
  charInfoList.push_back(firstCharInfo);
  string line;
  while (getline(fileStream, line)){
    updateCharCount(line);
  }
  displayCharUsage();
  return 0;
}
