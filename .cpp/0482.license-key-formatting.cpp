/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
// 1. 模拟
// 2021-12-17 submission
// 38/38 cases passed
// Runtime: 8 ms, faster than 80.96% of cpp online submissions.
// Memory Usage: 8.3 MB, less than 67.18% of cpp online submissions.
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt = 0;
        for (char c : s) {
            if (isalnum(c)) ++cnt;
        }

        string res;
        for (char c : s) {
            if (isalnum(c)) {
                cnt--;
                res.append(1, toupper(c));
                if (cnt % k == 0 && cnt != 0) {
                    res.append(1, '-');
                }
            }
        }
        return res;
    }
};
// @lc code=end
