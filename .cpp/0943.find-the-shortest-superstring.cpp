/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 */

// @lc code=start
// 1. 动态规划
// 2025-06-07 submission
// 85/85 cases passed
// Runtime: 820 ms, faster than 34.11% of cpp online submissions.
// Memory Usage: 395.5 MB, less than 28.97% of cpp online submissions.
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n, 0));

        // calculate overlap between every pair of words
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    overlap[i][j] = getOverlap(words[i], words[j]);
                }
            }
        }

        vector<vector<string>> dp(1 << n, vector<string>(n));
        for (int i = 0; i < n; ++i) {
            dp[1 << i][i] = words[i];
        }
        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) == 0) continue; // i is not in the mask
                int prev_mask = mask ^ (1 << i);
                for (int j = 0; j < n; ++j) {
                    // j is not in the previous mask
                    if (prev_mask == 0 || (prev_mask & (1 << j)) == 0) continue;
                    string candidate = dp[prev_mask][j] + words[i].substr(overlap[j][i]);
                    if (dp[mask][i].empty() || candidate.length() < dp[mask][i].length()) {
                        dp[mask][i] = candidate;
                    }
                }
            }
        }
        string result;
        int final_mask = (1 << n) - 1;
        for (int i = 0; i < n; ++i) {
            if (result.empty() || dp[final_mask][i].length() < result.length()) {
                result = dp[final_mask][i];
            }
        }
        return result;
    }

    int getOverlap(const string& a, const string& b) {
        int max_overlap = 0;
        int len_a = a.length(), len_b = b.length();

        for (int i = min(len_a, len_b); i > 0; --i) {
            if (a.substr(len_a - i) == b.substr(0, i)) {
                max_overlap = i;
                break;
            }
        }
        return max_overlap;
    }
};
// @lc code=end
