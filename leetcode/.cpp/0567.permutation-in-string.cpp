/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
// 1. 滑动窗口+哈希表
// 2023-06-06 submission
// 108/108 cases passed
// Runtime: 11 ms, faster than 51.34% of cpp online submissions.
// Memory Usage: 7.3 MB, less than 69.17% of cpp online submissions.
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26, 0);
        for (char c : s1) {
            cnt[c - 'a']++;
        }
        int n = s2.size();
        int m = s1.size();
        int total = m;
        for (int i = 0; i < n; i++) {
            cnt[s2[i] - 'a']--;
            if (cnt[s2[i] - 'a'] >= 0) {
                total--;
            }
            if (i >= m) {
                cnt[s2[i - m] - 'a']++;
                if (cnt[s2[i - m] - 'a'] > 0) {
                    total++;
                }
            }
            if (total == 0) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2. 滑动窗口+双哈希表
// 2023-06-06 submission
// 108/108 cases passed
// Runtime: 12 ms, faster than 48.46% of cpp online submissions.
// Memory Usage: 7.2 MB, less than 91.2% of cpp online submissions.
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        vector<int> cnt1(26), cnt2(26);
        for (int i = 0; i < n; ++i) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }
        if (cnt1 == cnt2) return true;
        for (int i = n; i < m; ++i) {
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i - n] - 'a'];
            if (cnt1 == cnt2) return true;
        }
        return false;
    }
};
// @lc code=end
