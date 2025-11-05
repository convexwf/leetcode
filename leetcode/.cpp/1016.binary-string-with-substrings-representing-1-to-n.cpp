/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 */

// @lc code=start
// 1. bitset
// 2023-11-30 submission
// 28/28 cases passed
// Runtime: 3 ms, faster than 52.74% of cpp online submissions.
// Memory Usage: 6.7 MB, less than 91.14% of cpp online submissions.
class Solution {
public:
    bool queryString(string s, int n) {
        for (int i = 1; i <= n; ++i) {
            bitset<32> bs(i);
            string str = bs.to_string();
            str.erase(0, str.find_first_not_of('0'));
            if (s.find(str) == string::npos) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法
// 2023-11-30 submission
// 28/28 cases passed
// Runtime: 3 ms, faster than 52.74% of cpp online submissions.
// Memory Usage: 6.8 MB, less than 44.3% of cpp online submissions.
class Solution {
public:
    bool queryString(string s, int n) {
        if (n > 1000) {
            return false;
        }
        for (int i = n; i > n / 2; --i) {
            string b = bitset<32>(i).to_string();
            b = b.substr(b.find_first_not_of('0'));
            if (s.find(b) == string::npos) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
