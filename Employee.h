//
//  Employee.h
//  employee program
//
//  Created by Imaad Aziz on 3/27/20.
//  Copyright © 2020 Imaad Aziz. All rights reserved.
//

#ifndef Employee_h
#define Employee_h
#include <string>


using namespace std;

class Employee
{
private: // private variables for the employee class
    string ID;
    string lastName;
    string firstName;
    string bDate;
    char gender;
    string sDate;
    double salary;
public: // public functions and constructors for employee class
    Employee(); // default constructor
    Employee(string); // constructor that only takes the ID as a parameter
    Employee(string, string, string, string, char, string, double); // constructor that takes all variables as parameters
    const Employee* operator=(const Employee* right) // overloaded operator '=' so employees can be compared and equalled to each other
    {
        this->ID = right->ID;
        this->lastName = right->lastName;
        this->firstName = right->firstName;
        this->bDate = right->bDate;
        this->gender = right->gender;
        this->sDate = right->sDate;
        this->salary = right->salary;
        return this;
    }
    string getID() const // standard get and set functions
    { return this->ID; }
    string getLastName() const
    { return this->lastName; }
    string getFirstName() const
    { return this->firstName; }
    string getBirthdate() const
    { return this->bDate; }
    char getGender() const
    { return this->gender; }
    string getStartDate() const
    { return this->sDate; }
    double getSalary() const
    { return this->salary; }
    void setID(string);
    void setLastName(string);
    void setFirstName(string);
    void setBirthDate(string);
    void setGender(char);
    void setStartDate(string);
    void setSalary(double);
};

#endif /* Employee_h */


