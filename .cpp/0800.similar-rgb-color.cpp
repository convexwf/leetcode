/*
 * @lc app=leetcode id=800 lang=cpp
 *
 * [800] Similar RGB Color
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    string similarRGB(string color) {
        return "#" + f(color.substr(1, 2)) + f(color.substr(3, 2)) + f(color.substr(5, 2));
    }

    string f(string comp) {
        int num = stoi(comp, nullptr, 16);
        int q = num / 17, r = num % 17;
        if (r > 17 / 2) q++;
        return string(2, '0' + q);
    }
};
// @lc code=end
