/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
// 2020-09-19 submission
// 58/58 cases passed
// Runtime: 8 ms, faster than 63.19% of C++ online submissions.
// Memory Usage: 8.3 MB, less than 38.13% of C++ online submissions.
class Solution {
public:
    string reverseWords(string s) {
        string res_s;
        if (s.length() == 0) return res_s;
        vector<string> res;

        bool word = false;
        int begin = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && !word) {
                word = true;
            }
            if (s[i] == ' ') {
                if (word) res.push_back(s.substr(begin+1, i-begin-1));
                begin = i;
                word = false;
            }
        }
        if (s[s.length()-1] != ' ') res.push_back(s.substr(begin+1));

        for (int i = res.size()-1; i >= 0; i--) {
            res_s.append(res[i]);
            res_s.append(" ");
        }
        return res_s.substr(0, res_s.length()-1);
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 58/58 cases passed
// Runtime: 14 ms, faster than 37.09% of C++ online submissions.
// Memory Usage: 20.9 MB, less than 17.44% of C++ online submissions.
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string tmp;
        is >> s;
        while(is >> tmp) s = tmp + " " + s;
        if(!s.empty() && s[0] == ' ') s = "";
        return s;
    }
};
// @lc code=end

// @lc code=start
// 2023-01-14 submission
// 58/58 cases passed
// Runtime: 10 ms, faster than 52.11% of C++ online submissions.
// Memory Usage: 21 MB, less than 17.44% of C++ online submissions.
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        s = "";
        string t = "";
        while (getline(is, t, ' ')) {
            if (t.empty()) continue;
            s = (s.empty() ? t : (t + " " + s));
        }
        return s;
    }
};
// @lc code=end