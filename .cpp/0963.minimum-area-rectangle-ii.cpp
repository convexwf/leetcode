/*
 * @lc app=leetcode id=963 lang=cpp
 *
 * [963] Minimum Area Rectangle II
 */

// @lc code=start
// 1. 计算几何-对角线长度相等
// 2024-01-17 submission
// 109/109 cases passed
// Runtime: 99 ms, faster than 43.02% of cpp online submissions.
// Memory Usage: 29.9 MB, less than 24.42% of cpp online submissions.
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<string, vector<vector<int>>> m;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int x = x1 + x2, y = y1 + y2;
                double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
                string key = to_string(d) + "," + to_string(x) + "," + to_string(y);
                m[key].push_back({x1, y1, x2, y2});
            }
        }
        double res = INT_MAX;
        for (auto& [k, v] : m) {
            if (v.size() < 2) continue;
            for (int i = 0; i < v.size(); ++i) {
                for (int j = i + 1; j < v.size(); ++j) {
                    res = min(res, area(v[i], v[j]));
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }

    double area(vector<int>& p1, vector<int>& p2) {
        int x1 = p1[0], y1 = p1[1], x2 = p1[2], y2 = p1[3];
        int x3 = p2[0], y3 = p2[1], x4 = p2[2], y4 = p2[3];
        double d1 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
        double d2 = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
        return d1 * d2;
    }
};
// @lc code=end

// @lc code=start
// 2. 计算几何-邻边垂直
// 2024-01-17 submission
// 109/109 cases passed
// Runtime: 66 ms, faster than 47.67% of cpp online submissions.
// Memory Usage: 9.5 MB, less than 72.09% of cpp online submissions.
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        auto f = [](int x, int y) { return x * 40001 + y; };
        int n = points.size();
        unordered_set<int> s;
        for (auto& p : points) {
            s.insert(f(p[0], p[1]));
        }
        double ans = 1e20;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    int x2 = points[j][0], y2 = points[j][1];
                    for (int k = j + 1; k < n; ++k) {
                        if (k != i) {
                            int x3 = points[k][0], y3 = points[k][1];
                            int x4 = x2 - x1 + x3, y4 = y2 - y1 + y3;
                            if (x4 >= 0 && x4 < 40000 && y4 >= 0 && y4 <= 40000 &&
                                s.count(f(x4, y4))) {
                                if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) == 0) {
                                    int ww = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                                    int hh = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
                                    ans = min(ans, sqrt(1LL * ww * hh));
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans == 1e20 ? 0 : ans;
    }
};
// @lc code=end
