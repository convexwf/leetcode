/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (65.01%)
 * Likes:    4631
 * Dislikes: 155
 * Total Accepted:    558.6K
 * Total Submissions: 859.2K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of the range [1, n].
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
 *
 *
 */

// @lc code=start
// 2022-07-26 submission
// 27/27 cases passed
// Runtime: 44 ms, faster than 49.19% of C++ online submissions.
// Memory Usage: 8.9 MB, less than 91.31% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        DFS(n, k, 1, out, res);
        return res;
    }

    void DFS(int n, int k, int level, vector<int>& out,
             vector<vector<int>>& res) {
        if (out.size() == k) {
            res.push_back(out);
            return;
        }
        for (int i = level; i <= n; ++i) {
            out.push_back(i);
            DFS(n, k, i + 1, out, res);
            out.pop_back();
        }
    }
};
// @lc code=end

// @lc code=start
// 2022-07-26 submission
// 27/27 cases passed
// Runtime: 59 ms, faster than 32.36% of C++ online submissions.
// Memory Usage: 34.1 MB, less than 24.7% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k > n || k < 0) return {};
        if (k == 0) return {{}};
        vector<vector<int>> res = combine(n - 1, k - 1);
        for (auto &a : res) a.push_back(n);
        for (auto &a : combine(n - 1, k)) res.push_back(a);
        return res;
    }
};
// @lc code=end

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out(k, 0);
        int i = 0;
        while (i >= 0) {
            ++out[i];
            if (out[i] > n) --i;
            else if (i == k - 1) res.push_back(out);
            else {
                ++i;
                out[i] = out[i - 1];
            }
        }
        return res;
    }
};
// @lc code=end
