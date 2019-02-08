#include <iostream>

using namespace std;

void printArray(int array[])
{
  for (int i = 0; i < 4; i++)
  {
    cout << array[i] << " ";
  }
}

void reverseArray(int array[])
{
  int temp;
  for (int i = 0; i < 2; i++)
  {
    temp = array[i];
    array[i] = array[3-i];
    array[3-i] = temp;

  }
}

int main()
{
  int array [] = {1,2,3,4};

  printArray(array);
  cout << endl;
  reverseArray(array);
  printArray(array);
  cout << endl;

  return 0;
}
