/*
 * @lc app=leetcode id=984 lang=cpp
 *
 * [984] String Without AAA or BBB
 */

// @lc code=start
// 1. 贪心算法
// 2023-10-16 submission
// 103/103 cases passed
// Runtime: 3 ms, faster than 39.15% of cpp online submissions.
// Memory Usage: 6.7 MB, less than 26.68% of cpp online submissions.
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        while (a > 0 || b > 0) {
            bool writeA = false;
            int len = res.size();
            if (len >= 2 && res[len - 1] == res[len - 2]) {
                if (res[len - 1] == 'b') {
                    writeA = true;
                }
            }
            else {
                if (a >= b) {
                    writeA = true;
                }
            }
            if (writeA) {
                --a;
                res += 'a';
            }
            else {
                --b;
                res += 'b';
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 递归
// 2023-10-16 submission
// 103/103 cases passed
// Runtime: 3 ms, faster than 39.15% of cpp online submissions.
// Memory Usage:  MB, less than 10.72% of cpp online submissions.
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        if (a == 0 && b == 0) return "";
        if (a == 0) return "b" + strWithout3a3b(a, b - 1);
        if (b == 0) return "a" + strWithout3a3b(a - 1, b);
        if (a > b) return "aab" + strWithout3a3b(a - 2, b - 1);
        if (a < b) return "bba" + strWithout3a3b(a - 1, b - 2);
        return "ab" + strWithout3a3b(a - 1, b - 1);
    }
};
// @lc code=end
