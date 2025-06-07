/*
 * @lc app=leetcode id=995 lang=cpp
 *
 * [995] Minimum Number of K Consecutive Bit Flips
 */

// @lc code=start
// 1. 差分数组
// 2025-06-05 submission
// 113/113 cases passed
// Runtime: 8 ms, faster than 37.84% of cpp online submissions.
// Memory Usage: 114.8 MB, less than 21.91% of cpp online submissions.
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        int flips = 0, res = 0;

        for (int i = 0; i < n; ++i) {
            flips += diff[i];
            if ((nums[i] + flips) % 2 == 0) {
                diff[i]++;
                if (i + k > n) {
                    return -1;
                }
                res++;
                flips++;
                diff[i + k]--;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 位操作+贪心算法
// 2025-06-05 submission
// 113/113 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 110.1 MB, less than 92.75% of cpp online submissions.
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, flipped = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k && nums[i - k] == -1) {
                flipped ^= 1;
            }
            if (flipped == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                flipped ^= 1;
                ++ans;
                nums[i] = -1;
            }
        }
        return ans;
    }
};
// @lc code=end
