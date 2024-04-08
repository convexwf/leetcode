/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
// 2023-01-14 submission
// 59/59 cases passed
// Runtime: 4 ms, faster than 48.28% of cpp online submissions.
// Memory Usage: 9.1 MB, less than 74.47% of cpp online submissions.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 59/59 cases passed
// Runtime: 8 ms, faster than 16.84% of cpp online submissions.
// Memory Usage: 9.1 MB, less than 33.71% of cpp online submissions.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }
    }
};
// @lc code=end
