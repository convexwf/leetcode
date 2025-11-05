/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
// 1. 贪心算法+最大堆
// 2024-01-02 submission
// 97/97 cases passed
// Runtime: 299 ms, faster than 20.82% of cpp online submissions.
// Memory Usage: 56.4 MB, less than 85.77% of cpp online submissions.
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        priority_queue<int> pq;
        int cur_time = 0;
        for (auto& course : courses) {
            cur_time += course[0];
            pq.push(course[0]);
            if (cur_time > course[1]) {
                cur_time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
// @lc code=end
