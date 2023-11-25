/*
 * @lc app=leetcode id=638 lang=cpp
 *
 * [638] Shopping Offers
 */

// @lc code=start
// 1. 递归+记忆化搜索
// 2023-11-20 submission
// 65/65 cases passed
// Runtime: 15 ms, faster than 80.19% of cpp online submissions.
// Memory Usage: 15.4 MB, less than 43.68% of cpp online submissions.
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }

private:
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        string key = encode(needs);
        if (memo.count(key)) return memo[key];
        int res = 0;
        for (int i = 0; i < needs.size(); ++i) {
            res += needs[i] * price[i];
        }
        for (int i = 0; i < special.size(); ++i) {
            vector<int> clone = needs;
            bool isValid = true;
            for (int j = 0; j < needs.size(); ++j) {
                if (needs[j] < special[i][j]) {
                    isValid = false;
                    break;
                }
                clone[j] -= special[i][j];
            }
            if (isValid) {
                res = min(res, special[i][needs.size()] + dfs(price, special, clone));
            }
        }
        return memo[key] = res;
    }

    string encode(vector<int>& needs) {
        string res = "";
        for (int i = 0; i < needs.size(); ++i) {
            res += to_string(needs[i]) + ",";
        }
        return res;
    }

    unordered_map<string, int> memo;
};
// @lc code=end
