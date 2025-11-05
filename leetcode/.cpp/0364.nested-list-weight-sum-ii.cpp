/*
 * @lc app=leetcode id=364 lang=cpp
 *
 * [364] Nested List Weight Sum II
 */

// @lc code=start
// 1. dfs
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int total = 0, weightedTotal = 0, maxDepth = 0;
        for (auto& nested : nestedList) {
            dfs(nested, 1, total, weightedTotal, maxDepth);
        }
        return (maxDepth + 1) * total - weightedTotal;
    }

    void dfs(NestedInteger& nested, int depth, int& total, int& weightedTotal, int& maxDepth) {
        if (nested.isInteger()) {
            total += nested.getInteger();
            weightedTotal += depth * nested.getInteger();
            maxDepth = max(maxDepth, depth);
        }
        else {
            for (auto& nest : nested.getList()) {
                dfs(nest, depth + 1, total, weightedTotal, maxDepth);
            }
        }
    }
};
// @lc code=end
