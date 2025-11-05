/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

// @lc code=start
// 1. 哈希表
// 2023-10-25 submission
// 35/35 cases passed
// Runtime: 31 ms, faster than 47.42% of cpp online submissions.
// Memory Usage: 28.4 MB, less than 35.64% of cpp online submissions.
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<long> hash(60, 0);
        for (int t : time) {
            hash[t % 60]++;
        }
        int count = 0;
        for (int i = 1; i < 30; i++) {
            count += hash[i] * hash[60 - i];
        }
        count += hash[0] * (hash[0] - 1) / 2;
        count += hash[30] * (hash[30] - 1) / 2;
        return count;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表+一次遍历
// 2023-10-25 submission
// 35/35 cases passed
// Runtime: 25 ms, faster than 77.85% of cpp online submissions.
// Memory Usage: 28.4 MB, less than 50.92% of cpp online submissions.
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        vector<int> cnt(60);
        for (int t : time) {
            res += cnt[(600 - t) % 60];
            ++cnt[t % 60];
        }
        return res;
    }
};
// @lc code=end
