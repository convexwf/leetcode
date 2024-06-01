/*
 * @lc app=leetcode id=157 lang=cpp
 *
 * [157] Read N Characters Given Read4
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    int read(char *buf, int n) {
        int readBytes = 0;
        char buf4[4];
        while (readBytes < n) {
            int curBytes = read4(buf4);
            if (curBytes == 0) {
                break;
            }
            for (int i = 0; i < curBytes && readBytes < n; ++i) {
                buf[readBytes++] = buf4[i];
            }
        }
        return readBytes;
    }
};
// @lc code=end
