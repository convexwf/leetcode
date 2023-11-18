/*
 * @lc app=leetcode id=488 lang=cpp
 *
 * [488] Zuma Game
 */

// @lc code=start
class Solution {
public:
    int findMinStep(string board, string hand) {
        if (board.empty()) {
            return 0;
        }
        if (hand.empty()) {
            return -1;
        }
        int res = INT_MAX;
        for (int i = 0; i <= board.size(); ++i) {
            for (int j = 0; j < hand.size(); ++j) {
                string new_board = board.substr(0, i) + hand[j] + board.substr(i);
                string new_hand = hand.substr(0, j) + hand.substr(j + 1);
                int next = findMinStep(removeConsecutive(new_board), new_hand);
                if (next != -1) {
                    res = min(res, next + 1);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }

private:
    string removeConsecutive(string board) {
        if (memo.count(board)) {
            return memo[board];
        }
        for (int i = 0, j = 0; j <= board.size(); ++j) {
            if (j < board.size() && board[i] == board[j]) {
                continue;
            }
            if (j - i >= 3) {
                return removeConsecutive(board.substr(0, i) + board.substr(j));
            }
            else {
                i = j;
            }
        }
        return memo[board] = board;
    }

    unordered_map<string, string> memo;
};
// @lc code=end

// @lc code=start
class Solution {
public:
    string del(string board) {
        for (int i = 0; i < board.size();) {
            int j = i;
            while (j < board.size() && board[i] == board[j]) j++;
            if (j - i >= 3)
                return del(board.substr(0, i) + board.substr(j));
            else
                i = j;
        }
        return board;
    }
    int dfs(string board, unordered_map<char, int>& hash) {
        board = del(board);
        if (board.size() == 0) return 0;
        int rs = 6, need = 0;
        for (int i = 0; i < board.size();) {
            int j = i;
            while (j < board.size() && board[i] == board[j]) j++;
            need = 3 - (j - i);
            if (hash[board[i]] >= need) {
                hash[board[i]] -= need;
                rs = min(rs, need + dfs(board.substr(0, i) + board.substr(j), hash));
                hash[board[i]] += need;
            }
            i = j;
        }
        return rs;
    }
    int findMinStep(string board, string hand) {
        unordered_map<char, int> hash;
        for (auto x : hand) hash[x]++;
        int res = dfs(board, hash);
        return res == 6 ? -1 : res;
    }
};
// @lc code=end
