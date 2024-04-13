/*
 * @lc app=leetcode id=497 lang=cpp
 *
 * [497] Random Point in Non-overlapping Rectangles
 */

// @lc code=start
// 1. 面积计算
// 2023-05-24 submission
// 35/35 cases passed
// Runtime: 97 ms, faster than 54.2% of cpp online submissions.
// Memory Usage:  MB, less than 76.34% of cpp online submissions.
class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int area = 0;
        for (auto& rect : rects) {
            area += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            areas.push_back(area);
        }
    }

    vector<int> pick() {
        int area = rand() % areas.back();
        int idx = upper_bound(areas.begin(), areas.end(), area) - areas.begin();
        auto& rect = rects[idx];
        int x = rand() % (rect[2] - rect[0] + 1) + rect[0];
        int y = rand() % (rect[3] - rect[1] + 1) + rect[1];
        return {x, y};
    }

private:
    vector<vector<int>> rects;
    vector<int> areas;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end
