/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
// 1. 数学方法+结果数组
// 2024-05-21 submission
// 311/311 cases passed
// Runtime: 3 ms, faster than 77.98% of cpp online submissions.
// Memory Usage: 8.4 MB, less than 59.12% of cpp online submissions.
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];
                res[i + j] += sum / 10;
                res[i + j + 1] = sum % 10;
            }
        }
        string result;
        for (int i = 0; i < res.size(); i++) {
            if (result.empty() && res[i] == 0) continue;
            result.push_back(res[i] + '0');
        }
        return result.empty() ? "0" : result;
    }
};
// @lc code=end

// @lc code=start
// 2. 数学方法+字符串
// 2022-07-29 submission
// 311/311 cases passed
// Runtime: 4 ms, faster than 91.9% of cpp online submissions.
// Memory Usage: 6.6 MB, less than 83.46% of cpp online submissions.
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string res(m + n, '0');
        int carry = 0;
        int idx = res.length() - 1;
        for (int i = 0; i < m + n - 1; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j >= m || i - j >= n) continue;
                carry += (num1[(m - 1) - j] - '0') * (num2[(n - 1) - (i - j)] - '0');
            }
            if (carry > 0) {
                idx = res.length() - i - 1;
                res[idx] = carry % 10 + '0';
            }
            carry /= 10;
        }
        res[0] = carry + '0';
        return carry > 0 ? res : res.substr(idx);
    }
};
// @lc code=end
