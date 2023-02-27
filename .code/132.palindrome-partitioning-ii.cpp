/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (33.41%)
 * Likes:    3856
 * Dislikes: 92
 * Total Accepted:    216.6K
 * Total Submissions: 648.4K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a"
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: s = "ab"
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2000
 * s consists of lowercase English letters only.
 *
 *
 */

// @lc code=start
// 2023-02-27 submission
// 36/36 cases passed
// Runtime: 28 ms, faster than 92.06% of C++ online submissions.
// Memory Usage: 8.2 MB, less than 45.56% of C++ online submissions.
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> judge(n, vector<bool>(n, false));
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = i + 1;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (j + 2 > i || judge[j + 1][i - 1])) {
                    judge[j][i] = true;
                    dp[i + 1] = min(dp[j] + 1, dp[i + 1]);
                }
            }
        }
        return dp.back() - 1;
    }
};
// @lc code=end