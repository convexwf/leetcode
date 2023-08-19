/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
// 1. DFS
// 2023-08-16 submission
// 277/277 cases passed
// Runtime: 8 ms, faster than 67.77% of cpp online submissions.
// Memory Usage: 13.9 MB, less than 65.42% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;
        dfs(image, sr, sc, m, n, oldColor, newColor);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int m, int n, int oldColor, int newColor) {
        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != oldColor) return;
        image[sr][sc] = newColor;
        dfs(image, sr - 1, sc, m, n, oldColor, newColor);
        dfs(image, sr + 1, sc, m, n, oldColor, newColor);
        dfs(image, sr, sc - 1, m, n, oldColor, newColor);
        dfs(image, sr, sc + 1, m, n, oldColor, newColor);
    }
};
// @lc code=end
