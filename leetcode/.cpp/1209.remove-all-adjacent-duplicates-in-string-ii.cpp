/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
// 1. 栈
// 2025-04-08 submission
// 21/21 cases passed
// Runtime: 10 ms, faster than 53.25% of cpp online submissions.
// Memory Usage: 14.2 MB, less than 43.75% of cpp online submissions.
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for (const char& c : s) {
            if (!stk.empty() && stk.top().first == c) {
                stk.top().second++;
            }
            else {
                stk.push({c, 1});
            }
            if (stk.top().second == k) {
                stk.pop();
            }
        }
        string result;
        while (!stk.empty()) {
            auto [c, count] = stk.top();
            stk.pop();
            result.append(count, c);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
