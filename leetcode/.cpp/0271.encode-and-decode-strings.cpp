/*
 * @lc app=leetcode id=271 lang=cpp
 *
 * [271] Encode and Decode Strings
 */

// @lc code=start
// 1. 编码字符串长度
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        stringstream ss;
        for (const string& str : strs) {
            int len = str.size();
            ss << setw(3) << setfill('0') << len << str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int len = stoi(s.substr(i, 3));
            i += 3;
            res.push_back(s.substr(i, len));
            i += len;
        }
    }
};
// @lc code=end
