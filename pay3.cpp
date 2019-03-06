#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "person3.h"
#include "person3.cpp"

void readData(vector<Person> &emp);
void companyNames(vector<Person> &emp, vector<string> &comp);
void printHighestPaid(vector<Person> &emp);
void separateAndSave(vector<Person> &emp, vector<string> &cNames);

int main()
{
  vector<string> cNames;
  vector<Person> employees;
  readData(employees);
  companyNames(employees, cNames);
  printHighestPaid(employees);
  separateAndSave(employees, cNames);

  return 0;
}

void readData(vector<Person> &emp)
{
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
  }
  inFile.close();
}

void companyNames(vector<Person> &emp, vector<string> &comp)
{
  int count = 0;
  bool duplicate = false;
  string temp1 = "";
  string temp2 = "";
  comp.push_back(emp.at(0).getCompanyName());
  for(int i = 0; i < emp.size(); i++)
  {
    duplicate = false;
    temp1 = emp.at(i).getCompanyName();
    for(int j=0; j < comp.size(); j++)
    {
      temp2 = comp.at(j);
      if(temp1==temp2)
      {
        duplicate = true;
        break;
      }
    }
    if(!duplicate)
    {
      comp.push_back(temp1);
    }
  }
}

void printHighestPaid(vector<Person> &emp)
{
  float highestPay = 0;
  int empLoc = 0;
  for(int i = 0; i < emp.size(); i++)
  {
    if(emp.at(i).totalPay() > highestPay)
    {
      highestPay = emp.at(i).totalPay();
      empLoc = i;
    }
  }
  cout.precision(2);
  cout << setw(15) << left << "Highest paid: " << emp.at(empLoc).fullName() << endl
  << setw(15) << left << "Employee ID: " << emp.at(empLoc).getEmployeeId() << endl
  << setw(15) << left << "Employer: " << emp.at(empLoc).getCompanyName() << endl
  << setw(15) << left << "Total Pay: " << "$" << fixed << emp.at(empLoc).totalPay() << endl;
}

void separateAndSave(vector<Person> &emp, vector<string> &cNames)
{
  ofstream outFile;
  string temp1;
  string temp2;
  for (int i = 0; i < emp.size(); i++)
  {
    temp1 = emp.at(i).getCompanyName();
    for (int j = 0; j < cNames.size(); j++)
    {
      temp2 = cNames.at(j);
      if(temp1==temp2)
      {
        outFile.open(temp1+".txt", outFile.out | outFile.app);
        outFile.precision(2);
        outFile << " " << setw(20) << left << emp.at(i).fullName() << " " << setw(5) << left << emp.at(i).getEmployeeId()
        << " " << setw(10) << left << emp.at(i).getCompanyName() << " " << setw(15) << left << fixed << emp.at(i).totalPay() << endl;
        outFile.close();
        break;
      }
    }
  }
}
