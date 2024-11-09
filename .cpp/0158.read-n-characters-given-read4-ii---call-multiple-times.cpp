/*
 * @lc app=leetcode id=158 lang=cpp
 *
 * [158] Read N Characters Given read4 II - Call Multiple Times
 */

// @lc code=start
// 1. 模拟
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        for (int i = 0; i < n; ++i) {
            if (readPos == writePos) {
                writePos = read4(buff);
                readPos = 0;
                if (writePos == 0) return i;
            }
            buf[i] = buff[readPos++];
        }
        return n;
    }

private:
    int readPos = 0, writePos = 0;
    char buff[4];
};
// @lc code=end
