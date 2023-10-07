/*
 * @lc app=leetcode id=488 lang=cpp
 *
 * [488] Zuma Game
 */

// @lc code=start
class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<int, int> m;
        for (char c : hand) ++m[c];
        return helper(board, m, 0);
    }

    int helper(string board, unordered_map<int, int>& m, int level) {
        if (board.length() == 0) return 0;

        int res = INT_MAX;
        for (int i = 0; i < board.length();) {
            int right = i + 1;
            while (right < board.length() && board[i] == board[right]) {
                ++right;
            }
            if (right - i >= 2 && m[board[i]] > 0)
        }
    }

    string convert(string s, int i) {
        int l = i - 1, r = i, cnt = 1;
        while (0 <= l && r < s.length()) {
            while (l)

        }
    }
};
// @lc code=end

