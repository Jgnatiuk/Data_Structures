#include <map>
#include <vector>
#include <unordered_map>
#include "Employee.h"

using std::vector;


vector<Employee> employees();
std::map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp);
std::map<int,vector<Employee>> mapSalRange(vector<Employee> & emp);
void printSalRange(std::map<int,vector<Employee>> & salRange);
std::unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp);
std::unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp);
void uprintSalRange(std::unordered_map<int,vector<Employee>> & salRange);

