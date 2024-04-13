/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */

// @lc code=start
// 1. 回溯
// 2023-10-04 submission
// 45/45 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.5 MB, less than 15.26% of cpp online submissions.
class Solution {
public:
    bool isAdditiveNumber(string num) {
        return backtrack(num, 0, "0", "0", 0);
    }

private:
    bool backtrack(string& num, int idx, string sum, string pre, int cnt) {
        if (idx == num.size()) {
            return cnt >= 3;
        }
        for (int i = idx; i < num.size(); ++i) {
            string cur = num.substr(idx, i - idx + 1);
            // 0 开头的数字只能是 0
            if (cur.size() > 1 && cur[0] == '0') {
                break;
            }
            // 剪枝
            if (cnt >= 2 && greater(cur, sum)) {
                break;
            }
            // 前两个数字，或者当前数字等于前两个数字之和
            if (cnt < 2 || cur == sum) {
                if (backtrack(num, i + 1, add(cur, pre), cur, cnt + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    string add(string& a, string& b) {
        string res(max(a.size(), b.size()) + 1, '0');
        int carry = 0;
        for (int i = 0; i < res.size(); ++i) {
            int sum = carry;
            if (i < a.size()) {
                sum += a[a.size() - 1 - i] - '0';
            }
            if (i < b.size()) {
                sum += b[b.size() - 1 - i] - '0';
            }
            res[res.size() - 1 - i] = sum % 10 + '0';
            carry = sum / 10;
        }
        return res[0] == '0' ? res.substr(1) : res;
    }

    bool greater(string& a, string& b) {
        if (a.size() != b.size()) {
            return a.size() > b.size();
        }
        return a > b;
    }
};
// @lc code=end
