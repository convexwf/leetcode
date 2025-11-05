/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
// 1. 栈
// 2023-11-21 submission
// 106/106 cases passed
// Runtime: 17 ms, faster than 72.09% of cpp online submissions.
// Memory Usage: 11.3 MB, less than 78.96% of cpp online submissions.
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (auto c : s) {
            if (!res.empty() && c == res.back()) {
                res.pop_back();
            }
            else {
                res.push_back(c);
            }
        }
        return res;
    }
};
// @lc code=end
