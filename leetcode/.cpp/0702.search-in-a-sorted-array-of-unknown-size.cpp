/*
 * @lc app=leetcode id=702 lang=cpp
 *
 * [702] Search in a Sorted Array of Unknown Size
 */

// @lc code=start
// 1. 二分查找
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int right = 1;
        while (reader.get(right) < target) {
            right <<= 1;
        }
        int left = right >> 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int num = reader.get(mid);
            if (num == target) {
                return mid;
            }
            else if (num < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
