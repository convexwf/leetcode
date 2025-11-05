/*
 * @lc app=leetcode id=656 lang=cpp
 *
 * [656] Coin Path
 */

// @lc code=start
// 1. 动态规划
class Node {
public:
    int cost;
    vector<int> path;
    Node(int c, vector<int> p) : cost(c), path(p) {
    }

    void insertPos(int pos) {
        path.insert(path.begin(), pos);
    }

    bool operator<(const Node& other) const {
        if (cost != other.cost) {
            return cost < other.cost;
        }
        int n = path.size();
        int m = other.path.size();
        for (int i = 0; i < n && i < m; ++i) {
            if (path[i] != other.path[i]) {
                return path[i] < other.path[i];
            }
        }
        return n < m;
    }

    bool operator>(const Node& other) const {
        return other < *this;
    }

    bool operator==(const Node& other) const {
        if (cost != other.cost) {
            return false;
        }
        int n = path.size();
        int m = other.path.size();
        if (n != m) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (path[i] != other.path[i]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int n = coins.size();
        if (coins[n - 1] == -1) {
            return {};
        }
        vector<Node> dp(n, Node(-1, {}));
        dp[n - 1] = Node(coins[n - 1], {n});
        for (int i = n - 2; i >= 0; --i) {
            if (coins[i] == -1) {
                continue;
            }
            Node minNode(-1, {});
            for (int j = i + 1; j <= min(i + maxJump, n - 1); ++j) {
                if (dp[j].cost == -1) {
                    continue;
                }
                Node curNode(dp[j].cost + coins[i], dp[j].path);
                curNode.insertPos(i + 1);
                if (minNode.cost == -1 || curNode < minNode) {
                    minNode = curNode;
                }
            }
            dp[i] = minNode;
        }
        return dp[0].cost == -1 ? vector<int>{} : dp[0].path;
    }
};
// @lc code=end
