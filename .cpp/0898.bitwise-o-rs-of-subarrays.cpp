/*
 * @lc app=leetcode id=898 lang=cpp
 *
 * [898] Bitwise ORs of Subarrays
 */

// @lc code=start
// 1. 哈希集合
// 2023-10-18 submission
// 83/83 cases passed
// Runtime: 1084 ms, faster than 53.01% of cpp online submissions.
// Memory Usage: 209.6 MB, less than 68.27% of cpp online submissions.
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // cur: 之前的所有子数组的结果
        // tmp: 计算过程中的子数组的结果
        // res: 所有子数组的结果
        unordered_set<int> res, cur, tmp;
        for (int i : arr) {
            tmp = {i}; // 新数字加入到之前的所有子数组中
            for (int j : cur) tmp.insert(i | j);
            cur = tmp;
            for (int j : cur) res.insert(j);
        }
        return res.size();
    }
};
// @lc code=end
