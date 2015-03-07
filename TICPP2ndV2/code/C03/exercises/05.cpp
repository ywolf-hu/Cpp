#include <string>
#include <iostream>

using namespace std;

int main()
{
  string one("I walked down the canyon with the moving mountain bikers.");
  string two("The bikers passed by me too close for comfort.");
  string three("I went hiking instead.");

  string walkedStr("walked");
  size_t walkedPos = one.find("walked");
  one.replace(walkedPos, walkedStr.length(), "moved");
  string movingStr("moving ");
  size_t movingPos = one.find(movingStr);
  one.erase(movingPos, movingStr.length());

  string bikersStr("bikers");
  size_t bikersPos = two.find(bikersStr);
  two.replace(bikersPos, bikersStr.length(), "mountains bikers");

  cout << one << " " << two << " " << "So " + three << endl;
  return 0;
}
