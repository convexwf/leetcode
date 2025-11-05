/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
// 1. 递归
// 2024-04-11 submission
// 30/30 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 9.1 MB, less than 47.1% of cpp online submissions.
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string prev = countAndSay(n - 1);
        string res;
        for (int i = 0; i < prev.size(); i++) {
            int count = 1;
            while (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
                count++;
                i++;
            }
            res += to_string(count) + prev[i];
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 迭代
// 2022-08-07 submission
// 30/30 cases passed
// Runtime: 10 ms, faster than 68.15% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 78.34% of cpp online submissions.
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string res = "1";
        while (n-- > 0) {
            string cur = "";
            for (int i = 0; i < res.size(); ++i) {
                int cnt = 1;
                while (i + 1 < res.size() && res[i] == res[i + 1]) {
                    ++cnt;
                    ++i;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
};
// @lc code=end
