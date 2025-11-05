/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
// 1. 哈希表+字符串处理
// 2025-02-27 submission
// 136/136 cases passed
// Runtime: 331 ms, faster than 97.51% of cpp online submissions.
// Memory Usage: 263.7 MB, less than 93.24% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> word_map;
        unordered_set<int> length_set;
        for (int i = 0; i < words.size(); ++i) {
            word_map[words[i]] = i;
            length_set.insert(words[i].length());
        }

        vector<vector<int>> res;
        for (int idx = 0; idx < words.size(); ++idx) {
            string word = words[idx];
            int word_len = word.length();
            reverse(word.begin(), word.end());
            if (word_map.count(word) && word_map[word] != idx) {
                res.push_back({idx, word_map[word]});
            }
            for (int other_len : length_set) {
                if (word_len <= other_len) {
                    continue;
                }
                if (word_map.count(word.substr(0, other_len)) &&
                    isPalindrome(word, other_len, word_len - 1)) {
                    res.push_back({word_map[word.substr(0, other_len)], idx});
                }
                if (word_map.count(word.substr(word_len - other_len)) &&
                    isPalindrome(word, 0, word_len - other_len - 1)) {
                    res.push_back({idx, word_map[word.substr(word_len - other_len)]});
                }
            }
        }
        return res;
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表+有序集合+字符串处理
// 2023-02-27 submission
// 136/136 cases passed
// Runtime: 593 ms, faster than 95.04% of cpp online submissions.
// Memory Usage: 361.6 MB, less than 84.07% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> word_map;
        set<int> length_set;
        for (int i = 0; i < words.size(); ++i) {
            word_map[words[i]] = i;
            length_set.insert(words[i].length());
        }

        vector<vector<int>> res;
        for (int idx = 0; idx < words.size(); ++idx) {
            string word = words[idx];
            int word_len = word.length();
            reverse(word.begin(), word.end());
            if (word_map.count(word) && word_map[word] != idx) {
                res.push_back({idx, word_map[word]});
            }
            set<int>::iterator pivot = length_set.find(word_len);
            for (set<int>::iterator it = length_set.begin(); it != pivot; ++it) {
                int other_len = *it;
                if (word_map.count(word.substr(0, other_len)) &&
                    isPalindrome(word, other_len, word_len - 1)) {
                    res.push_back({word_map[word.substr(0, other_len)], idx});
                }
                if (word_map.count(word.substr(word_len - other_len)) &&
                    isPalindrome(word, 0, word_len - other_len - 1)) {
                    res.push_back({idx, word_map[word.substr(word_len - other_len)]});
                }
            }
        }
        return res;
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 3. 字符串哈希
// 2025-02-27 submission
// 136/136 cases passed
// Runtime: 1380 ms, faster than 56.11% of cpp online submissions.
// Memory Usage: 47.9 MB, less than 99.17% of cpp online submissions.
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        const int n = words.size();
        const int MOD = 1e9 + 7;
        const int base = 26;

        vector<long> base_pow(301, 1);
        for (int i = 1; i < base_pow.size(); ++i) {
            base_pow[i] = base_pow[i - 1] * base % MOD;
        }

        vector<long> prefix_hash(n), suffix_hash(n);
        for (int i = 0; i < n; ++i) {
            int len = words[i].size();
            const string& word = words[i];
            for (int j = 0; j < len; ++j) {
                prefix_hash[i] = (prefix_hash[i] * base + (word[j] - 'a')) % MOD;
                suffix_hash[i] = (suffix_hash[i] * base + (word[len - 1 - j] - 'a')) % MOD;
            }
        }

        function<bool(int, int, int, int)> is_palindrome = [&](int i, int j, int len2, int len1) {
            long hash1 = (prefix_hash[i] * base_pow[len2] + prefix_hash[j]) % MOD;
            long hash2 = (suffix_hash[j] * base_pow[len1] + suffix_hash[i]) % MOD;
            return hash1 == hash2;
        };
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (is_palindrome(i, j, words[j].size(), words[i].size())) {
                    ans.push_back({i, j});
                }
                if (is_palindrome(j, i, words[i].size(), words[j].size())) {
                    ans.push_back({j, i});
                }
            }
        }
        return ans;
    }
};
// @lc code=end
