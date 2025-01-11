/*
 * @lc app=leetcode id=956 lang=cpp
 *
 * [956] Tallest Billboard
 */

// @lc code=start
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        unordered_map<int, int> memo;
        return dfs(0, 0, 0, rods, memo);
    }

    int dfs(int i, int s1, int s2, vector<int>& rods, unordered_map<int, int>& memo) {
        if (i == rods.size()) {
            return s1 == s2 ? s1 : 0;
        }
        int key = i * 1000 + s1;
        if (memo.count(key)) {
            return memo[key];
        }
        int res = max({dfs(i + 1, s1 + rods[i], s2, rods, memo),
                       dfs(i + 1, s1, s2 + rods[i], rods, memo), dfs(i + 1, s1, s2, rods, memo)});
        memo[key] = res;
        return res;
    }
};
// @lc code=end
