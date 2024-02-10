/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
// 2021-12-21 submission
// 551/551 cases passed
// Runtime: 3 ms, faster than 33.99% of C++ online submissions.
// Memory Usage: 6.7 MB, less than 28.96% of C++ online submissions.
class Solution {
public:
    bool detectCapitalUse(string word) {
        vector<vector<int> > trans{
            {1, 2},
            {1, 5},
            {3, 4},
            {3, 5},
            {5, 4},
            {5, 5}
        };
        int state = 0;
        for (char c : word) {
            int next = isupper(c) ? 1 : 0;
            state = trans[state][next];
            if (state == 5) break;
        }
        return state != 5;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-31 submission
// 551/551 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 5.9 MB, less than 99.79% of C++ online submissions.
class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0, n = word.size();
        for (int i = 0; i < n; ++i) {
            if (word[i] <= 'Z') ++cnt;
        }
        return cnt == 0 || cnt == n || (cnt == 1 && word[0] <= 'Z');
    }
};
// @lc code=end