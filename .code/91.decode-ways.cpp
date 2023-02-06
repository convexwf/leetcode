/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (30.83%)
 * Likes:    7434
 * Dislikes: 3922
 * Total Accepted:    824.7K
 * Total Submissions: 2.7M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z can be encoded into numbers using the
 * following mapping:
 *
 *
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 *
 *
 * To decode an encoded message, all the digits must be grouped then mapped
 * back into letters using the reverse of the mapping above (there may be
 * multiple ways). For example, "11106" can be mapped into:
 *
 *
 * "AAJF" with the grouping (1 1 10 6)
 * "KJF" with the grouping (11 10 6)
 *
 *
 * Note that the grouping (1 11 06) is invalid because "06" cannot be mapped
 * into 'F' since "6" is different from "06".
 *
 * Given a string s containing only digits, return the number of ways to decode
 * it.
 *
 * The test cases are generated so that the answer fits in a 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "12"
 * Output: 2
 * Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: s = "226"
 * Output: 3
 * Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2
 * 2 6).
 *
 *
 * Example 3:
 *
 *
 * Input: s = "06"
 * Output: 0
 * Explanation: "06" cannot be mapped to "F" because of the leading zero ("6"
 * is different from "06").
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 *
 *
 */

// @lc code=start
// 2023-02-02 submission
// 269/269 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.2 MB, less than 77.39% of C++ online submissions.
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            if (i >= 2 && s.substr(i - 2, 2) <= "26" && s.substr(i - 2, 2) >= "10") {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
// @lc code=end

// @lc code=start
// 2023-02-02 submission
// 269/269 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.2 MB, less than 77.39% of C++ online submissions.
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int a = 1, b = 1, n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') a = 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                a = a + b;
                b = a - b;
            } else {
                b = a;
            }
        }
        return a;
    }
};
// @lc code=end