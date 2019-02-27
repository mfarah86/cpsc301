#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "person3.h"
#include "person3.cpp"

int readData(vector<Person> &emp);
void printHighestPaid(int size, vector<Person> &emp);
void separateAndSave(vector<Person> &emp, vector<string> &cNames);

int main()
{
  vector<string> companyNames;
  vector<Person> employees;
  int fileSize;

  fileSize = readData(employees);
  printHighestPaid(fileSize, employees);
  separateAndSave(employees, companyNames);

  return 0;
}

int readData(vector<Person> &emp)
{
  int i;
  string firstName;
  string lastName;
  int idNum;
  float rate;
  float hours;
  string compName;
  ifstream inFile;
  inFile.open("input3.txt");
  Person p;

  while(!inFile.eof())
  {
    inFile >> firstName >> lastName >> idNum >> compName >> hours >> rate;

    p.setFirstName(firstName);
    p.setLastName(lastName);
    p.setEmployeeId(idNum);
    p.setCompanyName(compName);
    p.setHoursWorked(hours);
    p.setPayRate(rate);

    emp.push_back(p);

    cout << emp.at(i).getFirstName() << " " << emp.at(i).getLastName() << " " << emp.at(i).getEmployeeId() << " "
    << emp.at(i).getCompanyName() << " " << emp.at(i).getHoursWorked() << " " << emp.at(i).getPayRate() << endl;

    if (inFile.eof())
    {
      //i++;
    }
    else
    {
      i++;
    }
  }
  inFile.close();

  return i;
}

void printHighestPaid(int size, vector<Person> &emp)
{

}

void separateAndSave(vector<Person> &emp, vector<string> &cNames)
{

}
