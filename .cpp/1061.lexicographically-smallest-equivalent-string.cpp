/*
 * @lc app=leetcode id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

// @lc code=start
// 1. 并查集
// 2023-10-25 submission
// 116/116 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.1 MB, less than 31.36% of cpp online submissions.
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < s1.size(); ++i) {
            int p1 = find(parent, s1[i] - 'a');
            int p2 = find(parent, s2[i] - 'a');
            if (p1 < p2) {
                parent[p2] = p1;
            }
            else {
                parent[p1] = p2;
            }
        }
        for (int i = 0; i < baseStr.size(); ++i) {
            baseStr[i] = find(parent, baseStr[i] - 'a') + 'a';
        }
        return baseStr;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};
// @lc code=end
