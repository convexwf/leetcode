/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */

// @lc code=start
// 1. brute force
// 2023-09-05 submission
// 202/202 cases passed
// Runtime: 5 ms, faster than 30.65% of cpp online submissions.
// Memory Usage: 7.6 MB, less than 7.88% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int start = 0, end = 0;
        s.append(1, '#');
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                end = i;
            }
            else {
                if (end - start + 1 >= 3) {
                    res.push_back({start, end});
                }
                start = i;
                end = i;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 双指针
// 2023-09-05 submission
// 202/202 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 85.81% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int n = S.size(), i = 0, j = 0;
        while (j < n) {
            while (j < n && S[j] == S[i]) ++j;
            if (j - i >= 3) res.push_back({i, j - 1});
            i = j;
        }
        return res;
    }
};
// @lc code=end
