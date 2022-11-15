/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 *
 * https://leetcode.com/problems/employee-importance/description/
 *
 * algorithms
 * Medium (64.84%)
 * Likes:    1733
 * Dislikes: 1267
 * Total Accepted:    182.8K
 * Total Submissions: 282K
 * Testcase Example:  '[[1,5,[2,3]],[2,3,[]],[3,3,[]]]\n1'
 *
 * You have a data structure of employee information, including the employee's
 * unique ID, importance value, and direct subordinates' IDs.
 *
 * You are given an array of employees employees where:
 *
 *
 * employees[i].id is the ID of the i^th employee.
 * employees[i].importance is the importance value of the i^th employee.
 * employees[i].subordinates is a list of the IDs of the direct subordinates of
 * the i^th employee.
 *
 *
 * Given an integer id that represents an employee's ID, return the total
 * importance value of this employee and all their direct and indirect
 * subordinates.
 *
 *
 * Example 1:
 *
 *
 * Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
 * Output: 11
 * Explanation: Employee 1 has an importance value of 5 and has two direct
 * subordinates: employee 2 and employee 3.
 * They both have an importance value of 3.
 * Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.
 *
 *
 * Example 2:
 *
 *
 * Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
 * Output: -3
 * Explanation: Employee 5 has an importance value of -3 and has no direct
 * subordinates.
 * Thus, the total importance value of employee 5 is -3.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= employees.length <= 2000
 * 1 <= employees[i].id <= 2000
 * All employees[i].id are unique.
 * -100 <= employees[i].importance <= 100
 * One employee has at most one direct leader and may have several
 * subordinates.
 * The IDs in employees[i].subordinates are valid IDs.
 *
 *
 */

// @lc code=start
// 2022-08-26 submission
// 102/102 cases passed
// Runtime: 58 ms, faster than 40.52% of C++ online submissions.
// Memory Usage: 14.1 MB, less than 56.93% of C++ online submissions.
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
        unordered_map<int, Employee*> m;
        for (auto e : employees) m[e->id] = e;
        return DFS(id, m);
    }
    int DFS(int id, unordered_map<int, Employee*>& m) {
        int res = m[id]->importance;
        for (int num : m[id]->subordinates) {
            res += DFS(num, m);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-26 submission
// 102/102 cases passed
// Runtime: 61 ms, faster than 35.09% of C++ online submissions.
// Memory Usage: 14.2 MB, less than 49.7% of C++ online submissions.
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        queue<int> q{{id}};
        unordered_map<int, Employee*> m;
        for (auto e : employees) m[e->id] = e;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            res += m[t]->importance;
            for (int num : m[t]->subordinates) {
                q.push(num);
            }
        }
        return res;
    }
};
// @lc code=end
