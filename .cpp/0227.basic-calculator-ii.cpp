/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
// 1. 栈
// 2023-01-14 submission
// 110/110 cases passed
// Runtime: 22 ms, faster than 71.97% of cpp online submissions.
// Memory Usage: 11.2 MB, less than 41.1% of cpp online submissions.
class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int> nums;
        int num = 0;
        char op = '+';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            else {
                if (op == '+') {
                    nums.push(num);
                }
                else if (op == '-') {
                    nums.push(-num);
                }
                else if (op == '*') {
                    int tmp = nums.top();
                    nums.pop();
                    nums.push(tmp * num);
                }
                else if (op == '/') {
                    int tmp = nums.top();
                    nums.pop();
                    nums.push(tmp / num);
                }
                num = 0;
                op = s[i];
            }
        }
        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 栈-优化
// 2023-01-14 submission
// 110/110 cases passed
// Runtime: 13 ms, faster than 90.24% of cpp online submissions.
// Memory Usage: 9.5 MB, less than 64.02% of cpp online submissions.
class Solution {
public:
    int calculate(string s) {
        s += '+';
        int res = 0, cur = 0, num = 0;
        char op = '+';
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            else {
                if (op == '+') {
                    cur += num;
                }
                else if (op == '-') {
                    cur -= num;
                }
                else if (op == '*') {
                    cur *= num;
                }
                else if (op == '/') {
                    cur /= num;
                }
                if (s[i] == '+' || s[i] == '-') {
                    res += cur;
                    cur = 0;
                }
                op = s[i];
                num = 0;
            }
        }
        return res;
    }
};
// @lc code=end
