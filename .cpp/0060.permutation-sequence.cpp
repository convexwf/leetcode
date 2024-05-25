/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
// 1. 枚举+数学方法
// 2022-07-20 submission
// 200/200 cases passed
// Runtime: 3 ms, faster than 59.97% of cpp online submissions.
// Memory Usage: 6 MB, less than 80.63% of cpp online submissions.
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> frac(n, 1);
        string nums = "123456789";
        string ret = "";
        for (int i = 1; i < n; i++) {
            frac[i] = frac[i - 1] * i;
        }
        --k;
        for (int i = n - 1; i >= 0; i--) {
            ret += nums[k / frac[i]];
            nums.erase(k / frac[i], 1);
            k %= frac[i];
        }
        return ret;
    }
};
// @lc code=end
