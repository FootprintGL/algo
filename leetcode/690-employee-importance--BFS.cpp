

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
        int n = employees.size();
        if (n == 0)
            return 0;

        queue<Employee *>qu;
        int sum = 0, i;

        for (auto e : employees) {
            if (e->id == id) {
                qu.push(e);
                break;
            }
        }

        /* BFS */
        while (!qu.empty()) {
            Employee *cur = qu.front();
            sum += cur->importance;
            qu.pop();
            for (auto idx : cur->subordinates) {
                for (auto e : employees) {
                    if (e->id == idx) {
                        qu.push(e);
                        break;
                    }
                }
            }
        }

        return sum;
    }
};


/* 错误 - id可能有断的 */
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
        /* BFS */
        int n = employees.size();
        if (n == 0 || id > n)
            return 0;

        queue<Employee *>qu;
        int sum = 0;

        qu.push(employees[id - 1]);
        while (!qu.empty()) {
            Employee *cur = qu.front();
            sum += cur->importance;
            qu.pop();
            for (auto idx : cur->subordinates)
                qu.push(employees[idx - 1]);
        }

        return sum;
    }
};
