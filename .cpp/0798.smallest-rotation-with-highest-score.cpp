/*
 * @lc app=leetcode id=798 lang=cpp
 *
 * [798] Smallest Rotation with Highest Score
 */

// @lc code=start
// 1. 差分数组
// 2025-06-04 submission
// 44/44 cases passed
// Runtime: 4 ms, faster than 71.97% of cpp online submissions.
// Memory Usage: 78.4 MB, less than 51.52% of cpp online submissions.
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            int l = (i + 1) % n;
            int r = (n + i + 1 - nums[i]) % n;
            ++diff[l];
            --diff[r];
        }

        int score = 0, mx = -1, ans = n;
        for (int k = 0; k < n; ++k) {
            score += diff[k];
            if (score > mx) {
                mx = score;
                ans = k;
            }
        }
        return ans;
    }
};
// @lc code=end
