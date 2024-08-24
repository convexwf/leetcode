/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
// 1. 动态规划
// 2023-05-20 submission
// 49/49 cases passed
// Runtime: 57 ms, faster than 55.57% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 93.84% of cpp online submissions.
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // 先将数组升序排列
        vector<int> dp(n, 1);
        int maxlen = 1, maxidx = 0; // 记录最长整除子集的长度和对应的最大整数下标
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) { // 找到所有比nums[i]小的能够整除它的数
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > maxlen) { // 更新最长整除子集长度和对应最大整数下标
                maxlen = dp[i];
                maxidx = i;
            }
        }
        vector<int> res;
        int curmax = nums[maxidx], curdp = maxlen; // 从最大整数倒推找到最长整除子集
        for (int i = maxidx; i >= 0; --i) {
            if (curmax % nums[i] == 0 && dp[i] == curdp) {
                res.push_back(nums[i]);
                curmax = nums[i];
                curdp--;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划+记录前驱值
// 2023-05-20 submission
// 49/49 cases passed
// Runtime: 52 ms, faster than 72.22% of cpp online submissions.
// Memory Usage: 8.7 MB, less than 93.84% of cpp online submissions.
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // 先将数组升序排列
        vector<pair<int, int>> dp(n, make_pair(1, -1));
        int maxlen = 1, maxidx = 0; // 记录最长整除子集的长度和对应的最大整数下标
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) { // 找到所有比nums[i]小的能够整除它的数
                if (nums[i] % nums[j] == 0 && dp[i].first < dp[j].first + 1) {
                    dp[i] = make_pair(dp[j].first + 1, j);
                }
            }
            if (dp[i].first > maxlen) { // 更新最长整除子集长度和对应最大整数下标
                maxlen = dp[i].first;
                maxidx = i;
            }
        }
        vector<int> res(maxlen);
        int idx = maxidx, k = maxlen - 1; // 从最大整数倒推找到最长整除子集
        while (idx != -1) {
            res[k--] = nums[idx];
            idx = dp[idx].second;
        }
        return res;
    }
};
// @lc code=end
