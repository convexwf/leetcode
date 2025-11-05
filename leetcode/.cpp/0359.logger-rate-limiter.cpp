/*
 * @lc app=leetcode id=359 lang=cpp
 *
 * [359] Logger Rate Limiter
 */

// @lc code=start
// 1. 哈希表
class Logger {
public:
    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (m.count(message) && timestamp - m[message] < 10) {
            return false;
        }
        m[message] = timestamp;
        return true;
    }

private:
    unordered_map<string, int> m;
};
// @lc code=end
