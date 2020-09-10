/*
 Author: Imaad Aziz
 Date: 3/27/20
 Compiler: XCode
 */

#include <iostream>
#include <fstream>
#include "FileIO.h" // FileIO class that deals with everything involving the file
#include "Employee.h" // Employee class that defines and instantiates everything with employees

using namespace std;

int main()
{
    string fileName = "Employees.txt"; // name of file
    ifstream inFile; // input file
    ofstream outFile; // output
    int size;
    int choice = 0;
    inFile.open(fileName); // opens input file
    FileIO file; // declares a fileIO object
    if (!(inFile.fail())) // if
    {
        file.readFile(inFile, size);
    }
    while (choice != 5)
    {
        cout << "1. New Employee Information\n2. Display all employee information in alphabetical order by last name.\n3. Look up an employee by ID\n4. Remove an employee.\n5. Save all data to Employee.txt and exit." << endl; // menu
        cout << "Enter an option: ";
        cin >> choice;
        switch (choice) // switch for the menu
        {
            case 1: // adds employee to the data
            {
                string testId;
                cout << "Enter the ID for the employee you wish to add: ";
                cin >> testId;
                file.addEmployee(testId, size);
                break;
            }
            case 2: // displays all employees in alphabetical order and saves it like that
            {
                file.displayEmployeesByName(size);
                break;
            }
            case 3: // searches for the ID of an employee and returns the data of the employee
            {
                string testId;
                cout << "Enter the ID for the employee you wish to search for: ";
                cin >> testId;
                file.searchEmployee(testId, size);
                break;
            }
            case 4: // deletes an employee from the data and shortens the size
            {
                string testId;
                cout << "Enter the ID for the employee you wish to delete: ";
                cin >> testId;
                file.deleteEmployee(testId, size);
                break;
            }
            case 5: // overwrites the current contents of the file and creates a new one.
            {
                inFile.close();
                file.writeFile(outFile, size);
                break;
            }
        }
        inFile.close(); // closes both files
        outFile.close();
    }
    return 0;
}
