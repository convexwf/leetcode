/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
// 1, 哈希表
// 2023-08-16 submission
// 48/48 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.7 MB, less than 43.21% of cpp online submissions.
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        unordered_map<string, int> hash;
        for (auto &c : banned) {
            hash[c] = -1;
        }
        string word;
        paragraph.append(" ");
        for (char &c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            }
            else if (word != "") {
                if (hash[word] != -1) hash[word]++;
                word = "";
            }
        }
        int max_count = 0;
        string res;
        for (auto [k, v] : hash) {
            // cout << k << " " << v << endl;
            if (v > max_count) {
                max_count = v;
                res = k;
            }
        }
        return res;
    }
};
// @lc code=end
