/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Medium (39.22%)
 * Likes:    12085
 * Dislikes: 1442
 * Total Accepted:    1.3M
 * Total Submissions: 3.4M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1,-100,3,99], k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^5
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Try to come up with as many solutions as you can. There are at least three
 * different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 * 
 */

// @lc code=start
// 2022-11-17 submission
// 38/38 cases passed
// Runtime: 78 ms, faster than 38.13% of C++ online submissions.
// Memory Usage: 25 MB, less than 84.71% of C++ online submissions.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int start = 0, idx = 0, pre = 0, cur = nums[0], n = nums.size();
        for (int i = 0; i < n; ++i) {
            pre = cur;
            idx = (idx + k) % n;
            cur = nums[idx];
            nums[idx] = pre;
            if (idx == start) {
                idx = ++start;
                cur = nums[idx];
            }
        }
    }
};
// 1 2 3 4 5 6 7
// 1 2 3 1 5 6 7
// 1 2 3 1 5 6 4
// 1 2 7 1 5 6 4
// 1 2 7 1 5 3 4
// 1 6 7 1 5 3 4
// 1 6 7 1 2 3 4
// 5 6 7 1 2 3 4
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 38/38 cases passed
// Runtime: 52 ms, faster than 70.88% of C++ online submissions.
// Memory Usage: 25 MB, less than 84.71% of C++ online submissions.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()) return;
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
// 1 2 3 4 5 6 7
// 4 3 2 1 5 6 7
// 4 3 2 1 7 6 5
// 5 6 7 1 2 3 4
// @lc code=end

// @lc code=start
// 2022-11-17 submission
// 38/38 cases passed
// Runtime: 100 ms, faster than 6.05% of C++ online submissions.
// Memory Usage: 25.1 MB, less than 60.15% of C++ online submissions.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        int n = nums.size(), start = 0;
        while (n && (k %= n)) {
            for (int i = 0; i < k; ++i) {
                swap(nums[i + start], nums[n - k + i + start]);
            }
            n -= k;
            start += k;
        }
    }
};
// 1 2 3 4 5 6 7
// 5 2 3 4 1 6 7
// 5 6 3 4 1 2 7
// 5 6 7 4 1 2 3
// 5 6 7 1 4 2 3
// 5 6 7 1 2 4 3
// 5 6 7 1 2 3 4
// @lc code=end