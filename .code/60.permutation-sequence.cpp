/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Hard (42.86%)
 * Likes:    4296
 * Dislikes: 403
 * Total Accepted:    284.1K
 * Total Submissions: 662.9K
 * Testcase Example:  '3\n3'
 *
 * The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 *
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 *
 * Given n and k, return the k^th permutation sequence.
 *
 *
 * Example 1:
 * Input: n = 3, k = 3
 * Output: "213"
 * Example 2:
 * Input: n = 4, k = 9
 * Output: "2314"
 * Example 3:
 * Input: n = 3, k = 1
 * Output: "123"
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 9
 * 1 <= k <= n!
 *
 *
 */

// @lc code=start
// 2022-07-20 submission
// 200/200 cases passed
// Runtime: 3 ms, faster than 59.97% of C++ online submissions.
// Memory Usage: 6 MB, less than 80.63% of C++ online submissions.
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> frac(n, 1);
        string nums = "123456789";
        string ret = "";
        for (int i = 1; i < n; i++) {
            frac[i] = frac[i - 1] * i;
        }
        --k;
        for (int i = n - 1; i >= 0; i--) {
            ret += nums[k / frac[i]];
            nums.erase(k / frac[i], 1);
            k %= frac[i];
        }
        return ret;
    }
};
// @lc code=end