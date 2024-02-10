/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
// 2021-03-18 submission
// 83/83 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6.3 MB, less than 35.63% of C++ online submissions.
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;

        while (p1 < version1.length() || p2 < version2.length()) {

            int x1 = 0, x2 = 0;
            while (p1 < version1.length() && version1[p1] != '.') {
                x1 = x1 * 10 + (version1[p1] - '0');
                ++p1;
            }

            while (p2 < version2.length() && version2[p2] != '.') {
                x2 = x2 * 10 + (version2[p2] - '0');
                ++p2;
            }

            if (x1 < x2) return -1;
            else if (x1 > x2) return 1;
            ++p1; ++p2;
        }
        return 0;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-15 submission
// 83/83 cases passed
// Runtime: 4 ms, faster than 25.42% of C++ online submissions.
// Memory Usage: 6.3 MB, less than 35.63% of C++ online submissions.
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream v1(version1 + "."), v2(version2 + ".");
        int d1 = 0, d2 = 0;
        char dot = '.';
        while (v1.good() || v2.good()) {
            if (v1.good()) v1 >> d1 >> dot;
            if (v2.good()) v2 >> d2 >> dot;
            if (d1 > d2) return 1;
            else if (d1 < d2) return -1;
            d1 = d2 = 0;
        }
        return 0;
    }
};
// @lc code=end