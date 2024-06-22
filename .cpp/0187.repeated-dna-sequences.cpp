/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
// 1. 哈希表
// 2024-06-14 submission
// 31/31 cases passed
// Runtime: 44 ms, faster than 61.83% of cpp online submissions.
// Memory Usage: 26.9 MB, less than 47.27% of cpp online submissions.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        vector<string> res;
        for (int i = 0; i + 10 <= s.size(); i++) {
            string sub = s.substr(i, 10);
            if (++hash[sub] == 2) {
                res.push_back(sub);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表+位操作
// 2020-09-18 submission
// 31/31 cases passed
// Runtime: 99 ms, faster than 70.8% of cpp online submissions.
// Memory Usage: 15.7 MB, less than 94.93% of cpp online submissions.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> hash;
        unordered_map<char, int> dna{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int cur = 0;
        vector<string> res;
        for (int i = 0; i < s.size(); i++) {
            cur = (cur << 2 | dna[s[i]]) & 0xfffff;
            if (i < 9) continue;
            if (hash[cur]++ == 1) {
                res.push_back(s.substr(i - 9, 10));
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 3. Rabin-Karp 字符串匹配算法
// 2024-06-17 submission
// 31/31 cases passed
// Runtime: 31 ms, faster than 93.48% of cpp online submissions.
// Memory Usage: 15.7 MB, less than 94.07% of cpp online submissions.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};
        unordered_map<char, int> to_int = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int base = 4, mod = int(pow(4, 10 - 1)), hash = 0;

        unordered_map<int, int> hash_map;
        vector<string> res;
        for (int i = 0; i < s.length(); ++i) {
            hash = (hash * base + to_int[s[i]]);
            if (i < 9) continue;
            if (hash_map[hash]++ == 1) {
                res.push_back(s.substr(i - 9, 10));
            }
            hash = (hash - mod * to_int[s[i - 9]]);
        }
        return res;
    }
};
// @lc code=end
