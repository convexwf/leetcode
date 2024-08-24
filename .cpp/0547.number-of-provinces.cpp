/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
// 1. 并查集
// 2023-02-13 submission
// 113/113 cases passed
// Runtime: 21 ms, faster than 89.62% of cpp online submissions.
// Memory Usage: 13.8 MB, less than 61.28% of cpp online submissions.
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = n;
        vector<int> root(n);
        for (int i = 0; i < n; ++i) {
            root[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] == 1) {
                    int p1 = _find(root, i);
                    int p2 = _find(root, j);
                    if (p1 != p2) {
                        --res;
                        root[p2] = p1;
                    }
                }
            }
        }
        return res;
    }

    int _find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = _find(parent, parent[x]);
        }
        return parent[x];
    }
};
// @lc code=end
