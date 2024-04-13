/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
// 1. BFS
// 2023-05-31 submission
// 48/48 cases passed
// Runtime: 182 ms, faster than 68.04% of cpp online submissions.
// Memory Usage: 30.8 MB, less than 81.67% of cpp online submissions.
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1;
        if (target == "0000") return 0;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    string up = plusOne(cur, j);
                    if (up == target) return step + 1;
                    if (!visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = minusOne(cur, j);
                    if (down == target) return step + 1;
                    if (!visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }

private:
    string plusOne(string s, int j) {
        s[j] = (s[j] - '0' + 1) % 10 + '0';
        return s;
    }
    string minusOne(string s, int j) {
        s[j] = (s[j] - '0' - 1 + 10) % 10 + '0';
        return s;
    }
};
// @lc code=end

// @lc code=start
// 2. 双向 BFS
// 2023-05-31 submission
// 48/48 cases passed
// Runtime: 1194 ms, faster than 5.07% of cpp online submissions.
// Memory Usage: 222.3 MB, less than 5.54% of cpp online submissions.
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end()); // 将死亡数字存入 hashset 中
        if (deads.count("0000")) return -1; // 特判 "0000" 是死亡数字的情况
        if (target == "0000") return 0;     // 特判目标值为 "0000" 的情况

        queue<string> q1, q2;
        unordered_set<string> visited1, visited2;
        q1.push("0000");
        q2.push(target);
        visited1.insert("0000");
        visited2.insert(target);

        int step = 0;
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) { // 优先扩展队列中状态数较少的那个队列
                if (visit_queue(q2, deads, visited2, visited1)) {
                    return step - 1; // -1 是为了减去在最后一次扩展时多加的一次
                }
            }
            else {
                if (visit_queue(q1, deads, visited1, visited2)) return step - 1;
            }
            ++step;
        }
        return -1; // 无法到达目标状态，返回 -1
    }

private:
    string plusOne(string s, int j) {
        s[j] = (s[j] - '0' + 1) % 10 + '0';
        return s;
    }

    string minusOne(string s, int j) {
        s[j] = (s[j] - '0' - 1 + 10) % 10 + '0';
        return s;
    }

    bool visit_queue(queue<string>& q, unordered_set<string>& dead, unordered_set<string>& visited,
                     unordered_set<string>& otherVisited) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            string cur = q.front();
            q.pop();
            if (otherVisited.count(cur)) return true; // 遇到相同状态，搜索结束
            if (dead.count(cur)) continue;            // 遇到死亡数字，跳过该状态
            visited.insert(cur);

            for (int j = 0; j < 4; ++j) {
                string up = plusOne(cur, j), down = minusOne(cur, j);
                if (!visited.count(up)) q.push(up);
                if (!visited.count(down)) q.push(down);
            }
        }
        return false;
    }
};
// @lc code=end
