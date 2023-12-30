/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 */

// @lc code=start
// 1. 哈希表
// 2023-12-26 submission
// 50/50 cases passed
// Runtime: 7 ms, faster than 11.82% of cpp online submissions.
// Memory Usage: 9.1 MB, less than 12.06% of cpp online submissions.
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto& word : words) {
            if (match(word, pattern)) {
                res.push_back(word);
            }
        }
        return res;
    }

    bool match(string& word, string& pattern) {
        unordered_map<char, char> w2p;
        unordered_map<char, char> p2w;
        for (int i = 0; i < word.size(); ++i) {
            if (!w2p.count(word[i]) && !p2w.count(pattern[i])) {
                w2p[word[i]] = pattern[i];
                p2w[pattern[i]] = word[i];
            }
            else if (w2p[word[i]] != pattern[i] || p2w[pattern[i]] != word[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 双哈希表改进
// 2023-12-26 submission
// 50/50 cases passed
// Runtime: 5 ms, faster than 20.99% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 35.95% of cpp online submissions.
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string word : words) {
            vector<int> w(26), p(26);
            int i = 0, n = word.size();
            for (; i < n; ++i) {
                if (w[word[i] - 'a'] != p[pattern[i] - 'a']) break;
                w[word[i] - 'a'] = p[pattern[i] - 'a'] = i + 1;
            }
            if (i == n) res.push_back(word);
        }
        return res;
    }
};
// @lc code=end
