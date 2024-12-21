/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
// 1. 枚举直线
// 2024-12-17 submission
// 41/41 cases passed
// Runtime: 55 ms, faster than 35.98% of cpp online submissions.
// Memory Usage: 10.2 MB, less than 82.08% of cpp online submissions.
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                int cnt = 0;
                long long x1 = points[i][0], y1 = points[i][1];
                long long x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 && y1 == y2) {
                    ++duplicate;
                    continue;
                }
                for (int k = 0; k < points.size(); ++k) {
                    int x3 = points[k][0], y3 = points[k][1];
                    if (x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3 == 0) {
                        ++cnt;
                    }
                }
                res = max(res, cnt);
            }
            res = max(res, duplicate);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 斜率判断
// 2024-12-17 submission
// 41/41 cases passed
// Runtime: 27 ms, faster than 73.07% of cpp online submissions.
// Memory Usage: 20.9 MB, less than 38.39% of cpp online submissions.
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (res >= n - i || res > n / 2) {
                break;
            }
            unordered_map<string, int> m;
            for (int j = i + 1; j < n; ++j) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int gcd = gcdFunc(x, y);
                string key = to_string(x / gcd) + "_" + to_string(y / gcd);
                m[key]++;
            }
            for (auto& [_, cnt] : m) {
                res = max(res, cnt + 1);
            }
        }
        return res;
    }

    int gcdFunc(int a, int b) {
        return b == 0 ? a : gcdFunc(b, a % b);
    }
};
// @lc code=end
