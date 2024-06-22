/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
// 1. 排序+合并区间
// 2020-07-14 submission
// 156/156 cases passed
// Runtime: 7 ms, faster than 99.44% of cpp online submissions.
// Memory Usage: 17.1 MB, less than 78.6% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (newInterval.empty()) return intervals;
        vector<vector<int>> res;

        int cur = 0;
        int cnt = intervals.size();
        while (cur < cnt) {
            if (intervals[cur][1] < newInterval[0])
                res.push_back(intervals[cur++]);
            else
                break;
        }

        vector<int> temp_interval(newInterval.begin(), newInterval.end());
        for (; cur < cnt; cur++) {
            if (judge(temp_interval, intervals[cur])) {
                temp_interval[0] = min(temp_interval[0], intervals[cur][0]);
                temp_interval[1] = max(temp_interval[1], intervals[cur][1]);
            }
            else
                break;
            // cout << "interval " << temp_interval[0] << " " << temp_interval[1] << endl;
        }
        res.push_back(temp_interval);

        while (cur < cnt) {
            res.push_back(intervals[cur++]);
        }
        return res;
    }

    bool judge(vector<int>& A, vector<int>& B) {
        return (A[1] >= B[0] && A[0] <= B[1]) || (B[1] >= A[0] && B[0] <= A[1]);
    }
};
// @lc code=end

// @lc code=start
// 2. 一次遍历
// 2023-02-02 submission
// 156/156 cases passed
// Runtime: 12 ms, faster than 88.99% of cpp online submissions.
// Memory Usage: 17.1 MB, less than 78.6% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int new_start = newInterval[0], new_end = newInterval[1];
        bool placed = false;
        for (const vector<int>& interval : intervals) {
            int start = interval[0], end = interval[1];
            if (end < new_start) {
                res.push_back(interval);
            }
            else if (start > new_end) {
                if (!placed) {
                    res.push_back({new_start, new_end});
                    placed = true;
                }
                res.push_back(interval);
            }
            else {
                new_start = min(new_start, start);
                new_end = max(new_end, end);
            }
        }
        if (!placed) {
            res.push_back({new_start, new_end});
        }
        return res;
    }
};
// @lc code=end
