/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
// 1. 一次遍历
// 2024-08-02 submission
// 53/53 cases passed
// Runtime: 19 ms, faster than 61.15% of cpp online submissions.
// Memory Usage: 25.1 MB, less than 17.31% of cpp online submissions.
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) {
            return false;
        }
        int i = 0;
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }
        if (i == 0 || i == n - 1) {
            return false;
        }
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }
        return i == n - 1;
    }
};
// @lc code=end
