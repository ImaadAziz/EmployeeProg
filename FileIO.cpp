//
//  FileIO.cpp
//  employee program
//
//  Created by Imaad Aziz on 3/27/20.
//  Copyright © 2020 Imaad Aziz. All rights reserved.
//

#include <stdio.h>
#include "FileIO.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

FileIO::FileIO() // default constructor
{
    
}

void FileIO::readFile(ifstream& inFile, int &size) // read file function
{
    int i = 0;
    size = 0;
    string id, lName, fName, date1, date2;
    double sal;
    char sex;
    while (inFile >> id >> lName >> fName >> date1 >> sex >> date2 >> sal) // takes in values from the file
    {
        employees[i] = new Employee(id, lName, fName, date1, sex, date2, sal); // declares and initializes a pointer to an employee using the overloaded '='
        i++;
        if (i >= 100) // if there are more than 100 employees in the file
        {
            cout << "More than 100 employees in the text file please try again." << endl;
            exit(EXIT_FAILURE);
        }
    }
    size = i; // size reference variable that is used throughout the program
    
}

void FileIO::writeFile(ofstream& outFile, int &size) // outputs the data to a file
{
    if (inFile.fail()) // if there is no current file one is created
    {
        outFile.open("Employees.txt");
    }
    else // if there is, the previous contents are deleted and replaced
    {
        outFile.open("Employees.txt", ios::trunc);
    }
    for (int i = 0; i < size; i++) // writes the contents to a file
    {
        outFile << employees[i]->getID() << " " << employees[i]->getLastName() << " " << employees[i]->getFirstName() << " " << employees[i]->getBirthdate() << " " << employees[i]->getGender() << " " << employees[i]->getStartDate() << " " << employees[i]->getSalary() << endl;
    }
}

void FileIO::displayEmployeesByName(int &size) // bubble sorts the data alphabetically and displays it
{
    bool swap; // bubble sort code
    do
    {
        swap = false;
        for (int i = 0; i < size-1; i++)
        {
            if (employees[i]->getLastName() > employees[i+1]->getLastName()) // comparing strings
            {
                Employee* temp = employees[i];
                employees[i] = employees[i+1];
                employees[i+1] = temp;
                swap = true;
            }
        }
    }   while(swap);
    for (int i = 0; i < size; i++)
    {
        cout << setw(12) << left << employees[i]->getID() << setw(17) << left << employees[i]->getLastName() << setw(12)  << left << employees[i]->getFirstName() << setw(12) << left << employees[i]->getBirthdate() << setw(12) << left << employees[i]->getGender() << setw(12) << left << employees[i]->getStartDate() << setw(12) << left << employees[i]->getSalary() << endl;
    }
}

void FileIO::addEmployee(string id, int &size) // adds an employee to the data
{
    string lName, fName, date1, date2;
    double sal;
    char sex;
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (id == employees[i]->getID()) // if employee already exists in the data an error message is printed
        {
            found = true;
            cout << "Employee already exists please try again. " << endl;
        }
    }
    if (!found) // if employee not found employee is added to the end of the data and the size of the array is increased
    {
        cout << "Enter the rest of the information for the new employee (Last Name, First Name, Birthdate, Gender, Start Date, Salary): ";
        cin >> lName >> fName >> date1 >> sex >> date2 >> sal;
        employees[size] = new Employee(id, lName, fName, date1, sex, date2, sal);
        size++;
    }
}

void FileIO::searchEmployee(string id, int &size) // searches for an employee given the ID
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (id == employees[i]->getID()) // if employee is found prints the data for that employee
        {
            cout << setw(12) << left << employees[i]->getID() << setw(17) << left << employees[i]->getLastName() << setw(12)  << left << employees[i]->getFirstName() << setw(12) << left << employees[i]->getBirthdate() << setw(12) << left << employees[i]->getGender() << setw(12) << left << employees[i]->getStartDate() << setw(12) << left << employees[i]->getSalary() << endl;
            found = true;
            
        }
    }
    if (!found) // if employee is not found an error message is printed
    {
        cout << "Employee not found in data please try again." << endl;
    }
}

void FileIO::deleteEmployee(string id, int &size) // deletes an employee given the ID
{
    bool found = false;
    int i = 0;
    while (!found)
    {
        if (id == employees[i]->getID()) // if the employee is found
        {
            delete employees[i]; // deletes the allocated memory for that employee
            for (int j = i; j < size - 1; j++) // all data is pushed back due to the hole that was created in the deletion.
            {
                employees[i] = employees[j + 1]; // again overloaded '=' is used
            }
            size--; // due to a deletion the size decreases
            found = true;
        }
        i++;
    }
}
