/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */

// @lc code=start
// 2022-08-26 submission
// 102/102 cases passed
// Runtime: 58 ms, faster than 40.52% of cpp online submissions.
// Memory Usage: 14.1 MB, less than 56.93% of cpp online submissions.
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
// Runtime: 61 ms, faster than 35.09% of cpp online submissions.
// Memory Usage: 14.2 MB, less than 49.7% of cpp online submissions.
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
