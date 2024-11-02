/*
 * @lc app=leetcode id=339 lang=cpp
 *
 * [339] Nested List Weight Sum
 */

// @lc code=start
// 1. dfs
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }

    int dfs(vector<NestedInteger>& nestedList, int depth) {
        int res = 0;
        for (auto& nest : nestedList) {
            if (nest.isInteger()) {
                res += nest.getInteger() * depth;
            }
            else {
                res += dfs(nest.getList(), depth + 1);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start

// 2. bfs
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0, depth = 1;
        queue<NestedInteger> q;
        for (auto& nest : nestedList) {
            q.push(nest);
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                NestedInteger nest = q.front();
                q.pop();
                if (nest.isInteger()) {
                    res += nest.getInteger() * depth;
                }
                else {
                    for (auto& n : nest.getList()) {
                        q.push(n);
                    }
                }
            }
            ++depth;
        }
        return res;
    }
};
// @lc code=end
