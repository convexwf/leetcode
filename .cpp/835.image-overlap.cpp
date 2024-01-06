/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
// 1. Brute Force
// 2024-01-03 submission
// 59/59 cases passed
// Runtime: 151 ms, faster than 38.41% of cpp online submissions.
// Memory Usage: 9.8 MB, less than 78.15% of cpp online submissions.
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int res = 0;
        for (int i = -n + 1; i < n; ++i) {
            for (int j = -n + 1; j < n; ++j) {
                res = max(res, overlap(img1, img2, i, j));
            }
        }
        return res;
    }

private:
    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int x, int y) {
        int n = img1.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + x < 0 || i + x >= n || j + y < 0 || j + y >= n) {
                    continue;
                }
                res += img1[i][j] * img2[i + x][j + y];
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 枚举+哈希表
// 2024-01-03 submission
// 59/59 cases passed
// Runtime: 90 ms, faster than 50.33% of cpp online submissions.
// Memory Usage: 12.4 MB, less than 50.99% of cpp online submissions.
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int N = img1.size();
        vector<int> A, B;
        unordered_map<int, int> count;
        for (int i = 0; i < N * N; ++i) {
            if (img1[i / N][i % N] == 1) {
                A.push_back(i / N * 100 + i % N);
            }
            if (img2[i / N][i % N] == 1) {
                B.push_back(i / N * 100 + i % N);
            }
        }
        for (int i : A) {
            for (int j : B) {
                ++count[i - j];
            }
        }
        int res = 0;
        for (auto& [_, c] : count) {
            res = max(res, c);
        }
        return res;
    }
};
// @lc code=end
