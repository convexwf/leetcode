/*
 * @lc app=leetcode id=340 lang=cpp
 *
 * [340] Longest Substring with At Most K Distinct Characters
 */

// @lc code=start
// 1. 滑动窗口+哈希表
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if (n == 0 || k == 0) {
            return 0;
        }
        unordered_map<char, int> hash;
        int left = 0, right = 0;
        int res = 0;
        while (right < n) {
            hash[s[right]]++;
            while (hash.size() > k) {
                hash[s[left]]--;
                if (hash[s[left]] == 0) {
                    hash.erase(s[left]);
                }
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
// @lc code=end
