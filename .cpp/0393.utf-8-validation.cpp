/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
// 1. 位操作
// 2022-11-14 submission
// 51/51 cases passed
// Runtime: 37 ms, faster than 20.66% of cpp online submissions.
// Memory Usage: 14.1 MB, less than 44.42% of cpp online submissions.
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int i = 0; i < data.size(); i++) {
            if (cnt == 0) {
                // 0xxxxxxx
                if (!(data[i] & 0b10000000 ^ 0b00000000)) {
                    cnt = 0;
                }
                // 110xxxxx 10xxxxxx
                else if (!(data[i] & 0b11100000 ^ 0b11000000)) {
                    cnt = 1;
                }
                // 1110xxxx 10xxxxxx 10xxxxxx
                else if (!(data[i] & 0b11110000 ^ 0b11100000)) {
                    cnt = 2;
                }
                // 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
                else if (!(data[i] & 0b11111000 ^ 0b11110000)) {
                    cnt = 3;
                }
                else {
                    return false;
                }
            }
            else {
                if (!(data[i] & 0b11000000 ^ 0b10000000)) {
                    cnt--;
                }
                else {
                    return false;
                }
            }
        }
        return cnt == 0;
    }
};
// @lc code=end
