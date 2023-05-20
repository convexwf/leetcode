/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start
// 1. 排序+二分查找
// 2023-05-19 submission
// 19/19 cases passed
// Runtime: 64 ms, faster than 94.95% of cpp online submissions.
// Memory Usage:  MB, less than 91.01% of cpp online submissions.
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n, -1); // 初始化结果数组为-1

        vector<pair<int, int>> sorted_intervals; // 存储排序后的区间和对应原始索引
        for (int i = 0; i < n; i++) {
            sorted_intervals.push_back({intervals[i][0], i});
        }
        sort(sorted_intervals.begin(), sorted_intervals.end()); // 按起点排序

        for (int i = 0; i < n; i++) {
            int target = intervals[i][1]; // 当前区间的终点作为二分查找的目标值
            int left = 0, right = n;
            while (left < right) { // 二分查找第一个起点大于等于当前区间终点的区间
                int mid = left + (right - left) / 2;
                if (sorted_intervals[mid].first < target) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }
            res[i] = right < n ? sorted_intervals[right].second : -1; // 找到则更新结果数组
        }

        return res;
    }
};
// @lc code=end
