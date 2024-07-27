/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
// 1. 一次遍历
// 2022-11-15 submission
// 34/34 cases passed
// Runtime: 13 ms, faster than 60.43% of cpp online submissions.
// Memory Usage: 9.2 MB, less than 66.05% of cpp online submissions.
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long m1 = LLONG_MIN, m2 = LLONG_MIN, m3 = LLONG_MIN;
        for (int num : nums) {
            if (num > m1) {
                m3 = m2;
                m2 = m1;
                m1 = num;
            }
            else if (num < m1 && num > m2) {
                m3 = m2;
                m2 = num;
            }
            else if (num < m2 && num > m3) {
                m3 = num;
            }
        }
        return m3 == LLONG_MIN ? m1 : m3;
    }
};
// @lc code=end
