/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
// 2023-02-27 submission
// 37/37 cases passed
// Runtime: 34 ms, faster than 43.46% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 79.14% of cpp online submissions.
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, n = s.size();
        for (int cnt = 1; cnt <= 26; ++cnt) {
            int start = 0, i = 0, uniqueCnt = 0;
            vector<int> charCnt(26);
            while (i < n) {
                bool valid = true;
                if (charCnt[s[i++] - 'a']++ == 0) ++uniqueCnt;
                while (uniqueCnt > cnt) {
                    if (--charCnt[s[start++] - 'a'] == 0) --uniqueCnt;
                }
                for (int j = 0; j < 26; ++j) {
                    if (charCnt[j] > 0 && charCnt[j] < k) valid = false;
                }
                if (valid) res = max(res, i - start);
            }
        }
        return res;
    }
};
// @lc code=end
