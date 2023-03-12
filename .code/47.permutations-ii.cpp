/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (55.94%)
 * Likes:    6084
 * Dislikes: 107
 * Total Accepted:    679.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
// 2023-02-28 submission
// 33/33 cases passed
// Runtime: 6 ms, faster than 83.27% of C++ online submissions.
// Memory Usage: 8.4 MB, less than 88.88% of C++ online submissions.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> candidate;
        map<int, int> m;

        int n = nums.size();
        for (int num : nums) {
            ++m[num];
        }
        permute(result, candidate, m, n);
        return result;
    }

    void permute(vector<vector<int>>& result, vector<int>& candidate, map<int, int>& m, int n) {
        if (candidate.size() == n) {
            result.push_back(candidate);
            return;
        }
        for (auto it : m) {
            if (it.second <= 0) continue;
            m[it.first] -= 1;
            candidate.push_back(it.first);
            permute(result, candidate, m, n);
            candidate.pop_back();
            m[it.first] += 1;
        }
    }
};
// @lc code=end