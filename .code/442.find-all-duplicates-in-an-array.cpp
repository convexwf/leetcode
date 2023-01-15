/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (73.43%)
 * Likes:    7909
 * Dislikes: 298
 * Total Accepted:    485K
 * Total Submissions: 660.5K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an integer array nums of length n where all the integers of nums are
 * in the range [1, n] and each integer appears once or twice, return an array
 * of all the integers that appears twice.
 *
 * You must write an algorithm that runs in O(n) time and uses only constant
 * extra space.
 *
 *
 * Example 1:
 * Input: nums = [4,3,2,7,8,2,3,1]
 * Output: [2,3]
 * Example 2:
 * Input: nums = [1,1,2]
 * Output: [1]
 * Example 3:
 * Input: nums = [1]
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= n
 * Each element in nums appears once or twice.
 *
 *
 */

// @lc code=start
// 2021-03-19 submission
// 28/28 cases passed
// Runtime: 71 ms, faster than 76.13% of C++ online submissions.
// Memory Usage: 33.6 MB, less than 81.71% of C++ online submissions.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int dst = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            dst = nums[i] > 0 ? nums[i] : nums[i] + (n + 1);
            if (nums[dst-1] >= 0) nums[dst-1] -= (n + 1);
            else res.push_back(dst);
        }
        return res;
    }
    // 另一种写法
    // vector<int> findDuplicates(vector<int>& nums) {
    //     vector<int> res;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         int idx = abs(nums[i]) - 1;
    //         if (nums[idx] < 0) res.push_back(idx + 1);
    //         nums[idx] = -nums[idx];
    //     }
    //     return res;
    // }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 28/28 cases passed
// Runtime: 76 ms, faster than 71.78% of C++ online submissions.
// Memory Usage: 33.5 MB, less than 81.71% of C++ online submissions.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) res.push_back(nums[i]);
        }
        return res;
    }
};
// @lc code=end