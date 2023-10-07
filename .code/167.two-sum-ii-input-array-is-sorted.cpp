/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
// 2022-11-14 submission
// 21/21 cases passed
// Runtime: 36 ms, faster than 27.96% of C++ online submissions.
// Memory Usage: 15.5 MB, less than 92.98% of C++ online submissions.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() < 2) return {};
        int l = 0;
        int r = (int)numbers.size() - 1;
        while(l <= r) {
            int left = numbers[l];
            int right = numbers[r];
            if(left + right < target) l++;
            else if(left + right > target) r--;
            else return {l + 1, r + 1};
        }
        return vector<int>{};
    }
};
// @lc code=end