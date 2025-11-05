/*
 * @lc app=leetcode id=774 lang=cpp
 *
 * [774] Minimize Max Distance to Gas Station
 */

// @lc code=start
// 1. 二分查找
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = (left + right) / 2;
            int count = 0;
            for (int i = 1; i < stations.size(); ++i) {
                count += (int)((stations[i] - stations[i - 1]) / mid);
            }
            if (count <= k) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return right;
    }
};
// @lc code=end
