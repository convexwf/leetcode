/*
 * @lc app=leetcode id=816 lang=cpp
 *
 * [816] Ambiguous Coordinates
 */

// @lc code=start
// 1. 模拟
// 2023-12-12 submission
// 346/346 cases passed
// Runtime: 8 ms, faster than 66.36% of cpp online submissions.
// Memory Usage: 10.2 MB, less than 49.09% of cpp online submissions.
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        string lpart, rpart;
        for (int i = 2; i < s.size() - 1; ++i) {
            lpart = s.substr(1, i - 1);
            rpart = s.substr(i, s.size() - i - 1);
            vector<string> lres = extract(lpart);
            vector<string> rres = extract(rpart);
            for (string& l : lres) {
                for (string& r : rres) {
                    res.push_back("(" + l + ", " + r + ")");
                }
            }
        }
        return res;
    }

    vector<string> extract(string s) {
        vector<string> res;
        if (s.size() == 1 || s[0] != '0') {
            res.push_back(s);
        }
        if (s[0] == '0' && s.back() != '0') {
            res.push_back("0." + s.substr(1));
        }
        else if (s.back() != '0') {
            for (int i = 1; i < s.size(); ++i) {
                res.push_back(s.substr(0, i) + "." + s.substr(i));
            }
        }
        return res;
    }
};
// @lc code=end
