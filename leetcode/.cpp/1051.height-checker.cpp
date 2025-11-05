/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
// 1. 排序
// 2023-10-09 submission
// 81/81 cases passed
// Runtime: 4 ms, faster than 37.75% of cpp online submissions.
// Memory Usage: 8.5 MB, less than 13.18% of cpp online submissions.
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights);
        sort(expected.begin(), expected.end());
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != expected[i]) {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// 2. 计数排序
// 2023-10-09 submission
// 81/81 cases passed
// Runtime: 0 ms, faster than 100% of cpp online submissions.
// Memory Usage: 8.4 MB, less than 36.73% of cpp online submissions.
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> cnt(101, 0);
        for (int h : heights) {
            cnt[h]++;
        }
        int res = 0;
        for (int i = 1, j = 0; i < cnt.size(); i++) {
            while (cnt[i]-- > 0) {
                if (heights[j++] != i) {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
