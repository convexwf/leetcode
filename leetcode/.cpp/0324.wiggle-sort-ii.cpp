/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
// 1. 排序
// 2023-05-22 submission
// 52/52 cases passed
// Runtime: 19 ms, faster than 85.4% of cpp online submissions.
// Memory Usage: 17.7 MB, less than 72.05% of cpp online submissions.
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = nums.size();
        int left = (n - 1) / 2; // [0, 1, 2, 3] 取 1，[0, 1, 2, 3, 4] 取 2
        int right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                nums[i] = tmp[right--];
            }
            else {
                nums[i] = tmp[left--];
            }
        }
    }
};
// @lc code=end

// @lc code=start
// 2. 快速选择算法
// 2025-02-12 submission
// 52/52 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 21.4 MB, less than 93.61% of cpp online submissions.
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = nums[n / 2];
        int left = 0, right = n - 1;
        int i = 0;
        while (i <= right) {
            if (nums[reIndex(i, n)] > mid) {
                swap(nums[reIndex(i++, n)], nums[reIndex(left++, n)]);
            }
            else if (nums[reIndex(i, n)] < mid) {
                swap(nums[reIndex(i, n)], nums[reIndex(right--, n)]);
            }
            else {
                i++;
            }
        }
    }

    int reIndex(int index, int n) {
        return (1 + 2 * index) % (n | 1);
    }
};
// @lc code=end
