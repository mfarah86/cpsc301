#include <iostream>
#include <string>
#include <cstring>
#include "person.h"

using namespace std;

Person::Person()
{
  string firstName = " ";
  string lastName = " ";
  float hoursWorks = 0;
  float payRate = 0;
}
void Person::setLastName(string lName)
{
  lastName = lName;
}
string Person::getLastName()
{
  return lastName;
}
void Person::setFirstName(string fName)
{
  firstName = fName;
}
string Person::getFirstName()
{
  return firstName;
}
void Person::setPayRate(float rate)
{
  payRate = rate;
}
float Person::getPayRate()
{
  return payRate;
}
void Person::setHoursWorked(float hours)
{
  hoursWorked = hours;
}
float Person::getHoursWorked()
{
  return hoursWorked;
}
float Person::totalPay()
{
  float totalPay = hoursWorked * payRate;
  return totalPay;
}
string Person::fullName()
{
  string fullName = firstName + " " + lastName;
  return fullName;
}
