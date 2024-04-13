/*
 * @lc app=leetcode id=825 lang=cpp
 *
 * [825] Friends Of Appropriate Ages
 */

// @lc code=start
// 1. 桶数组
// 2023-09-06 submission
// 89/89 cases passed
// Runtime: 37 ms, faster than 82.8% of cpp online submissions.
// Memory Usage: 37.5 MB, less than 23.39% of cpp online submissions.
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        vector<int> numInAge(121), sumInAge(121);
        for (int age : ages) ++numInAge[age];
        for (int i = 1; i <= 120; ++i) {
            sumInAge[i] = numInAge[i] + sumInAge[i - 1];
        }
        for (int i = 15; i <= 120; ++i) {
            if (numInAge[i] == 0) continue;
            int cnt = sumInAge[i] - sumInAge[i * 0.5 + 7];
            res += (cnt - 1) * numInAge[i];
        }
        return res;
    }
};
// @lc code=end
