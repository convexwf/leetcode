/*
 * @lc app=leetcode id=765 lang=cpp
 *
 * [765] Couples Holding Hands
 */

// @lc code=start
// 1. 贪婪算法
// 2024-01-17 submission
// 56/56 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.8 MB, less than 50.36% of cpp online submissions.
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int ans = 0;
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }
        for (int i = 0; i < n; i += 2) {
            int x = row[i];
            int y = x ^ 1;
            if (row[i + 1] != y) {
                int j = pos[y];
                swap(row[i + 1], row[j]);
                pos[row[j]] = j;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

// @lc code=start
// 2. 并查集
// 2024-01-17 submission
// 56/56 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 50.36% of cpp online submissions.
class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent, parent[x]);
    }

    void _union(vector<int>& parent, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int len = n / 2;
        vector<int> parent(len);
        for (int i = 0; i < len; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i += 2) {
            _union(parent, row[i] / 2, row[i + 1] / 2);
        }
        int ans = len;
        for (int i = 0; i < len; ++i) {
            cout << i << " " << parent[i] << endl;
            if (parent[i] == i) {
                --ans;
            }
        }
        return ans;
    }
};
// @lc code=end
