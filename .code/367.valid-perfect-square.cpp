/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (43.30%)
 * Likes:    3197
 * Dislikes: 272
 * Total Accepted:    448.8K
 * Total Submissions: 1M
 * Testcase Example:  '16'
 *
 * Given a positive integer num, return true if num is a perfect square or
 * false otherwise.
 *
 * A perfect square is an integer that is the square of an integer. In other
 * words, it is the product of some integer with itself.
 *
 * You must not use any built-in library function, such as sqrt.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 16
 * Output: true
 * Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
 *
 *
 * Example 2:
 *
 *
 * Input: num = 14
 * Output: false
 * Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an
 * integer.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num <= 2^31 - 1
 *
 *
 */

// @lc code=start
// 2020-09-22 submission
// 70/70 cases passed
// Runtime: 4 ms, faster than 20.34% of C++ online submissions.
// Memory Usage: 6 MB, less than 39.61% of C++ online submissions.
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        for (int i = 2; i <= int(sqrt(num)); i++) {
            if (num % i == 0 && num / i == i) return true;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 70/70 cases passed
// Runtime: 3 ms, faster than 43.85% of C++ online submissions.
// Memory Usage: 6 MB, less than 39.61% of C++ online submissions.
class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0, right = num;
        while (left <= right) {
            long mid = left + (right - left) / 2, t = mid * mid;
            if (t == num) return true;
            if (t < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 70/70 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6 MB, less than 39.61% of C++ online submissions.
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 70/70 cases passed
// Runtime: 3 ms, faster than 43.85% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 39.61% of C++ online submissions.
class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 70/70 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 39.61% of C++ online submissions.
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        int root = floorSqrt(num);
        return root * root == num;
    }

    int32_t floorSqrt(int32_t x) {
        double y=x; int64_t i=0x5fe6eb50c7b537a9;
        y = *(double*)&(i = i-(*(int64_t*)&y)/2);
        y = y * (3 - x * y * y) * 0.5;
        y = y * (3 - x * y * y) * 0.5;
        i = x * y + 1; return i - (i * i > x);
    }
};
// @lc code=end