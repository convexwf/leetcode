/*
 * @lc app=leetcode id=360 lang=cpp
 *
 * [360] Sort Transformed Array
 */

// @lc code=start
// 1. 数学方法+分类讨论+双指针
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n - 1;
        int i = a >= 0 ? n - 1 : 0;
        auto f = [&](int x) { return a * x * x + b * x + c; };
        while (left <= right) {
            int leftVal = f(nums[left]);
            int rightVal = f(nums[right]);
            if (a >= 0) {
                if (leftVal >= rightVal) {
                    res[i--] = leftVal;
                    left++;
                }
                else {
                    res[i--] = rightVal;
                    right--;
                }
            }
            else {
                if (leftVal <= rightVal) {
                    res[i++] = leftVal;
                    left++;
                }
                else {
                    res[i++] = rightVal;
                    right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
