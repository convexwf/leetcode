/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
// 2020-09-14 submission
// 106/106 cases passed
// Runtime: 6 ms, faster than 56.57% of cpp online submissions.
// Memory Usage: 6.5 MB, less than 72.19% of cpp online submissions.
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int c1 = s1.length(), c2 = s2.length();
        if (c1 + c2 != s3.length()) return false;
        vector<bool> dp(c1 + 1, true);

        for (int i = 1; i <= c1; i++) {
            dp[i] = (s1.substr(0, i) == s3.substr(0, i));
        }
        for (int i = 1; i <= c2; i++) {
            dp[0] = (s2.substr(0, i) == s3.substr(0, i));
            for (int j = 1; j <= c1; j++) {
                dp[j] = (dp[j - 1] && s1[j - 1] == s3[i + j - 1]) ||
                        (dp[j] && s2[i - 1] == s3[i + j - 1]);
                // cout << s1[j-1] << " " << s2[i-1] << endl;
            }
        }

        return dp[c1];
    }
};
// @lc code=end

// @lc code=start
// 2023-02-02 submission
// 106/106 cases passed
// Runtime: 3 ms, faster than 82.88% of cpp online submissions.
// Memory Usage: 10.7 MB, less than 32.05% of cpp online submissions.
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        unordered_set<int> s;
        return helper(s1, 0, s2, 0, s3, 0, s);
    }
    bool helper(string& s1, int i, string& s2, int j, string& s3, int k, unordered_set<int>& s) {
        int key = i * s3.length() + j;
        if (s.count(key)) return false;
        if (i == s1.length()) return s2.substr(j) == s3.substr(k);
        if (j == s2.length()) return s1.substr(i) == s3.substr(k);
        if ((s1[i] == s3[k] && helper(s1, i + 1, s2, j, s3, k + 1, s)) ||
            (s2[j] == s3[k] && helper(s1, i, s2, j + 1, s3, k + 1, s)))
            return true;
        s.insert(key);
        return false;
    }
};
// @lc code=end
