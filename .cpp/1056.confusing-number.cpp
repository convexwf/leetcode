/*
 * @lc app=leetcode id=1056 lang=cpp
 *
 * [1056] Confusing Number
 */

// @lc code=start
class Solution {
public:
    bool confusingNumber(int N) {
        int num = N;
        int res = 0;
        unordered_map<int, int> m = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
        while (num) {
            int digit = num % 10;
            if (!m.count(digit)) {
                return false;
            }
            res = res * 10 + m[digit];
            num /= 10;
        }
        return res != N;
    }
};
// @lc code=end
