/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

// @lc code=start
// 1. 栈
// 2024-02-06 submission
// 152/152 cases passed
// Runtime: 6 ms, faster than 33.3% of cpp online submissions.
// Memory Usage: 8.3 MB, less than 34.95% of cpp online submissions.
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        vector<int> stk;
        istringstream iss(preorder);
        string node;
        while (getline(iss, node, ',')) {
            // node 0 means null, node 1 means not null
            if (node == "#") {
                while (!stk.empty() && stk.back() == 0) {
                    stk.pop_back();
                    if (stk.empty() || stk.back() == 0) return false;
                    stk.pop_back();
                }
                stk.push_back(0);
            }
            else {
                stk.push_back(1);
            }
        }
        return stk.size() == 1 && stk.back() == 0;
    }
};
// @lc code=end
