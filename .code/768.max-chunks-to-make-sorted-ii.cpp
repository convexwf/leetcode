/*
 * @lc app=leetcode id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        int res = 0;
        for (int x : arr) {
            if (stk.empty() || stk.top() <= x) {
                stk.push(x);
            }
            else {

            }
        }
    }
};
// @lc code=end

