/*
 * @lc app=leetcode id=302 lang=cpp
 *
 * [302] Smallest Rectangle Enclosing Black Pixels
 */

// @lc code=start
// 1. 二分查找
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int left = binarySearch(image, true, 0, y, 0, m, true);
        int right = binarySearch(image, true, y + 1, n, 0, m, false);
        int top = binarySearch(image, false, 0, x, left, right, true);
        int bottom = binarySearch(image, false, x + 1, m, left, right, false);
        return (right - left) * (bottom - top);
    }

    int binarySearch(vector<vector<char>>& image, bool horizontal, int low, int high, int min,
                     int max, bool goLower) {
        while (low < high) {
            int mid = low + (high - low) / 2;
            bool hasBlackPixel = false;
            for (int i = min; i < max; i++) {
                if ((horizontal ? image[i][mid] : image[mid][i]) == '1') {
                    hasBlackPixel = true;
                    break;
                }
            }
            if (hasBlackPixel == goLower) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
// @lc code=end
