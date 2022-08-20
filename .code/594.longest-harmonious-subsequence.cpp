/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (53.00%)
 * Likes:    1655
 * Dislikes: 158
 * Total Accepted:    121.8K
 * Total Submissions: 229.7K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmonious array as an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 * 
 * Given an integer array nums, return the length of its longest harmonious
 * subsequence among all its possible subsequences.
 * 
 * A subsequence of array is a sequence that can be derived from the array by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,1,1,1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 */

// @lc code=start
// 2022-08-19 submission
// 206/206 cases passed
// Runtime: 206 ms, faster than 19.15% of C++ online submissions.
// Memory Usage: 41.6 MB, less than 35.24% of C++ online submissions.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        map<int, int> m;
        for (int num : nums) ++m[num];
        for (auto it = next(m.begin()); it != m.end(); ++it) {
            auto pre = prev(it);
            if (it->first == pre->first + 1) {
                res = max(res, it->second + pre->second);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 206/206 cases passed
// Runtime: 95 ms, faster than 85.98% of C++ online submissions.
// Memory Usage: 40.1 MB, less than 52.71% of C++ online submissions.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums) ++m[num];
        for (auto a : m) {
            if (m.count(a.first + 1)) {
                res = max(res, m[a.first] + m[a.first + 1]);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 206/206 cases passed
// Runtime: 162 ms, faster than 36.92% of C++ online submissions.
// Memory Usage: 39.9 MB, less than 72.75% of C++ online submissions.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int num : nums) {
            ++m[num];
            if (m.count(num + 1)) {
                res = max(res, m[num] + m[num + 1]);
            }
            if (m.count(num - 1)) {
                res = max(res, m[num] + m[num - 1]);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 206/206 cases passed
// Runtime: 73 ms, faster than 97.04% of C++ online submissions.
// Memory Usage: 32.5 MB, less than 89.93% of C++ online submissions.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int l = 0;
        for (int r = 1; r < nums.size(); ++r) {
            if (nums[r] - nums[l] == 1) {
                res = max(res, r - l + 1);
            }
            else if (nums[r] - nums[l] > 1) {
                while (nums[r] - nums[l] > 1) ++l;
            }
        }
        return res;
    }
};
// @lc code=end