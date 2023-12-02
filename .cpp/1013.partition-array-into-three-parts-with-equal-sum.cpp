/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
// 1. 两次遍历
// 2023-12-01 submission
// 72/72 cases passed
// Runtime: 38 ms, faster than 54.2% of cpp online submissions.
// Memory Usage: 33.1 MB, less than 11.36% of cpp online submissions.
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0) return false;
        int cnt = 0, prefix = 0;
        for (int i = 0; i < arr.size(); ++i) {
            prefix += arr[i];
            if (prefix == sum / 3) {
                ++cnt;
                prefix = 0;
            }
            if (cnt == 3) return true;
        }
        return false;
    }
};
// @lc code=end
