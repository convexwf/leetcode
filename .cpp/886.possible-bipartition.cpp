/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n, vector<int>{});
        for(vector<int> dislike : dislikes) {
            graph[dislike[0] - 1].push_back(dislike[1] - 1);
            graph[dislike[1] - 1].push_back(dislike[0] - 1);
        }

        vector<int> root(n, 0);
        for (int i = 0; i < n; ++i) {
            root[i] = i;
        }
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].empty()) continue;
            int x = find(root, i), y = find(root, graph[i][0]);
            if (x == y) return false;
            for (int j = 1; j < graph[i].size(); ++j) {
                int parent = find(root, graph[i][j]);
                if (x == parent) return false;
                root[parent] = y;
            }
        }
        return true;
    }

    int find(vector<int>& root, int i) {
        return i == root[i] ? i : find(root, root[i]);
    }
};
// @lc code=end

