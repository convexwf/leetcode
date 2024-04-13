/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
// 1. 排序
// 2023-10-31 submission
// 36/36 cases passed
// Runtime: 113 ms, faster than 60.04% of cpp online submissions.
// Memory Usage: 12.3 MB, less than 74.31% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> res;
        for (auto& p : people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 排序+空间优化
// 2023-10-31 submission
// 36/36 cases passed
// Runtime: 93 ms, faster than 64.05% of cpp online submissions.
// Memory Usage: 12.4 MB, less than 66.28% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        for (int i = 1; i < people.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < i; ++j) {
                if (cnt == people[i][1]) {
                    auto t = people[i];
                    for (int k = i - 1; k >= j; --k) {
                        people[k + 1] = people[k];
                    }
                    people[j] = t;
                    break;
                }
                ++cnt;
            }
        }
        return people;
    }
};
// @lc code=end
