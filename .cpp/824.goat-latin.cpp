/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

// @lc code=start
// 1. 字符串处理
// 2023-07-06 submission
// 99/99 cases passed
// Runtime: 5 ms, faster than 34.41% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 27.65% of cpp online submissions.
class Solution {
public:
    string toGoatLatin(string sentence) {
        istringstream iss(sentence);
        string res = "";
        string word = "";
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int index = 1;
        while (iss >> word) {
            if (vowels.count(word[0])) {
                res += word + "ma";
            }
            else {
                res += word.substr(1) + word[0] + "ma";
            }
            res.append(index, 'a');
            res += ' ';
            ++index;
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
