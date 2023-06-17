/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 */

// @lc code=start
// 1. 排序
// 2023-06-13 submission
// 113/113 cases passed
// Runtime: 11 ms, faster than 89.44% of cpp online submissions.
// Memory Usage: 13.7 MB, less than 23.23% of cpp online submissions.
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for (auto& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            times.push_back(hour * 60 + minute);
        }
        sort(times.begin(), times.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < times.size(); ++i) {
            minDiff = min(minDiff, times[i] - times[i - 1]);
        }
        minDiff = min(minDiff, times[0] + 24 * 60 - times.back());
        return minDiff;
    }
};
// @lc code=end

// @lc code=start
// 2. 位图
// 2023-06-13 submission
// 113/113 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 14.2 MB, less than 5.96% of cpp online submissions.
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> buckets(1440, 0);
        for (auto& time : timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            int total = hour * 60 + minute;
            if (buckets[total] == 1) return 0;
            buckets[total] = 1;
        }
        int prev = 0, minDiff = INT_MAX;
        int first = INT_MAX, last = INT_MIN;
        for (int i = 0; i < 1440; ++i) {
            if (buckets[i] == 1) {
                if (first != INT_MAX) {
                    minDiff = min(minDiff, i - prev);
                }
                first = min(first, i);
                last = max(last, i);
                prev = i;
            }
        }
        minDiff = min(minDiff, 1440 - last + first);
        return minDiff;
    }
};
// @lc code=end
