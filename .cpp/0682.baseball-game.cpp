/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
// 1. 栈
// 2022-08-20 submission
// 39/39 cases passed
// Runtime: 8 ms, faster than 44.66% of cpp online submissions.
// Memory Usage: 8.2 MB, less than 99.8% of cpp online submissions.
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> vec;
        int sum = 0;
        for (string op : ops) {
            int n = vec.size();
            if (op == "+") {
                vec.push_back(vec[n - 1] + vec[n - 2]);
                sum += vec.back();
            }
            else if (op == "D") {
                vec.push_back(vec[n - 1] * 2);
                sum += vec.back();
            }
            else if (op == "C") {
                sum -= vec.back();
                vec.pop_back();
            }
            else {
                vec.push_back(stoi(op));
                sum += vec.back();
            }
        }
        return sum;
    }
};
// @lc code=end
