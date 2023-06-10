/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 */

// @lc code=start
// 1. 标记法
// 2023-06-09 submission
// 885/885 cases passed
// Runtime: 164 ms, faster than 51.61% of cpp online submissions.
// Memory Usage: 91.4 MB, less than 87.1% of cpp online submissions.
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != -1) {
                int start = nums[i], count = 0;
                while (nums[start] != -1) {
                    int temp = start;
                    start = nums[start];
                    nums[temp] = -1;
                    ++count;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 交换法
// 2023-06-09 submission
// 885/885 cases passed
// Runtime: 143 ms, faster than 87.1% of cpp online submissions.
// Memory Usage: 91.3 MB, less than 87.1% of cpp online submissions.
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 1;
            while (nums[i] != i) {
                swap(nums[i], nums[nums[i]]);
                ++cnt;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
// @lc code=end