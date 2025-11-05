/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
// 1. 分桶
// 2023-11-07 submission
// 53/53 cases passed
// Runtime: 163 ms, faster than 80.59% of cpp online submissions.
// Memory Usage: 71.3 MB, less than 34.17% of cpp online submissions.
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int, int>>> buckets(26);
        for (int i = 0; i < words.size(); ++i) {
            buckets[words[i][0] - 'a'].emplace_back(i, 1);
        }
        int res = 0;
        for (char c : s) {
            vector<pair<int, int>> bucket = std::move(buckets[c - 'a']);
            buckets[c - 'a'].clear();
            for (pair<int, int>& p : bucket) {
                if (p.second == words[p.first].size()) {
                    ++res;
                }
                else {
                    buckets[words[p.first][p.second] - 'a'].emplace_back(p.first, p.second + 1);
                }
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 哈希表+二分查找
// 2023-11-10 submission
// 53/53 cases passed
// Runtime: 232 ms, faster than 58.41% of cpp online submissions.
// Memory Usage: 51.8 MB, less than 60.18% of cpp online submissions.
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<char, vector<int>> hash;
        for (int i = 0; i < s.size(); ++i) {
            hash[s[i]].push_back(i);
        }
        for (string& word : words) {
            int pos = -1;
            bool flag = true;
            for (char& c : word) {
                auto it = upper_bound(hash[c].begin(), hash[c].end(), pos);
                if (it == hash[c].end()) {
                    flag = false;
                    break;
                }
                pos = *it;
            }
            if (flag) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end
