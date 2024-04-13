/*
 * @lc app=leetcode id=842 lang=cpp
 *
 * [842] Split Array into Fibonacci Sequence
 */

// @lc code=start
// 1. 回溯
// 2023-10-08 submission
// 71/71 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 6.8 MB, less than 68.4% of cpp online submissions.
class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> res;
        dfs(num, 0, 0, 0, res);
        return res;
    }

    bool dfs(string& num, int idx, long long sum, long long pre, vector<int>& res) {
        // 字符串遍历完毕，且分割出的数字个数大于等于 3，则返回 true
        if (idx == num.size() && res.size() >= 3) {
            return true;
        }
        long long cur = 0;
        for (int i = idx; i < num.size(); ++i) {
            // 如果当前数字以 0 开头，则只能是 0
            if (i > idx && num[idx] == '0') {
                break;
            }
            cur = cur * 10 + num[i] - '0';
            // 如果当前数字大于 INT 的范围，则直接退出
            if (cur > INT_MAX) {
                break;
            }
            // 此时已经找到了前两个数，需要判断当前的数是否等于前两个数的和
            if (res.size() >= 2) {
                // 如果当前数字小于前两个数的和，则继续取下一个数字
                if (cur < sum) {
                    continue;
                }
                // 如果当前数字大于前两个数的和，则直接退出
                else if (cur > sum) {
                    break;
                }
            }
            res.push_back(cur);
            if (dfs(num, i + 1, pre + cur, cur, res)) {
                return true;
            }
            res.pop_back();
        }
        return false;
    }
};
// @lc code=end
