/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (39.11%)
 * Likes:    4953
 * Dislikes: 122
 * Total Accepted:    185.5K
 * Total Submissions: 488K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi]
 * represents the width and the height of an envelope.
 *
 * One envelope can fit into another if and only if both the width and height
 * of one envelope are greater than the other envelope's width and height.
 *
 * Return the maximum number of envelopes you can Russian doll (i.e., put one
 * inside the other).
 *
 * Note: You cannot rotate an envelope.
 *
 *
 * Example 1:
 *
 *
 * Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 *
 *
 * Example 2:
 *
 *
 * Input: envelopes = [[1,1],[1,1],[1,1]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= envelopes.length <= 10^5
 * envelopes[i].length == 2
 * 1 <= wi, hi <= 10^5
 *
 *
 */

// @lc code=start
// 一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

// 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

// 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

// 注意：不允许旋转信封。

// Follow up是信封可以旋转，怎么的最长序列？答案是<3,4>加入，然后<4,3>也加入，再找最长序列。
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        envelopes.insert(envelopes.begin(), vector<int>{0, 0});

        vector<int> dp(envelopes.size(), 0);
        int res = 0;
        for (int i = 1; i < envelopes.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

