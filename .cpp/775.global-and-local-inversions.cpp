/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

// @lc code=start
// 1. 比较
// 2023-09-26 submission
// 226/226 cases passed
// Runtime: 111 ms, faster than 44.41% of cpp online submissions.
// Memory Usage: 83.6 MB, less than 40.44% of cpp online submissions.
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int maxVal = -1;
        for (int i = 0; i < (int)nums.size() - 2; ++i) {
            maxVal = max(maxVal, nums[i]);
            if (maxVal > nums[i + 2]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 归并排序
// 2023-09-26 submission
// 226/226 cases passed
// Runtime: 240 ms, faster than 27.7% of cpp online submissions.
// Memory Usage: 87.4 MB, less than 22.62% of cpp online submissions.
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        int local = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) ++local;
        }
        return local == mergeSort(nums, tmp, 0, n - 1);
    }

    long mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) return 0;
        int mid = l + (r - l) / 2;
        long inversions = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos++] = nums[i++];
            }
            else {
                inversions += mid - i + 1;
                tmp[pos++] = nums[j++];
            }
        }
        while (i <= mid) tmp[pos++] = nums[i++];
        while (j <= r) tmp[pos++] = nums[j++];
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inversions;
    }
};
// @lc code=end

// @lc code=start
// 3. 数学方法
// 2023-09-26 submission
// 226/226 cases passed
// Runtime: 106 ms, faster than 55.77% of cpp online submissions.
// Memory Usage: 83.6 MB, less than 40.44% of cpp online submissions.
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i) {
            if (abs(A[i] - i) > 1) return false;
        }
        return true;
    }
};
// @lc code=end
