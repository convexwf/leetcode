/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */

// @lc code=start
// 1. 哈希表
// 2023-08-30 submission
// 39/39 cases passed
// Runtime: 3 ms, faster than 52.38% of cpp online submissions.
// Memory Usage: 6.4 MB, less than 30.01% of cpp online submissions.
class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> m;
        for (char c : T) {
            m[c]++;
        }
        string res;
        for (char c : S) {
            if (m.count(c)) {
                res += string(m[c], c);
                m.erase(c);
            }
        }
        for (auto a : m) {
            res += string(a.second, a.first);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 自定义排序
// 2023-08-30 submission
// 39/39 cases passed
// Runtime: 3 ms, faster than 52.38% of cpp online submissions.
// Memory Usage: 6.2 MB, less than 82.91% of cpp online submissions.
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> pos(26, 26);
        for (int i = 0; i < S.size(); ++i) {
            pos[S[i] - 'a'] = i;
        }
        sort(T.begin(), T.end(), [&](char a, char b) { return pos[a - 'a'] < pos[b - 'a']; });
        return T;
    }
};
// @lc code=end
