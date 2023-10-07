/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
// 2022-08-01 submission
// 11510/11510 cases passed
// Runtime: 22 ms, faster than 54.64% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 31.85% of C++ online submissions.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int div = 1;
        while (x / div >= 10) div *= 10;
        while (x > 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-01 submission
// 11510/11510 cases passed
// Runtime: 15 ms, faster than 81.79% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 31.85% of C++ online submissions.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;

        int reverted = 0;
        while (x > reverted) {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }
        return x == reverted || x == reverted / 10;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-01 submission
// 11510/11510 cases passed
// Runtime: 11 ms, faster than 92.34% of C++ online submissions.
// Memory Usage: 5.7 MB, less than 90.95% of C++ online submissions.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        return reverse(x) == x;
    }

    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (res > INT_MAX / 10) return -1;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
// @lc code=end
