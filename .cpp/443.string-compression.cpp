/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
// 1. 双指针法
// 2023-05-29 submission
// 75/75 cases passed
// Runtime: 3 ms, faster than 90.72% of cpp online submissions.
// Memory Usage: 9.1 MB, less than 41.97% of cpp online submissions.
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 1) {
            return 1;
        }
        // 双指针法
        int count = 1;
        int index = 0;
        for (int i = 1; i < n; ++i) {
            if (chars[i] == chars[i - 1]) {
                ++count;
            }
            else {
                chars[index++] = chars[i - 1];
                if (count > 1) {
                    string s = to_string(count);
                    for (int j = 0; j < s.size(); ++j) {
                        chars[index++] = s[j];
                    }
                }
                count = 1;
            }
        }
        chars[index++] = chars[n - 1];
        if (count > 1) {
            string s = to_string(count);
            for (int j = 0; j < s.size(); ++j) {
                chars[index++] = s[j];
            }
        }
        return index;
    }
};
// @lc code=end
