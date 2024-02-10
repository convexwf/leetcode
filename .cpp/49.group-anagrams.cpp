/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
// 2022-07-21 submission
// 117/117 cases passed
// Runtime: 35 ms, faster than 92.92% of C++ online submissions.
// Memory Usage: 18.3 MB, less than 95% of C++ online submissions.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        for (string str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            if (!m.count(t)) {
                m[t] = res.size();
                res.push_back({});
            }
            res[m[t]].push_back(str);
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2022-07-21 submission
// 117/117 cases passed
// Runtime: 106 ms, faster than 12.38% of C++ online submissions.
// Memory Usage: 24.9 MB, less than 12.89% of C++ online submissions.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string str : strs) {
            vector<int> cnt(26);
            string t;
            for (char c : str) {
                ++cnt[c - 'a'];
            };
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] == 0) continue;
                t += string(1, i + 'a') + to_string(cnt[i]);
            }
            m[t].push_back(str);
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};
// @lc code=end