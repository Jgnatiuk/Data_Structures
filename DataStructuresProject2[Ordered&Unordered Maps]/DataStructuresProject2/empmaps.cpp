#include "empmaps.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::unordered_map;
using std::map;
using std::string;





vector<Employee> employees()                                                 // Function to build vector of employees
{
    vector<Employee> emps;                                                   // Declaration of empty Employee Vector

    ifstream file;                                                           // Declaration of file object
    string row,fileName;                                                     // Declaration of fileName string and file row string

    cout << "Enter file of employee data to process: ";                      // Prompt for fileName
    cin >> fileName;
    cout << endl;

    file.open(fileName);                                                     // Attempt to open file

      if (!file)                                                             // If file is not present, output file not found
    {
        cout << "File not found." << endl;
    }
    else if (file.is_open())                                                 // If file is successfully opened
    {
        while(std::getline(file, row))                                       // While there is a new row
        {

            istringstream index(row);                                        // Declaration of an isstream object to parse row string

            int identifier, salary;                                          // Declaration of integer to hold employee identifier and salary
            string lastName;                                                 // Declaration of string to hold employee lastName

            index >> identifier;                                             // input first row value as employee identifier
            index >> lastName;                                               // input second row value as employee lastName
            index >> salary;                                                 // input third row value as employee salary

            Employee employee(identifier, lastName, salary);                 // build employee with inputted values

            emps.push_back(employee);                                        // push employee object onto vector

        }
        cout << "Number of Employees: " << emps.size() << endl;              // Output number of employees
    }


    return emps;
};

map<int, vector<Employee>> mapEmpDept(vector<Employee> & emp)                // Function to build map of employee departments
{
    map<int, vector<Employee>> empMap;                                       // Create employee map container
    int key;                                                                 // Declaration of key value

    for(auto employee : emp)                                                 // For each employee object within the employee vector
    {
       key = (employee.id() - (employee.id() % 100)) / 100;                  // set key(departmentID) equal to first 4 significant digits of EmployeeID

       empMap[key].push_back(employee);                                      // Push employee object onto employee department map at key index
    }

    return empMap;
};

map<int,vector<Employee>> mapSalRange(vector<Employee> & emp)                // Function to build map of employee Salary Ranges
{
    map<int, vector<Employee>> salMap;                                       // Create employee salary map container
    int key;                                                                 // Declaration of key value

    for(auto employee : emp)                                                 // for each employee object within the employee vector
    {
        key = employee.sal() - (employee.sal() % 10000);                     // Set key(salaryRange) equal to lower increment of 10,000

        salMap[key].push_back(employee);                                     // Push employee object onto employee salary range map at key index
    }

    return salMap;
};

void printSalRange(std::map<int,vector<Employee>> & salRange)                // Function to print employee salary ranges along with amount of employees within each salary range
{
    vector<Employee> largestRange;                                           // Declaration of largestRange vector container
    int largestRangeSize= 0;                                                 // Declaration of integers to hold largest range size and number of employees in largest range
    int largestRangeCount;

    for(auto range : salRange)                                               // for each salaryRange within map of salary ranges
    {
        const vector<Employee> & salaryRange = range.second;                 // set employee vector salaries equal to salary range vector

        if(salaryRange.size() > largestRangeSize)                           // If number of employees within salary range is larger than last
        {
            largestRangeSize = salaryRange.size();                           // set Largest range size equal to size of current salary range vector ( # of employees within range)
            largestRange = salaryRange;                                      // set Largest range vector equal to current salary range vector
            largestRangeCount = range.first;                                 // set Largest range equal to current range
        }

        cout << "ORDERED MAP Salary Range " << range.first << " contains " << salaryRange.size() << endl;  // Output salary range index (increment of 10K) as well as number of employees within range
    }

    cout << "ORDERED MAP Salary Range with most employees: " << largestRangeCount  << " containing " << largestRange.size() << " employees" << endl; // Output largest salary range

};

unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp)
{
    unordered_map<int, vector<Employee>> empMap;                             // Create employee map container
    int key;                                                                 // Declaration of key value

    for(auto employee : emp)                                                 // For each employee object within the employee vector
    {
       key = (employee.id() - (employee.id() % 100)) / 100;                  // set key(departmentID) equal to first 4 significant digits of EmployeeID

       empMap[key].push_back(employee);                                      // Push employee object onto employee department map at key index
    }

    return empMap;

};

unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp)
{
    unordered_map<int, vector<Employee>> salMap;                             // Create employee salary map container
    int key;                                                                 // Declaration of key value

    for(auto employee : emp)                                                 // for each employee object within the employee vector
    {
        key = employee.sal() - (employee.sal() % 10000);                     // Set key(salaryRange) equal to lower increment of 10,000

        salMap[key].push_back(employee);                                     // Push employee object onto employee salary range map at key index
    }

    return salMap;
};

void uprintSalRange(std::unordered_map<int,vector<Employee>> & salRange)
{
    vector<Employee> largestRange;                                           // Declaration of largestRange vector container
    int largestRangeSize= 0;                                                 // Declaration of integers to hold largest range size and number of employees in largest range
    int largestRangeCount;

    for(auto range : salRange)                                               // for each salaryRange within map of salary ranges
    {
        const vector<Employee> & salaryRange = range.second;                 // set employee vector salaries equal to salary range vector

        if(salaryRange.size() > largestRangeSize)                           // If number of employees within salary range is larger than last
        {
            largestRangeSize = salaryRange.size();                           // set Largest range size equal to size of current salary range vector ( # of employees within range)
            largestRange = salaryRange;                                      // set Largest range vector equal to current salary range vector
            largestRangeCount = range.first;                                 // set Largest range equal to current range
        }

        cout << "UNORDERED MAP Salary Range " << range.first << " contains " << salaryRange.size() << endl;  // Output salary range index (increment of 10K) as well as number of employees within range
    }

    cout << "UNORDERED MAP Salary Range with most employees: " << largestRangeCount  << " containing " << largestRange.size() << " employees" << endl; // Output largest salary range

};


