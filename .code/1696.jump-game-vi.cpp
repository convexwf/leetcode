/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 *
 * https://leetcode.com/problems/jump-game-vi/description/
 *
 * algorithms
 * Medium (46.14%)
 * Likes:    3075
 * Dislikes: 107
 * Total Accepted:    97K
 * Total Submissions: 210.3K
 * Testcase Example:  '[1,-1,-2,4,-7,3]\n2'
 *
 * You are given a 0-indexed integer array nums and an integer k.
 *
 * You are initially standing at index 0. In one move, you can jump at most k
 * steps forward without going outside the boundaries of the array. That is,
 * you can jump from index i to any index in the range [i + 1, min(n - 1, i +
 * k)] inclusive.
 *
 * You want to reach the last index of the array (index n - 1). Your score is
 * the sum of all nums[j] for each index j you visited in the array.
 *
 * Return the maximum score you can get.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,-1,-2,4,-7,3], k = 2
 * Output: 7
 * Explanation: You can choose your jumps forming the subsequence [1,-1,4,3]
 * (underlined above). The sum is 7.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [10,-5,-2,4,0,3], k = 3
 * Output: 17
 * Explanation: You can choose your jumps forming the subsequence [10,4,3]
 * (underlined above). The sum is 17.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length, k <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
// 2023-02-28 submission
// 72/72 cases passed
// Runtime: 189 ms, faster than 75.09% of C++ online submissions.
// Memory Usage: 77.9 MB, less than 89.15% of C++ online submissions.
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int, int>> q;
        q.push_back({0, nums[0]});
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            while (!q.empty() && i - k > q.front().first) {
                q.pop_front();
            }
            ans = q.front().second + nums[i];
            while (!q.empty() && ans >= q.back().second) {
                q.pop_back();
            }
            q.push_back({i, ans});
        }
        return ans;
    }
};
// @lc code=end