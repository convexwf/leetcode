/*
 * @lc app=leetcode id=660 lang=cpp
 *
 * [660] Remove 9
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    int newInteger(int n) {
        int count = 0;
        for (int i = 1;; i++) {
            if (to_string(i).find('9') != string::npos) {
                continue;
            }
            count++;
            if (count == n) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 2. 找规律
class Solution {
public:
    int newInteger(int n) {
        int res = 0;
        int base = 1;
        while (n) {
            res += n % 9 * base;
            n /= 9;
            base *= 10;
        }
        return res;
    }
};
// @lc code=end
