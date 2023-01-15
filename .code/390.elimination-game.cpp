/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 *
 * https://leetcode.com/problems/elimination-game/description/
 *
 * algorithms
 * Medium (46.42%)
 * Likes:    1121
 * Dislikes: 607
 * Total Accepted:    54.5K
 * Total Submissions: 117.4K
 * Testcase Example:  '9'
 *
 * You have a list arr of all integers in the range [1, n] sorted in a strictly
 * increasing order. Apply the following algorithm on arr:
 *
 *
 * Starting from left to right, remove the first number and every other number
 * afterward until you reach the end of the list.
 * Repeat the previous step again, but this time from right to left, remove the
 * rightmost number and every other number from the remaining numbers.
 * Keep repeating the steps again, alternating left to right and right to left,
 * until a single number remains.
 *
 *
 * Given the integer n, return the last number that remains in arr.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 9
 * Output: 6
 * Explanation:
 * arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
 * arr = [2, 4, 6, 8]
 * arr = [2, 6]
 * arr = [6]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^9
 *
 *
 */

// @lc code=start
// 2020-12-06 submission
// 3377/3377 cases passed
// Runtime: 3 ms, faster than 89.89% of C++ online submissions.
// Memory Usage: 6 MB, less than 47.1% of C++ online submissions.
class Solution {
public:
    int lastRemaining(int n) {
        bool ltor = true;
        int step = 1, cur = 1;
        while (n > 1) {
            if (ltor || n % 2) cur += step;
            step *= 2;
            ltor = not ltor;
            n /= 2;
        }
        return cur;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 3377/3377 cases passed
// Runtime: 7 ms, faster than 60.05% of C++ online submissions.
// Memory Usage: 6 MB, less than 7.77% of C++ online submissions.
class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};
// @lc code=end
