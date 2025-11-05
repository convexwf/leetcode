/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
// 1. 计数
// 2022-11-15 submission
// 42/42 cases passed
// Runtime: 88 ms, faster than 48.57% of cpp online submissions.
// Memory Usage: 36.1 MB, less than 70.87% of cpp online submissions.
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cnt = 0;
        for (int num : nums) {
            if (num == 0) {
                cnt = 0;
            }
            else {
                ++cnt;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法
// 2022-11-15 submission
// 42/42 cases passed
// Runtime: 98 ms, faster than 30.28% of cpp online submissions.
// Memory Usage: 36.2 MB, less than 21.5% of cpp online submissions.
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, sum = 0;
        for (int num : nums) {
            sum = (sum + num) * num;
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end
