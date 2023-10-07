/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
// 2021-12-17 submission
// 92/92 cases passed
// Runtime: 61 ms, faster than 16.89% of C++ online submissions.
// Memory Usage: 27.8 MB, less than 35.13% of C++ online submissions.
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int val1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int val2 = nums[n - 1] * nums[0] * nums[1];
        return max(val1, val2);
    }
};
// @lc code=end

// @lc code=start
// 2021-12-17 submission
// 92/92 cases passed
// Runtime: 44 ms, faster than 62.61% of C++ online submissions.
// Memory Usage: 27.8 MB, less than 35.13% of C++ online submissions.
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int A = INT_MIN, B = INT_MIN, C = INT_MIN;
        int a = INT_MAX, b = INT_MAX;
        for (int num : nums) {
            // max three numbers
            if (num > A) {
                C = B;
                B = A;
                A = num;
            }
            else if (A > num && num > B) {
                C = B;
                B = num;
            }
            else if (B > num && num > C) {
                C = num;
            }
            // min two numbers
            if (num < a) {
                b = a;
                a = num
            }
            else if (a < num && num < b) {
                b = num;
            }
        }
        return max(A * B * C, a * b * A);
    }
};
// @lc code=end
