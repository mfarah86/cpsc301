#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "person.h"
#include "person.cpp"

using namespace std;

int readData(Person employees[]);
void writeData(int fileSize, Person employees[]);

int main()
{
  Person employees[20];
  int fileSize = 0;
  fileSize = readData(employees);
  writeData(fileSize, employees);

  return 0;
}

int readData(Person employees[])
{
  ifstream inFile;
  string fName;
  string lName;
  float hoursWorked;
  float payRate;
  int i = 0;
  inFile.open("input.txt");

  while(!inFile.eof())
    {
      inFile >> fName;
      employees[i].setFirstName(fName);
      employees[i].getFirstName();

      inFile >> lName;
      employees[i].setLastName(lName);
      employees[i].getLastName();

      inFile >> hoursWorked;
      employees[i].setHoursWorked(hoursWorked);
      employees[i].getHoursWorked();

      inFile >> payRate;
      employees[i].setPayRate(payRate);
      employees[i].getPayRate();
      i++;
    }
    i--;
    inFile.close();
    return i;

}
void writeData(int fileSize, Person employees[])
{
  ofstream outFile;
  outFile.open("output.txt");
  for(int i = 0; i < fileSize; i++)
  {
    outFile << employees[i].fullName() << " " << employees[i].totalPay()<< endl;
  }
  outFile.close();
}
