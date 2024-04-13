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
        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        vector<int> cnt(26);
        for (int i = 0; i < n; ++i) {
            ++cnt[s1[i] - 'a'];
        } 
        int l = 0, r = 0;
        while (r < m) {
            if (cnt[s2[r] - 'a'] > 0) {
                --cnt[s2[r] - 'a'];
                ++r;
            } else {
                ++cnt[s2[l] - 'a'];
                ++l;
            }
            if (r - l == n) return true;
        }
        // Another way to write the while loop
        // for (int r = 0; r < m; ++r) {
        //     if (--cnt[s2[r] - 'a'] < 0) {
        //         while (++m[s2[l++] - 'a'] != 0);
        //     } else if (r - l + 1 == n) return true;
        // }
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
