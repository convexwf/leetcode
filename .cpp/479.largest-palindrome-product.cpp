/*
 * @lc app=leetcode id=479 lang=cpp
 *
 * [479] Largest Palindrome Product
 */

// @lc code=start
// 1. 枚举
// 2023-11-16 submission
// 8/8 cases passed
// Runtime: 68 ms, faster than 44.14% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 24.14% of cpp online submissions.
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = pow(10, n) - 1, lower = pow(10, n - 1);
        for (int i = upper; i >= lower; --i) {
            string s = to_string(i);
            long long num = stoll(s + string(s.rbegin(), s.rend()));
            for (long long j = upper; j * j >= num; --j) {
                if (num % j == 0) return num % 1337;
            }
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 2. 打表
// 2023-11-16 submission
// 8/8 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 90.34% of cpp online submissions.
class Solution {
public:
    int largestPalindrome(int n) {
        vector<int> table = {0, 9, 987, 123, 597, 677, 1218, 877, 475};
        return table[n];
    }
};
// @lc code=end
