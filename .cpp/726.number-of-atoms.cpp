/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
// 1. 哈希表+栈
// 2023-08-22 submission
// 32/32 cases passed
// Runtime: 3 ms, faster than 59.42% of cpp online submissions.
// Memory Usage: 8.1 MB, less than 5.8% of cpp online submissions.
class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<map<string, int>> stk;
        map<string, int> mp;
        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                stk.push(mp);
                mp.clear();
                i++;
            }
            else if (formula[i] == ')') {
                int j = i + 1;
                while (j < n && isdigit(formula[j])) j++;
                int num = (j == i + 1) ? 1 : stoi(formula.substr(i + 1, j - i - 1));
                for (auto &[atom, v] : mp) {
                    stk.top()[atom] += v * num;
                }
                mp = stk.top();
                stk.pop();
                i = j;
            }
            else {
                int j = i + 1;
                while (j < n && islower(formula[j])) j++;
                string atom = formula.substr(i, j - i);
                i = j;
                while (j < n && isdigit(formula[j])) j++;
                int num = (j == i) ? 1 : stoi(formula.substr(i, j - i));
                mp[atom] += num;
                i = j;
            }
        }
        string ans;
        for (auto &[atom, v] : mp) {
            ans += atom;
            if (v > 1) ans += to_string(v);
        }
        return ans;
    }
};
// @lc code=end
