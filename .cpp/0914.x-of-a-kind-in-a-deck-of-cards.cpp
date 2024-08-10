/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 */

// @lc code=start
// 1. 数学方法
// 2023-09-08 submission
// 75/75 cases passed
// Runtime: 16 ms, faster than 38.2% of cpp online submissions.
// Memory Usage: 17.4 MB, less than 86.3% of cpp online submissions.
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> cardCnt;
        for (int card : deck) ++cardCnt[card];
        int res = 0;
        for (auto& a : cardCnt) {
            res = gcd(a.second, res);
        }
        return res > 1;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
// @lc code=end
