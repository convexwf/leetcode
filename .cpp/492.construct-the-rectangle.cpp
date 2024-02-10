/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
// 2022-11-17 submission
// 52/52 cases passed
// Runtime: 0 ms, faster than 100% of C++ online submissions.
// Memory Usage: 6 MB, less than 90.96% of C++ online submissions.
class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int W = (int)sqrt(area); W > 1; W--) {
            if (area % W == 0) {
                return {area / W, W};
            }
        }
        return {area, 1};
    }
};
// @lc code=end