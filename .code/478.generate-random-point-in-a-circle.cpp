/*
 * @lc app=leetcode id=478 lang=cpp
 *
 * [478] Generate Random Point in a Circle
 *
 * https://leetcode.com/problems/generate-random-point-in-a-circle/description/
 *
 * algorithms
 * Medium (39.53%)
 * Likes:    379
 * Dislikes: 695
 * Total Accepted:    34.7K
 * Total Submissions: 87.8K
 * Testcase Example:  '["Solution","randPoint","randPoint","randPoint"]\n[[1.0,0.0,0.0],[],[],[]]'
 *
 * Given the radius and the position of the center of a circle, implement the
 * function randPoint which generates a uniform random point inside the
 * circle.
 *
 * Implement the Solution class:
 *
 *
 * Solution(double radius, double x_center, double y_center) initializes the
 * object with the radius of the circle radius and the position of the center
 * (x_center, y_center).
 * randPoint() returns a random point inside the circle. A point on the
 * circumference of the circle is considered to be in the circle. The answer is
 * returned as an array [x, y].
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Solution", "randPoint", "randPoint", "randPoint"]
 * [[1.0, 0.0, 0.0], [], [], []]
 * Output
 * [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
 *
 * Explanation
 * Solution solution = new Solution(1.0, 0.0, 0.0);
 * solution.randPoint(); // return [-0.02493, -0.38077]
 * solution.randPoint(); // return [0.82314, 0.38945]
 * solution.randPoint(); // return [0.36572, 0.17248]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 < radius <= 10^8
 * -10^7 <= x_center, y_center <= 10^7
 * At most 3 * 10^4 calls will be made to randPoint.
 *
 *
 */

// @lc code=start
// 2022-08-19 submission
// 8/8 cases passed
// Runtime: 145 ms, faster than 45.21% of C++ online submissions.
// Memory Usage: 26.8 MB, less than 97.34% of C++ online submissions.
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius; centerX = x_center; centerY = y_center;
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
// Runtime: 106 ms, faster than 81.38% of C++ online submissions.
// Memory Usage: 27.3 MB, less than 48.4% of C++ online submissions.
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius; centerX = x_center; centerY = y_center;
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
