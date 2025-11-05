/*
 * @lc app=leetcode id=1064 lang=cpp
 *
 * [1064] Fixed Point
 */

// @lc code=start
// 1. 模拟
class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == i) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

// @lc code=start
// 2. 二分查找
class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < mid) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return arr[left] == left ? left : -1;
    }
};
