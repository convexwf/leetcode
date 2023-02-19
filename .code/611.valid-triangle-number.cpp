/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 *
 * https://leetcode.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (50.48%)
 * Likes:    3238
 * Dislikes: 177
 * Total Accepted:    164K
 * Total Submissions: 324.9K
 * Testcase Example:  '[2,2,3,4]'
 *
 * Given an integer array nums, return the number of triplets chosen from the
 * array that can make triangles if we take them as side lengths of a
 * triangle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,2,3,4]
 * Output: 3
 * Explanation: Valid combinations are: 
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,2,3,4]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
// 2023-02-13 submission
// 241/241 cases passed
// Runtime: 425 ms, faster than 21.84% of C++ online submissions.
// Memory Usage: 13 MB, less than 11.25% of C++ online submissions.
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = nums[i] + nums[j], left = j + 1, right = n;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum) left = mid + 1;
                    else right = mid;
                }
                res += right - 1 - j;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-13 submission
// 241/241 cases passed
// Runtime: 103 ms, faster than 83.01% of C++ online submissions.
// Memory Usage: 13.1 MB, less than 11.25% of C++ online submissions.
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    res += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return res;
    }
};
// @lc code=end