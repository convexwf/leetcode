/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
 */

// @lc code=start
// 1. 模拟
// 2023-08-08 submission
// 58/58 cases passed
// Runtime: 88 ms, faster than 93.12% of cpp online submissions.
// Memory Usage:  MB, less than 50.14% of cpp online submissions.
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int evenSum = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] % 2 == 0) {
                evenSum += A[i];
            }
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i) {
            int val = queries[i][0];
            int index = queries[i][1];
            if (A[index] % 2 == 0 && val % 2 == 0) {
                evenSum += val;
            }
            else if (A[index] % 2 == 0 && val % 2 != 0) {
                evenSum -= A[index];
            }
            else if (A[index] % 2 != 0 && val % 2 == 0) {
                // do nothing
            }
            else {
                evenSum += A[index] + val;
            }
            A[index] += val;
            ans.push_back(evenSum);
        }
        return ans;
    }
};
// @lc code=end
