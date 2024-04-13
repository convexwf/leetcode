/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
// 1. 贪心
// 2023-07-28 submission
// 60/60 cases passed
// Runtime: 72 ms, faster than 100% of cpp online submissions.
// Memory Usage: 83.3 MB, less than 65.6% of cpp online submissions.
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            }
            else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
