/*
 * @lc app=leetcode id=866 lang=cpp
 *
 * [866] Prime Palindrome
 */

// @lc code=start
// 1. 数学规律
// 2023-10-30 submission
// 61/61 cases passed
// Runtime: 35 ms, faster than 75.5% of cpp online submissions.
// Memory Usage: 6.3 MB, less than 36.14% of cpp online submissions.
class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int primePalindrome(int N) {
        if (N <= 2) return 2;
        if (N <= 3) return 3;
        if (N <= 5) return 5;
        if (N <= 7) return 7;
        if (N <= 11) return 11;
        for (int i = 1; i < 100000; ++i) {
            string s = to_string(i);
            string t = s;
            reverse(t.begin(), t.end());
            int num = stoi(s + t.substr(1));
            if (num >= N && isPrime(num)) return num;
        }
        return -1;
    }
};
// @lc code=end
