/*
 * @lc app=leetcode id=902 lang=cpp
 *
 * [902] Numbers At Most N Given Digit Set
 */

// @lc code=start
// 1. 记忆化搜索
// 2025-06-07 submission
// 84/84 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than % of cpp online submissions.
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        unordered_set<int> nums;
        for (const string& digit : digits) {
            nums.insert(stoi(digit));
        }

        int m = s.size();
        vector<int> memo(m, -1);
        function<int(int, bool, bool)> dfs = [&](int i, bool isLimit, bool isLeading) -> int {
            if (i == m) {
                return isLeading ? 0 : 1; // 如果是前导零，返回 0，否则返回 1
            }
            if (!isLimit && !isLeading && memo[i] != -1) {
                return memo[i];
            }

            int up = isLimit ? s[i] - '0' : 9;
            int count = 0;

            for (int j = 0; j <= up; ++j) {
                if (j == 0 && isLeading) {
                    count += dfs(i + 1, isLimit && (j == up), true); // 前导零
                }
                else if (nums.count(j)) {
                    count += dfs(i + 1, isLimit && (j == up), false); // 非前导零
                }
            }

            if (!isLimit && !isLeading) {
                memo[i] = count;
            }

            return count;
        };
        return dfs(0, true, true);
    }
};
// @lc code=end
