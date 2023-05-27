/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */

// @lc code=start
// 1. 排序 + 二分查找
// 2023-05-26 submission
// 30/30 cases passed
// Runtime: 74 ms, faster than 45.53% of cpp online submissions.
// Memory Usage: 25.3 MB, less than 82.28% of cpp online submissions.
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int house : houses) {
            // lower_bound 返回第一个大于等于 house 的迭代器
            auto pos = lower_bound(heaters.begin(), heaters.end(), house);
            int dist1 = (pos == heaters.end()) ? INT_MAX : *pos - house;
            int dist2 = (pos == heaters.begin()) ? INT_MAX : house - *(--pos);
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};
// @lc code=end
