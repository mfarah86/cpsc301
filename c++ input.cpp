#include <iostream>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;

int main()
{
  ifstream inData;
  int records = 0;
  string rest = "";
  inData.open("data.txt");

  while(inData)
  {
    getline(inData, rest);
    records++;
  }




  inData.close("data.txt");
  return 0;
}
