/*
 * @lc app=leetcode id=488 lang=cpp
 *
 * [488] Zuma Game
 */

// @lc code=start
// 1. 递归+哈希表+记忆化搜索
// 2025-05-13 submission
// 57/57 cases passed
// Runtime: 924 ms, faster than 33.85% of cpp online submissions.
// Memory Usage: 231.7 MB, less than 7.69% of cpp online submissions.
class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<string, int> memo;
        for (const char& c : hand) {
            ballCount[c]++;
        }
        return minMoves(board, hand, memo);
    }

private:
    int minMoves(string board, string hand, unordered_map<string, int>& memo) {
        if (board.empty()) {
            return 0;
        }
        if (hand.empty()) {
            return -1;
        }

        string state = board + "#" + hand;
        if (memo.count(state)) {
            return memo[state];
        }

        int minSteps = INT_MAX;
        int boardSize = board.size();
        int handSize = hand.size();

        for (int i = 0; i < handSize; ++i) {
            char ball = hand[i];
            string newHand = hand.substr(0, i) + hand.substr(i + 1);

            for (int j = 0; j <= boardSize; ++j) {
                if (shouldSkipInsertion(board, j, ball)) continue;

                string newBoard = insertAndReduce(board, j, ball);
                int nextMove = minMoves(newBoard, newHand, memo);

                if (nextMove != -1) {
                    minSteps = min(minSteps, 1 + nextMove);
                }
            }
        }

        memo[state] = minSteps;
        return minSteps;
    }

    bool shouldSkipInsertion(const string& board, int pos, char ball) {
        if (pos > 0 && board[pos - 1] == ball) {
            return true;
        }
        if (ballCount[ball] == 1 || ballCount[ball] == 2) {
            if (pos == 0) {
                return board[pos] != ball;
            }
            if (pos == board.size()) {
                return board[pos - 1] != ball;
            }
            return board[pos - 1] != ball && board[pos] != ball && board[pos - 1] != board[pos];
        }
        return false;
    }

    string insertAndReduce(string board, int pos, char ball) {
        board.insert(pos, 1, ball);
        return reduceBoard(board);
    }

    string reduceBoard(string board) {
        bool changed;
        do {
            changed = false;
            for (int i = 0, j; i < board.size(); i = j) {
                j = i;
                while (j < board.size() && board[j] == board[i]) ++j;
                if (j - i >= 3) {
                    board.erase(i, j - i);
                    changed = true;
                    break;
                }
            }
        } while (changed);
        return board;
    }

    unordered_map<int, int> ballCount;
};
// @lc code=end
