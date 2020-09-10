//
//  FileIO.h
//  employee program
//
//  Created by Imaad Aziz on 3/27/20.
//  Copyright © 2020 Imaad Aziz. All rights reserved.
//

#ifndef FileIO_h
#define FileIO_h
#include "Employee.h"
#include <fstream>
#include <string>

class FileIO
{
private: // private variables for FileIO class
    Employee* employees[100]; // dynamically allocated array of pointers to employees
    ofstream outFile;
    ifstream inFile;
public:
    FileIO(); // default constructor
    void readFile(ifstream&, int&); // read function that reads the contents of the file
    void writeFile(ofstream&, int&); // write function that outputs the changes made by user to a file
    void displayEmployeesByName(int&); // displays employees in alphabetical order
    void addEmployee(string, int&); // adds an employee to the data with data from the user
    void searchEmployee(string, int&); // searches for an employee with the ID of an employee
    void deleteEmployee(string, int&); // deletes an employee from the data with the ID of an employee
};

#endif /* FileIO_h */
