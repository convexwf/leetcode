/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 *
 * https://leetcode.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (49.93%)
 * Likes:    4187
 * Dislikes: 97
 * Total Accepted:    177.1K
 * Total Submissions: 354.6K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * We want to split a group of n people (labeled from 1 to n) into two groups
 * of any size. Each person may dislike some other people, and they should not
 * go into the same group.
 *
 * Given the integer n and the array dislikes where dislikes[i] = [ai, bi]
 * indicates that the person labeled ai does not like the person labeled bi,
 * return true if it is possible to split everyone into two groups in this
 * way.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
 * Output: true
 * Explanation: The first group has [1,4], and the second group has [2,3].
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
 * Output: false
 * Explanation: We need at least 3 groups to divide them. We cannot put them in
 * two groups.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2000
 * 0 <= dislikes.length <= 10^4
 * dislikes[i].length == 2
 * 1 <= ai < bi <= n
 * All the pairs of dislikes are unique.
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n, vector<int>{});
        for(vector<int> dislike : dislikes) {
            graph[dislike[0] - 1].push_back(dislike[1] - 1);
            graph[dislike[1] - 1].push_back(dislike[0] - 1);
        }

        vector<int> root(n, 0);
        for (int i = 0; i < n; ++i) {
            root[i] = i;
        }
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].empty()) continue;
            int x = find(root, i), y = find(root, graph[i][0]);
            if (x == y) return false;
            for (int j = 1; j < graph[i].size(); ++j) {
                int parent = find(root, graph[i][j]);
                if (x == parent) return false;
                root[parent] = y;
            }
        }
        return true;
    }

    int find(vector<int>& root, int i) {
        return i == root[i] ? i : find(root, root[i]);
    }
};
// @lc code=end

