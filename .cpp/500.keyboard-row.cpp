/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
// 1. 哈希表
// 2022-11-17 submission
// 22/22 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7 MB, less than 34.32% of cpp online submissions.
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_set<char> row1{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> row2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> row3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        for (string word : words) {
            int one = 0, two = 0, three = 0;
            for (char c : word) {
                c = tolower(c);
                if (row1.count(c)) one = 1;
                if (row2.count(c)) two = 1;
                if (row3.count(c)) three = 1;
                if (one + two + three > 1) break;
            }
            if (one + two + three == 1) res.push_back(word);
        }
        return res;
    }
};
// @lc code=end
