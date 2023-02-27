/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 *
 * https://leetcode.com/problems/jump-game-iii/description/
 *
 * algorithms
 * Medium (63.36%)
 * Likes:    3533
 * Dislikes: 85
 * Total Accepted:    182.3K
 * Total Submissions: 287.5K
 * Testcase Example:  '[4,2,3,0,3,1,2]\n5'
 *
 * Given an array of non-negative integers arr, you are initially positioned at
 * start index of the array. When you are at index i, you can jump to i +
 * arr[i] or i - arr[i], check if you can reach to any index with value 0.
 *
 * Notice that you can not jump outside of the array at any time.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [4,2,3,0,3,1,2], start = 5
 * Output: true
 * Explanation:
 * All possible ways to reach at index 3 with value 0 are:
 * index 5 -> index 4 -> index 1 -> index 3
 * index 5 -> index 6 -> index 4 -> index 1 -> index 3
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [4,2,3,0,3,1,2], start = 0
 * Output: true
 * Explanation:
 * One possible way to reach at index 3 with value 0 is:
 * index 0 -> index 4 -> index 1 -> index 3
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [3,0,2,1,2], start = 2
 * Output: false
 * Explanation: There is no way to reach at index 1 with value 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 5 * 10^4
 * 0 <= arr[i] < arr.length
 * 0 <= start < arr.length
 *
 *
 */

// @lc code=start
// 2023-02-24 submission
// 56/56 cases passed
// Runtime: 40 ms, faster than 92.84% of C++ online submissions.
// Memory Usage: 31.3 MB, less than 85.81% of C++ online submissions.
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(start);
        int idx = 0, lp = 0, rp = 0;
        while (!q.empty()) {
            idx = q.front(); q.pop();
            if (arr[idx] == 0) return true;
            lp = idx - arr[idx];
            rp = idx + arr[idx];
            if (lp >= 0 && !visited[lp]) {
                visited[lp] = true;
                q.push(lp);
            }
            if (rp < n && !visited[rp]) {
                visited[rp] = true;
                q.push(rp);
            }
        }
        return false;
    }
};
// @lc code=end
