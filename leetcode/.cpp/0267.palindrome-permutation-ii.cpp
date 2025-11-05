/*
 * @lc app=leetcode id=267 lang=cpp
 *
 * [267] Palindrome Permutation II
 */

// @lc code=start
// 1. 哈希表+递归
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }
        string mid;
        for (auto& [c, n] : cnt) {
            if (n % 2) {
                if (!mid.empty()) {
                    return {};
                }
                mid = string(1, c);
                n--;
            }
        }
        vector<string> res;
        auto dfs = [&](string cur, int len) {
            if (len == s.size()) {
                res.push_back(cur);
                return;
            }
            for (auto& [c, n] : cnt) {
                if (n > 0) {
                    n -= 2;
                    dfs(c + cur + c, len + 2);
                    n += 2;
                }
            }
        };
        dfs(mid, mid.size());
        return res;
    }
};
// @lc code=end
