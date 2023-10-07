/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */

// @lc code=start
// 2023-02-22 submission
// 52/52 cases passed
// Runtime: 4 ms, faster than 29.59% of C++ online submissions.
// Memory Usage: 7.1 MB, less than 81.12% of C++ online submissions.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int last = -1, res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (i > last) ++res;
            last = max(last, arr[i]);
        }
        return res;
    }
};
// @lc code=end