/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
// 2022-11-14 submission
// 15/15 cases passed
// Runtime: 7 ms, faster than 79.87% of C++ online submissions.
// Memory Usage: 8 MB, less than 48.64% of C++ online submissions.
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i & (i-1)] + 1;
        }
        return dp;
    }
};
// @lc code=end

// @lc code=start
// 2022-11-14 submission
// 15/15 cases passed
// Runtime: 4 ms, faster than 92.76% of C++ online submissions.
// Memory Usage: 7.8 MB, less than 88.2% of C++ online submissions.
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        for(int i = 1; i < num + 1; ++i){
            result[i] = bitset<32>(i).count();
        }
        return result;
    }
};
// @lc code=end