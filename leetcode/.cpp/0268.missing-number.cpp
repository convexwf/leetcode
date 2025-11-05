/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
// 1. 数学方法
// 2022-08-26 submission
// 122/122 cases passed
// Runtime: 21 ms, faster than 87.75% of cpp online submissions.
// Memory Usage: 17.9 MB, less than 93.42% of cpp online submissions.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int num : nums) {
            sum += num;
        }
        return n * (n + 1) / 2 - sum;
    }
};
// @lc code=end

// @lc code=start
// 2. 位操作
// 2022-08-26 submission
// 122/122 cases passed
// Runtime: 38 ms, faster than 32.58% of cpp online submissions.
// Memory Usage: 17.9 MB, less than 64.62% of cpp online submissions.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= (i + 1) ^ nums[i];
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. 二分查找
// 2022-08-26 submission
// 122/122 cases passed
// Runtime: 43 ms, faster than 21.03% of cpp online submissions.
// Memory Usage: 18.1 MB, less than 20.2% of cpp online submissions.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return right;
    }
};
// @lc code=end
