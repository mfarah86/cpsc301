#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "person3.h"
#include "person3.cpp"

int readData(vector<Person> &emp);
int companyNames(int size, vector<Person> &emp, vector<string> &comp);
void printHighestPaid(int size, vector<Person> &emp);
void separateAndSave(int eSize, int cSize, vector<Person> &emp, vector<string> &cNames);

int main()
{
  vector<string> cNames;
  vector<Person> employees;
  int fileSize;
  int compSize;

  fileSize = readData(employees);
  compSize = companyNames(fileSize, employees, cNames);
  printHighestPaid(fileSize, employees);
  separateAndSave(fileSize, compSize, employees, cNames);

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

  inFile >> firstName;
  while(!inFile.eof())
  {
    inFile >> lastName >> idNum >> compName >> hours >> rate;

    p.setFirstName(firstName);
    p.setLastName(lastName);
    p.setEmployeeId(idNum);
    p.setCompanyName(compName);
    p.setHoursWorked(hours);
    p.setPayRate(rate);

    inFile >> firstName;

    emp.push_back(p);

    //cout << emp.at(i).getFirstName() << " " << emp.at(i).getLastName() << " " << emp.at(i).getEmployeeId() << " "
    //<< emp.at(i).getCompanyName() << " " << emp.at(i).getHoursWorked() << " " << emp.at(i).getPayRate() << endl;

    i++;
  }
  cout << endl;
  inFile.close();

  return i;
}

int companyNames(int size, vector<Person> &emp, vector<string> &comp)
{
  int count = 1;
  string temp1 = "";
  string temp2 = "";
  for (int i = 0; i < size; i++)
  {
    temp1 = emp.at(i).getCompanyName();
    for (int j = 0; j < count; j++)
    {
      temp2 = comp.at(j);
      if (temp1==temp2)
      {
        count++;
      }
    }
  }

  return count;
}

void printHighestPaid(int size, vector<Person> &emp)
{
  float highestPay = 0;
  int empLoc = 0;
  for(int i = 0; i < size; i++)
  {
    if(emp.at(i).totalPay() > highestPay)
    {
      highestPay = emp.at(i).totalPay();
      empLoc = i;
    }
  }

  cout << "Highest paid: " << emp.at(empLoc).fullName() << endl
  << "Employee ID: " << emp.at(empLoc).getEmployeeId() << endl
  << "Employer: " << emp.at(empLoc).getCompanyName() << endl
  << "Total Pay: $" << emp.at(empLoc).totalPay() << endl;

}

void separateAndSave(int eSize, int cSize, vector<Person> &emp, vector<string> &cNames)
{
  ofstream outFile;
  string temp1;
  string temp2;
  for (int i = 0; i < eSize; i++)
  {
    temp1 = emp.at(i).getCompanyName();
    for (int j = 0; j < cSize; j++)
    {

    }

  }

}
