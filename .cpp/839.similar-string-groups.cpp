/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 */

// @lc code=start
// 1. 并查集
// 2024-01-15 submission
// 77/77 cases passed
// Runtime: 17 ms, faster than 94.71% of cpp online submissions.
// Memory Usage: 10.2 MB, less than 97.49% of cpp online submissions.
class Solution {
public:
    int find(vector<int>& parent, int index) {
        if (parent[index] == index) {
            return index;
        }
        return parent[index] = find(parent, parent[index]);
    }

    void _union(vector<int>& parent, int index1, int index2) {
        int root1 = find(parent, index1);
        int root2 = find(parent, index2);
        if (root1 != root2) {
            parent[root2] = root1;
        }
    }

    bool isSimilar(string& a, string& b) {
        int n = a.size();
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                num++;
                if (num > 2) {
                    return false;
                }
            }
        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    _union(parent, i, j);
                }
            }
        }
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                num++;
            }
        }
        return num;
    }
};
// @lc code=end
