/*
 * @lc app=leetcode id=249 lang=cpp
 *
 * [249] Group Shifted Strings
 */

// @lc code=start
// 1. 哈希表
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < strings.size(); i++) {
            string key = getKey(strings[i]);
            mp[key].push_back(i);
        }
        vector<vector<string>> res;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<string> group;
            for (int i = 0; i < it->second.size(); i++) {
                group.push_back(strings[it->second[i]]);
            }
            res.push_back(group);
        }
        return res;
    }

    string getKey(string& s) {
        string key = "";
        for (int i = 1; i < s.size(); i++) {
            int diff = s[i] - s[i - 1];
            if (diff < 0) diff += 26;
            key += 'a' + diff;
        }
        return key;
    }
};
// @lc code=end
