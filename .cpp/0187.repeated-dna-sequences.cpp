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
// 2020-09-18 submission
// 31/31 cases passed
// Runtime: 99 ms, faster than 70.8% of cpp online submissions.
// Memory Usage: 15.7 MB, less than 94.93% of cpp online submissions.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res; // 用 set 替代 vector，因为可能出现多次重复
        unordered_set<int> hash_set;
        unordered_map<char, int> dna{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int cur = 0;
        for (int i = 0; i < 9; i++) {
            cur = cur << 2 | dna[s[i]];
        }
        for (int i = 9; i < s.length(); i++) {
            cur = (cur & 0x0003ffff) << 2 | dna[s[i]]; // 每次只保留 20-2=18 位，再加上后来的2位
            if (hash_set.count(cur))
                res.insert(s.substr(i - 9, 10));
            else
                hash_set.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};
// @lc code=end
