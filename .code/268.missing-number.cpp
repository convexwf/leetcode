/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (61.10%)
 * Likes:    7086
 * Dislikes: 2959
 * Total Accepted:    1.2M
 * Total Submissions: 2M
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array nums containing n distinct numbers in the range [0, n],
 * return the only number in the range that is missing from the array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,0,1]
 * Output: 2
 * Explanation: n = 3 since there are 3 numbers, so all numbers are in the
 * range [0,3]. 2 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: n = 2 since there are 2 numbers, so all numbers are in the
 * range [0,2]. 2 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * Explanation: n = 9 since there are 9 numbers, so all numbers are in the
 * range [0,9]. 8 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 10^4
 * 0 <= nums[i] <= n
 * All the numbers of nums are unique.
 *
 *
 *
 * Follow up: Could you implement a solution using only O(1) extra space
 * complexity and O(n) runtime complexity?
 *
 */

// @lc code=start
// 2022-08-26 submission
// 122/122 cases passed
// Runtime: 21 ms, faster than 87.75% of C++ online submissions.
// Memory Usage: 17.9 MB, less than 93.42% of C++ online submissions.
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
// 2022-08-26 submission
// 122/122 cases passed
// Runtime: 38 ms, faster than 32.58% of C++ online submissions.
// Memory Usage: 17.9 MB, less than 64.62% of C++ online submissions.
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
// 2022-08-26 submission
// 122/122 cases passed
// Runtime: 43 ms, faster than 21.03% of C++ online submissions.
// Memory Usage: 18.1 MB, less than 20.2% of C++ online submissions.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
};
// @lc code=end
