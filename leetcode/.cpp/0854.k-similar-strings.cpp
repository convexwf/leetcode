/*
 * @lc app=leetcode id=854 lang=cpp
 *
 * [854] K-Similar Strings
 */

// @lc code=start
// 1. bfs
// 2024-01-24 submission
// 66/66 cases passed
// Runtime: 395 ms, faster than 21.5% of cpp online submissions.
// Memory Usage: 159.9 MB, less than 11.5% of cpp online submissions.
class Solution {
public:
    // Why only check the first different char?
    void next(const string &s, const string &s2, vector<string> &result) {
        int i = 0;
        while (s[i] == s2[i]) {
            ++i;
        }
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[j] == s2[i]) {
                string next = s;
                swap(next[i], next[j]);
                result.push_back(next);
            }
        }
    }

    int kSimilarity(string s1, string s2) {
        if (s1 == s2) {
            return 0;
        }
        unordered_set<string> visited;
        queue<string> q;
        q.push(s1);
        visited.insert(s1);
        int res = 0;
        while (!q.empty()) {
            ++res;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string s = q.front();
                q.pop();
                vector<string> nexts;
                next(s, s2, nexts);
                for (const auto &next : nexts) {
                    if (next == s2) {
                        return res;
                    }
                    if (!visited.count(next)) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
