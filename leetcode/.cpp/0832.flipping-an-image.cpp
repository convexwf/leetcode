/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
// 1. 双指针+位操作
// 2024-11-08 submission
// 82/82 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 11.6 MB, less than 7.99% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int k = 0; k < n; ++k) {
            int i = 0, j = n - 1;
            while (i < j) {
                if (image[k][i] == image[k][j]) {
                    image[k][i] ^= 1;
                    image[k][j] ^= 1;
                }
                ++i;
                --j;
            }
            if (i == j) {
                image[k][i] ^= 1;
            }
        }
        return image;
    }
};
// @lc code=end
