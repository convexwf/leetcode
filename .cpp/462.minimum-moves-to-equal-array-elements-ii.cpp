/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
// 1. 排序
// 2023-05-25 submission
// 32/32 cases passed
// Runtime: 21 ms, faster than 5.96% of cpp online submissions.
// Memory Usage: 11.9 MB, less than 19.78% of cpp online submissions.
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = nums[n / 2];
        return accumulate(nums.begin(), nums.end(), 0,
                          [&](int acc, int num) { return acc + abs(num - mid); });
    }
};
// @lc code=end

// @lc code=start
// 2. 快速选择算法
// 2023-05-25 submission
// 32/32 cases passed
// Runtime: 2068 ms, faster than 5.96% of cpp online submissions.
// Memory Usage: 11.7 MB, less than 92.61% of cpp online submissions.
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        int l = 0, r = n - 1;
        while (l < r) {
            int p = partition(nums, l, r);
            if (p == mid) {
                break;
            }
            else if (p < mid) {
                l = p + 1;
            }
            else {
                r = p - 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += abs(nums[i] - nums[mid]);
        }
        return ans;
    }

private:
    int partition(vector<int>& nums, int s, int e) {
        if (s >= e) return s;

        int i = s - 1;
        for (int j = s; j < e; ++j) {
            if (nums[j] <= nums[e]) {
                ++i;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[++i], nums[e]);
        return i;
    }
};
// @lc code=end