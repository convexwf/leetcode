/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 *
 * https://leetcode.com/problems/longest-turbulent-subarray/description/
 *
 * algorithms
 * Medium (47.23%)
 * Likes:    1601
 * Dislikes: 191
 * Total Accepted:    81.1K
 * Total Submissions: 171.7K
 * Testcase Example:  '[9,4,2,10,7,8,8,1,9]'
 *
 * Given an integer array arr, return the length of a maximum size turbulent
 * subarray of arr.
 *
 * A subarray is turbulent if the comparison sign flips between each adjacent
 * pair of elements in the subarray.
 *
 * More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said
 * to be turbulent if and only if:
 *
 *
 * For i <= k < j:
 *
 *
 * arr[k] > arr[k + 1] when k is odd, and
 * arr[k] < arr[k + 1] when k is even.
 *
 *
 * Or, for i <= k < j:
 *
 * arr[k] > arr[k + 1] when k is even, and
 * arr[k] < arr[k + 1] when k is odd.
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [9,4,2,10,7,8,8,1,9]
 * Output: 5
 * Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [4,8,12,16]
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [100]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 4 * 10^4
 * 0 <= arr[i] <= 10^9
 *
 *
 */

// @lc code=start
// 2023-02-18 submission
// 91/91 cases passed
// Runtime: 86 ms, faster than 60.44% of C++ online submissions.
// Memory Usage: 43.8 MB, less than 9.43% of C++ online submissions.
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> inc(n, 1);
        vector<int> dec(n, 1);
        int res = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i-1]) {
                inc[i] = dec[i-1] + 1;
                res = max(res, inc[i]);
            }
            else if (arr[i] < arr[i-1]) {
                dec[i] = inc[i-1] + 1;
                res = max(res, dec[i]);
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2023-02-18 submission
// 91/91 cases passed
// Runtime: 81 ms, faster than 76.89% of C++ online submissions.
// Memory Usage: 40.4 MB, less than 64.51% of C++ online submissions.
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int inc = 1, dec = 1, res = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i-1]) {
                inc = dec + 1;
                dec = 1;
                res = max(res, inc);
            }
            else if (arr[i] < arr[i-1]) {
                dec = inc + 1;
                inc = 1;
                res = max(res, dec);
            }
            else {
                inc = dec = 1;
            }
        }
        return res;
    }
};
// @lc code=end