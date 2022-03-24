/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (51.73%)
 * Likes:    4617
 * Dislikes: 1946
 * Total Accepted:    1.7M
 * Total Submissions: 3.2M
 * Testcase Example:  '121'
 *
 * Given an integer x, return true if x is palindrome integer.
 * 
 * An integer is a palindrome when it reads the same backward as forward.
 * 
 * 
 * For example, 121 is a palindrome while 123 is not.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you solve it without converting the integer to a string?
 */
// @lc solution=start
题目描述：回文数判断

解题思路

1. 分别取最左和最右的数字，然后向中间靠拢。
2. 将数字从中间一分为二。
// @lc solution=end

// @lc code=start
// 2021-12-19 submission
// 11510/11510 cases passed
// Runtime: 8 ms, faster than 79.01% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 31.86% of C++ online submissions.
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
// 2021-12-19 submission
// 11510/11510 cases passed
// Runtime: 11 ms, faster than 59.36% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 31.86% of C++ online submissions.
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