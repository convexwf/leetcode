/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
// 2022-07-18 submission
// 987/987 cases passed
// Runtime: 7 ms, faster than 92.47% of C++ online submissions.
// Memory Usage: 8.4 MB, less than 57.99% of C++ online submissions.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int l = 0;
        vector<int> m(256, 0); // unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            ++m[s[i]];
            while(m[s[i]] > 1) {
                m[s[l++]]--;
            }
            max_length = max(max_length, i - l + 1);
        }
        return max_length;
    }
};
// @lc code=end