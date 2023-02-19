/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (42.72%)
 * Likes:    6245
 * Dislikes: 269
 * Total Accepted:    375.3K
 * Total Submissions: 878.5K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an integer array nums, return true if there exists a triple of indices
 * (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such
 * indices exists, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4,5]
 * Output: true
 * Explanation: Any triplet where i < j < k is valid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,4,3,2,1]
 * Output: false
 * Explanation: No triplet exists.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,1,5,0,4,6]
 * Output: true
 * Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4]
 * == 4 < nums[5] == 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5 * 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you implement a solution that runs in O(n) time complexity
 * and O(1) space complexity?
 */

// @lc code=start
// 2023-02-13 submission
// 78/78 cases passed
// Runtime: 150 ms, faster than 49.78% of C++ online submissions.
// Memory Usage: 111.7 MB, less than 19.22% of C++ online submissions.
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for (auto a : nums) {
            if (m1 >= a) m1 = a;
            else if (m2 >= a) m2 = a;
            else return true;
        }
        return false;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-13 submission
// 78/78 cases passed
// Runtime: 178 ms, faster than 20.57% of C++ online submissions.
// Memory Usage: 121.1 MB, less than 5.53% of C++ online submissions.
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int n = nums.size();
        vector<int> f(n, nums[0]), b(n, nums.back());
        for (int i = 1; i < n; ++i) {
            f[i] = min(f[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            b[i] = max(b[i + 1], nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > f[i] && nums[i] < b[i]) return true;
        }
        return false;
    }
};
// @lc code=end