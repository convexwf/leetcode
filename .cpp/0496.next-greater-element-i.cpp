/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
// 2022-08-26 submission
// 15/15 cases passed
// Runtime: 18 ms, faster than 24.42% of cpp online submissions.
// Memory Usage: 8.8 MB, less than 71.01% of cpp online submissions.
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> m;
        stack<int> stk;
        for (int i = 0; i < nums.size(); ++i) {
            while (!stk.empty() && stk.top() < nums[i]) {
                m[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(nums[i]);
        }

        vector<int> res;
        for (int num : findNums) {
            if (m.count(num)) {
                res.push_back(m[num]);
            }
            else {
                res.push_back(-1);
            }
        }
        return res;
    }
};
// @lc code=end
