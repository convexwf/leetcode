/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
// 2022-11-15 submission
// 34/34 cases passed
// Runtime: 13 ms, faster than 60.43% of C++ online submissions.
// Memory Usage: 9.2 MB, less than 66.05% of C++ online submissions.
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long A = LLONG_MIN, B = LLONG_MIN, C = LLONG_MIN;
        for (int num : nums) {
            if (num > A) {
                C = B; B = A; A = num;
            }
            else if (A > num && num > B) {
                C = B; B = num;
            }
            else if (B > num && num > C) {
                C = num;
            }
            // cout << A << " " << B << " " << C << endl;
        }
        return C > LLONG_MIN ? C : A;
    }
};
// @lc code=end