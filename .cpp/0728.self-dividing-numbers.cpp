/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

// @lc code=start
// 1. 模拟
// 2023-08-17 submission
// 31/31 cases passed
// Runtime: 9 ms, faster than 7.04% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 5.1% of cpp online submissions.
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; ++i) {
            if (isSelfDividingNumber(i)) {
                res.push_back(i);
            }
        }
        return res;
    }

private:
    bool isSelfDividingNumber(int num) {
        string str = to_string(num);
        for (char c : str) {
            if (c == '0' || num % (c - '0') != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// @lc code=start
// 1. 模拟
// 2024-09-14 submission
// 31/31 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 38.57% of cpp online submissions.
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left, n = 0; i <= right; ++i) {
            for (n = i; n > 0; n /= 10) {
                if (n % 10 == 0 || i % (n % 10) != 0) break;
            }
            if (n == 0) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end
