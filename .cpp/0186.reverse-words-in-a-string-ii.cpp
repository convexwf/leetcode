/*
 * @lc app=leetcode id=186 lang=cpp
 *
 * [186] Reverse Words in a String II
 */

// @lc code=start
// 1. 双指针
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        reverse(s.begin() + start, s.end());
    }
};
// @lc code=end
