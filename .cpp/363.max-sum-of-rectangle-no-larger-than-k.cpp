/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
// 2. 前缀和 + 二分查找
// 2023-05-12 submission
// 36/36 cases passed
// Runtime: 1103 ms, faster than 22.36% of cpp online submissions.
// Memory Usage: 238.2 MB, less than 21.08% of cpp online submissions.
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MIN;
        // 枚举上边界
        for (int i = 0; i < m; i++) {
            vector<int> sum(n);
            // 枚举下边界
            for (int j = i; j < m; j++) {
                // 求出每列的前缀和
                for (int c = 0; c < n; c++) {
                    sum[c] += matrix[j][c];
                }
                set<int> s{0};
                int cur_sum = 0;
                for (int x : sum) {
                    cur_sum += x;
                    auto it = s.lower_bound(cur_sum - k);
                    if (it != s.end()) {
                        ans = max(ans, cur_sum - *it);
                    }
                    s.insert(cur_sum);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
