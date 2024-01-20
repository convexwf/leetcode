/*
 * @lc app=leetcode id=950 lang=cpp
 *
 * [950] Reveal Cards In Increasing Order
 */

// @lc code=start
// 1. 队列模拟
// 2024-01-16 submission
// 33/33 cases passed
// Runtime: 7 ms, faster than 21.91% of cpp online submissions.
// Memory Usage: 9.1 MB, less than 5.24% of cpp online submissions.
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            q.push(i);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};
// @lc code=end
