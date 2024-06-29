/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
// 1. 双指针
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
        chars.push_back(' ');
        int j = 0, count = 1;
        for (int i = 1; i < n + 1; i++) {
            if (chars[i] == chars[i - 1]) {
                count++;
            }
            else {
                chars[j++] = chars[i - 1];
                if (count > 1) {
                    string s = to_string(count);
                    for (char c : s) {
                        chars[j++] = c;
                    }
                }
                count = 1;
            }
        }
        return j;
    }
};
// @lc code=end
