/*
 * @lc app=leetcode id=484 lang=cpp
 *
 * [484] Find Permutation
 */

// @lc code=start
// 1. 贪心算法
class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size();
        vector<int> res(n + 1);
        for (int i = 0; i <= n; i++) {
            res[i] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') {
                int j = i;
                while (i < n && s[i] == 'D') {
                    i++;
                }
                reverse(res.begin() + j, res.begin() + i + 1);
            }
        }
        return res;
    }
};
// @lc code=end
