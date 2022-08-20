/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (55.27%)
 * Likes:    1730
 * Dislikes: 1146
 * Total Accepted:    133.5K
 * Total Submissions: 241.4K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 *
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,2,3,1]
 * Output: 2
 * Explanation:
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,2,3,1,4,2]
 * Output: 6
 * Explanation:
 * The degree is 3 because the element 2 is repeated 3 times.
 * So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 *
 *
 *
 * Constraints:
 *
 *
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 *
 *
 */

// @lc solution=start
解题思路

1. 首先统计数组元素的出现次数，以及数组元素的右边界。得到最大出现次数后，从左往右遍历，依次计算元素是否符合最大出现次数，如果符合就计算区间长度，并将出现次数减一，防止后续重复计算。
// @lc solution=end

// @lc code=start
// 2021-12-15 submission
// 89/89 cases passed
// Runtime: 44 ms, faster than 56.21% of C++ online submissions.
// Memory Usage: 25.5 MB, less than 67.47% of C++ online submissions.
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;      // 出现次数的映射
        unordered_map<int, int> right;  // 右边界的映射
        int max_val = 0;                // 数组的度, 最多出现次数
        for (int i = 0; i < nums.size(); i++) {
            ++m[nums[i]];
            right[nums[i]] = i;
            max_val = max(max_val, m[nums[i]]);
        }

        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] == max_val) {
                res = min(res, right[nums[i]] - i + 1);
                --m[nums[i]];
            }
        }
        return res;
    }
};
// @lc code=end

