/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
// 1. 最大堆
// 2023-10-26 submission
// 74/74 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 7.9 MB, less than 67.58% of cpp online submissions.
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int stone : stones) {
            pq.push(stone);
        }
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(y - x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
// @lc code=end
