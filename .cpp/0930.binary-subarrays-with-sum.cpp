/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
// 1. 累计和数组+哈希表
// 2023-09-22 submission
// 60/60 cases passed
// Runtime: 28 ms, faster than 63.4% of cpp online submissions.
// Memory Usage:  MB, less than 8.21% of cpp online submissions.
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += m[sum - goal];
            ++m[sum];
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 滑动窗口
// 2023-09-22 submission
// 60/60 cases passed
// Runtime: 1322 ms, faster than 5.07% of cpp online submissions.
// Memory Usage: 29.2 MB, less than 56.69% of cpp online submissions.
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int res = 0, sum = 0, left = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            while (left < i && sum > S) sum -= A[left++];
            if (sum < S) continue;
            if (sum == S) ++res;
            for (int j = left; j < i && A[j] == 0; ++j) {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
