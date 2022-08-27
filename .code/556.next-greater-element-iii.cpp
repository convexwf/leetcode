/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (34.02%)
 * Likes:    2620
 * Dislikes: 370
 * Total Accepted:    110.4K
 * Total Submissions: 324.6K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the smallest integer which has exactly the
 * same digits existing in the integer n and is greater in value than n. If no
 * such positive integer exists, return -1.
 *
 * Note that the returned integer should fit in 32-bit integer, if there is a
 * valid answer but it does not fit in 32-bit integer, return -1.
 *
 *
 * Example 1:
 * Input: n = 12
 * Output: 21
 * Example 2:
 * Input: n = 21
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
// 2022-08-26 submission
// 39/39 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 93.88% of C++ online submissions.
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.size(), i = len - 2, j = len - 1;
        while (i >= 0 && str[i] >= str[i + 1]) --i;
        if (i < 0) return -1;
        while (str[j] <= str[i]) --j;
        swap(str[i], str[j]);
        reverse(str.begin() + i + 1, str.end());
        long long res = stoll(str);
        return res > INT_MAX ? -1 : res;
    }
};
// @lc code=end
