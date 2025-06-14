/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // Create a map for quick lookup
        unordered_map<int, Employee*> empMap;
        for (Employee* emp : employees) {
            empMap[emp->id] = emp;
        }

        // Call the recursive DFS function
        return dfs(empMap, id);
    }

private:
    int dfs(unordered_map<int, Employee*>& empMap, int id) {
        Employee* employee = empMap[id];
        int total = employee->importance;

        for (int subId : employee->subordinates) {
            total += dfs(empMap, subId);
        }

        return total;
    }
};
