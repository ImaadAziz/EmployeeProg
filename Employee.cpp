//
//  Employee.cpp
//  employee program
//
//  Created by Imaad Aziz on 3/27/20.
//  Copyright © 2020 Imaad Aziz. All rights reserved.
//

#include <stdio.h>
#include "Employee.h"
#include <string>

using namespace std;

Employee::Employee() // default constructor
{
    
}

Employee::Employee(string IDnum) // constructor with one parameter
{
    ID = IDnum;
}

Employee::Employee(string IDnum, string lName, string fName, string date1, char sex, string date2, double sal) // constructor with all parameters
{
    ID = IDnum;
    lastName = lName;
    firstName = fName;
    bDate = date1;
    gender = sex;
    sDate = date2;
    salary = sal;
}

void Employee::setID(string num) // set functions for all variables
{
    ID = num;
}

void Employee::setLastName(string name1)
{
    firstName = name1;
}

void Employee::setFirstName(string name2)
{
    lastName = name2;
}

void Employee::setBirthDate(string date1)
{
    bDate = date1;
}

void Employee::setGender(char sex)
{
    gender = sex;
}

void Employee::setStartDate(string date2)
{
    sDate = date2;
}

void Employee::setSalary(double sal)
{
    if (sal > 0) // salary cannot be negative
        salary = sal;
}

