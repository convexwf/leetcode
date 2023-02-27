/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 *
 * https://leetcode.com/problems/jump-game-iv/description/
 *
 * algorithms
 * Hard (43.83%)
 * Likes:    2238
 * Dislikes: 87
 * Total Accepted:    84K
 * Total Submissions: 191.7K
 * Testcase Example:  '[100,-23,-23,404,100,23,23,23,3,404]'
 *
 * Given an array of integers arr, you are initially positioned at the first
 * index of the array.
 *
 * In one step you can jump from index i to index:
 *
 *
 * i + 1 where: i + 1 < arr.length.
 * i - 1 where: i - 1 >= 0.
 * j where: arr[i] == arr[j] and i != j.
 *
 *
 * Return the minimum number of steps to reach the last index of the array.
 *
 * Notice that you can not jump outside of the array at any time.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
 * Output: 3
 * Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that
 * index 9 is the last index of the array.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [7]
 * Output: 0
 * Explanation: Start index is the last index. You do not need to jump.
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [7,6,9,6,9,6,9,7]
 * Output: 1
 * Explanation: You can jump directly from index 0 to index 7 which is last
 * index of the array.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 5 * 10^4
 * -10^8 <= arr[i] <= 10^8
 *
 *
 */

// @lc code=start
// 2023-02-26 submission
// 33/33 cases passed
// Runtime: 210 ms, faster than 81.23% of C++ online submissions.
// Memory Usage: 73.6 MB, less than 70.93% of C++ online submissions.
class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() <= 1) return 0;

        vector<int> nums;
        unordered_map<int, vector<int>> m;
        int n = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (i == 0 || i == arr.size() - 1 || arr[i] != arr[i - 1] || arr[i] != arr[i+1]) {
                m[arr[i]].push_back(n++);
            }
        }

        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q; q.push(0);
        int step = 0;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize-- > 0) {
                int idx = q.front(); q.pop();

                for (int neighbor : vector<int>{idx - 1, idx + 1}) {
                    if (neighbor == n - 1) return ++step;
                    if (0 <= neighbor && neighbor < n && !visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }

                vector<int>& neighbors = m[arr[idx]];
                for (int i = (int)neighbors.size() - 1; i >= 0 ; --i) {
                    if (neighbors[i] == n - 1) return ++step;
                    if (!visited[neighbors[i]]) {
                        visited[neighbors[i]] = true;
                        q.push(neighbors[i]);
                    }
                }
                neighbors.clear(); // key operation
            }
            ++step;
        }
        return -1;
    }
};
// @lc code=end
