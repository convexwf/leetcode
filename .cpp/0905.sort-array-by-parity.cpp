/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
// 1. 双指针
// 2023-07-14 submission
// 285/285 cases passed
// Runtime: 8 ms, faster than 85.78% of cpp online submissions.
// Memory Usage: 16.1 MB, less than 71.14% of cpp online submissions.
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i < j && nums[i] % 2 == 0) ++i;
            while (i < j && nums[j] % 2 == 1) --j;
            if (i < j) swap(nums[i++], nums[j--]);
        }
        return nums;
    }
};
// @lc code=end

// @lc code=start
// 2. partition
// 2023-07-14 submission
// 285/285 cases passed
// Runtime: 13 ms, faster than 52.34% of cpp online submissions.
// Memory Usage: 16.3 MB, less than 45.44% of cpp online submissions.
class Solution {
private:
    int partition(std::vector<int>& nums, int left, int right) {
        int pivot = nums[right]; // 选择最后一个元素作为枢轴
        int i = left - 1;        // 偶数部分的边界索引

        for (int j = left; j < right; j++) {
            if (nums[j] % 2 == 0) {
                i++;
                std::swap(nums[i], nums[j]); // 将偶数放在前半部分
            }
        }

        std::swap(nums[i + 1], nums[right]); // 将枢轴放在偶数和奇数之间
        return i + 1;                        // 返回偶数部分的边界索引
    }

public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return nums; // 数组为空或只有一个元素，无需排序
        }
        partition(nums, 0, n - 1);
        return nums;
    }
};
// @lc code=end
