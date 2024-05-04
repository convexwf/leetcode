/*
 * @lc app=leetcode id=1055 lang=cpp
 *
 * [1055] Shortest Way to Form String
 */

// @lc code=start
class Solution {
public:
    int shortestWay(string source, string target) {
        int res = 0;
        int i = 0, j = 0, last_j = 0;
        while (j < target.size()) {
            last_j = j;
            while (i < source.size() && j < target.size()) {
                if (source[i] == target[j]) {
                    i++;
                    j++;
                }
                else {
                    i++;
                }
            }
            if (j == last_j) {
                return -1;
            }
            res++;
            i = 0;
        }
        return res;
    }
};
// @lc code=end
