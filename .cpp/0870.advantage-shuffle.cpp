/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start
// 1. 排序+贪心算法
// 2023-08-01 submission
// 67/67 cases passed
// Runtime: 135 ms, faster than 97.95% of cpp online submissions.
// Memory Usage: 62.6 MB, less than 87.5% of cpp online submissions.
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size(), left = 0, right = n - 1;
        vector<int> res(n);
        sort(A.begin(), A.end());
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            q.push({B[i], i});
        }
        while (!q.empty()) {
            int val = q.top().first, idx = q.top().second;
            q.pop();
            if (A[right] > val) {
                res[idx] = A[right--];
            }
            else {
                res[idx] = A[left++];
            }
        }
        return res;
    }
};
// @lc code=end
