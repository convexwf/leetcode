/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */

// @lc code=start
// 1. brute force
// 2023-06-02 submission
// 50/50 cases passed
// Runtime: 28 ms, faster than 26.74% of cpp online submissions.
// Memory Usage: 5.8 MB, less than 97.06% of cpp online submissions.
class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGood(i)) ++res;
        }
        return res;
    }

private:
    bool isGood(int n) {
        string str = to_string(n);
        bool flag = false;
        for (char c : str) {
            if (c == '3' || c == '4' || c == '7') return false;
            if (c == '2' || c == '5' || c == '6' || c == '9') flag = true;
        }
        return flag;
    }
};
// @lc code=end

// @lc code=start
// 2. 动态规划
// 2023-06-02 submission
// 50/50 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage:  MB, less than 13.1% of cpp online submissions.
class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n + 1, 0);
        int count = 0;
        for (int i = 0; i <= n; i++) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8) {
                    dp[i] = 1;
                }
                else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    count++;
                }
            }
            else {
                int a = dp[i / 10], b = dp[i % 10];
                if (a == 1 && b == 1) {
                    dp[i] = 1;
                }
                else if (a >= 1 && b >= 1) {
                    dp[i] = 2;
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

// @lc code=start
// 3. 数学方法
// 2023-06-02 submission
// 50/50 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.1 MB, less than 22.46% of cpp online submissions.
class Solution {
public:
    int rotatedDigits(int N) {
        vector<int> rotate = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
        vector<int> ds;
        while (N > 0) {
            ds.push_back(N % 10);
            N /= 10;
        }
        int count = 0;
        bool diff = false;
        for (int i = ds.size() - 1; i > -1; --i) {
            int good = 0, soso = 0, d = ds[i];
            for (int j = 0; j < d; ++j) {
                if (rotate[j] == 1)
                    ++good;
                else if (rotate[j] == 0)
                    ++soso;
            }
            count += (good + soso) * pow(7, i);
            if (!diff) count -= soso * pow(3, i);
            if (rotate[d] == -1) return count;
            if (rotate[d] == 1) diff = true;
        }
        return diff && rotate[ds[0]] > -1 ? count + 1 : count;
    }
};
// @lc code=end
