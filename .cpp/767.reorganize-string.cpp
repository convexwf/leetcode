/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
// 1. 哈希表+贪心
// 2023-08-10 submission
// 70/70 cases passed
// Runtime: 3 ms, faster than 52.32% of cpp online submissions.
// Memory Usage: 6.3 MB, less than % of cpp online submissions.
class Solution {
public:
    string reorganizeString(string S) {
        if (S.size() < 2) return S;
        vector<pair<int, char>> counts(26);
        for (int i = 0; i < 26; ++i) {
            counts[i].second = 'a' + i;
        }
        for (char c : S) {
            ++counts[c - 'a'].first;
        }
        sort(counts.begin(), counts.end(),
             [](const pair<int, char>& a, const pair<int, char>& b) { return a.first > b.first; });
        if (counts[0].first > (S.size() + 1) / 2) return "";
        string res(S.size(), ' ');
        int idx = 0;
        for (auto& count : counts) {
            for (int i = 0; i < count.first; ++i) {
                res[idx] = count.second;
                idx += 2;
                if (idx >= S.size()) idx = 1;
            }
        }
        return res;
    }
};
// @lc code=end
