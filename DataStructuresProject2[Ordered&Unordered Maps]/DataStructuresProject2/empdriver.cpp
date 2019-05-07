#include <iostream>
#include <ctime>
#include "empmaps.h"
#include "Employee.h"
using namespace std;

int main()
{
    vector<Employee> emps = employees();
    map<int, vector<Employee>> empDeptMap;
    map<int, vector<Employee>> empSalMap;

    unordered_map<int, vector<Employee>> uempDeptMap;
    unordered_map<int, vector<Employee>> uempSalMap;

    clock_t start, stop;

    start = clock();
    empDeptMap = mapEmpDept(emps);
    stop = clock();
    cout << "ORDERED Map creation with department as key clock ticks: " << double(stop-start) << endl;
    cout << "ORDERED Map number of departments: " << empDeptMap.size() << endl;

    start = clock();
    empSalMap = mapSalRange(emps);
    stop = clock();
    cout << "ORDERED Map creation with salary as key clock ticks: " << double(stop-start) << endl;
    cout << "ORDERED Map number of salary ranges: " << empSalMap.size() << endl;

    printSalRange(empSalMap); cout << endl;

    start = clock();
    uempDeptMap = umapEmpDept(emps);
    stop = clock();
    cout << "UNORDERED Map creation with department as key clock ticks: " << double(stop-start) << endl;
    cout << "UNORDERED Map number of departments: " << uempDeptMap.size() << endl;

    start = clock();
    uempSalMap = umapSalRange(emps);
    stop = clock();
    cout << "UNORDERED Map creation with salary as key clock ticks: " << double(stop-start) << endl;
    cout << "UNORDERED Map number of salary ranges: " << uempSalMap.size() << endl;

    uprintSalRange(uempSalMap);



}
