/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 *
 * https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (56.52%)
 * Likes:    2869
 * Dislikes: 112
 * Total Accepted:    131.2K
 * Total Submissions: 232.1K
 * Testcase Example:  '[[1,2],[2,3],[3,4]]'
 *
 * You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and
 * lefti < righti.
 *
 * A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can
 * be formed in this fashion.
 *
 * Return the length longest chain which can be formed.
 *
 * You do not need to use up all the given intervals. You can select pairs in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: pairs = [[1,2],[2,3],[3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4].
 *
 *
 * Example 2:
 *
 *
 * Input: pairs = [[1,2],[7,8],[4,5]]
 * Output: 3
 * Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 *
 *
 *
 * Constraints:
 *
 *
 * n == pairs.length
 * 1 <= n <= 1000
 * -1000 <= lefti < righti <= 1000
 *
 *
 */

// @lc code=start
// 2023-02-27 submission
// 205/205 cases passed
// Runtime: 75 ms, faster than 71.64% of C++ online submissions.
// Memory Usage: 24.5 MB, less than 34.17% of C++ online submissions.
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 0, end = INT_MIN;
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        for (auto pair : pairs) {
            if (pair[0] > end) {
                ++res;
                end = pair[1];
            }
        }
        return res;
    }
};
// @lc code=end
