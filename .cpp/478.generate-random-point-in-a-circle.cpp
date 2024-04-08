/*
 * @lc app=leetcode id=478 lang=cpp
 *
 * [478] Generate Random Point in a Circle
 */

// @lc code=start
// 2022-08-19 submission
// 8/8 cases passed
// Runtime: 145 ms, faster than 45.21% of cpp online submissions.
// Memory Usage: 26.8 MB, less than 97.34% of cpp online submissions.
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        centerX = x_center;
        centerY = y_center;
    }

    vector<double> randPoint() {
        while (true) {
            // number = (maxVal - minVal) * rand() / (RAND_MAX) + minVal
            // 生成 [-r, r] 范围内的小数
            double x = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            double y = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            if (x * x + y * y <= r * r) return {centerX + x, centerY + y};
        }
    }

private:
    double r, centerX, centerY;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end

// @lc code=start
// 2022-08-19 submission
// 8/8 cases passed
// Runtime: 106 ms, faster than 81.38% of cpp online submissions.
// Memory Usage: 27.3 MB, less than 48.4% of cpp online submissions.
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        centerX = x_center;
        centerY = y_center;
    }

    vector<double> randPoint() {
        double theta = 2 * M_PI * ((double)rand() / RAND_MAX);
        double len = sqrt((double)rand() / RAND_MAX) * r;
        return {centerX + len * cos(theta), centerY + len * sin(theta)};
    }

private:
    double r, centerX, centerY;
};
// @lc code=end
