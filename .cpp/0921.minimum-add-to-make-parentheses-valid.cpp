/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
// 1. 栈+贪心算法
// 2023-12-25 submission
// 115/115 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 74.46% of cpp online submissions.
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(') {
                stk.push(c);
            }
            else {
                if (stk.empty() || stk.top() != '(') {
                    stk.push(c);
                }
                else {
                    stk.pop();
                }
            }
        }
        return stk.size();
    }
};
// @lc code=end

// @lc code=start
// 2. 计数+贪心算法
// 2023-12-25 submission
// 115/115 cases passed
// Runtime: 3 ms, faster than 45.73% of cpp online submissions.
// Memory Usage: 6.5 MB, less than 74.46% of cpp online submissions.
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, left = 0;
        for (char c : s) {
            if (c == '(') {
                left++;
            }
            else {
                if (left > 0) {
                    left--;
                }
                else {
                    ans++;
                }
            }
        }
        return ans + left;
    }
};
// @lc code=end
