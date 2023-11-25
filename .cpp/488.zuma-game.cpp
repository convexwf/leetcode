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
    int findMinStep(string board, string hand) {
        string hand_count = "000000";
        for (char c : hand) {
            hand_count[color_map[c]]++;
        }
        for (char &c : board) {
            c = color_map[c] + '0';
        }
        // cout << board << " " << hand_count << endl;

        unordered_set<string> visited;
        queue<pair<string, string>> q;
        visited.insert(board + "#" + hand_count);
        q.push({board, hand_count});

        int step = 0;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                string board = q.front().first;
                string hand_count = q.front().second;
                q.pop();
                for (int i = 1; i <= 5; ++i) {
                    if (hand_count[i] == '0') {
                        continue;
                    }
                    for (int j = 0; j <= board.size(); ++j) {
                        string new_board =
                            board.substr(0, j) + string(1, i + '0') + board.substr(j);
                        new_board = removeConsecutive(new_board);
                        if (new_board.empty()) {
                            return step + 1;
                        }
                        string new_hand_count = hand_count;
                        new_hand_count[i]--;
                        if (visited.count(new_board + "#" + new_hand_count)) {
                            continue;
                        }
                        visited.insert(new_board + "#" + new_hand_count);
                        q.push({new_board, new_hand_count});
                    }
                }
            }
            ++step;
        }
        return -1;
    }

private:
    string removeConsecutive(string board) {
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
        return board;
    }
    unordered_map<char, int> color_map = {{'R', 1}, {'Y', 2}, {'B', 3}, {'G', 4}, {'W', 5}};
};
// @lc code=end
