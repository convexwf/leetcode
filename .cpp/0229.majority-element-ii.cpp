/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
// 1. 多数投票算法(Boyer-Moore Algorithm)
// 2022-11-14 submission
// 87/87 cases passed
// Runtime: 37 ms, faster than 21.31% of cpp online submissions.
// Memory Usage: 15.9 MB, less than 47.49% of cpp online submissions.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int a = 0, b = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
        for (int num : nums) {
            if (num == a) {
                ++cnt1;
            }
            else if (num == b) {
                ++cnt2;
            }
            else if (cnt1 == 0) {
                a = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                b = num;
                cnt2 = 1;
            }
            else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int num : nums) {
            if (num == a) {
                ++cnt1;
            }
            else if (num == b) {
                ++cnt2;
            }
        }
        if (cnt1 > n / 3) res.push_back(a);
        if (cnt2 > n / 3) res.push_back(b);
        return res;
    }
};
// @lc code=end
